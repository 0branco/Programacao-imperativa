//1
void libertaLista (Palavras l){
    Palavras aux = l;
    while(l != NULL){
        l = l->prox;
        free(aux->palavra);
        free(aux);
        aux = l;
    }
}

//2
int  quantasP (Palavras l)
{
    int cnt=0;
    while (l!=NULL)
    {
        cnt++;
        l= l->prox;
    }
    return cnt;
}

//3
void listaPal (Palavras l)
{
    while (l!=NULL)
    {
        printf("%c",l->palavra);
        printf("%d", l->ocorr);
        l=l->prox;
        printf("\n");
    }
}

//4
char * ultima (Palavras l)
{
    char *a;
    if (l!=NULL)
    {
        while (l->prox!=NULL)
            l=l->prox;
        a=l->palavra;
    }
    return a;
}

//5
Palavras acrescentaInicio (Palavras l, char *p)
{
    Palavras nova =malloc(sizeof(struct celula));
    nova-> palavra =strdup(p);
    nova-> ocorr=1;
    nova-> prox =1;
    return nova;
}


//6

//7
//acrescenta um elemento que já ocorreu
Palavras acrescenta (Palavras l, char *p)
{
    int r=0;
    while (l!=NULL && r==0)
    {
        if (l->palavra) {l->ocorr ++; r=1;}
        else
        {
        l=l-> prox 
        }
    }
}

//8
struct celula * maisFreq (Palavras l)
{
    Palavras max=l;
    while (l!=NULL)
    {
        if (l->ocorr > max->ocorr) max=l;
        l=l->prox;
    }
    return max
}