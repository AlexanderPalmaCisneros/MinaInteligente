#pragma once
namespace SigmaController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SigmaModel;

    /*El supervisor arma el grafo de zonas: salida, zonas colgadas arriba/derecha/abajo y quitar zonas*/
    public ref class GrafoZonasController {
    public:
        GrafoZonasController();

        /*Grafo armado con las zonas registradas y GrafoZonas.txt*/
        GrafoZonas^ CargarGrafo();

        /*Agregar/Quitar devuelven el motivo del rechazo, o nullptr si todo salio bien (y se guarda)*/
        String^ AgregarZonaSalida(String^ idZona);

        String^ AgregarZona(String^ idZona, String^ idPadre, CaraZona cara);

        String^ QuitarZona(String^ idZona);

        /*Zonas registradas que todavia no estan en el grafo*/
        List<Zona^>^ ZonasDisponibles();

        bool EstaEnGrafo(String^ idZona);

        NivelRiesgo ObtenerNivelRiesgo(Zona^ zona);

        /*Aislada: su ruta de escape pasa por una zona en riesgo critico*/
        bool EstaAislada(GrafoZonas^ grafo, Zona^ zona);
    };
}
