#include "Arquivo.hpp"

void Arquivo::escreverArquivo(const vector<vector<int>> &matrizInicial, const vector<vector<int>> &matrizFinal, const vector<vector<vector<int>>> &iteracoes, const Animal &animal, bool sobreviveu,int iteracaoMorte)
{
    std::ofstream arquivo("output.dat");

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de saída.\n";
        return;
    }

    arquivo << "Matriz Inicial:\n";
    for (const auto &linha : matrizInicial)
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

        int linha = -1, coluna = -1;
        const auto &caminho = animal.getCaminhoAbsoluto();


    
        if (i < caminho.size())
        {
            linha = caminho[i].first;
            coluna = caminho[i].second;
            
        }
        else if (!caminho.empty())
        {
            linha = caminho.back().first;
            coluna = caminho.back().second;
          
          
        }
    
        if (linha != -1 && coluna != -1)
        {
            arquivo << "Posição do animal: (" << linha << ", " << coluna << ")\n";
        }
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
    for (const auto &linha : matrizFinal)
    {
        for (int valor : linha)
        {
            arquivo << valor << " ";
        }
        arquivo << "\n";
    }

    int casasDeAgua = 0;
    const auto &caminho = animal.getCaminho();
    for (size_t i = 0; i < caminho.size(); i++)
    {
        int x = caminho[i].first;
        int y = caminho[i].second;

        if (i < iteracoes.size() && iteracoes[i][x][y] == 4)
        {
            casasDeAgua++;
        }
    }
    arquivo << "\nDados da simulacao:" << endl;

    arquivo << "Casas de água visitadas: " << casasDeAgua;

   arquivo << "\nCaminho percorrido pelo animal:\n";
    for (size_t i = 0; i < caminho.size(); i++)
    {
        arquivo << "(" << caminho[i].first << ", " << caminho[i].second << ")";
        if (i != caminho.size() - 1)
        {
            arquivo << " --> ";
        }
    }

    arquivo << "\nTotal de passos: " << caminho.size() << "\n";

    if (sobreviveu)
    {
        arquivo << "Condição final: Animal sobreviveu até o fim da simulação.\n";
    }
    else
    {
        arquivo << "Condição final: Animal foi atingido pelo fogo.\n";
        if (!caminho.empty() && iteracaoMorte > 0)
        {
            auto ultimaPosicao = caminho.back();
            arquivo << "Iteração em que o animal morreu: " << iteracaoMorte << "\n";
            arquivo << "Última posição do animal: (" << ultimaPosicao.first << ", " << ultimaPosicao.second << ")\n";
        }
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
