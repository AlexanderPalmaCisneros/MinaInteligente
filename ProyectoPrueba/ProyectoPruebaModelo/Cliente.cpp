#include "pch.h"
#include "Cliente.h"

using namespace ProyectoPruebaModelo;

Cliente::Cliente() {

}
Cliente::Cliente(int atributos, String^ id) {
	this->atributos = atributos;
	this->id = id;
}
String^ Cliente::GetID() {
	return this->id;
}
void Cliente::SetID(String^ id) {
	this->id = id;
}

