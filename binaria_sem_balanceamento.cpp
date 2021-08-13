#include <iostream>
#include <time.h>
#include <stdlib.h>

const int M = 99954; // tamanho do vetor e hash
const int N = 10000; // range dos valores a serem gerados

using namespace std;

struct arvore
{
    int num;
    arvore *esq, *dir;
};

arvore *inserir(arvore *aux, int num)
{
    if (aux == NULL)
    {
        aux = new arvore();
        aux->num = num;
        aux->esq = NULL;
        aux->dir = NULL;
    }
    else if (num < aux->num)
    {
        aux->esq = inserir(aux->esq, num);
    }
    else
    {
        aux->dir = inserir(aux->dir, num);
    }
    return aux;
}

void emOrdem(arvore *aux)
{
    if (aux != NULL)
    {
        emOrdem(aux->esq);
        // printf("%d\n", aux->num);
        emOrdem(aux->dir);
    }
}

arvore *desalocar(arvore *aux)
{
    if (aux != NULL)
    {
        aux->esq = desalocar(aux->esq);
        aux->dir = desalocar(aux->dir);
        delete aux;
    }
    return NULL;
}

int consultar(arvore *aux, int num, int achou)
{
    if (aux != NULL && achou == 0)
    {
        if (aux->num == num)
            achou = 1;
        else if (num < aux->num)
            achou = consultar(aux->esq, num, achou);
        else
            achou = consultar(aux->dir, num, achou);
    }
    return achou;
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
    arvore *raiz = NULL;
    arvore *aux;
    int numeros[M], num, achou = 0;
    double start, stop, elapsed;

    // Insersao

    Rand(numeros, N, M);
    start = (double)clock() / CLOCKS_PER_SEC;
    for (int i = 0; i < 1000; i++)
    {
        raiz = inserir(raiz, numeros[i]);
    }
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Insersao: %f\n", elapsed);

    // Busca

    printf("Elemento a ser buscado na arvore: ");
    scanf("%d", &num);
    start = (double)clock() / CLOCKS_PER_SEC;
    achou = consultar(raiz, num, achou);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo de busca: %f\n", elapsed);
    if(achou ==0)
            printf("Elemento nao encontrado.\n");
        else
            printf("Elemento encontrado. \n");

    // Remoção de todos os elementos

    start = (double)clock() / CLOCKS_PER_SEC;
    desalocar(raiz);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo gasto para remover todos os elementos: %f\n", elapsed);

    return 0;
}
