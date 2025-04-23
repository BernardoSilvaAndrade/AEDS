#include "Simulacao.hpp"
#include "Arquivo.hpp"

void Simulacao::executar(std::vector<std::vector<int>> &matriz, Animal &animal, Config &config)
{

    vector<vector<int>> matrizInicial = matriz;
    Floresta floresta(matriz, config);
    vector<vector<vector<int>>> iteracoes;

    bool sobreviveu = !animal.perdeuTodasAsVidas(matriz);

    for (int t = 0; t < config.getTicsTotais() && sobreviveu; t++)
    {
        cout << "\n=== Iteração " << t + 1 << " ===\n";

        floresta.propagarIncendio();
        matriz = floresta.getMatriz();

        int posX = animal.getX();
        int posY = animal.getY();

        if (animal.deveMorrer(matriz, config.getContador()))
        {
            cout << "O animal morreu por estar cercado ou por ficar tempo demais na casa 0.\n";
            sobreviveu = false;
            break;
        }

        if (matriz[posX][posY] == 0)
        {
            config.incrementarContador();

            if (config.precisaMoverDaCasaZero())
            {
                bool seMoveu = animal.mover(matriz);
                if (seMoveu)
                {
                    animal.registrarPasso();
                    config.resetarContador();
                }
                else if (animal.deveMorrer(matriz, config.getContador()))
                {
                    cout << "O animal morreu por estar cercado ou por ficar tempo demais na casa 0.\n";
                    sobreviveu = false;
                    break;
                }
            }
        }
        else
        {
            bool seMoveu = animal.mover(matriz);
            if (seMoveu)
            {
                animal.registrarPasso();
            }
            else if (animal.deveMorrer(matriz, config.getContador()))
            {
                cout << "O animal morreu por estar cercado ou por ficar tempo demais na casa 0.\n";
                sobreviveu = false;
                break;
            }
            config.resetarContador();
        }

        posX = animal.getX();
        posY = animal.getY();
        if (matriz[posX][posY] == 2)
        {
            sobreviveu = false;
            cout << "Animal foi atingido pelo fogo e morreu!\n";
            break;
        }

        if (animal.perdeuTodasAsVidas(matriz))
        {
            cout << "Animal perdeu todas as vidas e morreu no fogo!\n";
            sobreviveu = false;
            break;
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
    arquivo.escreverArquivo(matrizInicial, matriz, iteracoes, animal, sobreviveu);
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

    vector<vector<int>> matrizInicial = matriz;

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

    if (animal.deveMorrer(matriz, config.getContador()))
    {
        std::cout << "O animal morreu por estar cercado ou por ficar tempo demais na casa 0.\n";
    }

    animal.mostrarCaminho();
    cout << "Total de passos: " << animal.contarPassos() << endl;
}