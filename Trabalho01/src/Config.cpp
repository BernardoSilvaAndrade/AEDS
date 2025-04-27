#include "Config.hpp"
#include <iostream>

Config Config::getDefaultConfig()
{
    Config config(20, true); 
    return config;
}
Config::Config(int tics, bool vento)
{
    ticsTotais = tics;
    ventania = vento;
    contadorCasaZero = 0;

    ventoCima = true;
    ventoBaixo = true;
    ventoEsquerda = true;
    ventoDireita = true;
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

int Config::getContador() const
{
    return contadorCasaZero;
}

void Config::configurarVento(bool cima, bool baixo, bool esquerda, bool direita)
{
    ventoCima = cima;
    ventoBaixo = baixo;
    ventoEsquerda = esquerda;
    ventoDireita = direita;
}

bool Config::ventoSopraCima() const
{
    return ventoCima;
}
bool Config::ventoSopraBaixo() const
{
    return ventoBaixo;
}
bool Config::ventoSopraEsquerda() const
{
    return ventoEsquerda;
}
bool Config::ventoSopraDireita() const
{
    return ventoDireita;
}
