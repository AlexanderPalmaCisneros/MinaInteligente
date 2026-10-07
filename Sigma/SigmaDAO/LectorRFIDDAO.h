#pragma once
namespace SigmaDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SigmaModel;

	public ref class LectorRFIDDAO {
	private:
		List<LectorRFID^>^ LeerArchivo();
		void EscribirArchivo(List<LectorRFID^>^ lista);

	public:
		LectorRFIDDAO();

		/*Siguiente id libre con formato lector01, lector02...*/
		String^ GenerarId();

		bool RegistrarLectorRFID(LectorRFID^ elemento);

		LectorRFID^ ConsultarLectorRFID(String^ id);

		List<LectorRFID^>^ ListarLectoresRFID();

		/*Reemplaza el elemento que tenga el mismo id*/
		bool ModificarLectorRFID(LectorRFID^ elemento);

		bool EliminarLectorRFID(String^ id);
	};
}
