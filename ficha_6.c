struct staticStack {
    int tam;
    int values [Max];
} STACK, *SStack;

//1
//a
void SinitStack (SStack *s)
{
    s-> tam=0;
}

//b
int SisEmpty (SStack *s)
{
    int r=0;
    if (s-> tam==0) r=1;
    return r;
    
}

//c
int Spush (SStack *s, int x)
{
    if (s-> tam ==Max) return 1;
    else
    {
        s->values [s->tam]=x
        s-> tam++;
    }
}

//d
int Spop (SStack *s, int *x)
{
    if (s-> tam ==0) return 1;
    else
    {
        *x=s->values[s->tam-1]=0;
        s->tam--;

    
    }
}

//e
int Stop (SStack s, int *x){
    int r=1;
    if(s->tam>0)
    {
        r=0;
        *x = s->values[s->sp-1];
    }

    return r;
}

//2
//a
void SinitQueue (SQueue q)
{
    q-> front =0;
    q-> length=0;
}

//b
int SisEmptyQ (SQueue q)
{
    return (q-> length ==0);
    
}

//c
int Senqueue (SQueue q, int x)
{
    if (s->front + s->length==Max) return 1;
    else
    {
        s->values[s->front + s->length]=x;
        s->length++;
    }
}

//d
int Sdequeue (SQueue q, int *x)
{
    if (s->length==0) return 1;
    else 
    {
        *x= s->values[s-> front]
        s-> front ++;
        s-> length --;
        return 0;
    }    
}

//e
int Sfront (SQueue q, int *x)
{
    if (q-> length ==0) return 1;
    else 
    {
        *x=q->values[s->front];
    }
    return 0;
}



//3
typedef struct dinStack {
int size; // guarda o tamanho do array values
int sp;
int *values;
} *DStack;
typedef struct dinQueue {
int size; // guarda o tamanho do array values
int front;
int length;
int *values;
} *DQueue;




//3 ////1
//a
void DinitStack (DStack s)
{
    s->sp=0;
    s-> size=Max;
    s->values = malloc(sizeof(int)*s->size);
}
int DisEmpty (DStack s)
{
    return (s->sp==0);
}

int dupStack (DStack s){
    int r=1, i;
    int *temp = malloc(sizeof(int)*2*s->size);
    if(temp!=NULL){
        r=0;
        for(i=0; i<s->size; i++)
            temp[i] = s->values[i];
        free(s->values);
        s->values = temp;
        s->size *= 2;
    }

    return r;
}
int Dpush (DStack s, int x){
    int r=0;
    if(s->sp==s->size)
        r = dupStack(s);
    if(r==0)
        s->values[s->sp++] = x;
    return r;
}

int Dpop (DStack s, int *x)
{
    if (s->sp==0) return 1;
    else
    {
        *x=s->values[s->sp--];
    }
    return 0;
}

int push (STACK *s, int x) {
    if(s->size <= s->sp) {
        s->valores = (int*)realloc(s->valores, 2 * s->size * sizeof(int));
        s->size *= 2;
    }
    int N = s->sp++;
    s->valores[N] = x;
    return 0;
}

//d

int Dtop (DStack s, int *x)
{
    int r=1;
    if (s->sp>0) 
    {
        r=0;
        *x=s->values[s->sp-1]
    }
    return 0;
}
/////2
//a
void DinitQueue (DQueue q)
{
    q->size = MAX;
    q->front = 0;
    q->length = 0;
    q->values = malloc(sizeof(int)*q->size);
}

//b
int DisEmptyQ (DQueue q)
{
    return (q->length==0);
}

//c
int Denqueue (QUEUE* q, int x)
{
    if(q->size <= (q->inicio + q->tamanho)) 
    {
        q->valores = realloc(q->valores,2 * q->size * sizeof(int));
        q->size *= 2;
    }
    q->valores[q->inicio + q->tamanho++] = x;
    return 0;
}

//d
int Ddequeue (QUEUE* q, int* x) 
{
    if ( q->tamanho==0) return 1;
    else
    {
        *x=q->valores [q->inicio];
        q->inicio++;
        q->tamanho--;
    }
    return 0;
}

//e
int Dfront (DQueue q, int *x)
{
    if (q-> tamanho ==0) return 1;
    *x=q->valores[q-> front];
    return 0;
}
