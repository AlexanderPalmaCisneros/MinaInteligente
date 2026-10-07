#pragma once
namespace SigmaDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SigmaModel;

	public ref class TipoGasDAO {
	private:
		List<TipoGas^>^ LeerArchivo();
		void EscribirArchivo(List<TipoGas^>^ lista);

	public:
		TipoGasDAO();

		/*Siguiente id libre con formato tipogas01, tipogas02...*/
		String^ GenerarId();

		bool RegistrarTipoGas(TipoGas^ elemento);

		TipoGas^ ConsultarTipoGas(String^ id);

		List<TipoGas^>^ ListarTiposGas();

		/*Reemplaza el elemento que tenga el mismo id*/
		bool ModificarTipoGas(TipoGas^ elemento);

		bool EliminarTipoGas(String^ id);
	};
}
