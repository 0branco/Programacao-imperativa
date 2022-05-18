typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

int main() 
{
    LInt n1, n2, n3, n4;
    n1 = malloc(sizeof(struct lligada));
    n2 = malloc(sizeof(struct lligada));
    n3 = malloc(sizeof(struct lligada));
    n4 = malloc(sizeof(struct lligada));
    n1->valor = 10;
    n1->prox = n2;
    n2->valor = 20;
    n2->prox = n3;
    n3->valor = 20;
    n3->prox = n4;
    n4->valor = 40;
    n4->prox = NULL;
    LInt l = n1;
    removeAll(&l,20);
    verLista(l);
    return 0;
}



LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}


//1
int length (LInt l)
{
    int c=0;
    while (l!=NULL)
    {
        c++;
        l=l->prox;
    }
    return c;
}
int length (LInt *l)
{
    int c=0;
    LInt list=*l;
    while (list!=NULL)
    {
        c++;
        list=list->prox;
    }
    return c;
}

int length (LInt *l)
{
    int c=0;
    while (*l!=NULL)
    {
        c++;
        l=&((*l)->prox);
    }
    printf(")%d(",c);
    return c;
}
//2
void freeL (LInt l)
{
    while (l)
    {
        LInt temp=l;
        l=l->prox;
        free(temp);
    }
}

//3
void imprimeL (LInt l )
{
    while(l!=NULL)
    {
        printf("%d",l->valor);
        l=l->prox;
    }
}

//4
LInt reverseL (LInt l)
{
    LInt prev= NULL;
    LInt next;
    while (l != NULL)
    {
        next=l->prox;
        l->prox=prev;
        prev=l;
        l=next;
    }
    return prev;
}

//ou
int listTo (LInt l, int v[], int n)
{
    int i=0;
    while (l!=NULL && i<n)
    {
        v[i]=l->valor;
        l=l->prox;
        i++;
    }
    return i;
}
int reverse(int v[], int n)
{
    for(int i = 0; i<n/2; i++)
    {
        int temp = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = temp;
    }
    return n;
}
LInt reverseL (LInt l){
    int n=length (l);
    LInt ini=l;
    int v[n];
    v[n]=listTo(l,v,n);
    v[n]=reverse(v,n);
    int i=0;
    while (l != NULL)
    {
        l->valor=v[i];
        i++;
        l=l->prox;
    }
    return ini;
}
//5
void insertOrd (LInt *a, int x)
{
    LInt novo;
    novo = malloc(sizeof(struct lligada));
    novo -> valor = x;

    while( (*a!=NULL)   &&   ((*a)->valor)  <x)
    {
        a= &((*a)->prox);
    }
    novo->prox=*a;
    *a=novo;
} 
//ou

void insert(LInt *l, int x)
{
    LInt list=*l;
    while (list!=NULL && list->prox->valor<x)
    {
        list=list->prox;
    }
    LInt n= malloc(sizeof(struct lligada));
    n->valor=x;
    n->prox=list->prox;
    list->prox=n;
    
}


//6

int remover (LInt *l , int x){
    while ((*l!= NULL)&& ((*l)->valor != x)) {
		l=&((*l)->prox);
	}
	if (*l == NULL){
		return 1;
	}
    else{
    	*l = (*l)-> prox;
		return 0;
	}	
}

int removeOneOrd(LInt *l, int x) {
    LInt prev = NULL;
    for(;  *l && x != (*l)->valor   ; prev = *l, l = &((*l)->prox)   );
    if((*l)==NULL) return 1;
    else prev->prox = (*l)->prox;
    return 0;
}



//7
void merge (LInt *r, LInt a, LInt b){
    while(a!=NULL && b!=NULL)
    {
        if(a->valor > b->valor)
        {
            *r = b;
            b=b->prox;
        }
        else
        {
            *r = a;
            a=a->prox;
        }
        *r = (*r)->prox;
    }

    while(a!=NULL){
        *r = a;
        a=a->prox;
        *r = (*r)->prox;
    }
    while(b!=NULL){
        *r = b;
        b=b->prox;
        *r = (*r)->prox;
    }
}

//8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l!=NULL){
        if(l->valor < x){
            *mx = l;
            mx = &((*mx)->prox);
        }
        else
        {
            Mx = &l;    //l é um endereço para o qual mx aponta
            Mx = &((*Mx)->prox);
        }
        l = l->prox;
    }
    *mx = NULL; *Mx = NULL;
}

void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
    if(!l) return;
    if(l->valor < x) {
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    }
    else {
        (*Mx) = l;
        (*mx) = NULL;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}

//9
LInt parteAmeio (LInt *l)
{
    int i=0;
    LInt init,beg=*l;
    init->valor=(*l)->valor;
    init->prox = NULL;
    int len= length(*l)/2;
    while (i<len)
    {
        init->prox=&(*l)->valor;
        *l=(*l)->prox;
        i++;
    }
    init ->prox=NULL;
    return beg;
}

//10
int removeAll(LInt *l, int x) {
    int rem = 0;
    LInt prev = NULL;
    while(*l !=NULL) 
    {
        if((*l)->valor == x) {
            if(prev==NULL) (*l) = (*l)->prox;
            else prev->prox = (*l)->prox;
            rem++;
        }
        else 
        {
            prev = (*l);
            l = &((*l)->prox);
        }
    }
    return rem;
}
//11
int removeDups(LInt *l) {
    int rem = 0;
    for(;*l!=NULL; l = &((*l)->prox)) {
        LInt prevAux = (*l), aux = (*l)->prox;
        for(; aux!=NULL; aux = prevAux->prox) {
            if(aux->valor == (*l)->valor) {
                prevAux->prox = aux->prox;
                rem++;
                free(aux);
            }
            else prevAux = aux;
        }
    }
    return rem;
}

//12
int removeMaiorL (LInt *l)
{
    int c=max (l);
    LInt next=(*l)->prox, list=*l, temp;
    if ((*l)->valor==c) *l=(*l)->prox;
    else
    {
        while (next->valor!=c)
        {
            list=next;
            next=next->prox;
        }
        list->prox=next->prox;
    }
    return c;
}



//13
void init (LInt *l)
{
    LInt temp;
    while((*l)->prox != NULL)
    {
            l = &((*l)->prox);
    }
    (*l)=NULL;
}


void init (LInt *l){
    LInt temp;
    while((*l)->prox != NULL)
    {
            l = &((*l)->prox);
    }
    temp = *l;
    *l = (*l)->prox;
    free(temp);
}
//14
void appendL (LInt *l, int x )
{
    LInt novo = malloc(sizeof(struct lligada));
    new->valor=x;
    new->prox=NULL;
    if(   *l ==NULL  ) 
	(*l) = novo;
    else 
    {
        for(;(*l)->prox; l = &((*l)->prox));
        (*l)->prox = new;
    }
}

//ou

void appendL (LInt *l, int x)
{
    LInt n=malloc(sizeof(struct lligada));
    n->valor =x;
    n->prox=NULL;
    while ((*l)->prox !=NULL)
    {
        l=&((*l)->prox);
    }
    (*l)->prox=n;
}


//15
//o jbb era capaz de nao curtir
void concatL (LInt *a, LInt b)
{
    while (*a!=NULL)
    {
        a=&((*a)->prox);
    }
    *a=b;
}
//16
LInt cloneL (LInt l )
{
    LInt inicio=NULL, list=NULL;
    while (l!=NULL)
    {
        LInt n=malloc(sizeof(struct lligada));
        n->valor=l->valor;
        n->prox=NULL;
        if (inicio==NULL) inicio=list=n;
        else list->prox=n;
        l=l->prox;
        list =list->prox;
    }
    return inicio;
}

//17
LInt cloneRev (LInt l){
	LInt prev=NULL;
	while(l!=NULL){
		LInt new=malloc(sizeof(struct lligada));
		new->valor=l->valor;
		new->prox=prev;
		prev=new;
		l=l->prox; 
	}
	return prev;
}

//18

int maximo (LInt l) //tem uma iteração desnecessaria
{
    int m=l->valor;
    while (l!=NULL)
    {
        if (m>l->valor) m= l->valor;
        l=l->prox;
    }
    return max;
}

//ou 
int maximo (LInt l)
{
    int m=l->valor;
    l=l->prox;
    while (l!=NULL)
    {
        if (m>l->valor) m= l->valor;
        l=l->prox;
    }
    return m;
}

//19
int take (int n, LInt *l) {
	int length=0;
	while( ((*l) != NULL) && (length<=n)){
		length++;
		if(length<=n) l=&((*l)->prox);	//porque assim que length>n,nao andamos um nodo para a frente e alteramos já esse nodo;
	}
	if (length>n){
		free(*l);
		(*l)=NULL;
		return n;
	}
	else return length;
}

//20
int drop (int n, LInt *l)
{
    LInt temp;
    int i=0;
    while (*l!=NULL && n!=0)
    {
        temp=*l;
        
        *l=((*l)->prox);
        free(temp);
        n--;
        i++;
    }
    return i;
}

//21
LInt NForward (LInt l, int N)
{
    while(N!=0)
    {
        l = l->prox;
        N--;
    }
    return l;
}

//22
int listToArray (LInt l, int v[], int n)
{
    int i=0;
    while (l!=NULL && i<n)
    {
        v[i]=l->valor;
        l=l->prox;
        i++;
    }
    return i;
}

//23
LInt arrayToList (int v[], int n)
{
    LInt inicio=NULL;
    LInt list=NULL;
    for (int i=0;i<n;i++)
    {
        LInt nova=malloc(sizeof(lligadas));
        nova ->valor =v[i];
        nova->prox=NULL;


        if (inicio=NULL) inicio=list=nova;
        else list=list->prox=nova
    }
    return inicio;
}

//24
LInt somasAcL (LInt l)
{
    int ac=0;
    LInt inicio=NULL;
    LInt list=NULL;
    while (l!=NULL)
    {
        ac+=l->valor;
        LInt nova =malloc(sizeof(lligadas));
        nova->valor = ac;
        nova->prox=NULL;
        if (inico == NULL) inicio=list=nova;
        else list=list->prox=nova;
    }
    return inicio;
}


//alterar no mesmo array


LInt somasAcL (LInt l)
{
    int r=0;
    LInt inicio=l;
    while (l!=NULL)
    {
        r+=l->valor;
        l->valor=r;
        l=l->prox;
    }
    return inicio;
}


//25
void remreps (LInt l)
{
    LInt temp;
    if (l!=NULL)
    {
    while (l->prox!=NULL)
    {
        if (l->prox->valor==l->valor) 
        {
            temp=l->prox;
            l->prox=l->prox->prox;
            free(temp);
            
        }
        else l=l->prox;
        
    }
    }
}
//26

LInt rotateL (LInt l){
    if (l==NULL || l->prox ==NULL) return l;
    else
    {
        LInt i=l;
        LInt list=i->prox;
        while (l->prox!=NULL) l=l->prox;
        
        l->prox =i;
        i->prox =NULL;
        return list;
        
    }
    
}


//27

LInt parte (LInt l)
{
    LInt inicio=NULL, list =NULL;
    while (l!=NULL && l->prox!=NULL)
    {
        if (inicio==NULL) inicio =list=l->prox;
        else list = list->prox = l->prox;

        l = l->prox = l->prox->prox;
        list->prox = NULL;
    }
    return inicio;
}
/////////
//ABint//
/////////
//28
int altura (ABin a){
	int he,hd;
	if(a==NULL) return 0;
	else
	{
		he =altura(a->esq);
		hd=altura(a->dir);
		if(he<hd) h=hd+1;
		else h= he+1;
	}
	return h;
}

//29
ABin cloneAB (ABin a) 
{
    if (a==NULL) return NULL;
    ABin nova =malloc(sizeof(struct nodo));
    nova-> valor = a->valor;
    nova-> esq = cloneAB(a->esq);
    nova-> dir = cloneAB(a->dir);
    return nova;
}


//30
void mirror (ABin *a) 
{
    if (*a!=NULL) 
    {
    ABin temp=(*a)->esq;
    (*a)->esq=(*a)->dir;
    (*a)->dir=temp;
    mirror(&((*a)->esq));
    mirror(&((*a)->dir));
    }
}


//31
void inorder (ABin a, LInt *l)
{  
	if(a==NULL) (*l)=NULL;
	else{
		LInt new=malloc(sizeof(struct lligada));
		if(a->esq!=NULL) inorder(a->esq,l);
		
		new->valor=a->valor;
		new->prox=NULL;
		
		if((*l)==NULL) (*l)=new;
		else
		{
			while((*l)->prox!=NULL) l=&((*l)->prox);
			(*l)->prox=new;
		}
		if(a->dir!=NULL) inorder(a->dir,l);
	}
}


//32
void preorder (ABin arv, LInt *l)
{
    if(arv!=NULL)
    {
        *l = malloc(sizeof(struct nodo));
        (*l)->valor = arv->valor;
        preorder(arv->esq, &((*l)->prox));
        while(*l!=NULL)
            l = &((*l)->prox);
        preorder(arv->dir, l);
    }
    else
        (*l) = NULL;
}


//33


//34
//-1 se o pt chegar a NULL, entao nao está na arv
//raiz no nível 1

int depth (ABin a, int x)
{
    int r = -1;
    if(a!=NULL){
        if(a->valor == x)
            r = 1;
        else{
            int rEsq = depth(a->esq, x);
            int rDir = depth(a->dir, x);
            if(rEsq==-1 && rDir==-1)
                r = -1;
            else if(rEsq==-1)
                r = 1 + rDir;
            else if(rDir==-1)
                r = 1 + rEsq;
            else
                r = (rEsq < rDir) ? 1 + rEsq : 1 + rDir;
        }
    }

    return r;
}

//ou

int depth (ABin a, int x){
	int esq,dir;
	if(a==NULL) return -1;
	else 
	{
		if(a->valor==x)return 1;
		esq=depth(a->esq,x);
		dir=depth(a->dir,x);
	}
	if(esq>0 && dir>0) //aparece nos dois lados
	{
	    if(esq>dir) return dir+1;
	    else return esq+1;

	} //aparece apenas num dos lados
	else if(esq<0 && dir>0) return dir+1;
	else if(dir<0 && esq>0) return esq+1;
}

//35
int freeAB (ABin a){
	int n=0;
	if (a==NULL) return n;
	else
	{
		free(a);
		n = 1+ freeAB(a->esq) + freeAB(a->dir);
	}
	return n;
}

//ou
int freeAB (ABin a){
    int r = 0;
    if(a!=NULL){
        r += freeAB(a->esq);
        r += freeAB(a->dir);
        free(a);
        r++;
    }

    return r;
}
//36
int pruneAB (ABin *a, int l)
{
	int n;
	if((*a)==NULL) return 0;//caso de paragem
	
	if (l==0) //elimina os elementos
	{
		n = 1 + pruneAB(&((*a)->esq),l) + pruneAB(&((*a)->dir),l);
        free(*a);
        (*a) = NULL;
	}
	
	//caso até chegar ate profundidade l
	else n = pruneAB(&((*a)->esq),l - 1) + pruneAB(&((*a)->dir),l - 1);
	return n;
}

//37
int iguaisAB (ABin a, ABin b)
{
    int r = 0;
    if(a==NULL && b==NULL)
        r = 1;
    else if(a!=NULL && b!=NULL)
    {
        r = a->valor == b->valor;
        if(r!=0)
        {
            r = r && iguaisAB(a->esq, b->esq);
            r = r && iguaisAB(a->dir, b->dir);
        }
    }
    re


//38
LInt nivelL (ABin a, int n){
	if(a ==NULL) return NULL;
	if(n==1){
		LInt new=malloc(sizeof(struct lligada));
		new->valor=a->valor;
		new->prox=NULL;
		return new;
	}
	else {
		LInt l1,l2;
		l1=nivelL(a->esq,n-1);
		l2=nivelL(a->dir,n-1);
		if(l1==NULL) return l2;
		if(l2==NULL) return l1;
		else{
			LInt temp=l1;
			while(temp->prox !=  NULL) temp=temp->prox;
			temp->prox=l2;
			return l1; 
		}
	}
}

//39
int nivelV (ABin a, int n, int v[]){
	int i=0;
	if(a==NULL) return 0;
	if(n==1){
		v[i]=a->valor;
		return i+1;
	}
	else {
		int e= nivelV(a->esq,n-1,v);
		int d= nivelV(a->dir,n-1,v+e);
		return e+d;
	}
}


//40
int dumpAbin (ABin a, int v[], int n)
{
	int r=0;
	if (a==NULL || n<=0) return 0;
	else
	{
	     dumpAbin (a->esq, v, n);
	     if (n>r)
	     {
	           v[r]=a->valor;
	           r+=dumpAbin (a->dir,v+r,n-r);
	      }
        }
	return r;
}
//41
ABin somasAcA (ABin a){
    ABin new = NULL;
    if(a!=NULL){
        ABin esq = somasAcA(a->esq); //chamadas recursivas
        ABin dir = somasAcA(a->dir);
        new = malloc(sizeof(struct nodo));
        new->dir = dir;new->esq = esq; 
        
        if(esq!=NULL && dir!=NULL)
            new->valor = a->valor + esq->valor + dir->valor;
        else if(esq!=NULL)
            new->valor = a->valor + esq->valor;
        else if(dir!=NULL)
            new->valor = a->valor + dir->valor;
        else
            new->valor = a->valor;
    }

    return new;
}

//42

int contaFolhas (ABin a) {
    int r=0;
    if (a!=NULL)
    {
        if(a->esq==NULL && a->dir==NULL) r++;
        else r+=contaFolhas(a->esq)+contaFolhas(a->dir);
    }
    return r;
}
//ou
//não dá
int contaFolhas (ABin a) {
    if (a==NULL) return 0;
    if(a->esq==NULL && a->dir==NULL) return 1;
    if (a->esq!=NULL || a->dir!=NULL) return 0;
    else
    {
        int e= contaFolhas(a->esq);
        int d=contaFolhas(a->dir);
        
        return 1+ e+d;
    }
}

//43
ABin cloneMirror (ABin a)
{
ABin clone =cloneAB(a);
ABin final =mirror(clone);
return final;
}

//44
int addOrd (ABin *a, int x){
	if((*a)==NULL)                          //arv vazia
	{
		ABin new=malloc(sizeof(struct nodo));
		new->valor=x;
		new->esq=new->dir=NULL;
		(*a)=new;
		return 0;
	}
	if((*a)->valor ==x) return 1;           //igual retorna 1

	if((*a)->valor > x) return addOrd(&((*a)->esq),x);
	else return addOrd(&((*a)->dir),x);
}

//45
int lookupAB (ABin a, int x) 
{
    while (a!=NULL && a->valor!=x)
    {
        if (a->valor >x) a=a->esq;
        else a=a->dir;
    }
    if (a==NULL)return 0;
    else return 1;
}
//recursiva
int lookupAB (ABin a, int x) 
{
    if (a==NULL) return 0;
    if (a->valor ==x) return 1;
    else
    {
        if (a->valor >x) lookupAB(a->esq,x);
        else lookupAB(a->dir,x);
    }
}
//para árvore binaria normal
int lookupAB (ABin a, int x) 
{
    if (a==NULL) return 0;
    if (a->valor ==x) return 1;
    else
    {
        return (lookupAB(a->esq,x) ||lookupAB(a->dir,x));
    }
}



//46
//para arvore não de procura
int depthOrd (ABin a, int x) {
    int d=1;
    if (a==NULL) return -1;
    if (a->valor==x) return d;
    else
    {
        d++;
        return depthOrd(a->esq,x) || depthOrd(a->dir,x);
    }
    return d;
}

//ou
int depthOrd (ABin a, int x) {
    int i =1;
    while (a!=NULL && a->valor !=x)
    {
        i++;
        if (a->valor>x) a=a->esq;
        else a=a->dir;
    }
    if (a==NULL) return -1;
    else return i;
    
}

//47
int maiorAB (ABin a) 
{
    while (a->dir!=NULL) a=a->dir;
    return a->valor;
}

//48
void removeMaiorA (ABin *a)
{
    if(!(*a)->dir) {
        ABin temp = (*a);
        free(*a);
        (*a) = temp->esq;
    }
    else removeMaiorA(&((*a)->dir));
}

//49
int quantosMaiores (ABin a, int x)
{
	if(a == NULL) return 0;
	if(a->valor <= x) return quantosMaiores(a->dir,x);
	else return 1 + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x);
}

//50
void listToBTree (LInt l, ABin *a){
	ABin new= malloc(sizeof(struct nodo));
	int meio = length(l)/2;
	LInt temp = l, prev =  NULL;
	int i;
	for(i=0; i < meio; i++)
	{
		prev = temp;
		temp = temp ->prox;
	}

	new->valor= temp->valor;
	new->esq = new->dir = NULL;
	if(prev != NULL) prev->prox = NULL;

	if(l != NULL) listToBTree(l,&(new->esq));
	if(temp->prox != NULL) listToBTree(temp->prox,&(new->dir));

	(*a) = new;
}
//51

 int dumpAbin (ABin a, int v[], int N){
    int r = 0, esq, dir;
    if(a!=NULL && N>0){
        esq = dumpAbin(a->esq, v, N);
        if(esq < N){
            v[esq] = a->valor;
            dir = dumpAbin(a->dir, v+1+esq, N-1-esq);
            r += 1 + esq + dir;
        }else
            r = N;
    }

    return r;
}

int tam(ABin a)
{
    if (a==NULL) return 0;
    else return (1+tam(a->esq)+tam(a->dir));
}

int ord(int v, int n)
{
    for (int i=0;i<n&& v[i]<v[i+1];i++);
    if (i==n) return 1;
    else return 0;
}

//funcao principal
 int deProcura (ABin a) 
{
    int t=tam(a);
    int v[t];
    int k=dumpAbin(a,v,t);
    int f=ord(v,t);
    return f;
}
