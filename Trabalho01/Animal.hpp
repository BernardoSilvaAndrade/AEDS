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

public:
    Animal();

    pair<int, int> getPosicao() const;

    void setDirecao(int novoX, int novoY);
    int getX() const;
    int getY() const;

    pair<int, int> encontrarZero(const vector<vector<int>> &matriz);
    void mover(vector<vector<int>> &matriz);

    void registrarPasso();
    void mostrarCaminho() const;
    int contarPassos() const;
};