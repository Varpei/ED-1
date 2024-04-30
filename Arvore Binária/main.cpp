#include <iostream>

using namespace std;

class Dado
{
    private:
        int dado;
    public:
        Dado(){}
        Dado(int valor)
        {
            dado = valor;
        }

        int obterDado()
        {
            return dado;
        }
};

struct No
{
    Dado dado;
    No* filhoEsquerda;
    No* filhoDireita;
};

class Arvore
{
    private:
        No* raiz;
    public:

        Arvore():raiz(nullptr){}

        ~Arvore()
        {

        }

        void deletarArvore(No* noAtual)
        {

        }

        No* obterRaiz()
        {
            return raiz;
        }

        bool estaVazio()
        {
            return raiz == nullptr;
        }

        bool estaCheio()
        {
            try
            {
                No* temp = new No;
                delete temp;
                return false;
            }
            catch(bad_alloc)
            {
                return true;
            }
        }

        void inserir(Dado dado)
        {
            if(estaCheio())
            {
                    cout << "A arvore esta cheia!\n";
                    cout << "Nao foi possivel inserir este elemento!\n";
            }
            else
            {
                No* noNovo = new No;
                noNovo->dado = dado;
                noNovo->filhoEsquerda = nullptr;
                noNovo->filhoDireita = nullptr;

                if(estaVazio())
                {
                    raiz = noNovo;
                }
                else
                {
                    No* ponteiroNoAtual = raiz;
                    while(ponteiroNoAtual != nullptr)
                    {
                        if(dado.obterDado() < ponteiroNoAtual->dado.obterDado())
                        {
                            if(ponteiroNoAtual->filhoEsquerda == nullptr)
                            {
                                ponteiroNoAtual->filhoEsquerda = noNovo;
                                break;
                            }
                        }
                        else
                        {
                            if(ponteiroNoAtual->filhoDireita == nullptr)
                            {
                                ponteiroNoAtual->filhoDireita = noNovo;
                                break;
                            }
                            else
                            {
                                ponteiroNoAtual = ponteiroNoAtual->filhoDireita;
                            }
                        }
                    }
                }

            }
        }

        void remover(Dado dado)
        {
            removerBusca(dado, raiz);
        }

        void removerBusca(Dado& dado, No*& ponteiroNoAtual)
        {
            if(dado.obterDado() < ponteiroNoAtual->dado.obterDado())
            {
                removerBusca(dado, ponteiroNoAtual->filhoEsquerda);
            }
            else if(dado.obterDado() > ponteiroNoAtual->dado.obterDado())
            {
                removerBusca(dado, ponteiroNoAtual->filhoDireita);
            }
            else
            {
                deletarNo(ponteiroNoAtual);
            }
        }

        void deletarNo(No*& ponteiroNoAtual)
        {   
            No* temp = ponteiroNoAtual;

            if(ponteiroNoAtual->filhoEsquerda == nullptr)
            {
                ponteiroNoAtual = ponteiroNoAtual->filhoDireita;
                delete temp;
            }
            else if(ponteiroNoAtual->filhoDireita == nullptr)
            {
                ponteiroNoAtual = ponteiroNoAtual->filhoEsquerda;
                delete temp;
            }
            else
            {
                Dado dadoSucessor;
                obterSucessor(dadoSucessor, ponteiroNoAtual);
                ponteiroNoAtual->dado = dadoSucessor;
                removerBusca(dadoSucessor, ponteiroNoAtual->filhoDireita);
            }
        }

        void obterSucessor(Dado& dadoSucessor, No* temp)
        {
            temp = temp->filhoDireita;
            while(temp->filhoEsquerda != nullptr)
            {
                temp = temp->filhoEsquerda;
            }
            dadoSucessor = temp->dado;
        }

        void imprimirPreOrdem(No* noAtual)
        {
            if(noAtual != nullptr)
            {
                cout << "Dado: " << noAtual->dado.obterDado();
                imprimirPreOrdem(noAtual->filhoEsquerda);
                imprimirPreOrdem(noAtual->filhoDireita);
            }
        }

        void imprimirEmOrdem(No* noAtual)
        {
            imprimirPreOrdem(noAtual->filhoEsquerda);
            cout << "Dado: " << noAtual->dado.obterDado();
            imprimirPreOrdem(noAtual->filhoDireita);
        }

        void imprimirPosOrdem(No* noAtual)
        {
            imprimirPreOrdem(noAtual->filhoEsquerda);
            imprimirPreOrdem(noAtual->filhoDireita);
            cout << "Dado: " << noAtual->dado.obterDado();
        }
};
int main(){
    Arvore arvore;
    int opcao, data, imp;
    bool busca = false;

    do{
        cout << "Digite 0 para parar o algoritmo!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para buscar um elemento!\n";
        cout << "Digite 4 para imprimir a arvore!\n";
        cin >> opcao;

        if (opcao == 1)
        {
            cout << "Digite o dado:\n";
            cin >> data;
            Dado dado(data);
        if (arvore.estaCheio())
        {
            cout << "A Árvore esta cheia!\n";
            cout << "Nao foi possivel inserir o elemento!\n";
        } 
        else
        {            
            arvore.inserir(dado);
        }
        } 
        else if (opcao == 2)
        {
            cout << "Digite o dado a ser removido!\n";
            cin >> data;
            Dado dado(data);
            arvore.remover(data);
        } 
        else if (opcao == 3)
        {
            cout << "Digite o dado do dado a ser buscado!\n";
            cin >> data;
            Dado dado(data);
            if (busca)
            {
                cout << "Elemento encontrado!\n";
                cout << "Dado: " << dado.obterDado() << endl;
            } 
            else
            {
                cout << "Elemento nao encontrado!\n";
            }           
        } 
        else if (opcao == 4)
        {
            cout << "Digite 1 para fazer a impressao em pre ordem!\n";
            cout << "Digite 2 para fazer a impressao em ordem!\n";
            cout << "Digite 3 para fazer a impressao em pos ordem!\n";
            cin >> imp;
            if (imp == 1)
            {
                arvore.imprimirPreOrdem(arvore.obterRaiz());
            } 
            else if (imp == 2)
            {
                arvore.imprimirEmOrdem(arvore.obterRaiz());
            } 
            else
            {
                arvore.imprimirPosOrdem(arvore.obterRaiz());
            }                   
        }
    } while (opcao != 0);

    return 0;
}