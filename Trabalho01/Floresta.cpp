#include "Floresta.hpp"

const int TICS_PARA_QUEIMAR = 2;

Floresta::Floresta(vector<vector<int>> &matrizInicial, Config &config) : matriz(matrizInicial), config(config)
{
    int linhas = matriz.size();
    int colunas = linhas > 0 ? matriz[0].size() : 0;

    ticsEmChamas.resize(linhas, vector<int>(colunas, 0));

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            ticsEmChamas[i][j] = 0;
        }
    }
}

void Floresta::propagarIncendio()
{
    vector<vector<int>> novaMatriz = matriz;
    vector<vector<int>> novaTicsEmChamas = ticsEmChamas;

    pair<int, int> movimentos[] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool direcoes[] = {
        config.ventoSopraBaixo(),
        config.ventoSopraCima(),
        config.ventoSopraDireita(),
        config.ventoSopraEsquerda()};

    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz[i].size(); j++)
        {
            if (matriz[i][j] == 2)
            {
                novaTicsEmChamas[i][j]++;
                if (novaTicsEmChamas[i][j] >= TICS_PARA_QUEIMAR)
                {
                    novaMatriz[i][j] = 3;
                    novaTicsEmChamas[i][j] = 0;
                }
                else
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int novoI = i + movimentos[k].first;
                        int novoJ = j + movimentos[k].second;

                        if (novoI >= 0 && novoI < matriz.size() &&
                            novoJ >= 0 && novoJ < matriz[i].size())
                        {

                            if (matriz[novoI][novoJ] == 1)
                            {
                                bool propagar = true;

                                if (config.temVentania())
                                {
                                    propagar = direcoes[k];
                                }

                                if (propagar)
                                {
                                    novaMatriz[novoI][novoJ] = 2;
                                    novaTicsEmChamas[novoI][novoJ] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    matriz = novaMatriz;
    ticsEmChamas = novaTicsEmChamas;
}

bool Floresta::temArvoreFogosa() const
{
    for (const auto &linha : matriz)
    {
        for (int valor : linha)
        {
            if (valor == 2)
            {
                return true;
            }
        }
    }
    return false;
}

vector<vector<int>> &Floresta::getMatriz()
{
    return matriz;
}