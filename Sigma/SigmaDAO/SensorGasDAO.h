#pragma once
namespace SigmaDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SigmaModel;

	public ref class SensorGasDAO {
	private:
		List<SensorGas^>^ LeerArchivo();
		void EscribirArchivo(List<SensorGas^>^ lista);

	public:
		SensorGasDAO();

		/*Siguiente id libre con formato sensor01, sensor02...*/
		String^ GenerarId();

		bool RegistrarSensorGas(SensorGas^ elemento);

		SensorGas^ ConsultarSensorGas(String^ id);

		List<SensorGas^>^ ListarSensoresGas();

		/*Reemplaza el elemento que tenga el mismo id*/
		bool ModificarSensorGas(SensorGas^ elemento);

		bool EliminarSensorGas(String^ id);
	};
}
