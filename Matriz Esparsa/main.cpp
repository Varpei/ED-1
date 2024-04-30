#include <iostream>

using namespace std;

struct No 
{
    float dado;
    int coluna;
    No* prox;
    No() : dado(0.0), coluna(0), prox(nullptr) {}
    No(int valor) : dado(valor), coluna(0), prox(nullptr) {}
    ~No() {
        delete prox;
    }
};

class Matriz 
{
private:
    No** A;
    int linhas;
    int colunas;

public:
    Matriz() : A(nullptr), linhas(0), colunas(0) {}
    Matriz(int lin, int col) : A(nullptr), linhas(lin), colunas(col) {
        A = new No*[lin];
        for (int i = 0; i < lin; i++) {
            A[i] = nullptr;
        }
    }

    ~Matriz() {
        for (int i = 0; i < linhas; i++) {
            delete A[i];
        }
        delete[] A;
    }

    void atribuirMatriz(int lin, int col, float val)
    {
        if (lin < 0 || lin >= linhas || col < 0 || col >= colunas) {
            return;
        }

        No* ant = nullptr;
        No* atual = A[lin];

        while (atual != nullptr && atual->coluna < col) {
            ant = atual;
            atual = atual->prox;
        }

        if (atual != nullptr && atual->coluna == col) 
        {
            if (val == 0) {
                if (ant == nullptr) {
                    A[lin] = atual->prox;
                } else {
                    ant->prox = atual->prox;
                }
                delete atual;
            } else {
                atual->dado = val;
            }
        } else if (val != 0) {
            No* novo = new No;
            novo->coluna = col;
            novo->dado = val;
            novo->prox = atual;
            if (ant == nullptr) {
                A[lin] = novo;
            } else {
                ant->prox = novo;
            }
        }
    }

    float valorMatriz(int lin, int col) 
    {
        if (lin < 0 || lin >= linhas || col < 0 || col >= colunas) {
            return 0.0;
        }

        No* atual = A[lin];
        while (atual != nullptr && atual->coluna < col) {
            atual = atual->prox;
        }

        if (atual != nullptr && atual->coluna == col) {
            return atual->dado;
        }
        return 0.0;
    }
};

int main() 
{
    int linhas = 3;
    int colunas = 4;

    Matriz matriz(linhas, colunas);


    matriz.atribuirMatriz(0, 0, 1.0);
    matriz.atribuirMatriz(1, 1, 2.0);
    matriz.atribuirMatriz(2, 3, 3.0);


    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matriz.valorMatriz(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
