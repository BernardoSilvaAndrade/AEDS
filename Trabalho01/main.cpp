#include "Animal.hpp"
#include "Arquivo.hpp"
#include <iostream>
#include <vector>

using namespace std;

void lerMatriz(vector<vector<int>> &matriz, int linhas, int colunas, int fogoX, int fogoY);

int main()
{
    int linhas, colunas, fogoX, fogoY;
    vector<vector<int>> matriz;

    // Ler a matriz do arquivo
    lerMatriz(matriz, linhas, colunas, fogoX, fogoY);

    cout << "Matriz Inicial:\n";
    for (const auto &linha : matriz)
    {
        for (int valor : linha)
        {
            cout << valor << " ";
        }
        cout << "\n";
    }

    Animal animal;
    pair<int, int> direcao = animal.encontrarZero(matriz);
    cout << "Animal encontrou o primeiro 0 em: (" << direcao.first << ", " << direcao.second << ")\n";

    animal.mover(matriz);

    cout << "\nMatriz Após Movimento:\n";
    for (const auto &linha : matriz)
    {
        for (int valor : linha)
        {
            cout << valor << " ";
        }
        cout << "\n";
    }

    return 0;
}
