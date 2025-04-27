#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <iostream>

#include "Config.hpp"

using namespace std;

class Floresta
{
private:
    vector<vector<int>> matriz;
    vector<vector<int>> ticsEmChamas;
    Config &config;

public:
    Floresta(vector<vector<int>> &matriz, Config &config);

    void propagarIncendio();

    bool temArvoreFogosa() const;

    vector<vector<int>> &getMatriz();
};