#include <iostream>
#include "arvoreAVL.cpp"

using namespace std;

int main()
{
    ArvoreAVL arvore;
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
            arvore.inserir(data);
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
            arvore.buscar(dado, busca);
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
                system("clear");
                cout << "Arvore (PRE ORDEM): \n";
                arvore.imprimirPreOrdem(arvore.obterRaiz());
                cout << "\n";
            } 
            else if (imp == 2)
            {
                system("clear");
                cout << "Arvore (EM ORDEM): \n";
                arvore.imprimirEmOrdem(arvore.obterRaiz());
                cout << "\n";
            } 
            else
            {
                system("clear");
                cout << "Arvore (POS ORDEM): \n";
                arvore.imprimirPosOrdem(arvore.obterRaiz());
                cout << "\n";
            }                   
        }
    } while (opcao != 0);

    return 0;
}