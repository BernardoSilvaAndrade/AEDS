#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Animal
{
private:
    int x, y;
    std::vector<std::pair<int, int>> caminho;
    int ultimaPosX = -1, ultimaPosY = -1;
    int vidas = 2;
    
    public:
    std::vector<std::pair<int, int>> caminhoAbsoluto;
    Animal();

    pair<int, int> getPosicao() const;
    const vector<pair<int, int>> &getCaminho() const;
    vector<pair<int, int>> getCaminhoAbsoluto() const;

    void setPosicao(int linha, int coluna);
    int getX() const;
    int getY() const;

    pair<int, int> encontrarZero(const vector<vector<int>> &matriz);
    bool mover(vector<vector<int>> &matriz);
    bool perdeuTodasAsVidas(const vector<vector<int>> &matriz);
    bool deveMorrer(const std::vector<std::vector<int>> &matriz, int contadorCasaZero) const;

    void registrarPasso();
    int contarPassos() const;
};