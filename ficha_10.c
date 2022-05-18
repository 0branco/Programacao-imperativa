//1
//a
ABin removeMenor (ABin *a){
    ABin esquerda = NULL;
    if(*a!=NULL){
        while((*a)->esq!=NULL)
            a = &((*a)->esq);
        esquerda = *a;
        *a = (*a)->dir;
    }

    return esquerda;
}

//b
void removeRaiz (ABin *a)
{
    ABin n;
    if((*a)->dir != NULL)
    {
        n = removeMenor(&(*a)->dir);
        n->esq = (*a)->esq;
        n->dir = (*a)->dir;
    }
    else n = (*a)->esq; 
    free(*a);
    *a = n;
}

//c
usando as funçoes anteriores
int removeElem (ABin *a, int x){
    int r = 1;
    while(*a!=NULL && (*a)->valor != x){
        if((*a)->valor < x)
            a = &((*a)->dir);
        else
            a = &((*a)->esq);
    }
    if(*a!=NULL){
        r = 0;
        removeRaiz(a); 
    }

    return r;
}

//ou

int removeElem (ABin *a, int x)
{
    ABin prev;
    while (*a!=NULL &&(*a)->valor !=x)
    {
        prev=(*a);
        if ((*a)->valor >x) a=&((*a)->esq);
        else a=&((*a)->dir )
        
    }
    if ((*a)==NULL) return 1;
    else 
    {
        ABin n=removeMenor(&(*a)->dir);
        n->esq = (*a)->esq;
        n->dir = (*a)->dir;
        if (n-> valor < prev ->valor) prev->esq=n;
        else prev ->dir =n;
        return 0;
    }
}

//2
void rodaEsquerda (ABin *a){
ABin b = (*a)->dir;
(*a)->dir = b->esq;
b->esq = (*a);
*a = b;
}

void rodaDireita (ABin *a){
ABin b = (*a)->esq;
(*a)->esq = b->dir;
b->dir = *a;
*a = b;
}

void promoveMenor(ABin *a)
{
	if ((*a)->esq != NULL)
	{
		promoveMenor (&((*a)->esq));
		rodaDireita(a);
	}
}

void promoveMaior(ABin *a)
{
	if ((*a)->dir != NULL)
	{
		promoveMaior (&((*a)->esq));
		rodaEsquerda(a);
	}
}

