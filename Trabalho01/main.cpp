#include "Animal.hpp"
#include "Arquivo.hpp"
#include "Simulacao.hpp"
#include "Config.hpp"
#include <iostream>
#include <vector>

using namespace std;

void lerMatriz(vector<vector<int>> &matriz, int linhas, int colunas, int fogoX, int fogoY);

int main()
{
    int linhas, colunas, fogoX, fogoY;
    vector<vector<int>> matriz;

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
    animal.encontrarZero(matriz);

    auto pos = animal.getPosicao();
    cout << "Posição inicial correta: (" << pos.first << ", " << pos.second << ")\n";

    animal.mover(matriz);

    Config config(10, true);
    Simulacao::executar(matriz, animal, config);

    animal.mostrarCaminho();
    cout << "Total de passos: " << animal.contarPassos() << "\n";

    return 0;
}
