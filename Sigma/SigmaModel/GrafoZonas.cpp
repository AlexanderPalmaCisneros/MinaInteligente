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

void GrafoZonas::AgregarZona(Zona^ zona)
{
    this->zonas->Add(zona);
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
