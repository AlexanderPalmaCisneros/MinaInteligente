#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    public ref class TrabajadorController {
    private:
        /*Devuelve el mensaje del primer problema encontrado, o nullptr si los datos son validos*/
        String^ ValidarDatos(Trabajador^ elemento);

    public:
        TrabajadorController();

        /*Siguiente id autogenerado (obrero01, obrero02...)*/
        String^ GenerarId();

        /*Registrar/Modificar/Eliminar devuelven el motivo del rechazo, o nullptr si todo salio bien*/
        String^ RegistrarTrabajador(Trabajador^ elemento);

        Trabajador^ ConsultarTrabajador(String^ id);

        List<Trabajador^>^ ListarTrabajadores();

        List<Trabajador^>^ BuscarTrabajadores(String^ texto);

        String^ ModificarTrabajador(Trabajador^ elemento);

        String^ EliminarTrabajador(String^ id);

    };
}
