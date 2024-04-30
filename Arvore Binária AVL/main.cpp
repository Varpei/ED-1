#include <iostream>

using namespace std;

struct Dado{

    int dado;

    Dado()
    {

    }
    Dado(int valor)
    {
        dado = valor;
    }
    
    int obterDado()
    {
        return dado;
    }
};

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
        ArvoreAVL()//construtor
        {
                raiz = nullptr;
        }
        
        ~ArvoreAVL()//destrutor
        {
                deletarArvore(raiz);
        }

        void deletarArvore(No* noAtual)
        {
                if(noAtual != nullptr)
                {
                        deletarArvore(noAtual->filhoEsquerda);
                        deletarArvore(noAtual->filhoDireita);
                        delete noAtual;
                }
        }

        No* obterRaiz()
        {
                return raiz;
        }

        bool estaVazio()
        {
                return (raiz == nullptr);
        }

        bool estaCheio()
        {
                try{
                        No* temp = new No;//Pega um ponteiro temporario e o new No cria um espaço na memoria se achar um espaço na memoria que cabe um No quer dizer que não esta cheio
                        delete temp;//Já que não está cheio então o No temporario vai ser deletado do espaço da memooria para quando for inserir, o elemento ser inserido 
                        return false;//False porque ainda não está cheio
                }catch(bad_alloc exeption)//Se não conseguir criar ele vai pro catch
                {
                        return true;//True porquue é verdade que está cheio
                }
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
                        noNovo->dado = dado;//O NoNovo dado vai ser o dado que o usuario informmar
                        noNovo->filhoEsquerda = nullptr;//O NoNovo tem a informação do filho a esquerda que incializa como nullptr
                        noNovo->filhoDireita = nullptr;//O NoNovo tem a informação do filho a direita que inicializa como nullptr
                        //Falta saber a posição na arvore que o NoNovo vai ficar (Quem que vai apontar para ele - A arvore está vazia?)
                        if(estaVazio())
                        {//Se a (raiz == nullptr)
                             raiz = noNovo;//A raiz vai receber o novo No
                        }
                        else
                        {//Caso contrário, a raiz não seja nula, quer dizer que a raiz não é igual a nullptr, ou seja tem algum elemento ali, então vai ter que comparar, começando a comparar com a raiz e descendo, aonde caso o No for menor que a raiz vai comparar com a esquerda e caso o No for maior que raiz vai comparar com a direita 
                                No* temp = raiz;//Com esse No temporario ele vai percorrendo começando pela raiz e vai perguntando se for menor para esquerda se for maior para direita até achar um espaço vazio se ele achar esse espaço vazio vai ser o lugar que vai ser adicionado esse No novo
                                while(temp != nullptr)//Enquanto o temp for diferente de nullptr ele vai perguntando, quando chegar no nullptr ai a gente inserer o elemento
                                {
                                        if(dado.obterDado() < temp->dado.obterDado())//"dado" é o objeto criado como parametro da função inserir mas que tammbem é o elemento do NoNovo , função "obterRa" que é a função criada em dado.cpp 
                                        {//Se o Ra do dado que a gente vai inserir for menor que o Ra do dado do No que o temp que está apontando a gente vai para esquerda mas tem que verificar se a esquerda tem elemento se não tiver elemento na esquerda vai ser lá que vai ser inserido o elemento  
                                                if(temp->filhoEsquerda == nullptr)
                                                {//Se o filho a esquerda for nullptr quer dizer que achou um espaço vazio vai ser lá que vai ser colocado esse NoNovo
                                                        temp->filhoEsquerda = noNovo;
                                                        break;
                                                }
                                                else
                                                {//Se o filho a esquerda não for nullptr o No temporario vai para o filho a esquerda da onde ele está apontando
                                                        temp = temp->filhoEsquerda;
                                                }
                                        }
                                        else
                                        {//Se o Ra do dado que a gente vai inserir for maior que o Ra do dado do No que o temp que está apontando a gente vai para direita mas tem que verificar se a es tem elemento se não tiver elemento na direita vai ser lá que vai ser inserido o elemento  
                                                
                                                if(temp->filhoDireita == nullptr)
                                                {//Se o filho a direita for nullptr quer dizer que achou um espaço vazio vai ser lá que vai ser colocado esse NoNovo
                                                        temp->filhoDireita = nullptr;
                                                        break;
                                                }
                                                else
                                                {//Se o filho a direita não for nullptr o No temporario vai para o filho a direita da onde ele está apontando
                                                        temp = temp->filhoDireita;
                                                }
                                        }
                                }
                        }
                }
        } 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void insereRecursivo(No*& ponteiroNoAtual, Dado dado, bool& cresceu)
        { 
                if (ponteiroNoAtual == NULL)
                {
                        ponteiroNoAtual = new No;
                        ponteiroNoAtual->filhoDireita = NULL;
                        ponteiroNoAtual->filhoEsquerda = NULL;
                        ponteiroNoAtual->dado = dado;
                        ponteiroNoAtual->fatorB = 0;
                        cresceu = true;
                        return;
                }  
                if(dado.obterDado() < ponteiroNoAtual->dado.obterDado()) 
                {//Se o dado que estou buscando for menor que o dado que está no NoAtual então vai ser chamado o insereRecursivo para o filho da esquerda  
                        insereRecursivo(ponteiroNoAtual->filhoEsquerda, dado, cresceu);
                        if(cresceu)
                        {//Se o cresceu for verdeiro então vai ser atualizado o fator de balanceamento para diminuir 1
                                ponteiroNoAtual->fatorB-=1;   
                        } 
                } 
                else 
                {//Se o dado que estou buscando for menor que o dado que está no NoAtual então vai ser chamado o insereRecursivo para o filho da direita
                        insereRecursivo(ponteiroNoAtual->filhoDireita, dado, cresceu);
                        if(cresceu)
                        {//Se o cresceu for verdeiro então vai ser atualizado o fator de balanceamento para aumentar 1
                                ponteiroNoAtual->fatorB+=1;
                        }    
                } 
                realizaRotacao(ponteiroNoAtual);//Chegou no No vai ser atualizado o fator de balanceamento ou não, mas chama o realiza rotação de acordo se o fator de balanceamento não estiver entre -1 e 1 

                if(cresceu && ponteiroNoAtual->fatorB == 0)
                {//Se o cresceu é verdadeiro e o fator de balanceamento é 0 então o cresceu fica falso, ou seja, não vai precisar atualizar o fator de balanceamento de ninguém
                        cresceu = false;
                }
        }  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void remover(Dado dado)
        {
                bool diminuiu;
                removerBusca(dado, raiz, diminuiu);//Vai fazer a busca do dado começando pela raiz
        }

        void removerBusca(Dado dado, No*& ponteiroNoAtual, bool& diminuiu)
        {
                if(dado.obterDado() < ponteiroNoAtual->dado.obterDado())
                {//Se o DADO do dado parametro for menor que o DADO do dado que está no ponteiro No Atual ele vai para a esquerda
                        removerBusca(dado, ponteiroNoAtual->filhoEsquerda, diminuiu);
                        if(diminuiu)
                        {//Se for verdade que diminuiu a subarvore a esquerda então vai aumentar o fator de balanceamento em 1
                                ponteiroNoAtual->fatorB+=1;
                        }
                }
                else if(dado.obterDado() > ponteiroNoAtual->dado.obterDado())
                {//Se o DADO do dado parametro for maior que o DADO do dado que está no ponteiro No Atual ele vai para a esquerda
                        removerBusca(dado, ponteiroNoAtual->filhoDireita, diminuiu);
                        if(diminuiu)
                        {//Se for verdade que diminuiu a subarvore a esquerda então vai diminuir o fator de balanceamento em 1
                                ponteiroNoAtual->fatorB-=1;
                        }
                }
                else
                {//Se o DADO do dado parametro for igual que o DADO do dado que está no ponteiro No Atual ele vai para a esquerda
                        deletarNo(ponteiroNoAtual, diminuiu);
                }
                if(ponteiroNoAtual != nullptr)
                {//Se o ponteiro do no atual for não nulo então 
                        realizaRotacao(ponteiroNoAtual);//Vai chamar o realiza rotação para verificar se o fator de balanceamento está entre -1 e 1 para ver a possibilidade de realizar rotação
                        if(diminuiu and ponteiroNoAtual->fatorB != 0)
                        {//Se chegar em algum no que o fator de balanceamento for diferente de zero quer dizer que não diminuiu de ninguem
                                diminuiu = false;
                        }
                }
        }

        void deletarNo(No*& ponteiroNoAtual, bool& diminuiu)
        {
                No* temp = ponteiroNoAtual;
                if(ponteiroNoAtual->filhoEsquerda == nullptr)
                {//Se filho a esquerda do ponteiro do No atual for nullptr vai pegar o ponteiro do No atual ir para o filho da direita
                        ponteiroNoAtual = ponteiroNoAtual->filhoDireita;
                        diminuiu = true;
                        delete temp;
                }
                else if(ponteiroNoAtual->filhoDireita == nullptr)
                {//Se filho a direita do ponteiro do No atual for nullptr vai pegar o ponteiro do No atual ir para o filho da esquerda
                        ponteiroNoAtual = ponteiroNoAtual->filhoEsquerda;
                        diminuiu = true;
                        delete temp;
                }
                else
                {//Se o ponteiroNoAtual possuir dois filhos vai entrar nesse caso,  
                        Dado dadoSucessor;
                        obterSucessor(dadoSucessor, ponteiroNoAtual);//Vou obter o sucessor do ponteiro do No atual
                        ponteiroNoAtual->dado = dadoSucessor;//O dado do ponteiro No atual vai mudar de valor porque o No atual estara apontando para o cara que quero remover só que como ele tem 2 filhos vou só trocar o valor dele para o sucessor dele e vou remover o sucessor, no cara que quero remover não vou deletar os ponteiro dele vou só remover o valor dado dele, então o valor dado vai ser trocado pelo valor do dado sucessor
                        removerBusca(dadoSucessor, ponteiroNoAtual->filhoDireita, diminuiu);//Vai buscar o sucessor a partir do filho a direita dele e depois vai buscar ele de novo e vai deletar
                        if(diminuiu)
                        {//Atualiza o fator de balanceamento, caso for verdade que diminuiu
                                ponteiroNoAtual->fatorB -= 1;
                        }
                }
        }   
        
        void obterSucessor(Dado& dadoSucessor, No* temp)
        {
                temp = temp->filhoDireita;
                while (temp->filhoEsquerda != nullptr)
                {//Enquanto o filho da esquerda do No temporario for diferente de nullptr ele vai para esquerda até o No que ele estiver apontando for nullptr ai sim ele vai parar o while, quando for nullptr ele vai parar e achar o sucessor
                        temp = temp->filhoEsquerda;
                }
                dadoSucessor = temp->dado;
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void buscar(Dado& dado, bool& busca)//Pega bool& busca por referencia(&) pois se encontrar o busca vai modificar para true e se não encontrar vai modificar para false
        {
                busca = false;
                No* noAtual = raiz;//Ponteiro para o No e esse NoAtual começa apontando para o mesmo lugar aonde a raiz está apontando a raiz é um ponteiro para o No que está apontando como raiz da arvore ai ele vai descendo
                while(noAtual != nullptr)
                {//Enquanto o NoAtual for diferente de nullptr ele vai comparando 
                        if(dado.obterDado() < noAtual->dado.obterDado())
                        {//Se o DADO do dado que mandei para procurar for menor que o DADO do dado que está naquele No então ele vai para o filho da esquerda
                                noAtual = noAtual->filhoEsquerda;// vai para o filho da esquerda da onde ele está
                        }
                        else if(dado.obterDado() > noAtual->dado.obterDado())
                        {//Se o dado do dado que estou mandando procurar for maior que o DADO do dado que está no NoAtual que estou comparando 
                                noAtual = noAtual->filhoDireita;
                        }
                        else
                        {//Se o DADO do dado que estou mandando procurar for igual ao DADO do dado que está no NoAtual que estou comparando então achou o elemento que estava buscando                     
                                busca = true;
                                dado = noAtual->dado;//Além do DADO com essa linha você pega o nome do dado o que está armazenado no DADO
                                break;
                        }
                }
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void imprimirPreOrdem(No* noAtual)
        {
                if(noAtual != nullptr)
                {       
                        cout << " " << noAtual->dado.obterDado();
                        imprimirPreOrdem(noAtual->filhoEsquerda);
                        imprimirPreOrdem(noAtual->filhoDireita);
                }
        }

        void imprimirEmOrdem(No* noAtual)
        {
                if(noAtual != nullptr)
                {
                        imprimirPreOrdem(noAtual->filhoEsquerda);
                        cout << " " << noAtual->dado.obterDado();
                        imprimirPreOrdem(noAtual->filhoDireita);
                }
        }

        void imprimirPosOrdem(No* noAtual)
        {
                if(noAtual != nullptr)
                {
                        imprimirPosOrdem(noAtual->filhoEsquerda);
                        imprimirPosOrdem(noAtual->filhoDireita);
                        cout << " " << noAtual->dado.obterDado();
                } 
        }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void rotacaoDireita(No*& pai) 
        {
                No* novopai = pai->filhoEsquerda;//Vou salvar a informação do filho a esquerda do pai 
                pai->filhoEsquerda = novopai->filhoDireita;//O filho a direita do novopai vai receber o valor do filho a direita
                novopai->filhoDireita = pai;//O valor do pai vai para aonde o filho da direita estava
                pai = novopai;//Agora o novo pai vai ser o antigo filho a direita dele
        }

        void rotacaoEsquerda(No*& pai)
        {
                No* novopai = pai->filhoDireita;//Vou salvar a informação do filho a esquerda do pai
                pai->filhoDireita = novopai->filhoEsquerda;//O filho a direita do novopai vai receber o valor do filho a direita
                novopai->filhoEsquerda = pai;//O valor do pai vai para aonde o filho da direita estava
                pai = novopai;//Agora o novo pai vai ser o antigo filho a direita dele
        }

        void rotacaoEsquerdaDireita(No*& pai)
        {//vai acontecer sempre que o fator de balanceamento não estiver entre -1 e 1
                No* filho = pai->filhoEsquerda;//Vou salvar a informação do filho a esquerda do pai
                rotacaoEsquerda(filho);//Faço uma rotação para esquerda para rotação o filho da direita do pai
                pai->filhoEsquerda = filho;//O valor do filho a esquerda do pai vai receber o valor do filho a esquerda que salvei na variavel filho
                rotacaoDireita(pai);//Caso não estiver balanceado rotaciono o filho da esquerda do pai
        }


        void rotacaoDireitaEsquerda(No*& pai)
        {//vai acontecer sempre que o fator de balanceamento não estiver entre -1 e 1
                No* filho = pai->filhoDireita;//Vou salvar a informação do filho a esquerda do pai
                rotacaoDireita(filho);//Faço uma rotação para esquerda para rotacionar o filho da esquerda do pai
                pai->filhoDireita = filho;//O valor do filho a direita do pai vai receber o valor do filho a direitat que salvei na variavel filho 
                rotacaoEsquerda(pai);//Caso não estiver balanceado rotaciono o filho da esquerda
        }


        void realizaRotacao(No*& pai)
        {
                No* filho;
                No* neto; //Caso precise da rotação dupla

                if(pai->fatorB == -2)
                { //rotaciona para a direita

                        filho = pai->filhoEsquerda;

                        if(filho->fatorB == -1)
                        { //Simples para a direita
                                pai->fatorB = 0;
                                filho->fatorB = 0;
                                rotacaoDireita(pai);
                        } 
                        else if(filho->fatorB == 0)
                        { //Simples para a direita
                                pai->fatorB = -1;
                                filho->fatorB = 1;
                                rotacaoDireita(pai);
                        } 
                        else if(filho->fatorB == 1)
                        { //Rotação dupla
                                neto = filho->filhoDireita;
                                if(neto->fatorB == -1)
                                {
                                        pai->fatorB = 1;
                                        filho->fatorB = 0;
                                } 
                                else if(neto->fatorB == 0)
                                {
                                        pai->fatorB = 0;
                                        filho->fatorB = 0;                
                                } 
                                else if(neto->fatorB == 1)
                                {
                                        pai->fatorB = 0;
                                        filho->fatorB = -1;                
                                }
                                neto->fatorB = 0; 
                                rotacaoDireitaEsquerda(pai);            
                        }
                } 
                else if(pai->fatorB == 2)
                { //rotaciona para a esquerda
                        filho = pai->filhoDireita;
                        if(filho->fatorB == 1) 
                        { //Simples para a esquerda
                                pai->fatorB = 0;
                                filho->fatorB = 0;
                                rotacaoEsquerda(pai);
                        } 
                        else if(filho->fatorB == 0)
                        { //Simples para a esquerda         
                                pai->fatorB = 1;
                                filho->fatorB = -1;
                                rotacaoEsquerda(pai);
                        } 
                        else if(filho->fatorB == -1)
                        { //Rotacao dupla
                                neto = filho->filhoEsquerda;
                                if (neto->fatorB == -1){
                                pai->fatorB =  0;
                                filho->fatorB = 1; 
                                } else if (neto->fatorB == 0){
                                pai->fatorB =  0;
                                filho->fatorB = 0; 
                                } else if (neto->fatorB == 1){
                                pai->fatorB =  -1;
                                filho->fatorB = 0; 
                                }
                                neto->fatorB = 0;
                                rotacaoDireitaEsquerda(pai);
                        }
                }
        }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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