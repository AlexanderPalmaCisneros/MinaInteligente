#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    /*Vista unificada de los 4 tipos de dispositivo (LED, ventilador, sensor de gas y lector RFID)*/
    public ref class DispositivoController {
    public:
        DispositivoController();

        /*Tipos disponibles para el desplegable de filtro y de creacion*/
        array<String^>^ ObtenerTipos();

        List<Dispositivo^>^ ListarDispositivos();

        /*Filtra por texto (id, zona o tipo) y por tipo; tipo vacio o "TODOS" no filtra por tipo*/
        List<Dispositivo^>^ BuscarDispositivos(String^ texto, String^ tipo);

        Dispositivo^ ConsultarDispositivo(String^ id);

        /*Nombre del tipo del dispositivo: LED, VENTILADOR, SENSOR GAS o LECTOR RFID*/
        String^ ObtenerTipo(Dispositivo^ dispositivo);

        /*Dato propio de cada tipo para mostrar en la lista (caudal, gas, color...)*/
        String^ ObtenerDetalle(Dispositivo^ dispositivo);

        /*Elimina el dispositivo sin importar su tipo; devuelve el motivo del rechazo o nullptr*/
        String^ EliminarDispositivo(String^ id);
    };
}
