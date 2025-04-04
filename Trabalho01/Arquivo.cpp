#include "Arquivo.hpp"

void Arquivo::escreverArquivo(vector<vector<int>> &matriz, int linhas, int colunas, int fogoX, int fogoY)
{
    arquivo >> linhas >> colunas >> fogoX >> fogoY;
    matriz.resize(linhas, vector<int>(colunas));

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            arquivo << matriz[i][j];
        }
    }

    arquivo.close();
}
void lerMatriz(vector<vector<int>> &matriz, int linhas, int colunas, int fogoX, int fogoY)
{
    ifstream arquivo("input.dat");

    if (!arquivo)
    {
        cerr << "Erro ao abrir o arquivo!\n";
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

void Arquivo::exibirMatriz(const std::vector<std::vector<int>> &matriz)
{
    for (const auto &linha : matriz)
    {
        for (int valor : linha)
        {
            std::cout << valor << " ";
        }
        std::cout << "\n";
    }
}