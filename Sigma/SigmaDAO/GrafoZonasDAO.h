#pragma once
namespace SigmaDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SigmaModel;

	/*Guarda la forma del grafo de zonas en GrafoZonas.txt (idZona;idPadre;cara;fila;columna)*/
	public ref class GrafoZonasDAO {
	public:
		GrafoZonasDAO();

		/*Arma el grafo con las zonas dadas segun el archivo; se descartan las zonas que ya no existen*/
		GrafoZonas^ CargarGrafo(List<Zona^>^ zonas);

		/*Escribe las zonas en el orden en que se agregaron (cada padre queda antes que sus hijas)*/
		void GuardarGrafo(GrafoZonas^ grafo);
	};
}
