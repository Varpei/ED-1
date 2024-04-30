#include <iostream>
#include "dado.h"

struct No{
    Dado dado;
    No* filhoEsquerda;
    No* filhoDireita;

    int fatorB; 
};

class ArvoreAVL{ 
    private:
    No* raiz;

    public:
    ArvoreAVL(); 
    ~ArvoreAVL(); 
    void deletarArvore(No* noAtual);
    No* obterRaiz();
    bool estaVazio();
    bool estaCheio();
    void inserir(Dado dado); 
    void remover(Dado dado); 
    void removerBusca(Dado dado, No*& ponteiroNoAtual, bool& diminuiu); 
    void deletarNo(No*& ponteiroNoAtual, bool& diminuiu); 
    void obterSucessor(Dado& dadoSucessor, No* temp);
    void buscar(Dado& dado, bool& busca);
    void imprimirPreOrdem(No* ponteiroNoAtual);
    void imprimirEmOrdem(No* ponteiroNoAtual);
    void imprimirPosOrdem(No* ponteiroNoAtual);


    void rotacaoDireita(No*& arvore);
    void rotacaoEsquerda(No*& arvore);  
    void rotacaoEsquerdaDireita(No*& arvore);
    void rotacaoDireitaEsquerda(No*& arvore);
    void realizaRotacao(No*& arvore);
    void insereRecursivo(No*& ponteiroNoAtual, Dado dado, bool& cresceu);

};
