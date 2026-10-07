#pragma once

using namespace System;

namespace SigmaModel {

    public ref class TipoGas
    {
    private:
        String^ id;
        String^ nombre;
        String^ simbolo;
        double generacionGasDefault;

    public:
        TipoGas();
        TipoGas(String^ id, String^ nombre, String^ simbolo, double generacionGasDefault);

        String^ GetId();
        String^ GetNombre();
        String^ GetSimbolo();
        double GetGeneracionGasDefault();
        void SetSimbolo(String^ simbolo);

    };
}
