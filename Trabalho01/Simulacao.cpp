#include "Simulacao.hpp"
#include <iostream>

void Simulacao::executar(std::vector<std::vector<int>> &matriz, Animal &animal, Config &config)
{
    for (int t = 0; t < config.getTicsTotais(); t++)
    {
        int posX = animal.getX();
        int posY = animal.getY();

        if (matriz[posX][posY] == 0)
        {
            config.incrementarContador();

            if (config.precisaMoverDaCasaZero())
            {
                animal.mover(matriz);
                config.resetarContador();
            }
        }
        else
        {
            animal.mover(matriz);
            config.resetarContador();
        }

        cout << "\nMatriz Após Movimento:\n";
        for (const auto &linha : matriz)
        {
            for (int valor : linha)
            {
                cout << valor << " ";
            }
            cout << "\n";
        }
    }
}