#pragma once

class Config
{
private:
    bool ventoCima;
    bool ventoBaixo;
    bool ventoEsquerda;
    bool ventoDireita;

public:
    int contadorCasaZero;
    int ticsTotais;
    bool ventania;
    Config(int tics, bool vento);

    int getTicsTotais();
    bool temVentania();
    int getContador() const;

    void resetarContador();
    void incrementarContador();
    bool precisaMoverDaCasaZero();
    
    static Config getDefaultConfig(); 

    void configurarVento(bool cima, bool baixo, bool esquerda, bool direita);
    bool ventoSopraCima() const;
    bool ventoSopraBaixo() const;
    bool ventoSopraEsquerda() const;
    bool ventoSopraDireita() const;
};
