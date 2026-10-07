#include "pch.h"
#include "TipoGas.h"

using namespace SigmaModel;

TipoGas::TipoGas()
{
    this->id = String::Empty;
    this->nombre = String::Empty;
    this->simbolo = String::Empty;
    this->generacionGasDefault = 0.0;
}


TipoGas::TipoGas(String^ id, String^ nombre, String^ simbolo, double generacionGasDefault)
{
    this->id = id;
    this->nombre = nombre;
    this->simbolo = simbolo;
    this->generacionGasDefault = generacionGasDefault;
}

String^ TipoGas::GetId()
{
    return this->id;
}

String^ TipoGas::GetNombre()
{
    return this->nombre;
}

String^ TipoGas::GetSimbolo()
{
    return this->simbolo;
}

double TipoGas::GetGeneracionGasDefault()
{
    return this->generacionGasDefault;
}

void TipoGas::SetSimbolo(String^ simbolo) {
    this->simbolo = simbolo;
}
