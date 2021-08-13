#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int M = 99954; // tamanho do vetor e hash
const int N = 10000; // range dos valores a serem gerados

struct arvore
{
    int num, altd, alte;
    arvore *dir, *esq;
};

arvore *rotacao_esquerda(arvore *aux)
{
    arvore *aux1, *aux2;
    aux1 = aux->dir;
    aux2 = aux1->esq;
    aux->dir = aux2;
    aux1->esq = aux;
    if (aux->dir == NULL)
    {
        aux->altd = 0;
    }
    else if (aux->dir->alte > aux->dir->altd)
    {
        aux->altd = aux->dir->alte + 1;
    }
    else
    {
        aux->altd = aux->dir->altd + 1;
    }
    if (aux1->esq->alte > aux1->esq->altd)
    {
        aux1->alte = aux1->esq->alte + 1;
    }
    else
    {
        aux1->alte = aux1->esq->altd + 1;
    }
    return aux1;
}

arvore *rotacao_direita(arvore *aux)
{
    arvore *aux1, *aux2;
    aux1 = aux->esq;
    aux2 = aux1->dir;
    aux->esq = aux2;
    aux1->dir = aux;
    if (aux->esq == NULL)
    {
        aux->alte = 0;
    }
    else if (aux->esq->alte > aux->esq->altd)
    {
        aux->alte = aux->esq->alte + 1;
    }
    else
    {
        aux->alte = aux->esq->altd + 1;
    }
    if (aux1->dir->alte > aux1->dir->altd)
    {
        aux1->altd = aux1->dir->alte + 1;
    }
    else
    {
        aux->altd = aux1->dir->altd + 1;
    }
    return aux1;
}

arvore *balanceamento(arvore *aux)
{
    int d, df;
    d = aux->altd - aux->alte;
    if (d == 2)
    {
        df = aux->dir->altd - aux->dir->alte;
        if (df >= 0)
        {
            aux = rotacao_esquerda(aux);
        }
        else
        {
            aux->dir = rotacao_direita(aux->dir);
            aux = rotacao_esquerda(aux);
        }
    }
    else if (d == -2)
    {
        df = aux->esq->altd - aux->esq->alte;
        if (df <= 0)
        {
            aux = rotacao_direita(aux);
        }
        else
        {
            aux->esq = rotacao_esquerda(aux->esq);
            aux = rotacao_direita(aux);
        }
    }
    return aux;
}

arvore *inserir(arvore *aux, int num)
{
    arvore *novo;
    if (aux == NULL)
    {
        novo = new arvore();
        novo->num = num;
        novo->altd = 0;
        novo->alte = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        aux = novo;
    }
    else if (num < aux->num)
    {
        aux->esq = inserir(aux->esq, num);
        if (aux->esq->altd > aux->esq->alte)
        {
            aux->alte = aux->esq->altd + 1;
        }
        else
        {
            aux->alte = aux->esq->alte + 1;
        }
        aux = balanceamento(aux);
    }
    else
    {
        aux->dir = inserir(aux->dir, num);
        if (aux->dir->altd > aux->dir->alte)
        {
            aux->altd = aux->dir->altd + 1;
        }
        else
        {
            aux->altd = aux->dir->alte + 1;
        }
        aux = balanceamento(aux);
    }
    return aux;
}

arvore *atualiza(arvore *aux)
{
    if (aux != NULL)
    {
        aux->esq = atualiza(aux->esq);
        if (aux->esq == NULL)
        {
            aux->alte = 0;
        }
        else if (aux->esq->alte > aux->esq->altd)
        {
            aux->alte = aux->esq->alte + 1;
        }
        else
        {
            aux->alte = aux->esq->altd + 1;
        }
        aux->dir = atualiza(aux->dir);
        if (aux->dir == NULL)
        {
            aux->altd = 0;
        }
        else if (aux->dir->alte > aux->dir->altd)
        {
            aux->altd = aux->dir->alte + 1;
        }
        else
        {
            aux->altd = aux->dir->altd + 1;
        }
        aux = balanceamento(aux);
    }
    return aux;
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

void emOrdem(arvore *aux)
{
    if (aux != NULL)
    {
        emOrdem(aux->esq);
        // printf("%d\n", aux->num);
        emOrdem(aux->dir);
    }
}

int main(int argc, char const *argv[])
{
    arvore *raiz = NULL;
    arvore *aux;
    int numeros[M], num, achou;
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
    achou = 0;
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
