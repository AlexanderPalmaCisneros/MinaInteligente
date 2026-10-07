#pragma once
namespace SigmaDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SigmaModel;

	public ref class LEDDAO {
	private:
		List<LED^>^ LeerArchivo();
		void EscribirArchivo(List<LED^>^ lista);

	public:
		LEDDAO();

		/*Siguiente id libre con formato led01, led02...*/
		String^ GenerarId();

		bool RegistrarLED(LED^ elemento);

		LED^ ConsultarLED(String^ id);

		List<LED^>^ ListarLEDs();

		/*Reemplaza el elemento que tenga el mismo id*/
		bool ModificarLED(LED^ elemento);

		bool EliminarLED(String^ id);
	};
}
