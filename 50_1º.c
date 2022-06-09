//1
void exe1(){
    int max, num;
    scanf("%d", &num);
    max = num;
    while(num != 0){
        if(num > max)
            max = num;
        scanf("%d", &num);
    }
    printf("max: %d ", max);
}

//2
void exe2()
{
    double soma=0; 
    int cont=0, num;
    scanf("%d", &num);
    while(num != 0){
        soma += num;
        cont++;
        scanf("%d", &num);
    }
    printf("%f", soma/cont);
}

//3
void exe3(){
    int max, num;
    scanf("%d", &num);
    max = num;
    if(num!=0){
        int segundoMax;
        scanf("%d", &num);
        if(num > max){
            segundoMax = max;
            max = num;
        }else
            segundoMax = num;
        while(num!=0){
            if(num > max){
            segundoMax = max;
            max = num;
        }else if(num > segundoMax)
            segundoMax = num;
            scanf("%d", &num);
        }
        printf("%d", segundoMax);
    }
}



//4
int bitsUm (unsigned int n)
{
    for (int i=0;n!=0;n/=2)
    {
        if (n%2!=0) i++;
        else i=i;  
    }
    return i;
  
}

//5
int trailingZ (unsigned int n) 
{
    int cnt=0;
    while (n!=0)
    {
        if (n%2==1) break;
        else cnt++;
        n/=2;
    }
    return cnt;
}

//6
int qDig (unsigned int n)
{
    int i=0;
    while (n!=0)
    {
        i++;
        n=n/10;
    }
    return i;
}

//7


//8
char *strcpy (char *dest, char source[])
{
    for (int i=0;source[i]!='\0';i++)
    {
        dest[i]=source[i];
    }
    dest[i]='\0';
    return dest;
}


//9
int mystrcmp (char s1[], char s2[])
{
    int i=0;
    while (s1[i]!='\0' && s1[i]==s2[i]) i++;
    return s1[i]-s2[i];
}



//10
char *mystrstr (char s1[], char s2[]) {
    int i,j, k;
    char *r = NULL;

    if(s2[0]=='\0')
        r = s1;
    else{
        for(i=0; s1[i]!='\0' && r==NULL; i++){
            for(j=0, k=i; s2[j]!='\0' && s1[k]==s2[j]; j++, k++);
            if(s2[j]=='\0') r = s1 + i;
        }
    }
    return r;
}

//11 
int comprimento(char s1[])
{
    int i;
    for(i=0; s1[i] != '\0'; i++);
    return i;
}


void strrev (char s[])
{
    int l= comprimento(s);         //OU USAR strlen()
    char s2[l];
    for (int i=0; i<l; i++) s2[i]=s[l -i-1];  
}

int main() 
{
    char* a="abc";
    strrev(a);
}

//12
int isVowel (char c){
    int r = 0;
    char vogais[11] = "aeiouAEIOU";
    for(int i=0; vogais[i]!='\0' && r==0; i++){
        if(vogais[i] == c)
            r = 1;
    }

    return r;
}

void strnoV (char s[])
{
    int i, j;

    for(i=0, j=0; s[i]!='\0'; i++){
        if(isVowel(s[i])==0)
           s[j++] = s[i];
    }
    s[j] = '\0';
}

//14
char charMaisfreq (char s[]){
    int contaVezesMax; //é o contador geral
    char contaChar;
    for(int i=0; s[i]!='\0'; i++) //s[i] é para percorrer o array a 1a vez  
    {
        int contaVezes=0; //quantas vezes s[i] aparece
        for(int j=0; s[j]!='\0'; j++) //s[j] é para contar quantas vezes o s[i]
        {
            if(s[i]==s[j]) contaVezes++;
        }
        if(contaVezes > contaVezesMax) //compara com o cnt especifico de i
        {
            contaVezesMax = contaVezes;
            contaChar = s[i];
        }
    }
    printf("%c",contaChar);

    return contaChar;
}

//15
int iguaisConsecutivos (char s[])
{
    int r=0;
    for (int i=0;s[i]!='\0';i++)
    {
        for (int j=i;s[j]==s[i];j++)
        {
            if ((j-i+1)>r) r=(j-i+1);
            else r=r;
        }
        
    }
    return r
}


int main() 
{
    char s[9]= "aabccccccaac";
    iguaisConsecutivos (s);
}

//16
int compPrefixoSemRep (char s[]){
    int i, j, r=0;
    for(i=0; s[i]!='\0'; i++){
        for(j=0; s[j]!=s[i]; j++);

        if (j!=i) return r;
        else r++;
    }

    return r;
}

int difConsecutivos (char s[]){
    int r=0, t, i;
    for(i=0; s[i]!='\0'; i++){
        t = compPrefixoSemRep(s+i);
        if (t > r) r=t;
    }

    return r;
}

//17
int maiorPrefixo (char s1 [], char s2 [])
{
    int r=0;
    for(int i=0; s1[i]!='\0'; i++)
    {
        int cmp=1;
        for(int j=0; s2[j]!='\0' && s2[j+i]==s1[i]; j++)
        {
            cmp++;
            
        }
        if (r<=cmp) r=cmp;
        else r=r;
    }
    printf("%d",r);
    return r;
    
}

//19

int sufPref (char s1[], char s2[]) {
    int ans = 0, i, j = 0;
    for(i = 0; s1[i]; i++) {
        if(s1[i] == s2[j++]) ans++;
        else ans = j = 0;
    }
    printf("%d", ans);
    return ans;
}

//20
int contaPal (char s[]){
    int i, cont = 0;
    for(i=0; s[i]!='\0'; i++){
        if(s[i]!=' ' && s[i]!='\n' && (s[i+1]==' ' || s[i+1]=='\0'))
            cont++;
    }
    return cont;
}


//21
int ehvogal(char x)
{
    char *s="aeiouAEIOU";
    for (int i=0;s[i]!='\0';i++)
    {
        if (x==s[i]) return 1;
        else return 0;
    }
}
int contaVogais (char s[])
{
    int r=0;
    for (int i=0;s[i]!='\0';i++) if (ehvogal(s[i])) r++;
    return r;
}

//22
int contida (char a[], char b[]) 
{
    int cont = 1;
    for(int i = 0; a[i]; i++)  
	{
        int pertence = 0;
        for(int j = 0; b[j]; j++) 
	{
            if(a[i] == b[j]) pertence = 1;
        }
        if(pertence==0) 
	{
            cont = 0;
            break;
        }
    }
    return cont;
}

//23
int palindorome (char s[])
{
	int n=strlen(s);
	int f=1;
	for (int i=0;i<n/2;i++)
	{
		if (s[i]!=s[n-i-1]) return 0;
	}
	return f;
}

//24
int remRep (char x[]){
    int i, j;
    for(i=0, j=0; x[i]!='\0'; i++){
        if(x[i]!=x[i+1])
            x[j++] = x[i];
    }

    x[j] = '\0';

    return j;
}

//25
int limpaEspacos (char t[])
{
    int i, j;
    for (i=0,j=0;t[i]!='\0'; i++)
    {
        if (t[i]==' ' && t[i]==t[i+1]) t[j++]= t[i];
        else t[j]=t[i];
    }
    t[j]='\0';
    printf("%s", t);
    return j;
}

//26
void insere (int v[], int N, int x){
    int i, j, flag=0;
    for(i=0; i<N && flag==0; i++){
        if(v[i]>x){
            for(j=N; j>i; j--)
                v[j] = v[j-1];
            v[i] = x;
            flag = 1;
        }
    }
}



//27
void merge (int r [], int a[], int b[], int na, int nb){
    int i=0,j=0, w=0;

    while(i<na && j<nb){
        if(a[i] < b[j])
            r[w++] = a[i++];
        else
            r[w++] = b[j++];
    }
    while(i<na)
      r[w++] = a[i++];
    while(j<nb)
      r[w++] = b[j++];

}

//28
                        
int crescente (int a[], int i, int j){
    int m, r=1;

    for(m=i; m<j && r==1; m++){
        if(a[m] > a[m+1])
            r=0;
    }
    return r;
}

//29
// funçao com foco nos positivos
int retiraNeg (int v[], int N) {
    int i = 0;
    while(i < N) {
        if(v[i] < 0) {
            for(int j = i; j < N - 1; j++) v[j] = v[j + 1];
            N--;
        }
        else i++;
    }
    return N
}

//31
int maisFreq (int v[], int N)
{
    int c=0,m=0;
    for (int i=0;i<N-1;i++)
    {
        int a=i;
        while (v[i]==v[i+1]) {c++; i++;}
        if(m<c)
        {
            m=c;
            int j=v[i];
            printf("%d ", j);
        }
        c=1;
    }
    
}
//ou
int menosFreq (int v[], int N)
{
    int c=1,m=0;
    int ind;
    for (int i=0;i<N;i++)
    {
        int j=i;
        while (v[j]==v[i])
        {
            c++;
            j++;
        }
        if (c>m) 
        {
            ind =i;
            m=c;
        }
        c=1;
        
    }
    int val=v[ind];
    return val;
}

//32
int maxCresc (int v[], int N)
{
    int m=0;
    for (int i=0;i<N-1;i++)
    {
        int c=1;
        while(v[i]<=v[i+1])
        {
            c++;
            i++;
        }
        if (c>m) m=c;
    }
    return m;
    
}

//33
int elimRep (int v[], int n){
    int i, j, k;
    for(i=0; i<n; i++){
        j=i+1;
        while(j<n)
        {
            if(v[i]==v[j])
            {
                for(k=j; k<n; k++) v[k] = v[k+1];
                n--;
            }
            else j++;
        }
    }
    return n;
} 

//34
int elimRepOrd (int a[], int n)
{    
    for (int i=0;i<n-1;i++)
    {
        int j=i+1;
        while(a[j]==a[i])
        {
            a[j]=a[j+1];
            j++;
            n--;
        }
    }
    return n;
}
//ou
int elim (int v[], int N){
    int e = 0, l;
    for(l=1; l<N; l++){
        if(v[l]!=v[e]){
            e++;
            v[e] = v[l];
        }
    }

    e++;

    return e;
}


//35
int comunsOrd (int a[], int na, int b[], int nb)
{
    int c=0;
    int i=0, j=0;
    while (i<na && j<nb)
    {
        if (a[i]>b[j]) j++;
        else if (a[i]<b[j]) i++;
        else 
        {
            c++;
            i++;
            j++;
        }
    }
    return c;
}

//36
//com funçao auxiliar
int elem(int a,int s[], int n)
{
    for (int i=0;i<n;i++)
    {
        if ( s[i]==a) return 1;
        
    }
    return 0;
}

int comunsOrd (int a[], int na, int b[], int nb)
{
    int c=0;
    for (int i=0;i<na;i++)
    {
        if (elem (a[i],b,nb)==1) c++;
    }
    printf("%d", c);
}

// sem axuiliar

int comunsOrd (int a[], int na, int b[], int nb)
{
    int c=0;
    for (int i=0;i<na;i++)
    {
        for(int j=0;j<nb;j++)
        {
            if (a[i]==b[j]) c++;
            else c=c;
        }
    }
    return c;
}

//37
int minInd (int v[], int n)
{
    int min=0,ind=0;
    for (int i=0;i<n;i++) if (v[i]<min) ind=i;
    return ind;
}

//38
void somasAc (int v[], int ac [], int n)
{
    for (int i=0;i<n;i++)
    {
        int r=0;
        for (int j=0;j<=i;j++) r+=v[j];
        ac[i]=r;
    }
    //for (int k=0;k<n;k++) printf("%d ", ac[k]);
}

//39
int triSup (int N, float m [n][n])
{
    int r=1;
    for (int l=0;l<n;l++)
    {
        for (int c=0;c<l;c++) if (m[l][c] !=0) r=0; 
    }
    return r;
}

//40
void transposta (int N, float m [N][N])
{
    for (int l=0;l<N;l++)
    {
        for (int c=0;c<l; c++)
        {
            float temp=m [l] [c];
            m[l] [c]= m[c] [l];
            m[c] [l]=temp;
        }
    }
}


//41
void addTo (int N, int M, int a [N][M], int b[N][M])
{
    for (int l=0;l<N;l++)
    for (int c=0;c<M;c++) a[l] [c]+=b[l] [c];
}


int iguaisConsecutivos (char s[])
{
    int r=0;
    for (int i=0;s[i]!='\0';i++)
    {
        if (s[i]==s[i+1])
        {
            int n=i+1;
            while (s[n]!=s[i+1]) n++;
            i=n;
        }
        
        r=r+1;
        
    }
    printf("%d ",r);
}

//42
int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int c=0, i;

    for(i=0; i<N; i++)
        r[i] = v1[i]<v2[i] ? v2[i] : v1[i];
    
    return c;
}

//43
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int c=0, i;

    for(i=0; i<N; i++)
        if (v1[i] == v2[i]) 
            r[i] = v1[i];
        else
            r[i] = 0;

    return c;
}

//47
Posicao posFinal (Posicao inicial, Movimento *mov, int N){
    int i;
    for(i=0; i<N; i++){
        switch (mov[i]){
        case Norte:
            inicial.y++; 
            break;
        case Oeste:
            inicial.x--;
            break;
        case Este:
            inicial.x++;
            break;
        case Sul:
            inicial.y--;
            break;
    	}
    }
    return inicial;
}

//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i;
    for(i=0; i<N; i++){
        if(inicial.x < final.x){
            inicial.x++;
            mov[i] = Este;
        }else if(inicial.x > final.x){
            inicial.x--;
            mov[i] = Oeste;
        }else if(inicial.y < final.y){
            inicial.y++;
            mov[i] = Norte;
        }else if(inicial.y > final.y){
            inicial.y--;
            mov[i] = Sul;
        }else
            return i;
    }

    if(inicial.x != final.x || inicial.y != final.y)
        i = -1;
    return i;
}

//49

int manDist(int x, int y, int x0, int y0) 
{
	return abs(x - x0) + abs(y - y0);
}

int maisCentral (Posicao pos[], int N) {
    int minDist = manDist(pos[0].x,pos[0].y,0,0);
    int ans = 0, i;
    for(i = 1; i < N; i++) {
        if(manDist(pos[i].x,pos[i].y,0,0) < minDist) {
            ans = i;
            minDist = manDist(pos[i].x,pos[i].y,0,0);
        }
    }
    return ans;
}
//50

int vizinhos (Posicao p, Posicao pos[], int N) {
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(manDist(pos[i].x,pos[i].y,p.x,p.y) == 1) ans++;
    }
    return ans;
}
