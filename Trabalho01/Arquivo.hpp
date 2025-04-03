#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Arquivo
{
private:
    string nomeArquivo;

public:
    Arquivo();
    void escreverArquivo();
    void lerMatriz(vector<vector<int>> &matriz, int linhas, int colunas, int fogoX, int fogoY);
};