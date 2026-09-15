#pragma once

using namespace System;

#include "FuenteDatos.h"

namespace MinaInteligente {

    ref class Zona;

    public ref class FuenteDatosSimulada : public FuenteDatos
    {
    private:
        // Valor semilla configurado manualmente via ConfigurarValor() al iniciar la
        // simulacion; luego se autoactualiza en cada llamada a ObtenerLectura() segun
        // la formula 4.1.
        double valorSimulado;

        // Parametro configurable de la simulacion (antes vivia en Zona); tasa de
        // generacion de gas usada en la rama "ventilador apagado" de la formula 4.1.
        double generacionGas;

        // Referencia a la zona que esta fuente simula; permite consultar Ventilador
        // (estado/caudal) y el volumen de la zona para aplicar la formula 4.1.
        Zona^ zonaSimulada;

        // Marca de tiempo de la ultima llamada a ObtenerLectura(); permite calcular
        // deltaTiempo internamente sin alterar la firma heredada de FuenteDatos.
        DateTime ultimaActualizacion;

    public:
        // Implementa ambas ramas de la formula 4.1 usando zonaSimulada.ObtenerVentilador()
        // y zonaSimulada.GetVolumen(). deltaTiempo se calcula internamente (ahora -
        // ultimaActualizacion), sin agregar parametros a la firma heredada de FuenteDatos.
        virtual double ObtenerLectura() override;

        // Fija el valor semilla inicial de la simulacion (ej. "empezar en 30 ppm").
        void ConfigurarValor(double valor);

    private:
        void SimularAumento(bool VentiladorActivo);
        void SimularDecesenso(bool VentiladorActivo);
    };
}
