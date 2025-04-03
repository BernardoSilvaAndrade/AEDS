#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Posicao
{
public:
    int x;
    int y;
    Posicao(int x, int y) : x(x), y(y) {}
};

class Simulacao
{
private:
    vector<vector<int>> matriz;
    int linhas;
    int colunas;
    Posicao animal;
    int turnosNoVazio;

public:
};