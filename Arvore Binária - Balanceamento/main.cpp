#include <iostream>

using namespace std;

struct No{

    int dado;
    No* filhoEsquerda;
    No* filhoDireita;
};

class Arvore{

    private:
        No* raiz;
    public:

        Arvore()
        {
            raiz = nullptr;
        }

        No* inserir(int dado)
        {
            No* novoNo = new No();
            if(!novoNo)
            {
                cout << "Erro ao alocar memória!\n";
                return nullptr;
            }
            novoNo->dado = dado;
            novoNo->filhoEsquerda = nullptr;
            novoNo->filhoDireita = nullptr;

            return novoNo;
        }

        int altura(No* raiz)
        {
            if(raiz == nullptr)
            {
                return 0;
            }
            int filhoEsquerdaAltura = altura(raiz->filhoEsquerda);
            int filhoDireitaAltura = altura(raiz->filhoDireita);
            return 1 + max(filhoEsquerdaAltura, filhoDireitaAltura);
        }


        bool balanceado(No* raiz)
        {
            if(raiz == nullptr)
            {
                return true;
            }
            int filhoEsquerdaAltura = altura(raiz->filhoEsquerda);
            int filhoDireitaAltura = altura(raiz->filhoDireita);
            int diferenca = abs(filhoEsquerdaAltura - filhoDireitaAltura);
            if(diferenca <= 1 and balanceado(raiz->filhoEsquerda) and balanceado(raiz->filhoDireita))
            {
                return true;
            }
            return false;
        }        
};

int main() {
    // Criação da árvore de exemplo

    Arvore 
    raiz = inserir(1);
    raiz->filhoEsquerda = inserir(2);
    raiz->filhoDireita = inserir(3);
    raiz->filhoEsquerda->filhoEsquerda = inserir(4);
    raiz->filhoEsquerda->filhoDireita = inserir(5);

    

    return 0;
}