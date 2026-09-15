#pragma once

#include "FuenteDatos.h"

namespace MinaInteligente {

    public ref class FuenteDatosReal : public FuenteDatos
    {
    public:
        virtual double ObtenerLectura() override;
    };
}
