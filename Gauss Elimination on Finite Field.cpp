#include <iostream>
#include <vector>
#include <math.h>
#include "memory.h"
#define prime 11
#define MAXN 10

using namespace std;
typedef vector<int> vi;
typedef long long int lli;

/*int V,ans=0,match[MAXN],Flower[MAXN],S[MAXN],vis[MAXN];

//4,999,999 is the 348513rd prime number.*/

int V,E;
lli M[MAXN][MAXN],I[MAXN][MAXN];

void Input(){
    scanf("%d%d",&V,&E);
    for(int i=0;i<E;++i){
        int u,v;
        scanf("%d%d",&u,&v);--u,--v;
        M[u][v]=rand()%prime;
        M[v][u]=prime-M[u][v];
    }
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            I[i][j]=i==j;
        }
    }
}

lli inverse(lli base,lli power=prime-2){
    static lli dp[prime]={0};
    if(dp[base]) return dp[base];
    if( power==0 ) return 1;
    else{
        lli ans=inverse(base, power/2);
        ans=(ans*ans)%prime*(power%2?base:1);
        dp[base]=ans%prime;
        return dp[base];
    }
}

void printboard(){
    for(lli i=0;i<V;++i){
        for(lli j=0;j<V;++j)
            printf("%4lld ",M[i][j]);
        printf("\n");
    }
    printf("\n");
}


void GaussEllimination(){
    /*lli stay[V][V];
    for(int i=0;i<V;++i)for(int j=0;j<V;++j) stay[i][j]=M[i][j],I[i][j]=i==j;;//duplication*/
    for(int k=0;k<V;++k){
        for(int i=k;i<V;++i){//The for loop will only excute O(V)
            if(M[i][k]!=0){
                for(int j=0;j<V;++j) swap(M[i][j], M[k][j]),swap(I[i][j], I[k][j]);//O(V)
                for(int j=0;j<V;++j){
                    if(j==k)continue;
                    int mul=(prime-M[j][k])*inverse(M[k][k])%prime;
                    for(int h=0;h<V;++h){
                        M[j][h]+=(M[k][h]*mul)%prime,
                        M[j][h]%=prime;
                        I[j][h]+=(I[k][h]*mul)%prime,
                        I[j][h]%=prime;
                    }
                }break;
            }
        }
        int mul=inverse(M[k][k])%prime;
        for(int h=0;h<V;++h){
            M[k][h]=mul*M[k][h]%prime,I[k][h]=mul*I[k][h]%prime;
        }
    }
}


int main(){
    /*int E,u,v;
    scanf("%d%d",&V,&E);
    for(int i=0;i<V;++i) adj[i].clear();
    while (E--) {
        scanf("%d%d",&u,&v); --u; --v;
        adj[u].push_back(v),
        adj[v].push_back(u);
    }
    
    memset(match, -1, V*sizeof(int));
    memset(Flower, -1, V*sizeof(int));
    memset(pa, -1, V*sizeof(int));
    */

    Input();
    printboard();
    printf("\n");
    GaussEllimination();
    printboard();
    printf("\n");
    for(int i=0;i<V;++i){
        
    }

    
}