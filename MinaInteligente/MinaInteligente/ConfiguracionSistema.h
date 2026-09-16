#pragma once

using namespace System::Collections::Generic;

#include "ModoOperacion.h"

namespace MinaInteligente {

    ref class TipoGas;

    public ref class ConfiguracionSistema
    {
    private:
        // En C++/CLI los campos static de un ref class deben inicializarse
        // en la propia definicion de la clase, no en el .cpp.
        static ConfiguracionSistema^ instancia = nullptr;

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
