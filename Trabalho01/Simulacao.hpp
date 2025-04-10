#pragma once

#include <vector>
#include "Animal.hpp"
#include "Config.hpp"

class Simulacao
{
public:
    static void executar(std::vector<std::vector<int>> &matriz, Animal &animal, Config &config);
};
