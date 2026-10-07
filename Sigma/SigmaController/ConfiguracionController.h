#pragma once
namespace SigmaController {
    using namespace System;
    using namespace SigmaModel;

    /*Lee y modifica los parametros globales que viven en ConfiguracionSistema (Singleton)*/
    public ref class ConfiguracionController {
    public:
        ConfiguracionController();

        double GetUmbralActivacion();
        double GetUmbralDesactivacion();
        double GetUmbralCritico();
        double GetLimiteExposicion();
        ModoOperacion GetModoOperacion();

        /*Cada Actualizar devuelve el motivo del rechazo, o nullptr si se guardo bien*/
        String^ ActualizarUmbrales(double activacion, double desactivacion, double critico);
        String^ ActualizarLimiteExposicion(double limite);
        void CambiarModoOperacion(ModoOperacion modo);
    };
}
