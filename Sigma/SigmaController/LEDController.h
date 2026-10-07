#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    public ref class LEDController {
    private:
        /*Devuelve el mensaje del primer problema encontrado, o nullptr si los datos son validos*/
        String^ ValidarDatos(LED^ elemento);

    public:
        LEDController();

        /*Siguiente id autogenerado (led01, led02...)*/
        String^ GenerarId();

        /*Registrar/Modificar/Eliminar devuelven el motivo del rechazo, o nullptr si todo salio bien*/
        String^ RegistrarLED(LED^ elemento);

        LED^ ConsultarLED(String^ id);

        List<LED^>^ ListarLEDs();

        String^ ModificarLED(LED^ elemento);

        String^ EliminarLED(String^ id);

    };
}
