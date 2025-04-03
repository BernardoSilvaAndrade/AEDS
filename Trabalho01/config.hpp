#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Config
{
private:
    static int tics;
    static int ventania;

public:
    static int getTics();
    static int getVentania();
    static void setTics(int tics);
    static void setVentania(int ventania);
    static void carregarPadrao();
};