#pragma once

class Config
{
private:
    int ticsTotais;
    bool ventania;
    int contadorCasaZero;

    bool ventoCima;
    bool ventoBaixo;
    bool ventoEsquerda;
    bool ventoDireita;

public:
    Config(int tics, bool vento);

    int getTicsTotais();
    bool temVentania();
    int getContador() const;

    void resetarContador();
    void incrementarContador();
    bool precisaMoverDaCasaZero();

    void configurarVento(bool cima, bool baixo, bool esquerda, bool direita);
    bool ventoSopraCima() const;
    bool ventoSopraBaixo() const;
    bool ventoSopraEsquerda() const;
    bool ventoSopraDireita() const;
};
