#include<bits/stdc++.h>

using namespace std;
int siz=0;
struct no
{
    int n;
    struct no *prox;
};
typedef struct
{
    struct no *inicio;
}lista;
void create(lista *l)
{
    siz=0;
    l->inicio=NULL;
}
bool Empty(lista q)
{
    if(q.inicio==NULL)return true;
    return false;
}
void inserir(lista *q,int d)
{
    struct no *aux, *atual, *anterior;

    aux=(struct no *)malloc(sizeof(struct no));
    if(aux!=NULL)
    {
        aux->n = d;
        aux->prox=NULL;
        anterior=NULL;
        atual=q->inicio;
        int c=0;
        while(atual!=NULL  && d > atual->n)
        {
            anterior= atual;
            atual = atual->prox;
        }
        if(anterior == NULL)
        {
            aux->prox = q->inicio;
            q->inicio = aux;
        }
        else
        {
            anterior->prox=aux;
            aux->prox=atual;
        }
    }
    siz++;
}
void print(lista l)
{
    struct no *aux;
    aux= l.inicio;
    if(!Empty(l))
    {
        while(aux!=NULL)
        {
            printf("%d\n",aux->n);
            aux=aux->prox;
        }
    }
}
void remover(lista *q,int f)
{
    struct no *aux, *atual, *anterior;
    if(f=q->inicio->n)
    {
        aux=q->inicio;
        q->inicio = (q->inicio)->prox;
        free(aux);
    }
    else
    {
        anterior = q->inicio;
        atual=(q->inicio)->prox;
        while(atual!=NULL && atual->n!=f)
        {
            anterior = atual;
            atual = atual->prox;
        }
        if(atual!=NULL)
        {

            aux= atual;
            anterior->prox = atual->prox;
            free(aux);
        }
    }
    siz--;
}
bool busca(lista q,int val)
{
    struct no *aux;
    aux=q.inicio;
    if(!Empty(q))
    {
        while(aux!=NULL)
        {
            if(aux->n==val)
            {
                return true;
            }
            aux=aux->prox;
        }
    }
    return false;
}
int main()
{
    int n=1;
    lista l;
    create(&l);
    printf("Quantos numeros deseja inserir na lista? \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);
        inserir(&l,a);
    }
    printf("Qual valor deseja retirar? ");
    int xx;scanf("%d",&xx);
    printf("\nLista sem retirar as ocorrencias\n");
    print(l);
    while(busca(l,xx))
    { 
        remover(&l,xx);
    }
   

    printf("\nListas com as ocorrencias retiradas\n");
    print(l);

}
