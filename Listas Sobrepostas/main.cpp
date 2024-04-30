#include <iostream>

using namespace std;

struct No{
    int dado;
    No *prox = nullptr;
    No(int valor):dado(valor), prox(nullptr){}

};
int tamanhoLista(No *inicio){//função para determinar o tamanho da lista de ponteiros independente do tamanho
    int tamanho = 0;
    while(inicio != nullptr){
        tamanho++;
        inicio = inicio->prox;
    }
    return tamanho;
}

void avancarPonteiro(No *inicio, int passos){
    while(passos>0){
        inicio = inicio->prox;
        passos--;
    }
}

bool comum(No *inicioA, No *inicioB){
    int tamanhoA = tamanhoLista(inicioA);
    int tamanhoB = tamanhoLista(inicioB);

    if(tamanhoA > tamanhoB){
        avancarPonteiro(inicioA, tamanhoA - tamanhoB);
    }
    else
    {
        avancarPonteiro(inicioB, tamanhoB - tamanhoA);
    }

    while(inicioA && inicioB){
        if(inicioA == inicioB){
            return true;
        }
        inicioA = inicioA->prox;
        inicioB = inicioB->prox;
    }
    return false;
}

int main(){

        No *lista1 = new No(1);
        lista1->prox->prox = new No(2);
        lista1->prox->prox->prox = new No(3);
        lista1->prox->prox->prox->prox = new No(4);

        No *lista2 = new No(5);
        lista2->prox = lista1->prox->prox;
    
        if(comum(lista1,lista2)){
            cout<<"As listas tem um no comum.\n";
        }
        else
        {
            cout<<"As iistas nao tem um no comum.\n";
        }


}