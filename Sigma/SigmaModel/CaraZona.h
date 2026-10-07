#pragma once

namespace SigmaModel {

    /*Cara del cuadrado de la zona padre donde se cuelga una zona nueva.
      La cara izquierda no aparece: siempre es la union hacia la salida.*/
    public enum class CaraZona
    {
        ARRIBA,
        DERECHA,
        ABAJO
    };
}
