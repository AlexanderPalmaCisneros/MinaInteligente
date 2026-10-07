#pragma once
namespace SigmaDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SigmaModel;

	public ref class TrabajadorDAO {
	private:
		List<Trabajador^>^ LeerArchivo();
		void EscribirArchivo(List<Trabajador^>^ lista);

	public:
		TrabajadorDAO();

		/*Siguiente id libre con formato obrero01, obrero02...*/
		String^ GenerarId();

		bool RegistrarTrabajador(Trabajador^ elemento);

		Trabajador^ ConsultarTrabajador(String^ id);

		List<Trabajador^>^ ListarTrabajadores();

		/*Reemplaza el elemento que tenga el mismo id*/
		bool ModificarTrabajador(Trabajador^ elemento);

		bool EliminarTrabajador(String^ id);
	};
}
