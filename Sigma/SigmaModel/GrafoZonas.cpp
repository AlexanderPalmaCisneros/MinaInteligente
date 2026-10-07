#include "pch.h"
#include "GrafoZonas.h"
#include "Zona.h"
#include "Trabajador.h"
#include "LED.h"

using namespace SigmaModel;

GrafoZonas::GrafoZonas()
{
    this->zonas = gcnew List<Zona^>();
}

bool GrafoZonas::AgregarZonaSalida(Zona^ zona)
{
    if (zona == nullptr || this->zonas->Count > 0)
    {
        return false;
    }
    zona->UbicarEn(nullptr, CaraZona::DERECHA, 0, 0);
    zona->SetEsZonaSalida(true);
    this->zonas->Add(zona);
    return true;
}

bool GrafoZonas::AgregarZona(Zona^ nueva, Zona^ padre, CaraZona cara)
{
    if (nueva == nullptr || padre == nullptr || !this->ContieneZona(padre) || this->ContieneZona(nueva))
    {
        return false;
    }

    // La celda depende de la cara elegida; la izquierda siempre queda como union hacia la salida
    int fila = padre->GetFila();
    int columna = padre->GetColumna();
    if (cara == CaraZona::ARRIBA)
    {
        fila = fila - 1;
    }
    else if (cara == CaraZona::ABAJO)
    {
        fila = fila + 1;
    }
    else
    {
        columna = columna + 1;
    }

    if (this->ObtenerZonaEn(fila, columna) != nullptr)
    {
        return false;
    }

    nueva->UbicarEn(padre, cara, fila, columna);
    // Conexion dirigida hacia la salida: asi ObtenerRutaEscape siempre la encuentra
    nueva->ConectarCon(padre);
    this->zonas->Add(nueva);
    return true;
}

bool GrafoZonas::QuitarZona(Zona^ zona)
{
    if (!this->ContieneZona(zona) || this->ObtenerHijas(zona)->Count > 0)
    {
        return false;
    }

    Zona^ padre = zona->GetZonaPadre();
    if (padre != nullptr)
    {
        zona->ObtenerConexiones()->Remove(padre);
    }
    else
    {
        zona->SetEsZonaSalida(false);
    }
    zona->UbicarEn(nullptr, CaraZona::DERECHA, 0, 0);
    this->zonas->Remove(zona);
    return true;
}

Zona^ GrafoZonas::ObtenerZonaEn(int fila, int columna)
{
    for each (Zona ^ zona in this->zonas)
    {
        if (zona->GetFila() == fila && zona->GetColumna() == columna)
        {
            return zona;
        }
    }
    return nullptr;
}

List<Zona^>^ GrafoZonas::ObtenerHijas(Zona^ zona)
{
    List<Zona^>^ hijas = gcnew List<Zona^>();
    for each (Zona ^ otra in this->zonas)
    {
        if (otra->GetZonaPadre() == zona)
        {
            hijas->Add(otra);
        }
    }
    return hijas;
}

bool GrafoZonas::ContieneZona(Zona^ zona)
{
    return zona != nullptr && this->zonas->Contains(zona);
}

List<Zona^>^ GrafoZonas::ObtenerZonas()
{
    return this->zonas;
}

List<Zona^>^ GrafoZonas::ObtenerRutaEscape(Zona^ origen)
{
    List<Zona^>^ ruta = gcnew List<Zona^>();
    if (origen == nullptr)
    {
        return ruta;
    }

    // Busqueda en amplitud sobre el grafo dirigido de conexiones, hasta
    // encontrar la primera zona marcada como salida.
    Dictionary<Zona^, Zona^>^ predecesor = gcnew Dictionary<Zona^, Zona^>();
    List<Zona^>^ visitados = gcnew List<Zona^>();
    Queue<Zona^>^ pendientes = gcnew Queue<Zona^>();

    visitados->Add(origen);
    pendientes->Enqueue(origen);

    Zona^ zonaSalida = nullptr;

    while (pendientes->Count > 0 && zonaSalida == nullptr)
    {
        Zona^ actual = pendientes->Dequeue();

        if (actual->GetEsZonaSalida())
        {
            zonaSalida = actual;
            break;
        }

        for each (Zona ^ vecino in actual->ObtenerConexiones())
        {
            if (!visitados->Contains(vecino))
            {
                visitados->Add(vecino);
                predecesor[vecino] = actual;
                pendientes->Enqueue(vecino);
            }
        }
    }

    if (zonaSalida == nullptr)
    {
        // No hay ruta de escape alcanzable desde el origen.
        return ruta;
    }

    // Reconstruye la ruta desde la salida encontrada hasta el origen.
    Zona^ paso = zonaSalida;
    while (paso != nullptr)
    {
        ruta->Insert(0, paso);
        if (paso == origen)
        {
            break;
        }
        paso = predecesor[paso];
    }

    return ruta;
}

bool GrafoZonas::EvaluarRiesgoAislamiento(Trabajador^ trabajador, Zona^ zonaActual)
{
    List<Zona^>^ ruta = this->ObtenerRutaEscape(zonaActual);

    // Se evaluan las zonas intermedias de la ruta (se salta el indice 0,
    // que es la propia zonaActual: eso seria riesgo directo, no aislamiento).
    for (int i = 1; i < ruta->Count; i++)
    {
        Zona^ zonaIntermedia = ruta[i];
        if (zonaIntermedia->EvaluarRiesgoDirecto() == TipoRiesgo::DIRECTO)
        {
            return true;
        }
    }

    return false;
}

void GrafoZonas::PropagarRiesgoIndirecto(Zona^ zonaOrigen)
{
    // Marca en riesgo de aislamiento a las zonas vecinas directas desde las
    // que se podria cruzar hacia zonaOrigen, y enciende su LED en naranja
    // para advertir que no se debe cruzar hacia la zona en riesgo.
    for each (Zona ^ zona in this->zonas)
    {
        if (zona == zonaOrigen)
        {
            continue;
        }

        if (zona->ObtenerConexiones()->Contains(zonaOrigen))
        {
            zona->SetTipoRiesgo(TipoRiesgo::AISLAMIENTO);

            LED^ led = zona->ObtenerLed();
            if (led != nullptr)
            {
                led->ActualizarColor(TipoRiesgo::AISLAMIENTO);
            }
        }
    }
}
