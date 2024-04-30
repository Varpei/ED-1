#include <iostream>
#include "aluno.h"
using namespace std;


    Aluno::Aluno()
    {

    }
    Aluno::Aluno(int r, string n)
    {
        ra = r;
        nome = n;
    }

    string Aluno::obterNome()
    {
        return nome;
    }
    
    int Aluno::obterRa()
    {
        return ra;
    }
