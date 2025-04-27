#include "Simulacao.hpp"

void Simulacao::executar(std::vector<std::vector<int>> &matriz, Animal &animal, Config &config)
{

    vector<vector<int>> matrizInicial = matriz;
    Floresta floresta(matriz, config);
    vector<vector<vector<int>>> iteracoes;

    bool sobreviveu = !animal.perdeuTodasAsVidas(matriz);
    int iteracaoMorte = -1; 
    int ticsNaCasa0 = 0;

    for (int t = 0; t < config.getTicsTotais(); t++)
    {
        animal.caminhoAbsoluto.push_back(animal.getPosicao());

        floresta.propagarIncendio();
        matriz = floresta.getMatriz();

        if (!floresta.temArvoreFogosa()) {
            break;  
        }

        int posX = animal.getX();
        int posY = animal.getY();

        if (animal.deveMorrer(matriz, config.getContador()))
        {
            sobreviveu = false;
            iteracaoMorte = t+1;
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
                else 
                {
                    if (matriz[posX][posY] == 0) {
                        ticsNaCasa0++;
                
                        
                        if (ticsNaCasa0 >= 3) {
                            bool seMoveu = false;
                            while (!seMoveu) {
                                
                                seMoveu = animal.mover(matriz);
                
                                
                                if (matriz[animal.getX()][animal.getY()] == 2) {
                                    seMoveu = false;  
                                }
                            }
                
                            ticsNaCasa0 = 0; 
                        }
                    }
                }
            }
        }
        else
        {
            config.resetarContador();
            bool seMoveu = animal.mover(matriz);
            if (seMoveu)
            {
                animal.registrarPasso();
            }
            else if (animal.deveMorrer(matriz, config.getContador()))
            {
                
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
            
            break;
        }

        if (animal.perdeuTodasAsVidas(matriz))
        {
            sobreviveu = false;
            break;
        }

        iteracoes.push_back(matriz);
    }

    Arquivo arquivo;
    arquivo.escreverArquivo(matrizInicial, matriz, iteracoes, animal, sobreviveu, iteracaoMorte);
}

void Simulacao::simulacao()
{
    vector<vector<int>> matriz;
    int linhas, colunas, fogoX, fogoY;
    Arquivo arquivo;

    arquivo.lerMatriz(matriz, linhas, colunas, fogoX, fogoY);


    if (fogoX >= 0 && fogoX < linhas && fogoY >= 0 && fogoY < colunas)
    {
        matriz[fogoX][fogoY] = 2;
    }

    Config config = Config::getDefaultConfig();
    Floresta floresta(matriz, config);

    Animal animal;
    animal.encontrarZero(matriz);

    Simulacao::executar(matriz, animal, config);
}