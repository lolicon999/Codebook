#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include "limits.h"
#define f first
#define s second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
ll mul(ll a,ll b,ll m){
    if((a<INT_MAX && b<INT_MAX)||a<10||b<10)return a*b%m;
    ll sa=a/2,r=a%2,sb=b/2,k=b%2;
    return (4*mul(sa,sb,m)+2*k*sa+2*r*sb+r*k)%m;
    
}
ii gcd(ll a,ll b){
    if(!(a%b))return ii(0,1);
    ii d=gcd(b, a%b);
    return ii(d.s,d.f-a/b*d.s);
}

inline ll inverse(ll b,ll p){return (gcd(b,p).f+p)%p;}

//Input: two integer a,b
//Output: x,y in the font of pair<int,int> s.t. ax+by=gcd(a,b)

ll pmod(ll b,ll p,ll m){
    if(!p) return 1;
    ll a=pmod(b, p/2, m);
    return mul(mul(a, a, m),(p%2?b:1),m);
}

//Input: three long long int base, power, mod
//Output: (base^power)%mod#include <vector>

inline ll CRT(vector<ii> &prob){
    ll tmod=1,sol=0;
    for(ii a: prob) tmod*=a.s;//這裡會溢位
    for(ii a: prob) sol=(sol+a.f*inverse(tmod/a.s,a.s)*tmod/a.s)%tmod;
    return sol;
}
//Input: vector<ii> the chinese residue problem
//Output:
//i.e. vector<ii>{ii(2,3),ii(3,5),ii(6,7)}:find minimum number of : 2(mod 3),3(mod 5),6(mod 7)
ll table[]={2,3,5,7,11,13,17,19,23,29,31,37};
ll rho(ll C){//就有些要求來說，rho太慢了
    const ll r=rand()%(C-1);
    auto F=[=](ll a){return (mul(a, a, LONG_LONG_MAX)+r)%C;};
    ll d=1,p1=2,p2=2;
    while (d!=C) {
        p1=F(p1),p2=F(F(p2));
        ii g=gcd(abs(p1-p2),C);
        d=g.f*(abs(p1-p2))+g.s*C;
        if(d>1 && d<C) return d;
    }
    return rho(C);
}

ll isprime(ll k){//1 then true, other than factorial
    for(ll p: table){
        if(k==p)return 1;
        else if (!(k%p)) return p;
    }
    ll d=k-1,q=0;while(!(d%2)) d/=2,++q;
    for(ll p: table){
        ll t=pmod(p, d, k),r=0;
        if(t==1)continue;
        for(;r<q;++r,t=mul(t, t, k))if(t==k-1)break;
        if(t==k-1)continue;
        return rho(k);
    }
    return 1;
}
