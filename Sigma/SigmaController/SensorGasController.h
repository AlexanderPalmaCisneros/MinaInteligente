#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    public ref class SensorGasController {
    private:
        /*Devuelve el mensaje del primer problema encontrado, o nullptr si los datos son validos*/
        String^ ValidarDatos(SensorGas^ elemento);

    public:
        SensorGasController();

        /*Siguiente id autogenerado (sensor01, sensor02...)*/
        String^ GenerarId();

        /*Registrar/Modificar/Eliminar devuelven el motivo del rechazo, o nullptr si todo salio bien*/
        String^ RegistrarSensorGas(SensorGas^ elemento);

        SensorGas^ ConsultarSensorGas(String^ id);

        List<SensorGas^>^ ListarSensoresGas();

        String^ ModificarSensorGas(SensorGas^ elemento);

        String^ EliminarSensorGas(String^ id);

    };
}
