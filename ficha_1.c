//1
#include <stdio.h>
#include <stdlib.h>
int quadrado(int n) {

    for (int i=0; i<n;i++)
    {
        for (int j=0; j<n;j++)
        {
            printf("#");
        }
        putchar('\n');
        
    }
}

//2
void xadrez(int n) 
{
    for (int ln=0; ln<n;ln++)
    {
        for (int p=0;p<n;p++)
        {
            if ((ln+p)%2==0) printf("#");
            else printf("_");     
        }
        printf("\n");
    }
}

//3
void vertical(int n) 
{
    for (int i=1;i<=n;i++) // i é o número das linhas ____ n representa a linha onde a altura é máx
    {
        for (int j=1;j<=i;j++) putchar('#'); //j é o nº de carcteres por linha, e nnc é maior que o numero da linha
        printf("\n");
    }//inicia- se o ciclo para o inverso
    for (int k=n;k>0;k--){ //este ciclo não faz nenhuma linha com 3#
        for (int b=k-1;b>0;b--) putchar('#');//b=k-1 faz com que se com que haja menos um # por linha____ evita uma 2ª linha com 3#
        printf("\n");
    }
 
}
int horizontal(int n)
{
    for (int l=1;l<=n;l++)
    {
        for (int sp=n-l;sp>0;sp--)
        {
            putchar(' ');
        }
        for(int c=1;c<=2*l-1;c++){
            putchar('#');
        }
        printf("\n");
    }
}
void main() {
    vertical(5);
    horizontal(5);

}
//4
void circulo(int r)
{
    int c=0;
    for (int i=0;i<=2*r;i++)
    {
        for (int j=0;j<=2*r;j++)
        {
            if (pow(i-r,2)+pow(j-r,2)<=r*r)
            {
                putchar('#');
                c++;
            }
            else putchar(' ');
        }
        putchar('\n');
        
    }
    printf("%d", c);
}