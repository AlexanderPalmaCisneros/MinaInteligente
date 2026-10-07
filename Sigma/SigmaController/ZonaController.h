#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    public ref class ZonaController {
    private:
        /*Devuelve el mensaje del primer problema encontrado, o nullptr si los datos son validos*/
        String^ ValidarDatos(Zona^ elemento);

    public:
        ZonaController();

        /*Siguiente id autogenerado (zona01, zona02...)*/
        String^ GenerarId();

        /*Registrar/Modificar/Eliminar devuelven el motivo del rechazo, o nullptr si todo salio bien*/
        String^ RegistrarZona(Zona^ elemento);

        Zona^ ConsultarZona(String^ id);

        List<Zona^>^ ListarZonas();

        List<Zona^>^ BuscarZonas(String^ texto);

        String^ ModificarZona(Zona^ elemento);

        String^ EliminarZona(String^ id);

    };
}
