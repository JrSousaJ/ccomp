#include<bits/stdc++.h>

using namespace std;
struct no
{
    struct no *esq;
    struct no *dir;
    int n;
};
typedef struct no *Arvore;
void insertNode(Arvore *t, int d)
{
    if (*t == NULL)
    {
        *t = (struct no*) malloc(sizeof(struct no));
    if ( *t != NULL )
    {
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->n = d;
    }
    else
        printf("Memoria insuficiente");
    }
    else
        if (d < (*t)->n)
            insertNode(&(*t)->esq, d);
    else
        if (d > (*t)->n)
            insertNode(&(*t)->dir, d);
        else
            printf("Duplicacao de no");
}
void preorder(Arvore t)
{
    if(t!=NULL)
    {
        printf("%c\n",t->n);
        preorder(t->esq);
        preorder(t->dir);
    }
}
void inOrder(Arvore t)
{
    if(t!=NULL)
    {
        inOrder(t->esq);
        printf("%c", t->n);
        inOrder(t->dir);
    }
}
void posOrder(Arvore t)
{
    if (t != NULL)
    {
        posOrder(t->esq);
        posOrder(t->dir);
        printf("%c", t->n);
    }
}
void sucessor(Arvore a,int nx)
{
	if(a==NULL)return ;
	if(a->n==nx)
	{
			if(a->dir!=NULL)printf("Seu sucessor eh %d\n",a->dir->n);
			else printf("Nao possui sucessor\n");
	}
	sucessor(a->dir,nx);
	sucessor(a->esq,nx);
}
int main()
{
    Arvore a = NULL;
    printf("Quer inserir quantos valores? \n");
    int x;scanf("%d",&x);
    while(x--)
    {
        int aa;scanf("%d",&aa);
        insertNode(&a,aa);
    }
    int xx;printf("Qual o no? \n");
    scanf("%d",&xx);
  	sucessor(a,xx);
}
