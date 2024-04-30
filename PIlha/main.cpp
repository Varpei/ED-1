#include <iostream>

using namespace std;

class No{
    public:
        int dado;
        No*proximo;
        No():dado(0), proximo(nullptr){}

        No(int valor):dado(valor), proximo(nullptr){}

        ~No(){
            delete proximo;
        }

        void setProx(No *proximo){
            this->proximo = proximo;
        }

        No *getProx(){
            return proximo;
        }

        int getValor(){
            return dado;
        }
};

class Pilha{
    private:
        No *top = nullptr;
    public:

        Pilha():top(nullptr){}

        void push(int valor){
            No *novo = new No(valor);
            novo->dado = valor;
            novo->setProx(top);
            top = novo;
        }

        No *pop(){
            if(top==nullptr){
                cout<<"Pilha vazia"<<endl;
            }
            else
            {
                No *atual = top;
                top = top->getProx();
                atual->proximo = nullptr;
                delete atual;
                return atual;
            }
        }

        void imprimir()
        {
            No *atual = top;
            while (atual != nullptr){
                cout << atual->dado << " ";
                atual = atual->proximo;
            }
            cout << endl;
        }
};


int menu(){
    cout << "1. adicionar na pilha\n";
    cout << "2. remover na pilha\n";
    cout << "3. mostrar pilha\n";

    int op;
    cin >> op;

    return op;
}

int main(){

    Pilha p;

    int op = menu();

    while(op != 0){
        switch(op){
            case 1:
                cout << "Insira o elemento na pilha: ";
                int valor;
                cin >> valor;
                p.push(valor);
            break;

            case 2:
                p.pop();
            break;

            case 3:
                p.imprimir();
            break;
        }
        op = menu();
    }


    return 0;
}