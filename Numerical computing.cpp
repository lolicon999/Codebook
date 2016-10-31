#include <vector>
#include <utility>
#define f first
#define s second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;

ii gcd(ll a,ll b){
    if(!(a%b))return ii(0,1);
    ii d=gcd(b, a%b);
    return ii(d.s,d.f-a/b*d.s);
}

ll inverse(ll b,ll p){return (gcd(b,p).f+p)%p;}

//Input: two integer a,b
//Output: x,y in the font of pair<int,int> s.t. ax+by=gcd(a,b)

ll pmod(ll b,ll p,ll m){
    if(!p) return 1;
    ll a=pmod(b, p/2, m);
    return (a*a)%m*(p%2?b:1)%m;
}

//Input: three long long int base, power, mod
//Output: (base^power)%mod#include <vector>

ll CRT(vector<ii> &prob){
    ll tmod=1,sol=0;
    for(ii a: prob) tmod*=a.s;//這裡會溢位
    for(ii a: prob) sol=(sol+a.f*inverse(tmod/a.s,a.s)*tmod/a.s)%tmod;
    return sol;
}
//try vector<ii>{ii(2,3),ii(3,5),ii(6,7)};
//i.e. find minimum number of : 2(mod 3),3(mod 5),6(mod 7)
