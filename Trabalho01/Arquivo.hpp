#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Arquivo
{
private:
    string nomeArquivo;
    fstream arquivo;

public:
    void escreverArquivo(vector<vector<int>> &matriz, int linhas, int colunas, int fogoX, int fogoY);
    void lerMatriz(vector<vector<int>> &matriz, int linhas, int colunas, int fogoX, int fogoY);
    void exibirMatriz(const std::vector<std::vector<int>> &matriz);
};