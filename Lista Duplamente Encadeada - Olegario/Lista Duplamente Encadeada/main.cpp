#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

class No{
    private:
    int dado;
    No *proximo;
    No *anterior;

    public:
    No(int valor):dado(valor),proximo(nullptr), anterior(nullptr){}
    No(){
        dado=0;
        anterior = proximo = nullptr;
    }
    ~No(){
        if(proximo==nullptr){
            delete proximo;
        }
    }

    int getValor(){
        return dado;
    }

    void setProx(No *proximo){
        this->proximo = proximo;
    }

    No *getProx(){
        return proximo;
    }

    void setAnt(No *anterior){
        this->anterior = anterior;
    }

    No *getAnt(){
        return anterior;
    }
};


class Lista{
    private:
        No *primeiro;
        No *ultimo;
    public:
        Lista():primeiro(nullptr), ultimo(nullptr){}

        ~Lista(){
            if(vazio()){
                delete primeiro;
            }
        }

        bool vazio(){
            return primeiro == nullptr;
        }
        bool vazio_ultimo(){
            return ultimo == nullptr;
        }
    void inserirInicio(int valor){
        No *novo = new No(valor);

        if(vazio()){
            primeiro = ultimo = novo;    
        }
        else
        {
            primeiro->setAnt(novo);
            novo->setProx(primeiro);
            primeiro = novo;
        }
    }

    No *removerInicio(){
        if (vazio()){//Lista vazia
            throw string("Lista Vazia!");
        }
        else
        {//lista não vazia
            No* atual = primeiro;
            if(primeiro->getProx() == nullptr){//Lista apenas com único elemento
                
                primeiro = ultimo = nullptr;
            }
            else
            {//Lista com mais de um elemento
                
                primeiro = primeiro->getProx();
                primeiro->setAnt(nullptr);
                atual->setProx(nullptr);
                delete primeiro;
            }
        }
        return primeiro; 
    }

    void inserirFinal(int valor){
        No *novo = new No(valor);
        if(vazio()){
            throw string("Lista Vazia!");
        }
        else
        {
            if(vazio_ultimo()){
                primeiro = ultimo = novo;
            }
        }
        if(!vazio()){
            ultimo -> setProx(novo);
            novo -> setAnt(ultimo);
            ultimo=novo;
            //Atualiza o último elemento apontado para o novo no
        }
    }

    void imprimirLista(){
        No *atual = primeiro;
        cout << "Lista: ";
        while(atual != NULL){
            cout << atual->getValor() << " ";
            atual = atual->getAnt();
            cout << endl;
        }
    }
};

int menu(){
    cout << "1. Inserir no Inicio\n";
    cout << "2. Remover no Inicio\n";
    cout << "3. Imprimir\n";
    cout << "0. Sair\n";

    int op;
    cin>>op;
    
    return op;
}

int main(){
    Lista lista;

    int op = menu();
    while(op != 0){
        
        switch(op){
            case 1:
                cout << "Insira um número: \n";
                int valor;
                cin >> valor;
                lista.inserirInicio(valor);
            break;
            case 2:
                lista.removerInicio();
            break;
            case 3:
                lista.imprimirLista();
            break;
        }
        op = menu();
    }

    return 0;
}