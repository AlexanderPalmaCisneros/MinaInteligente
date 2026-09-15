#pragma once

using namespace System;

#include "RolUsuario.h"

namespace MinaInteligente {

    public ref class Usuario abstract
    {
    private:
        String^ id;
        String^ nombre;
        String^ credenciales;
        RolUsuario rol;

    public:
        String^ GetId();
        String^ GetNombre();
        bool ValidarCredenciales(String^ clave);
    };
}
