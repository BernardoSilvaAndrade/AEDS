#include "Config.hpp"

Config::Config(int tics, bool vento)
{
    ticsTotais = tics;
    ventania = vento;
    contadorCasaZero = 0;
}

int Config::getTicsTotais()
{
    return ticsTotais;
}

bool Config::temVentania()
{
    return ventania;
}

void Config::resetarContador()
{
    contadorCasaZero = 0;
}

void Config::incrementarContador()
{
    contadorCasaZero++;
}

bool Config::precisaMoverDaCasaZero()
{
    return contadorCasaZero >= 3;
}
