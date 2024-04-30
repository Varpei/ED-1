#include <iostream>
#include "dado.h"
using namespace std;


    Dado::Dado()
    {

    }
    Dado::Dado(int valor)
    {
        dado = valor;
    }
    
    int Dado::obterDado()
    {
        return dado;
    }
