//1
//
//
//
//
//
//5 5 12

//2
void swapM (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void swap(int *x, int *y)
{
    int tmp;
    tmp=*x;
    *x=*y;
    *y=tmp;
    

}
int main() 
{
    int x=3, y=5;
    swap(&x,&y);
    printf("%d %d \n",x,y);
}
//3
void swap(int v[],int i, intj)
{
    int t=v[i];
    v[i]=v[j];
    v[j]=t;

}
int main() 
{
    int x=3, y=5;
    swapM(&x,&y);
    printf("%d %d \n",x,y);
}

//4
void soma(int v[],int N)
{
    int sum=0;
    for (int i=0;i<N;i++)
    {
        sum+=v[i];
    }
    printf("%d", sum);
}
int main()
{
  int v[4]={1,2,3,4};
  soma(v,4);
}

//5
void inverteArray(int v[],int N)
{
    for(int i=0; i<N; i++, N--){
        swap(v, i, N-1);
    }
}
////////////////////////////////////////
int main() {
    // Write C code here
    int a=1;
    int *m=a;
    printf("%d", *(&m));
}
////////////////////////////////////////


//6
int maximum(int v[],int N, int *m)
{
    int r;
    if (N<0) r=-1;
    else
    {
        *m=v[0];
        for (int i=0;i<N;i++)
        {
            if (v[i]>*m) *m=v[i];
            else *m=*m;
        }
        r=0;
	//printf("%d", *m);
    }
	
    return r;
    
}
void main()
{
    int v[4]={1,2,3,4};
    int m;
    
    maximum(v,4,&m);
    printf("%d", m);
}


//maximum sem o apontador

int maximum(int v[],int N)
{
    int m=0;
    int r;
    if (N<0) r=-1;
    else
    {
        for (int i=0;i<N;i++)
        {
            if (v[i]>m) m=v[i];
            else m=m;
        }
        r=0;
    }
    printf("%d", (m));
    
}
void main()
{
    int v[4]={1,1112,13,4};
    
    maximum(v,4);
}




int maximum(int v[],int N, int *m)
{
    int r;
    if (N<0) r=-1;
    else
    {
        *m=v[0];
        for (int i=0;i<N;i++)
        {
            if (v[i]>*m) *m=v[i];
            else *m=*m;
        }
        r=0;
    }
    return r;
}
void main()
{
  int v[4]={1,2,3,4};
  maximum(v,4,*m);
}



//7
void quadrados(int q[], int N)
{
    for (int i=0;i<N;i++)
    {
        q[i]=i;
        
    }
    for (int i=0;i<N;i++)
    {
        q[i]=q[i]*q[i];
        printf("%d ", q[i]);
        
    }
    
}
int main() {
    // Write C code here
    int v[100];
    quadrados(v,4);
}

//8
void pascal2 (int v[], int N){
    for(int i=0; i<N; i++){
        v[i] = 1;
        for(int j=i-1; j>0; j--){
            v[j] += v[j-1];
        }
    }
}