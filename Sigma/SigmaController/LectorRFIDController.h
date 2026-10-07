#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    public ref class LectorRFIDController {
    private:
        /*Devuelve el mensaje del primer problema encontrado, o nullptr si los datos son validos*/
        String^ ValidarDatos(LectorRFID^ elemento);

    public:
        LectorRFIDController();

        /*Siguiente id autogenerado (lector01, lector02...)*/
        String^ GenerarId();

        /*Registrar/Modificar/Eliminar devuelven el motivo del rechazo, o nullptr si todo salio bien*/
        String^ RegistrarLectorRFID(LectorRFID^ elemento);

        LectorRFID^ ConsultarLectorRFID(String^ id);

        List<LectorRFID^>^ ListarLectoresRFID();

        String^ ModificarLectorRFID(LectorRFID^ elemento);

        String^ EliminarLectorRFID(String^ id);

    };
}
