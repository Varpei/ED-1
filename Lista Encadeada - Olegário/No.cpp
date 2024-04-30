#include <iostream>

using namespace std;

class No{
public:

    int dado;
    No *proximo;
    No():dado(0),proximo(nullptr)
    {}
    No(int valor):dado(valor),proximo(nullptr)
    {}
    ~No()
    {
        if(proximo==nullptr){
            delete proximo;
        }
    }

    void setProx(No *proximo){
        this -> proximo = proximo;
    }

    No *getProx() const{
        return proximo;
    }

    void setValor(int n){
        dado = n;
    }

    int getValor(){
        return dado;
    }
};