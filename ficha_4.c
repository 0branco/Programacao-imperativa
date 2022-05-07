#include <stdio.h>
#include <string.h>

// 1

int isvowel(char c){
    int r=0;
    if (c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u'|| c=='A'|| c=='E'||c=='I'|| c=='O'|| c=='U') r=1;
    else return r;
    
}
int contaVogais(char *s)
{
    int sum=0;
    for (int i=0;s[i]!='\0';i++)
    {
        if (isvowel(s[i])) sum++;
    }
    return sum;
    printf("%d",sum);
}
int main() {
    char *s="dnoerE";
    printf("%s \n", s);
    contaVogais(s);
}

//2
//a
int retiraVogaisRep (char *s)
{
    char aux[strlen(s)+1];
    int r,w;
    for (r=0,w=0;s[r]!='\0';r++)
    {
        if((isVowel(s[r]))==0  || s[r]!=s[r+1]==1) aux[w++] = s[r];
        else aux[w] = s[r];
    }
    printf("%s \n",aux);
    aux[w] = '\0';
    strcpy (s, aux);
    printf("%d",r-w);
    
}

//b
int retiraVogaisRep (char *s)
{
    int r,w;
    for (r=0,w=0;s[r]!='\0';r++)
    {
        if(s[r]!=s[r+1]==1 || (isVowel(s[r]))==0) s[w++] = s[r];
        else s[w] = s[r];
    }
    
    s[w] = '\0';
    printf("%s \n",s);
    printf("%d",r-w);
    
}

//3
//a
int duplicaVogais (char *s)
{
    int nvog=contaVogais(s);
    char aux[strlen(s)+1+nvog];
    int r, w;
    for(r=0, w=0; s[r]!='\0'; r++){
        aux[w++] = s[r];
        if(isvowel(s[r])) aux[w++] = s[r];
    }
    aux[w] = '\0';
    printf("%s",aux);
}

//b
int duplicaVogais2 (char *s){
    int vogaisrepetidas = contaVogais(s);
    int i = strlen(s) - 1, j = i + vogaisrepetidas;
    s[j+1] = '\0'; 
    while(i>=0){
        if(isVowel(s[i]))
            s[j--] = s[i];
        s[j--] = s[i--];
    }

    return vogaisrepetidas;
}


//PARTE 2
//1
int ordenado (int a[], int N){
    int r = 0, i;

    for(i=0; i<N-1 && a[i]<=a[i+1]; i++);
    if(i==N-1) r = 1;
    printf("%d", r);
    return r;
}
//ou
int ordenado (int v[], int N)
{
    int r=0;
    int max=v[0];
    for (int i=0;i<N-1;i++) 
    {
        if (v[i]>max) max=v[i];
        else max=max;
    }
    if (max==v[N]) r=1;
    return r;
}
//2
void merge (int a[], int na, int b[], int nb, int r[])
{
  int i=0, j=0, w=0;

  while(i<na && j<nb){
    if(a[i]<b[j])
      r[w++] = a[i++];
    else
      r[w++] = b[j++]; 
  }

  while(i<na)
    r[w++] = a[i++];
  while(j<nb)
    r[w++] = b[j++];
}


