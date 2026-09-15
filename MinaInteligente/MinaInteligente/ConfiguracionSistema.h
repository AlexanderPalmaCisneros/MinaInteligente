#pragma once

using namespace System::Collections::Generic;

#include "ModoOperacion.h"

namespace MinaInteligente {

    ref class TipoGas;

    public ref class ConfiguracionSistema
    {
    private:
        static ConfiguracionSistema^ instancia;

        double umbralActivacion;
        double umbralDesactivacion;
        double umbralCritico;
        double limiteExposicion;
        double caudalPorDefecto;
        ModoOperacion modoOperacion;
        List<TipoGas^>^ tiposGasDisponibles;

        ConfiguracionSistema();

    public:
        static ConfiguracionSistema^ ObtenerInstancia();

        void CargarConfiguracion();
        void GuardarConfiguracion();
        ModoOperacion GetModoOperacion();
        void SetModoOperacion(ModoOperacion modo);
        void AgregarTipoGas(TipoGas^ tipo);
        List<TipoGas^>^ ObtenerTiposGas();
        void ActualizarUmbrales(double activacion, double desactivacion, double critico);
        void SetLimiteExposicion(double valor);
        double GetLimiteExposicion();

        void GetUmbrales();
    };
}
