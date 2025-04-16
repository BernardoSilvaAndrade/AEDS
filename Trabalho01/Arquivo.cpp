#include "Arquivo.hpp"

void Arquivo::escreverArquivo(const vector<vector<int>> &matriz, const vector<vector<vector<int>>> &iteracoes, const Animal &animal, bool sobreviveu)
{
    std::ofstream arquivo("output.dat");

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de saída.\n";
        return;
    }

    arquivo << "Matriz Inicial:\n";
    for (const auto &linha : matriz)
    {
        for (int valor : linha)
        {
            arquivo << valor << " ";
        }
        arquivo << "\n";
    }
    arquivo << "\n";

       for (size_t i = 0; i < iteracoes.size(); i++)
    {
        arquivo << "Iteracao " << i + 1 << ":\n";
        for (const auto &linha : iteracoes[i])
        {
            for (int valor : linha)
            {
                arquivo << valor << " ";
            }
            arquivo << "\n";
        }
        arquivo << "\n";
    }

    arquivo << "Estado final da matriz:\n";
    for (const auto &linha : matriz)
    {
        for (int valor : linha)
        {
            arquivo << valor << " ";
        }
        arquivo << "\n";
    }

    arquivo << "\nCaminho percorrido pelo animal:\n";
    const auto &caminho = animal.getCaminho();
    for (const auto &passo : caminho)
    {
        arquivo << "(" << passo.first << ", " << passo.second << ")\n";
    }

    arquivo << "\nTotal de passos: " << caminho.size() << "\n";

    if (sobreviveu)
    {
        arquivo << "Condição final: Animal sobreviveu até o fim da simulação.\n";
    }
    else
    {
        arquivo << "Condição final: Animal foi atingido pelo fogo.\n";
    }

    arquivo.close();
}
void Arquivo::lerMatriz(vector<vector<int>> &matriz, int &linhas, int &colunas, int &fogoX, int &fogoY)
{
    ifstream arquivo("input.dat");

    if (!arquivo)
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
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
