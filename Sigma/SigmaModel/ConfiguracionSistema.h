#pragma once
#include "TipoGas.h"
#include "ModoOperacion.h"


using namespace System;
using namespace System::Collections::Generic;

namespace SigmaModel {

    public ref class ConfiguracionSistema
    {
    private:
        double umbralActivacion;
        double umbralDesactivacion;
        double umbralCritico;
        double limiteExposicion;
        ModoOperacion modoOperacion;
        List<TipoGas^>^ tiposGasDisponibles;

        static ConfiguracionSistema^ instancia = nullptr;

        // Constructor privado — patrón Singleton
        ConfiguracionSistema();

    public:
        static ConfiguracionSistema^ ObtenerInstancia();

        void CargarConfiguracion();
        void GuardarConfiguracion();

        ModoOperacion GetModoOperacion();
        void SetModoOperacion(ModoOperacion modo);

        void AgregarTipoGas(TipoGas^ tipo);
        List<TipoGas^>^ ObtenerTiposGas();

        // Devuelve false (sin cambiar nada) si no se cumple 0 < desactivacion < activacion < critico.
        bool ActualizarUmbrales(double activacion, double desactivacion, double critico);

        // Devuelve false si el valor no es mayor que cero.
        bool SetLimiteExposicion(double valor);
        double GetLimiteExposicion();

        double GetUmbralActivacion();
        double GetUmbralDesactivacion();
        double GetUmbralCritico();
    };
}