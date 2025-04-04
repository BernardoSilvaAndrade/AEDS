#include "Animal.hpp"

Animal::Animal() : x(-1), y(-1) {}

pair<int, int> Animal::encontrarZero(const vector<vector<int>> &matriz)
{
    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz[i].size(); j++)
        {
            if (matriz[i][j] == 0)
            {
                x = i;
                y = j;
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

void Animal::mover(vector<vector<int>> &matriz)
{
    vector<pair<int, int>> direcoes = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int melhorX = x, melhorY = y;

    for (int i = 0; i < 4; i++)
    {
        int novoX = x + direcoes[i].first;
        int novoY = y + direcoes[i].second;

        if (novoX >= 0 && novoX < matriz.size() && novoY >= 0 && novoY < matriz[0].size())
        {
            if (matriz[novoX][novoY] == 4)
            {
                melhorX = novoX;
                melhorY = novoY;
                break;
            }
        }
    }

    matriz[x][y] = 1;
    matriz[melhorX][melhorY] = 2;
    x = melhorX;
    y = melhorY;
}
