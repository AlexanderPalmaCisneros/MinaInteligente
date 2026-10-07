#pragma once
namespace SigmaDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SigmaModel;

	public ref class AdministradorDAO {
	private:
		List<Administrador^>^ LeerArchivo();
		void EscribirArchivo(List<Administrador^>^ lista);

	public:
		AdministradorDAO();

		/*Siguiente id libre con formato admin01, admin02...*/
		String^ GenerarId();

		bool RegistrarAdministrador(Administrador^ elemento);

		Administrador^ ConsultarAdministrador(String^ id);

		List<Administrador^>^ ListarAdministradores();

		/*Reemplaza el elemento que tenga el mismo id*/
		bool ModificarAdministrador(Administrador^ elemento);

		bool EliminarAdministrador(String^ id);
	};
}
