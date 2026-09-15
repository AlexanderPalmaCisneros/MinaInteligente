#pragma once

namespace MinaInteligente {

    // Seccion 3.8: separa modo real y modo simulacion sobre la misma logica de negocio.
    public ref class FuenteDatos abstract
    {
    public:
        virtual double ObtenerLectura() abstract;
    };
}
