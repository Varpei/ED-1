#include <iostream>
#include "Lista.cpp"

using namespace std;

int menu() {
    cout << "Escolha uma opcao:" << endl;
    cout << "1. Adicionar elemento - NO FINAL" << endl;
    cout << "2. Adicionar elemento - NO INICIO" << endl;
    cout << "3. Remover elemento - NO FINAL" << endl;
    cout << "4. Remover elemento - NO INICIO" << endl;
    cout << "5. Imprimir lista" << endl;
    cout << "0. Sair" << endl;

    int v;
    cin >> v;

    return v;
}

int main(){
    Lista lista;
    int v;
    v = menu();

    while(v != 0){

        switch(v)
        {
            case 1:
                int valor;
                cout << "Insira um valor na lista: ";
                cin>>valor;
                lista.inserirFinal(valor);
            break;

            case 2: 

                cout << "Insira um valor na lista: ";
                cin>>valor;
                lista.inserirNoInicio(valor);
            break;

            case 3:

                lista.removerNoFinal();

            case 4:

                lista.removerNoInicio();

            break;

            case 5:
                cout << "Lista: " << endl;
                lista.imprimir();
            break;

        }
        v = menu();
    }
}