#include <iostream>
#include "aluno.h"

using namespace std;

struct No{
    
    Aluno aluno;
    No* filhoEsquerda;
    No* filhoDireita;

};

class BST
{//BST = Binary Search Tree(Arvore Binaria de Busca)
    private:
        No* raiz;
    public:
        BST();
        ~BST();
        void deletarArvore(No* noAtual);
        No* obterRaiz();
        bool estaVazio();
        bool estaCheio();
        void inserir(Aluno aluno);
        void remover(Aluno aluno);
        void removerBusca(Aluno& aluno, No*& ponteiroNoAtual);    
        void deletarNo(No*& ponteiroNoAtual);   
        void obterSucessor(Aluno& alunoSucessor, No* temp);
        void buscar(Aluno& aluno, bool& busca);//Pega bool& busca por referencia(&) pois se encontrar o busca vai modificar para true e se não encontrar vai modificar para false
        void imprimirPreOrdem(No* noAtual);
        void imprimirEmOrdem(No* noAtual);
        void imprimirPosOrdem(No* noAtual);
};
