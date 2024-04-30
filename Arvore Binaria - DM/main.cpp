#include <iostream>

using namespace std;

struct No{
    int dado;
    No* filhoEsquerda;
    No* filhoDireita;

    No(int valor)
    {
        dado = valor;
    }


    int obterDado()
    {
        return dado;
    }
};

class Arvore{
    private:
        No* raiz;
    public:
        Arvore(){}
        Arvore()
        {
            raiz = nullptr;
        }

        bool obterVazio()
        {
            return raiz == nullptr;
        }
        
        bool obterCheio()
        {
            try{
                No* temp = new No;
                delete temp;
                return false;
            }
            catch(bad_alloc)
            {
                return true;
            }
        }

        void inserir(No dado)
        {
            if(estaCheio())
            {
                cout << "A arvore esta cheia!\n";
                cout << "Nao foi possivel inserir este elemento!\n";
            }
            else
            {
                No* novoNo = new No(dado);

            }
        }
};



int main(){

}