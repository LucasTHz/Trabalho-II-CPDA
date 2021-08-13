#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int M = 100000; // tamanho do vetor e hash
const int N = 10000;  // range dos valores a serem gerados

struct Hash
{
    int chave;
    char livre;
};

int funcao_hashing(int num)
{
    return num % M;
}

void mostrar_hash(Hash tabela[])
{
    for (int i = 0; i <= M; i++)
    {
        if (tabela[i].livre == 'O')
        {
            cout << "\nEntrada " << i << ": " << tabela[i].chave;
        }
    }
}

void inserir(Hash tabela[], int pos, int n)
{
    int i = 0;
    while (i < M && tabela[(pos + i) % M].livre != 'L' && tabela[(pos + i) % M].livre != 'R')
    {
        i = i + 1;
    }

    if (i < M)
    {
        tabela[(pos + i) % M].chave = n;
        tabela[(pos + i) % M].livre = 'O';
    }
    else
        cout << "\nTabela cheia";
}

int buscar(Hash tabela[], int n)
{
    int i = 0;
    int pos = funcao_hashing(n);

    while (i < M && tabela[(pos + i) % M].livre != 'L' && tabela[(pos + i) % M].chave != n)
        i = i + 1;

    if (tabela[(pos + i) % M].chave == n && tabela[(pos + i) % M].livre != 'R')
    {
        return (pos + i) % M;
    }
    else
        return M;
}

void remover(Hash tabela[], int n)
{
    int posicao = buscar(tabela, n);

    if (posicao < M)
    {
        tabela[posicao].livre = 'R';
    }

    else
    {
        cout << "\nElemento nao esta presente";
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

int main()
{
    Hash tabela[M];

    int op, pos, num, i, numeros[M];
    double start, stop, elapsed;

    for (i = 0; i < M; i++)
    {
        tabela[i].livre = 'L';
    }

    do
    {
        cout << "\nMenu de opcoes\n";
        cout << "\n1 - Inserir elemento";
        cout << "\n2 - Mostrar tabela hashing";
        cout << "\n3 - Excluir elemento";
        cout << "\n4 - Sair";
        cout << "\n5 - Limpar tabela";
        cout << "\nDigite sua opcao: ";
        cin >> op;
        system("clear");
        if (op < 1 || op > 5)
        {
            cout << "\n Opcao Invalida";
        }
        else
        {
            switch (op)
            {
            case 1:
                Rand(numeros, N, M);
                start = (double)clock() / CLOCKS_PER_SEC;
                for (int i = 0; i < N; i++)
                {
                    inserir(tabela, i, numeros[i]);
                }
                stop = (double)clock() / CLOCKS_PER_SEC;
                elapsed = stop - start;
                printf("Tempo total em segundos: %f", elapsed);
                break;
            case 2:
                start = (double)clock() / CLOCKS_PER_SEC;
                mostrar_hash(tabela);
                stop = (double)clock() / CLOCKS_PER_SEC;
                elapsed = stop - start;
                printf("Tempo total em segundos: %f", elapsed);
                break;
            case 3:
                cout << "\nDigite um numero:";
                cin >> num;
                remover(tabela, num);
                break;
            case 5:
                for (i = 0; i < M; i++)
                {
                    tabela[i].livre = 'L';
                }
            }
        }
        getchar();

    } while (op != 4);

    return 0;
}
