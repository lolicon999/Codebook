#include <iostream>
#include <vector>
#include <math.h>
#include "memory.h"
#define prime 4999999
#define MAXN 500

using namespace std;
typedef vector<int> vi;
typedef long long int lli;
/*int V,ans=0,match[MAXN],Flower[MAXN],S[MAXN],vis[MAXN];
 
 //4,999,999 is the 348513rd prime number.*/

int V,E;
int match[MAXN];
lli M[MAXN][MAXN],I[MAXN][MAXN];

void Input(){
    scanf("%d%d",&V,&E);
    for(int i=0;i<E;++i){
        int u,v;
        scanf("%d%d",&u,&v);--u,--v;
        M[u][v]=rand()%100000%prime;
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
        printf("\n\n\n");
        for(lli j=0;j<V;++j)
            printf("%4lld ",M[i][j]);
        printf(" | ");
        for(lli j=0;j<V;++j)
            printf("%4lld ",I[i][j]);
        printf("\n\n\n");
    }
}


void GaussEllimination(){
    lli stay[V][V];
    for(int i=0;i<V;++i)for(int j=0;j<V;++j) stay[i][j]=M[i][j],I[i][j]=i==j;//duplication
    for(int k=0;k<V;++k){
        for(int i=k;i<V;++i){//The for loop will only excute O(V)
            if(stay[i][k]!=0){
                for(int j=0;j<V;++j) {swap(stay[i][j], stay[k][j]),swap(I[i][j], I[k][j]);}//O(V)
                for(int j=0;j<V;++j){
                    if(j==k)continue;
                    int mul=(prime-stay[j][k])*inverse(stay[k][k])%prime;
                    for(int h=0;h<V;++h){
                        stay[j][h]+=(stay[k][h]*mul)%prime,
                        stay[j][h]%=prime;
                        I[j][h]+=(I[k][h]*mul)%prime,
                        I[j][h]%=prime;
                    }
                }break;
            }
        }
        int mul=inverse(stay[k][k])%prime;
        for(int h=0;h<V;++h){
            stay[k][h]=mul*stay[k][h]%prime,I[k][h]=mul*I[k][h]%prime;
        }
    }
}

int MV_matching_algorithm(int V){
    int mat=0;
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){//Eli col j
            if(M[i][j]!=0 && I[j][i]!=0){
                match[i]=j,match[j]=i,++mat;
                for(int a=0;a<V;++a){
                    if(a==i)continue;
                    int mul=(prime-M[a][j])*inverse(M[i][j])%prime;
                    for(int h=0;h<V;++h){
                        M[a][h]=(M[a][h]+M[i][h]*mul)%prime,I[h][i]=(prime+(I[h][i]-I[h][a]*mul)%prime)%prime;
                    }
                }
                for(int a=0;a<V;++a){
                    if(a==j)continue;
                    int mul=(prime-M[i][a])*inverse(M[i][j])%prime;
                    for(int h=0;h<V;++h){
                        M[h][a]=(M[h][a]+M[h][j]*mul)%prime,I[j][h]=(prime+(I[j][h]-I[a][h]*mul)%prime)%prime;
                    }
                }
                swap(i,j);
                for(int a=0;a<V;++a){
                    if(a==i)continue;
                    int mul=(prime-M[a][j])*inverse(M[i][j])%prime;
                    for(int h=0;h<V;++h){
                        M[a][h]=(M[a][h]+M[i][h]*mul)%prime,I[h][i]=(prime+(I[h][i]-I[h][a]*mul)%prime)%prime;
                    }
                }
                for(int a=0;a<V;++a){
                    if(a==j)continue;
                    int mul=(prime-M[i][a])*inverse(M[i][j])%prime;
                    for(int h=0;h<V;++h){
                        M[h][a]=(M[h][a]+M[h][j]*mul)%prime,I[j][h]=(prime+(I[j][h]-I[a][h]*mul)%prime)%prime;
                    }
                }
                swap(i,j);
                break;
            }
        }
    }
    return mat;
}

int main(){
    memset(match,-1,sizeof(match));
    Input();
    GaussEllimination();
    //printboard();
    int p=MV_matching_algorithm(V);
    printf("%d\n",p%2==0?p/2:p/2+1);
    for(int i=0;i<V;++i) printf("%d ",match[i]+1);
    cout<<endl;
    
    
}