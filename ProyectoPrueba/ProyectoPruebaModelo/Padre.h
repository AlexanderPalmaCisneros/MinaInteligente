#pragma once
namespace ProyectoPruebaModelo {
	using namespace System;

	public ref class producto {
	private:
		/*atributos*/
		int atributos;
		String^ id;

	public:
		/*Metodos o funciones miembro*/
		producto(); //constructor vacio
		producto(int atributos, String^ id); //Constructor completo
		String^ GetID();
		void SetID(String^ id);
	};
}
