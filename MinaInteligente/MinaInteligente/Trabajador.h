#pragma once

using namespace System;

namespace MinaInteligente {

    ref class HistorialExposicion;

    public ref class Trabajador
    {
    private:
        String^ id;
        String^ nombre;
        String^ idRFID;
        HistorialExposicion^ historial;

    public:
        Trabajador(String^ id, String^ nombre, String^ idRFID);

        String^ GetId();
        String^ GetIdRFID();
        HistorialExposicion^ GetHistorial();
    };
}
