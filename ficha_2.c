#include <stdio.h>

//1
float multInt1(int n,float m)
{
    float r=0;
    for (int c=1;c<=n;c++)
    {
        r+=m;
    }
    printf("%f",r);

}

//ou

float multInt1_2(int n,float m)
{
    int s=0;
    float r=0;
    do {
       r=r+m;
       s++;
       
    }
    while (s<n);

    printf("%f",r);

}

//ou

float multInt(int n, float m)
{
    int sum=0;
    while (n>0)
    {
        sum=sum+m;
        n--;
    }
    printf("%d", sum);
    return sum;
}

//2
float multInt2(int n, float m){
    float r=0;
    while (n>0)
    {
        if (n%2==1) r+=m;
        else r=r;
        n/=2;
        m=m*2;
    }
    printf("%f", r);
    
}

//3

int mdc(int a, int b){
    if (a>b)
    {
        int div;
        for (int i=1;i<=b;i++)
        {
         if (a%i==0 && b%i==0) div=i;
         else div=div;
        }
        printf("%d", div);
    }
    else mdc(b,a);
}
// ou recursiva e menos eficiente
int mdc1(int a, int b)
{
    int mdc;
    if (a>b) mdc1(b,a);
    else
    {
        if (b%a==0)  mdc =a;
        else mdc1(a-1,b);
    }
    printf("%d", mdc);
}
//4    versao eficiente

int mdc2(int a, int b){  
    while (a>0 && b>0)
    {
        if (a<b) b=b-a;
        else a=a-b;
    }
    printf("%d", (a+b));
}

//5
// forma mais simples
int mdc3(int a, int b){  
    while (a>0 && b>0)
    {
        if (a<b) b=b-a;
        else a=a-b;
    }
    printf("%d", (a+b));
}


int mdc3(int a, int b){  
    while (a>0 && b>0)
    {
        if (a<b) b=b%a;
        else a=a%b;
    }
    printf("%d", (a+b));
}

//6

//a
int fib1 (int n){
    if(n < 2)
        return n;
    else
        return(fib1 (n-1) + fib1(n-2));
}


//b

int fib2 (int n)
{ 
    int a=0;
    int b=1;
    for (int i=0;i<=n;i++)
    {
        b=b+a;
        a=b-a;
        
    }
    printf("%d ",a);

}
//ou 
int fib2 (int n){
    int s=0;
    int a=0;
    int b=1;
    for (int i=0;i<=n;i++)
    {
        s=b;
        b=b+a;
        a=s;
        
    }
    printf("%d ",a);

}