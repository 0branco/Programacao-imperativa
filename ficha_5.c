//1
int nota (Aluno a){
    int i, notaF = 0;
    float somaMiniT = 0;
    for(i=0; i<6; i++) 
        somaMiniT += a.miniT[i];
    
    somaMiniT = (somaMiniT * 20) / 12;

    if(somaMiniT >= 8 && a.teste >= 8){
        notaF = round (somaMiniT * 0.3 + a.teste * 0.7);
    }
    printf("%d", notaF);
    return notaF;
}

//2
typedef struct aluno {
int numero;
char nome[100];
int miniT [6];
float teste;
} Aluno;

int procuraNum (int num, Aluno t[], int N)
{
    int x=0;
    for (int i=0;i<N;i++)
    {
        if (num== t[i].numero) x=i;
    }
    return x;
}
int main() 
{
    struct aluno p[]={{2222, "J", {2,2,2,1,0,0}, 14.5},{7777, "M", {2,2,2,2,2,1}, 18.5}};
    procuraNum(77077,p,2);
}

//3
void ordenaPorNum (Aluno t [], int N)
{
    int min;
    Aluno temp;
    for (int i=0;i<N;i++)
    {
        min=i;
        for (int j=i+1;j<N;j++) if(t[i].numero>t[j].numero)  min=j;
        temp=t[i];
        t[i]=t[min];
        t[min]=temp;
        
    } 
}
int main() 
{
    struct aluno p[]={{4444, "Andre", {2,1,0,2,2,2}, 10.5}
    ,{2222, "Joana", {2,2,2,1,0,0}, 14.5}
    ,{7777, "Maria", {2,2,2,2,2,1}, 18.5}
    ,{3333, "Paulo", {0,0,2,2,2,1}, 8.7}};
    ordenaPorNum(p,4);
}

//4
void criaIndPorNum (Aluno t [], int N, int ind[N])
{
//vê quantos elementos sao maiores que t[i].numero
    for (int i=0;i<N;i++)
    {
        int c=0;
        for (int j=0;j<N;j++) if (t[j].numero > t[i].numero) c++;
        ind[i]=c;
    }
    //for (int k=0;k<N;k++) printf("%d", ind [k]);
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
//funçao para ordenar um array de inteiros

int f(int a[], int l)    
{    
    int temp = 0;
    for (int i = 0; i < l; i++) {     
        for (int j = i+1; j < l; j++) {    
           if(a[i] > a[j]) {    
               temp = a[i];    
               a[i] = a[j];    
               a[j] = temp;    
           } 
        }     
    }
}
