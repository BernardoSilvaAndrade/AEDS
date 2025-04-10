#pragma once

class Config
{
private:
    int ticsTotais;
    bool ventania;
    int contadorCasaZero;

public:
    Config(int tics, bool vento);

    int getTicsTotais();
    bool temVentania();

    void resetarContador();
    void incrementarContador();
    bool precisaMoverDaCasaZero();
};
