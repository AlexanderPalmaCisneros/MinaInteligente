#pragma once
namespace SigmaDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SigmaModel;

	public ref class ZonaDAO {
	private:
		List<Zona^>^ LeerArchivo();
		void EscribirArchivo(List<Zona^>^ lista);

	public:
		ZonaDAO();

		/*Siguiente id libre con formato zona01, zona02...*/
		String^ GenerarId();

		bool RegistrarZona(Zona^ elemento);

		Zona^ ConsultarZona(String^ id);

		List<Zona^>^ ListarZonas();

		/*Reemplaza el elemento que tenga el mismo id*/
		bool ModificarZona(Zona^ elemento);

		bool EliminarZona(String^ id);
	};
}
