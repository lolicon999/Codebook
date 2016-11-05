#include <iostream>
#include <utility>
#define f first
#define s second
#define N 10
#define p 4999999
#define FL(i,j,k) for(int i=j;i<k;++i)
using namespace std;
typedef long long int ll;
typedef pair<ll , ll> ii;

ii gcd(ll a,ll b){
    if(!(a%b))return ii(0,1);
    ii d=gcd(b, a%b);
    return ii(d.s,d.f-a/b*d.s);
}
inline ll inverse(ll b,ll pr=p){return (gcd(b,pr).f+pr)%pr;}


ll M[N][N],I[N][N];//matrix, inverse
void GaussElimination(){//O(n^3)
    ll S[N][N];FL(i,0,N)FL(j,0,N)S[i][j]=M[i][j],I[i][j]=i==j;//define & copy
    FL(k,0,N){
        ll mul;
        int a=k;while(S[a][k]==0)++a;swap(S[k],S[a]);swap(I[k], I[a]);
        mul=inverse(S[k][k]);
        FL(i, 0, N)S[k][i]=S[k][i]*mul%p,I[k][i]=I[k][i]*mul%p;
        FL(i,0,N){//如果只做triangluar的話可以從k開始
            if(i==k)continue;
            mul=S[i][k]%p;
            FL(j, 0, N)
                S[i][j]=(p+S[i][j]-mul*S[k][j]%p)%p,I[i][j]=(p+I[i][j]-mul*I[k][j]%p)%p;
        }
    }
}

//Run this amazing Input :-D
int main(){
    FL(i, 0, 10)FL(j, 0, 10)M[i][j]=rand()%p;
    GaussElimination();
    ll PDT[N][N]={0};
    FL(i,0,10)FL(j, 0, 10)FL(k, 0, 10) PDT[i][j]+=M[i][k]*I[k][j];
    FL(i,0,10){FL(j, 0, 10) printf("%2lld ",PDT[i][j]%p);printf("\n");}
}
