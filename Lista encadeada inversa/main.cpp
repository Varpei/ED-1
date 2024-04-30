#include <iostream>

using namespace std;

class No{
    public:
    int dado;
    No *proximo;
    No() : dado(0), proximo(nullptr){}
    No(int valor) : dado(valor), proximo(nullptr){}
    ~No(){
        delete proximo;
    }

    void setProx(No *proximo){
        this->proximo = proximo;
    }

    No *getProx(){
        return proximo;
    }

    int getValor(){
        return dado;
    }
    
};

class Lista{
    private:
        No *primeiro;
    public:
        Lista():primeiro(nullptr){}

        void inserir(int valor){
            No *novo = new No(valor);
            novo->setProx(primeiro);
            primeiro = novo;
        }

        void imprimir(){
            No *atual = primeiro;
            while (atual != nullptr){
                cout << atual->getValor() << " ";
                atual = atual->getProx();
            }
            cout << endl;
        }

        void inverter(int s, int f){
            if(s >= f || primeiro == nullptr){
                return;
            }
            
            No *anteriorS = nullptr;
            No *atual = primeiro;
            int posicao = 1;

            while(posicao < s and atual != nullptr){
                anteriorS = atual;
                atual = atual->getProx();
                posicao++;
            }

            No * anteriorF = atual;
            while(posicao < f and atual != nullptr){
                anteriorF = atual;
                atual = atual->getProx();
                posicao++;
            }

            if(atual == nullptr){
                return;
            }

            No *proximo = atual->getProx();
            No *novoPrimeiro = nullptr;
            while(proximo != nullptr){
                No *temp = proximo->getProx();
                proximo->setProx(novoPrimeiro);
                novoPrimeiro = proximo;
                proximo = temp;
            }

            if(anteriorS != nullptr){
                anteriorS->setProx(anteriorF->getProx());
            }
            else
            {
                primeiro = anteriorF->getProx();
            }

            anteriorF->setProx(novoPrimeiro);

        }
};


int main() {
    Lista lista;
    int n, s, f, valor;

    cout << "Informe a quantidade de elementos na lista: ";
    cin >> n;

    cout << "Informe os elementos da lista: ";
    for (int i = 0; i < n; i++) {
        cin >> valor;
        lista.inserir(valor);
    }
    cout << "Lista original: ";
    lista.imprimir();

    cout << "Informe s e f (s-ésimo e f-ésimo): ";
    cin >> s >> f;

    lista.inverter(s, f);

    cout << "Lista invertida de " << s << " a " << f << ": ";
    lista.imprimir();

    return 0;
}