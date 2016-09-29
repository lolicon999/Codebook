#include <iostream>
#include <vector>
#include <math.h>
#include "memory.h"
#define prime 4999999
#define MAXN 1000

using namespace std;
typedef long long int lli;

lli inverse(lli base,lli power=prime-2){
    if( power==0 ) return 1;
    else{
        lli ans=inverse(base, power/2);
        ans=(ans*ans)%prime*(power%2?base:1);
        return ans%prime;
    }
}

struct ffli{//finite field long long int
    lli a;
    ffli(lli b=0):a(b%prime){}
    inline ffli operator=(const ffli b){return a=b.a;}
    inline ffli operator*(const ffli b){return ffli((a*b.a)%prime);}
    inline ffli operator/(const ffli b){return ffli((a*inverse(b.a))%prime);}
    inline ffli operator+(const ffli b){return ffli((a+b.a)%prime);}
    inline ffli operator-(const ffli b){return ffli((prime+(a-b.a))%prime);}
    inline ffli operator%(const ffli b){return ffli(a%b.a);}
    inline ffli operator+=(const ffli b){return *this=*this+b;}
    inline ffli operator-=(const ffli b){return *this=*this-b;}
    inline ffli operator-(){return ffli(prime-a);}
    inline operator lli()const {return a;}
    inline ffli operator[](ffli);
};

//4,999,999 is the 348513rd prime number.*/

int V,E;
int match[MAXN];
ffli M[MAXN][MAXN],I[MAXN][MAXN];

inline int Input(){
    scanf("%d%d",&V,&E);
    for(int i=0;i<E;++i){
        int u,v;
        scanf("%d%d",&u,&v);--u,--v;
        M[u][v]=rand()%prime;
        M[v][u]=-M[u][v];
    }
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            I[i][j]=i==j;
        }
    }
    return V;
}


inline void printboard(){
    for(lli i=0;i<V;++i){
        for(lli j=0;j<V;++j)
            printf("%*lld ",(int)log(prime)-1,M[i][j]);
        printf(" | ");
        for(lli j=0;j<V;++j)
            printf("%*lld ",(int)log(prime)-1,I[i][j]);
        printf("\n");
    }
    printf("\n");
}


int GaussEllimination(){
    ffli S[MAXN][MAXN];
    int rank=V;
    for(int i=0;i<V;++i)for(int j=0;j<V;++j) S[i][j]=M[i][j],I[i][j]=i==j;//duplication
    for(int k=0;k<V;++k){
        rank-=1;
        for(int i=k;i<V;++i){//The for loop will only excute O(V)
            if(S[i][k]!=0){
                for(int j=0;j<V;++j) {swap(S[i][j], S[k][j]),swap(I[i][j], I[k][j]);}//O(V)
                for(int j=0;j<V;++j){
                    if(j==k)continue;
                    ffli mul=-S[j][k]/S[k][k];
                    for(int h=0;h<V;++h){
                        S[j][h]+=S[k][h]*mul,
                        I[j][h]+=I[k][h]*mul;
                    }
                }
                rank+=1;
                break;
            }
        }
        ffli mul=ffli(1)/S[k][k];
        for(int h=0;h<V;++h){
            S[k][h]=mul*S[k][h],I[k][h]=mul*I[k][h];
        }
        
        printboard();
    }
    return rank;
}

int MV_matching_algorithm(int V){
    int mat=0;
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){//Eli col j
            if(M[i][j]!=0 && I[j][i]!=0 && match[i]==-1 && match[j]==-1){
                match[i]=j,match[j]=i,++mat;
                for(int h=0;h<2;++h,swap(i, j)){
                    for(int a=0;a<V;++a){
                        if(a==i)continue;
                        ffli mul=-M[a][j]/M[i][j];
                        for(int h=0;h<V;++h){
                            M[a][h]=M[a][h]+M[i][h]*mul,I[h][i]=I[h][i]-I[h][a]*mul;
                        }
                    }
                    for(int a=0;a<V;++a){
                        if(a==j)continue;
                        ffli mul=-M[i][a]/M[i][j];
                        for(int h=0;h<V;++h){
                            M[h][a]=M[h][a]+M[h][j]*mul,I[j][h]=I[j][h]-I[a][h]*mul;
                        }
                    }
                }
                printboard();
                break;
            }
        }
    }
    return mat;
}

inline void join(int a){
    for(int i=V;i<V+a;++i){
        for(int j=0;j<V;++j){
            M[i][j]=rand()%prime;
            M[j][i]=-M[i][j];
        }
    }
    V+=a;
}

int main(){
    memset(match,-1,sizeof(match));
    int vertice=Input();
    int a=GaussEllimination();
    printf("a = %d\n",a);
    if(a!=V) {join(V-a);GaussEllimination();}
    int p=MV_matching_algorithm(V);
    printf("p = %d\n",p);
    printf("%d\n",a/2);
    for(int i=0;i<vertice;++i) printf("%d ",(match[i]+1)>vertice?0:match[i]+1);
    cout<<endl;
}
