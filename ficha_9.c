typedef struct nodo 
{
int valor;
struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) 
{
ABin a = malloc (sizeof(struct nodo));
if (a!=NULL) 
	{
		a->valor = r; a->esq = e; a->dir = d;
	}
return a;
}

//1
//a
int max(int x, int y){
    return (x>y) ? x : y;
}

int altura (ABin a){
    int r = 0;
    if(a!=NULL)
        r = 1 + max(altura(a->esq), altura(a->dir));
    return r;
}

//ou
int altura (ABin a)
{
    int h,he,hd;
    if (a==0) return 0;
    else
    {
        while (a!=NULL)
        {
            he= altura(a->esq));
            hd= (altura(a->dir));
            if (he>hd) h=he+1;
            else h=hd +1;
        }
    }
    return h;
}
//b
int nFolhas (ABin a)
{
    int r;
    if (a==NULL) return 0;
    if (a->esq==NULL && a->dir==NULL ) return 1;
    else {
        r=folhas(a->esq)+ folhas (a->dir);
    }
    return r;
}
//c
ABin maisEsquerda (ABin a)
{
    while (a->esq!=NULL)
    {
        a=a->esq;
    }
    return a;
}
//d
void imprimeNivel (ABin a, int l)
{
    if (a!=NULL)
    {
        if (n==0) printf("%d", a->valor);
        else
        {
            imprimeNivel(a->esq,l-1);
            imprimeNivel(a->dir,l-1);
        }
    }
}


//e
int procuraE (ABin a, int x)//0 se não ocorre 1 se ocorre
{
    if (a==NULL) return 0;
    if (a->valor == x) return 1;
    else
    {
        procuraE(a->esq,x);
        procuraE(a->dir,x);
    }
}

//2
//a
struct nodo *procura (ABin a, int x)
{
    if (a->valor==x) return a;
    else
    {
        while ((*a)!=NULL && ((*a)->valor!=x))
        {
            if (a)>valor >x) a=a->esq;
            else a=a->dir;
        }
        return a;
    }
}

//b
int nivel (ABin a, int x)
{
    int r=0;
    while (a!=NULL&& a->valor !=x)
    {
        n++;
        if (a)>valor >x) a=a->esq;
        else a=a->dir;
    }
    if (a==NULL) return (-1);
    else return n;
}

//c
void imprimeAte (ABin a, int x){
    if(a!=NULL)
    {
        imprimeAte(a->esq, x);
        if(a->valor<x)
        {
            printf("%d ", a->valor);
            imprimeAte(a->dir, x);
        }
    }
}