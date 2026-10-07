#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    public ref class TipoGasController {
    private:
        /*Devuelve el mensaje del primer problema encontrado, o nullptr si los datos son validos*/
        String^ ValidarDatos(TipoGas^ elemento);

    public:
        TipoGasController();

        /*Siguiente id autogenerado (tipogas01, tipogas02...)*/
        String^ GenerarId();

        /*Registrar/Modificar/Eliminar devuelven el motivo del rechazo, o nullptr si todo salio bien*/
        String^ RegistrarTipoGas(TipoGas^ elemento);

        TipoGas^ ConsultarTipoGas(String^ id);

        List<TipoGas^>^ ListarTiposGas();

        List<TipoGas^>^ BuscarTiposGas(String^ texto);

        String^ ModificarTipoGas(TipoGas^ elemento);

        String^ EliminarTipoGas(String^ id);

    };
}
