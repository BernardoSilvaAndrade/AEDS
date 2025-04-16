#include "Simulacao.hpp"
#include "Arquivo.hpp"

void Simulacao::executar(std::vector<std::vector<int>> &matriz, Animal &animal, Config &config)
{
    Floresta floresta(matriz, config);
    vector<vector<vector<int>>> iteracoes;

    bool sobreviveu = true;

    for (int t = 0; t < config.getTicsTotais(); t++)
    {
        cout << "\n=== Iteração " << t + 1 << " ===\n";

        floresta.propagarIncendio();
        matriz = floresta.getMatriz();

        int posX = animal.getX();
        int posY = animal.getY();

        if (matriz[posX][posY] == 0)
        {
            config.incrementarContador();

            if (config.precisaMoverDaCasaZero())
            {
                animal.mover(matriz);
                animal.registrarPasso();
                config.resetarContador();
            }
        }
        else
        {
            animal.mover(matriz);
            animal.registrarPasso();
            config.resetarContador();
        }

        posX = animal.getX();
        posY = animal.getY();
        if (matriz[posX][posY] == 2)
        {
            sobreviveu = false;
        }

        cout << "\nMatriz Após Iteração " << t + 1 << ":\n";
        for (const auto &linha : matriz)
        {
            for (int valor : linha)
            {
                cout << valor << " ";
            }
            cout << "\n";
        }

        iteracoes.push_back(matriz);
        cout << "Posição do animal: (" << animal.getX() << ", " << animal.getY() << ")\n";
    }

    Arquivo arquivo;
    arquivo.escreverArquivo(matriz, iteracoes, animal, sobreviveu);
}

void Simulacao::simulacao()
{
    vector<vector<int>> matriz;
    int linhas, colunas, fogoX, fogoY;
    Arquivo arquivo;

    arquivo.lerMatriz(matriz, linhas, colunas, fogoX, fogoY);

    cout << "linhas = " << linhas << ", colunas = " << colunas << endl;
    cout << "fogoX = " << fogoX << ", fogoY = " << fogoY << endl;

    if (fogoX >= 0 && fogoX < linhas && fogoY >= 0 && fogoY < colunas)
    {
        matriz[fogoX][fogoY] = 2;
    }

    Config config(10, true);

    config.configurarVento(true, true, true, true);

    Floresta floresta(matriz, config);

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

    Simulacao::executar(matriz, animal, config);

    animal.mostrarCaminho();
    cout << "Total de passos: " << animal.contarPassos() << endl;
}