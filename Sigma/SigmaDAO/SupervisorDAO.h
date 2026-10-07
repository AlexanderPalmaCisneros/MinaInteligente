#pragma once
namespace SigmaDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SigmaModel;

	public ref class SupervisorDAO {
	private:
		List<Supervisor^>^ LeerArchivo();
		void EscribirArchivo(List<Supervisor^>^ lista);

	public:
		SupervisorDAO();

		/*Siguiente id libre con formato supervisor01, supervisor02...*/
		String^ GenerarId();

		bool RegistrarSupervisor(Supervisor^ elemento);

		Supervisor^ ConsultarSupervisor(String^ id);

		List<Supervisor^>^ ListarSupervisores();

		/*Reemplaza el elemento que tenga el mismo id*/
		bool ModificarSupervisor(Supervisor^ elemento);

		bool EliminarSupervisor(String^ id);
	};
}
