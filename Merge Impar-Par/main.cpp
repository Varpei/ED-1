#include <iostream>

using namespace std;


struct No {
    int data;
    No* prox;

    No(int val) : data(val), prox(nullptr) {}
};

void adicionar(No*& Primeiro, int val) {
    No* novo = new No(val);
    if (!Primeiro) {
        Primeiro = novo;
        return;
    }
    No* atual = Primeiro;
    while (atual->prox) {
        atual = atual->prox;
    }
    atual->prox = novo;
}


void imprimirLista(No* Primeiro) {
    No* atual = Primeiro;
    while (atual) {
        cout << atual->data << " ";
        atual = atual->prox;
    }
    cout << endl;
}


No* mergeParImpar(No* Primeiro) {
    if (!Primeiro || !Primeiro->prox) {
        return Primeiro; 
    }

    No* atePrimeiro = nullptr; 
    No* chancePrimeiro = nullptr;  
    No* atual = Primeiro;

    while (atual) {
        
        if (atual->data % 2 == 0) {
            adicionar(atePrimeiro, atual->data); 
        } else {
            adicionar(chancePrimeiro, atual->data);  
        }
        atual = atual->prox;
    }

    
    No* listaMesclada = atePrimeiro;
    if (atePrimeiro) {
        atual = atePrimeiro;
        while (atual->prox) {
            atual = atual->prox;
        }
        atual->prox = chancePrimeiro;
    } else {
        listaMesclada = chancePrimeiro;
    }

    return listaMesclada;
}

int main() {
    No* Primeiro = nullptr;

    
    adicionar(Primeiro, 1);
    adicionar(Primeiro, 2);
    adicionar(Primeiro, 3);
    adicionar(Primeiro, 4);
    adicionar(Primeiro, 5);

    cout << "Lista original: ";
    imprimirLista(Primeiro);

    
    No* listaMesclada = mergeParImpar(Primeiro);

    cout << "Fusao par-impar: ";
    imprimirLista(listaMesclada);

    
    while (listaMesclada) {
        No* temp = listaMesclada;
        listaMesclada = listaMesclada->prox;
        delete temp;
    }

    return 0;
}
