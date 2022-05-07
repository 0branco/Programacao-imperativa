typedef struct slist {
int valor;
struct slist * prox;
} * LInt;
LInt newLInt (int x, LInt xs) {
LInt r = malloc (sizeof(struct slist));
if (r!=NULL) {
r->valor = x; r->prox = xs;
}
return r;
}


//1 Stacks
typedef LInt Stack;
void initStack (Stack *s)
{
    (*s)=NULL;
}

int SisEmpty (Stack s)
{
    int r;
    if ((s)==NULL) r=0;
    else r=1;
    return r;
}


int push (Stack *s, int x)
{
    LInt s1;
    s1 = malloc(sizeof(struct slist));
    s1->valor=x;
    s1->prox=NULL;
    while((*s)->prox!=NULL) *s= (*s)->prox;
    (*s)->prox=&s1;
}


int pop (Stack *s, int *x)
{
    LInt temp;
    if (*s==NULL) return 0;
    else 
    {
        while((*s)->prox!=NULL) *s= (*s)->prox;// s = &((*s)->prox)
        temp = *s;
        free(temp);
        return 1;
    }
}

int top (Stack s, int *x)
{
    if (s==NULL) return 0;
    else
    {
        while (s->prox != NULL)  s= s->prox;
        *x=s->valor;
        return 1;
    }
}

//2
void initQueue (Queue *q)
{
    
}

//3

//4
typedef struct dlist {
int valor;
struct dlist *ant, *prox;
} *DList;
typedef struct {
DList back, front;
} Deque;


DList newDList (int x, DList ant, DList prox){
    DList new = malloc(sizeof(struct dlist));
    if(new!=NULL)
    {
        new->valor = x;
        new->ant = ant;
        new->prox = prox;
    }
    return new;
}

