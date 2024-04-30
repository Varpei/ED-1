#include <iostream>
#include "arvorebinaria.h"

using namespace std;

        BST::BST()//construtor
        {
                raiz = nullptr;
        }
        
        BST::~BST()//destrutor
        {
                deletarArvore(raiz);
        }

        void BST::deletarArvore(No* noAtual)
        {
                if(noAtual != nullptr)
                {
                        deletarArvore(noAtual->filhoEsquerda);
                        deletarArvore(noAtual->filhoDireita);
                        delete noAtual;
                }
        }

        No* BST::obterRaiz()
        {
                return raiz;
        }

        bool BST::estaVazio()
        {
                return (raiz == nullptr);
        }

        bool BST::estaCheio()
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

        void BST::inserir(Aluno aluno)
        {
                if(estaCheio())
                {
                        cout << "A arvore esta cheia!\n";
                        cout << "Nao foi possivel inserir este elemento!\n";
                }
                else
                {
                        No* noNovo = new No;
                        noNovo->aluno = aluno;//O NoNovo aluno vai ser o aluno que o usuario informmar
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
                                        if(aluno.obterRa() < temp->aluno.obterRa())//"aluno" é o objeto criado como parametro da função inserir mas que tammbem é o elemento do NoNovo , função "obterRa" que é a função criada em aluno.cpp 
                                        {//Se o Ra do aluno que a gente vai inserir for menor que o Ra do aluno do No que o temp que está apontando a gente vai para esquerda mas tem que verificar se a esquerda tem elemento se não tiver elemento na esquerda vai ser lá que vai ser inserido o elemento  
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
                                        {//Se o Ra do aluno que a gente vai inserir for maior que o Ra do aluno do No que o temp que está apontando a gente vai para direita mas tem que verificar se a es tem elemento se não tiver elemento na direita vai ser lá que vai ser inserido o elemento  
                                                
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

        void BST::remover(Aluno aluno)
        {
                removerBusca(aluno, raiz);//Vai fazer a busca do aluno começando pela raiz
        }

        void BST::removerBusca(Aluno& aluno, No*& ponteiroNoAtual)
        {
                if(aluno.obterRa() < ponteiroNoAtual->aluno.obterRa())
                {//Se o Ra do aluno parametro for menor que o Ra do aluno que está no ponteiro No Atual ele vai para a esquerda
                        removerBusca(aluno, ponteiroNoAtual->filhoEsquerda);
                }
                else if(aluno.obterRa() > ponteiroNoAtual->aluno.obterRa())
                {//Se o Ra do aluno parametro for maior que o Ra do aluno que está no ponteiro No Atual ele vai para a esquerda
                        removerBusca(aluno, ponteiroNoAtual->filhoDireita);
                }
                else
                {//Se o Ra do aluno parametro for igual que o Ra do aluno que está no ponteiro No Atual ele vai para a esquerda
                        deletarNo(ponteiroNoAtual);
                }
        }    
        void BST::deletarNo(No*& ponteiroNoAtual)
        {
                No* temp = ponteiroNoAtual;
                if(ponteiroNoAtual->filhoEsquerda == nullptr)
                {//Se filho a esquerda do ponteiro do No atual for nullptr vai pegar o ponteiro do No atual ir para o filho da direita
                        ponteiroNoAtual = ponteiroNoAtual->filhoDireita;
                        delete temp;
                }
                else if(ponteiroNoAtual->filhoDireita == nullptr)
                {//Se filho a direita do ponteiro do No atual for nullptr vai pegar o ponteiro do No atual ir para o filho da esquerda
                        ponteiroNoAtual = ponteiroNoAtual->filhoEsquerda;
                        delete temp;
                }
                else
                {//Se o ponteiroNoAtual possuir dois filhos vai entrar nesse caso,  
                        Aluno alunoSucessor;
                        obterSucessor(alunoSucessor, ponteiroNoAtual);//Vou obter o sucessor do ponteiro do No atual
                        ponteiroNoAtual->aluno = alunoSucessor;//O aluno do ponteiro No atual vai mudar de valor porque o No atual estara apontando para o cara que quero remover só que como ele tem 2 filhos vou só trocar o valor dele para o sucessor dele e vou remover o sucessor, no cara que quero remover não vou deletar os ponteiro dele vou só remover o valor aluno dele, então o valor aluno vai ser trocado pelo valor do aluno sucessor
                        removerBusca(alunoSucessor, ponteiroNoAtual->filhoDireita);//Vai buscar o sucessor a partir do filho a direita dele e depois vai buscar ele de novo e vai deletar
                }
        }   
        void BST::obterSucessor(Aluno& alunoSucessor, No* temp)
        {
                temp = temp->filhoDireita;
                while (temp->filhoEsquerda != nullptr)
                {//Enquanto o filho da esquerda do No temporario for diferente de nullptr ele vai para esquerda até o No que ele estiver apontando for nullptr ai sim ele vai parar o while, quando for nullptr ele vai parar e achar o sucessor
                        temp = temp->filhoEsquerda;
                }
                alunoSucessor = temp->aluno;
        }


        void BST::buscar(Aluno& aluno, bool& busca)//Pega bool& busca por referencia(&) pois se encontrar o busca vai modificar para true e se não encontrar vai modificar para false
        {
                busca = false;
                No* noAtual = raiz;//Ponteiro para o No e esse NoAtual começa apontando para o mesmo lugar aonde a raiz está apontando a raiz é um ponteiro para o No que está apontando como raiz da arvore ai ele vai descendo
                while(noAtual != nullptr)
                {//Enquanto o NoAtual for diferente de nullptr ele vai comparando 
                        if(aluno.obterRa() < noAtual->aluno.obterRa())
                        {//Se o Ra do aluno que mandei para procurar for menor que o Ra do aluno que está naquele No então ele vai para o filho da esquerda
                                noAtual = noAtual->filhoEsquerda;// vai para o filho da esquerda da onde ele está
                        }
                        else if(aluno.obterRa() > noAtual->aluno.obterRa())
                        {//Se o Ra do aluno que estou mandando procurar for maior que o Ra do aluno que está no NoAtual que estou comparando 
                                noAtual = noAtual->filhoDireita;
                        }
                        else
                        {//Se o Ra do aluno que estou mandando procurar for igual ao Ra do aluno que está no NoAtual que estou comparando então achou o elemento que estava buscando                     
                                busca = true;
                                aluno = noAtual->aluno;//Além do Ra com essa linha você pega o nome do aluno o que está armazenado no Ra
                                break;
                        }
                }
        }

        void BST::imprimirPreOrdem(No* noAtual)
        {
                if(noAtual != nullptr)
                {       
                        cout << "Nome: " << noAtual->aluno.obterNome() << ": ";
                        cout << "RA: " << noAtual->aluno.obterRa() << endl; 
                        imprimirPreOrdem(noAtual->filhoEsquerda);
                        imprimirPreOrdem(noAtual->filhoDireita);
                }
        }

        void BST::imprimirEmOrdem(No* noAtual)
        {
                if(noAtual != nullptr)
                {
                        imprimirPreOrdem(noAtual->filhoEsquerda);
                        cout << "Nome: " << noAtual->aluno.obterNome() << ": ";
                        cout << "RA: " << noAtual->aluno.obterRa() << endl;
                        imprimirPreOrdem(noAtual->filhoDireita);
                }
        }

        void BST::imprimirPosOrdem(No* noAtual)
        {
                if(noAtual != nullptr)
                {
                        imprimirPosOrdem(noAtual->filhoEsquerda);
                        imprimirPosOrdem(noAtual->filhoDireita);
                        cout << "Nome: " << noAtual->aluno.obterNome() << ": ";
                        cout << "RA: " << noAtual->aluno.obterRa() << endl;
                } 
        }