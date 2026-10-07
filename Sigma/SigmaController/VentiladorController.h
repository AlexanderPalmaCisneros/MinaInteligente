#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    public ref class VentiladorController {
    private:
        /*Devuelve el mensaje del primer problema encontrado, o nullptr si los datos son validos*/
        String^ ValidarDatos(Ventilador^ elemento);

    public:
        VentiladorController();

        /*Siguiente id autogenerado (ventilador01, ventilador02...)*/
        String^ GenerarId();

        /*Registrar/Modificar/Eliminar devuelven el motivo del rechazo, o nullptr si todo salio bien*/
        String^ RegistrarVentilador(Ventilador^ elemento);

        Ventilador^ ConsultarVentilador(String^ id);

        List<Ventilador^>^ ListarVentiladores();

        String^ ModificarVentilador(Ventilador^ elemento);

        String^ EliminarVentilador(String^ id);

    };
}
