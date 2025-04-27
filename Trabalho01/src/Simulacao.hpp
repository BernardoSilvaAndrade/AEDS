#pragma once
#include <iostream>
#include <vector>
#include "Animal.hpp"
#include "Config.hpp"
#include "Simulacao.hpp"
#include "Floresta.hpp"
#include "Arquivo.hpp"

class Simulacao
{
public:
    static void executar(std::vector<std::vector<int>> &matriz, Animal &animal, Config &config);
    static void simulacao();
};
 