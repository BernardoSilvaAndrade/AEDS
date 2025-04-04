#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Animal
{
private:
    int x, y;

public:
    Animal();
    pair<int, int> encontrarZero(const vector<vector<int>> &matriz);
    void mover(vector<vector<int>> &matriz);
};