#include "Animal.hpp"

Animal::Animal() : x(-1), y(-1) {}

int Animal::getX() const
{
    return x;
}

int Animal::getY() const
{
    return y;
}

const vector<pair<int, int>> &Animal::getCaminho() const
{
    return caminho;
}

void Animal::setPosicao(int linha, int coluna)
{
    x = linha;
    y = coluna;
}

pair<int, int> Animal::getPosicao() const
{
    return {x, y};
}

pair<int, int> Animal::encontrarZero(const vector<vector<int>> &matriz)
{
    for (int i = 0; i < (int)(matriz.size()); i++)
    {
        for (int j = 0; j < (int)(matriz.size()); j++)
        {
            if (matriz[i][j] == 0)
            {
                x = i;
                y = j;
                caminho.clear();
                registrarPasso();
                return {x, y};
            }
        }
    }
    return {-1, -1};
}

bool Animal::mover(vector<vector<int>> &matriz)
{
    pair<int, int> movimentos[] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int prioridades[] = {4, 0, 1, 3};

    for (int i = 0; i < 4; i++)
    {
        int prioridade = prioridades[i];

        for (int j = 0; j < 4; j++)
        {
            int novoX = x + movimentos[j].first;
            int novoY = y + movimentos[j].second;

            if (novoX >= 0 && novoX < (int)(matriz.size()) &&
                novoY >= 0 && novoY < (int)(matriz.size()))
            {

                int valor = matriz[novoX][novoY];

                if (valor != 2 && valor == prioridade)
                {
                    if (matriz[x][y] != 0)
                    {
                        matriz[x][y] = 1;
                    }
                    x = novoX;
                    y = novoY;

                    if (prioridade == 4)
                    {
                        matriz[x][y] = 0;

                        for (int k = 0; k < 4; k++)
                        {
                            int adjX = x + movimentos[k].first;
                            int adjY = y + movimentos[k].second;

                            if (adjX >= 0 && adjX < (int)(matriz.size()) &&
                                adjY >= 0 && adjY < (int)(matriz.size()) &&
                                matriz[adjX][adjY] != 2)
                            {
                                matriz[adjX][adjY] = 1;
                            }
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

void Animal::registrarPasso()
{
    caminho.push_back({x, y});
    std::cout << "Registrando passo em: (" << x << ", " << y << ")\n";
}

void Animal::mostrarCaminho() const
{
    cout << "Caminho percorrido pelo animal:\n";
    for (const auto &passo : caminho)
    {
        cout << "(" << passo.first << ", " << passo.second << ")\n";
    }
}

int Animal::contarPassos() const
{
    return caminho.size();
}

bool Animal::perdeuTodasAsVidas(const std::vector<std::vector<int>> &matriz)
{
    if (matriz[x][y] == 2)
    {
        vidas--;
        return vidas <= 0;
    }
    return false;
}

bool Animal::deveMorrer(const std::vector<std::vector<int>> &matriz, int contadorCasaZero) const
{

    if (matriz[x][y] == 0 && contadorCasaZero >= 3)
    {
        return true;
    }

    std::pair<int, int> direcoes[] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool cercado = true;

    for (auto dir : direcoes)
    {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx >= 0 && nx < (int)(matriz.size()) &&
            ny >= 0 && ny < (int)(matriz.size()))
        {
            if (matriz[nx][ny] != 2)
            {
                cercado = false;
                break;
            }
        }
    }

    return cercado;
}