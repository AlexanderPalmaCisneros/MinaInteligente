#pragma once

namespace ProyectoPruebaModelo {
	using namespace System;
	
	public ref class Cliente{
		private:
			/*atributos*/
			int atributos;
			String^ id;

		public:
			/*Metodos o funciones miembro*/
			Cliente(); //constructor vacio
			Cliente(int atributos, String^ id); //Constructor completo
			String^ GetID();
			void SetID(String^ id);
	};
}


