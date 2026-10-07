#pragma once

#include "CaraZona.h"

using namespace System::Collections::Generic;

namespace SigmaModel {

    ref class Zona;
    ref class Trabajador;

    public ref class GrafoZonas
    {
    private:
        List<Zona^>^ zonas;

    public:
        GrafoZonas();

        /*La primera zona del grafo es la salida (fila 0, columna 0); su cara izquierda da al exterior*/
        bool AgregarZonaSalida(Zona^ zona);

        /*Cuelga la zona nueva en la cara (arriba, derecha o abajo) de padre y la conecta hacia padre.
          Falla si la celda ya esta ocupada, si padre no esta en el grafo o si la zona ya esta en el grafo.*/
        bool AgregarZona(Zona^ nueva, Zona^ padre, CaraZona cara);

        /*Solo se puede quitar una zona que no tenga zonas colgando*/
        bool QuitarZona(Zona^ zona);

        Zona^ ObtenerZonaEn(int fila, int columna);
        List<Zona^>^ ObtenerHijas(Zona^ zona);
        bool ContieneZona(Zona^ zona);

        List<Zona^>^ ObtenerRutaEscape(Zona^ origen);
        List<Zona^>^ ObtenerZonas();

        bool EvaluarRiesgoAislamiento(Trabajador^ trabajador, Zona^ zonaActual);

        void PropagarRiesgoIndirecto(Zona^ zonaOrigen);
    };
}
