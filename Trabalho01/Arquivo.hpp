#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Animal.hpp"

using namespace std;

class Arquivo
{
private:
    string nomeArquivo;
    fstream arquivo;

public:
    void escreverArquivo(const vector<vector<int>> &matrizInicial, const vector<vector<int>> &matrizFinal, const vector<vector<vector<int>>> &iteracoes, const Animal &animal, bool sobreviveu);
    static void lerMatriz(vector<vector<int>> &matriz, int &linhas, int &colunas, int &fogoX, int &fogoY);
};