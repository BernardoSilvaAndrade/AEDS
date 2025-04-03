#include "Arquivo.hpp"

Arquivo::Arquivo()
{
    nomeArquivo = "input.dat";
}

void Arquivo::escreverArquivo()
{
}

void Arquivo::lerMatriz(vector<vector<int>> &matriz, int linhas, int colunas, int fogoX, int fogoY)
{
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    arquivo >> linhas >> colunas >> fogoX >> fogoY;
    matriz.resize(linhas, vector<int>(colunas));

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            arquivo >> matriz[i][j];
        }
    }

    arquivo.close();
}