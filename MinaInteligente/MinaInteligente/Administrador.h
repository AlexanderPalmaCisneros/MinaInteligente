#pragma once

using namespace System;

#include "Usuario.h"

namespace MinaInteligente {

    ref class TipoGas;

    public ref class Administrador : public Usuario
    {
    public:
        Administrador(String^ id, String^ nombre, String^ credenciales);

        void GestionarUsuarios();
        void GestionarZonas();
        void GestionarDispositivos();
        void ConfigurarParametros();
        TipoGas^ AgregarTipoGas(String^ nombre, String^ simbolo, double generacionDefault);
    };
}
