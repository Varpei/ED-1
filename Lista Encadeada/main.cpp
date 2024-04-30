#include <iostream>

using namespace std;

struct No
{
        int dado;
        No *proximo;

        No(int valor):dado(valor), proximo(nullptr){}

        int getValor(){
            return dado;
        }

        void setProx(No *proximo){
            this -> proximo = proximo;
        }

        No *getProx(){
           return proximo;
        }
        
};
class Lista
{
    public:
    No *primeiro;//primeiro elemento da lista
    Lista():primeiro(nullptr){}
    
    ~Lista()
    {
        while(!vazio())
        {

            delete primeiro;
        
        }
    }

    bool vazio() const 
    {
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
                atual = atual->getProx();//enquanto o elemento atual não for nulo, vai ser inserido na lista o mesmo
            }
            atual->setProx(novo);//após ser inserido o atual valor vai parar de apontar para aquele que já foi inserido e vai ser inserido em outra caixa 
        }
    }

    void inserirNoInicio(int valor){
        	No *novo = new No(valor);//novo valor a ser inserido
	        novo->setProx(primeiro);//o novo elemento vai passar o próximo elemento para a primeira casa da lista
	        primeiro = novo; // o primeiro vai receber o novo valor 
    }

    void removerNoInicio()
    {
        if(vazio())
        {
            throw string("Lista vazia!");// se estiver vazio vai imprimir (lista vazia!)
        }
        else//se não estiver vazio
        {
            No *atual = primeiro;//O atual elemento recebe o primeiro
            primeiro = primeiro->getProx();//o primeiro elemento vai receber o retorno do proximo na lista substituindo o que vai ser deletado
            delete atual;//O elemento é deletado
        }
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

        while(atual->getProx()->getProx() != nullptr)//enquanto o elemento atual for diferente de nulo
        {
            anterior = atual;
            atual = atual->getProx()->getProx();
        }

        anterior->setProx(nullptr);//O proximo elemento do anterior vai ser definido como nulo, logo, o último elemento será removido
        delete atual;

        return atual;//retorna o elemento que foi removido da lista
    }

    void removerValor(int valor)
    {
        No *atual = primeiro;
        No *anterior = nullptr;

        while (vazio()) 
        {
            if (atual->getValor() == valor) 
            {
                if (anterior == nullptr) 
                {
                    primeiro = atual->getProx();
                } 
                else 
                {
                    anterior->setProx(atual->getProx());
                }
                No *aux = atual;
                atual = atual->getProx();  
                delete aux;  
            } 
            else 
            {
                anterior = atual;
                atual = atual->getProx();
            }
        }
    }

    void imprimir()
    {
        No *atual = primeiro;
        while(atual != nullptr)
        {
            cout << atual->getValor() << " "; 
            atual = atual->getProx();
        }
        cout<<endl;
    }
    
};

int menu() {
    cout << "Escolha uma opcao:" << endl;
    cout << "1. Adicionar elemento - NO FINAL" << endl;
    cout << "2. Adicionar elemento - NO INICIO" << endl;
    cout << "3. Remover elemento - POR VALOR" << endl;
    cout << "4. Remover elemento - NO FINAL" << endl;
    cout << "5. Remover elemento - NO INICIO" << endl;
    cout << "6. Imprimir lista" << endl;
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

                cout << "Insira o elemento que deseja remover: ";
                cin >> valor;
                lista.removerValor(valor);
            break;

            case 4:

                lista.removerNoFinal();
            break;

            case 5:

                lista.removerNoInicio();
            break;

            case 6:

                cout << "Lista: " << endl;
                lista.imprimir();
            break;

        }
        v = menu();
    }
}