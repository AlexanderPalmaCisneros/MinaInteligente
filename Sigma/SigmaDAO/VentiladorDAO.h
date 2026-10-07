#pragma once
namespace SigmaDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SigmaModel;

	public ref class VentiladorDAO {
	private:
		List<Ventilador^>^ LeerArchivo();
		void EscribirArchivo(List<Ventilador^>^ lista);

	public:
		VentiladorDAO();

		/*Siguiente id libre con formato ventilador01, ventilador02...*/
		String^ GenerarId();

		bool RegistrarVentilador(Ventilador^ elemento);

		Ventilador^ ConsultarVentilador(String^ id);

		List<Ventilador^>^ ListarVentiladores();

		/*Reemplaza el elemento que tenga el mismo id*/
		bool ModificarVentilador(Ventilador^ elemento);

		bool EliminarVentilador(String^ id);
	};
}
