#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    public ref class AdministradorController {
    private:
        /*Devuelve el mensaje del primer problema encontrado, o nullptr si los datos son validos*/
        String^ ValidarDatos(Administrador^ elemento);

    public:
        AdministradorController();

        /*Siguiente id autogenerado (admin01, admin02...)*/
        String^ GenerarId();

        /*Registrar/Modificar/Eliminar devuelven el motivo del rechazo, o nullptr si todo salio bien*/
        String^ RegistrarAdministrador(Administrador^ elemento);

        Administrador^ ConsultarAdministrador(String^ id);

        List<Administrador^>^ ListarAdministradores();

        List<Administrador^>^ BuscarAdministradores(String^ texto);

        String^ ModificarAdministrador(Administrador^ elemento);

        String^ EliminarAdministrador(String^ id);

        /*Devuelve el administrador si el usuario (id o nombre) y la clave coinciden; si no, nullptr*/
        Administrador^ Autenticar(String^ usuario, String^ clave);
    };
}
