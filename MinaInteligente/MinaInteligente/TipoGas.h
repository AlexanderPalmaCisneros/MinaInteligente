#pragma once

using namespace System;

namespace MinaInteligente {

    public ref class TipoGas
    {
    private:
        String^ id;
        String^ nombre;
        String^ simbolo;
        double generacionGasDefault;

    public:
        // El diagrama no especifica el tipo de los parametros del constructor;
        // se usan los tipos inferidos de los atributos homonimos.
        TipoGas(String^ id, String^ nombre, String^ simbolo, double generacionGasDefault);

        String^ GetId();
        String^ GetNombre();
    };
}
