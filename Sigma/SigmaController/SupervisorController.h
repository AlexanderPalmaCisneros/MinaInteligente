#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    public ref class SupervisorController {
    private:
        /*Devuelve el mensaje del primer problema encontrado, o nullptr si los datos son validos*/
        String^ ValidarDatos(Supervisor^ elemento);

    public:
        SupervisorController();

        /*Siguiente id autogenerado (supervisor01, supervisor02...)*/
        String^ GenerarId();

        /*Registrar/Modificar/Eliminar devuelven el motivo del rechazo, o nullptr si todo salio bien*/
        String^ RegistrarSupervisor(Supervisor^ elemento);

        Supervisor^ ConsultarSupervisor(String^ id);

        List<Supervisor^>^ ListarSupervisores();

        List<Supervisor^>^ BuscarSupervisores(String^ texto);

        String^ ModificarSupervisor(Supervisor^ elemento);

        String^ EliminarSupervisor(String^ id);

        /*Devuelve el supervisor si el usuario (id o nombre) y la clave coinciden; si no, nullptr*/
        Supervisor^ Autenticar(String^ usuario, String^ clave);
    };
}
