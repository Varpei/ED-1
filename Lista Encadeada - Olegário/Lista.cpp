#include <iostream>
#include "No.cpp"

using namespace std;


class Lista{
private:

    No *primeiro;
public:

    Lista():primeiro(nullptr){}

    ~Lista(){
        while(!vazio()){
            delete primeiro;
        }
    }

    bool vazio(){
        return primeiro == nullptr;
    }

    void inserirFinal(int valor)
    {
        No *novo = new No(valor);//novo valor a ser inserido

        if(vazio())
        {
            primeiro = novo;//se a lista estiver vazia o primeiro elemento da lista vai receber o novo elemento a ser inserido nela
        }
        else
        {
            No *atual = primeiro; //O atual vai receber o valor que está no ponteiro primeiro que é o primeiro elemento da lista
            while(atual->getProx() != nullptr)
            {
                atual = atual->getProx();//enquanto o elemento atual não for nulo ele pode ser inserido na lista
            }
            atual->setProx(novo);//O elemento atual vai receber o valor da variável de novo elemento
        }
    }

    void inserirNoInicio(int valor){
        	No *novo = new No(valor);//novo valor a ser inserido
	        novo->setProx(primeiro);//o novo elemento vai passar o próximo elemento para a primeira casa da lista
	        primeiro = novo; // o primeiro vai receber o novo valor 
    }

    No *removerNoFinal()
    {
        if(vazio())
        {
            throw string("Lista vazia!");// se estiver vazio vai imprimir (lista vazia!)
        }
        if(primeiro->getProx() == nullptr){//se retorno do proximo elemento na lista for nulo  ele entra na condição
            No*anterior = primeiro;
            primeiro = nullptr;//o primeiro elemento vai receber a parte nula
            return anterior;
        }

        No *atual = primeiro;//O elemento atual vai receber o valor do primeiro elemento
        No *anterior = nullptr;//O elemento anterior vai receber nulo

        while(atual->getProx() != nullptr)//enquanto o elemento atual for diferente de nulo
        {
            anterior = atual;
            atual = atual->getProx();//O elemento atual vai ser apagado da lista
        }

        anterior->setProx(nullptr);//O proximo elemento do anterior vai ser definido como nulo, logo, o último elemento será removido
        delete atual;

        return atual;//retorna o elemento que foi removido da lista
    }


    No *removerNoInicio()
    {
        if(vazio())//se a lista estiver vazia
        {
            throw string("Lista vazia!");//avisa que (Lista Vazia!)
        }
        No *atual = primeiro; //O elemento atual recebe o primeiro elemento
        if(primeiro->getProx() == nullptr){
            primeiro = nullptr;//se o proximo elemento do primeiro elemento for nulo, O primeiro elemento da lista vai ser nulo indicando lista vazia
        }
        else
        {
            //No *atual = primeiro;
            primeiro = primeiro->getProx();//O proximo do primeiro elemento vai ser definido como primeiro da lista
            atual->setProx(nullptr);//O elemento na primeira posição na lista vai receber nulo, indicando a eliminação do elemento da lista
        }
        return atual;//retorna todos os valores que não forem nulos na lista
    }

    void imprimir()
    {
        No *atual = primeiro;
        while(atual != nullptr)
        {
            cout << atual->getValor() << " "; 
            atual = atual->getProx();
        }

        if(primeiro == nullptr){
            throw string("Lista Vazia!");
        }
        cout<<endl;
    }

};