#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int M = 100000; // range dos valores a serem gerados
const int P = 10000;  // tamanho do vetor e hash

struct Hash
{
    int chave;
    Hash *prox;
};

void inserir(Hash *tabela[], int pos, int n)
{
    Hash *novo;
    novo = new Hash();
    novo->chave = n;
    novo->prox = tabela[pos];
    tabela[pos] = novo;
}

int funcao_hashing(int num)
{
    return num % M;
}

void mostrar_hash(Hash *tabela[])
{
    Hash *aux;

    for (int i = 0; i < P; i++)
    {
        aux = tabela[i];
        while (aux != NULL)
        {
            cout << "\nEntrada " << i << ": " << aux->chave;
            aux = aux->prox;
        }
    }
}

void excluir_hash(Hash *tabela[], int num)
{
    int pos = funcao_hashing(num);
    Hash *aux;

    if (tabela[pos] != NULL)
    {
        if (tabela[pos]->chave == num)
        {
            aux = tabela[pos];
            tabela[pos] = tabela[pos]->prox;
            delete aux;
        }
        else
        {
            aux = tabela[pos]->prox;
            Hash *ant = tabela[pos];
            while (aux != NULL && aux->chave != num)
            {
                ant = aux;
                aux = aux->prox;
            }
            if (aux != NULL)
            {
                ant->prox = aux->prox;
                delete aux;
            }
            else
            {
                cout << "\nNumero nao encontrado";
            }
        }
    }
    else
    {
        cout << "\nUmero nao encontrado";
    }
}

bool Exites(int valores[], int x, int valor)
{
    for (int i = 0; i < x; i++)
    {
        if (valores[i] == valor)
        {
            return true;
        }
    }

    return false;
}

void Rand(int numeros[], int N, int M)
{
    srand(time(NULL));

    int v;
    for (int i = 0; i < N; i++)
    {
        v = rand() % M;
        while (Exites(numeros, i, v))
        {
            v = rand() % M;
        }
        numeros[i] = v;
    }
}

int main(int argc, char const *argv[])
{
    Hash *tabela[M];
    Hash *aux;
    int op, pos, num, i, numeros[M];
    double start, stop, elapsed;

    for (i = 0; i < M; i++)
    {
        tabela[i] = NULL;
    }

    do
    {
        cout << "\nMenu de opcoes\n";
        cout << "\n1 - Inserir elemento";
        cout << "\n2 - Mostrar tabela hashing";
        cout << "\n3 - Excluir elemento";
        cout << "\n4 - Sair";
        cout << "\nDigite sua opcao: ";
        cin >> op;
        system("clear");
        if (op < 1 || op > 4)
        {
            cout << "\n Opcao Invalida";
        }
        else
        {
            switch (op)
            {
            case 1:
                Rand(numeros, P, M);
                start = (double)clock() / CLOCKS_PER_SEC;
                for (int i = 0; i < P; i++)
                {
                    inserir(tabela, i, numeros[i]);
                }
                stop = (double)clock() / CLOCKS_PER_SEC;
                elapsed = stop - start;
                printf("Tempo total em segundos: %f\n", elapsed);
                break;
            case 2:
                start = (double)clock() / CLOCKS_PER_SEC;
                mostrar_hash(tabela);
                stop = (double)clock() / CLOCKS_PER_SEC;
                elapsed = stop - start;
                printf("\nTempo total em segundos: %f", elapsed);
                break;
            case 3:
                cout << "\nDigite um numero:";
                cin >> num;
                excluir_hash(tabela, num);
                break;
            }
        }
    } while (op != 4);

    for (i = 0; i < P; i++)
    {
        while (tabela[i] != NULL)
        {
            aux = tabela[i];
        }
    }
}
