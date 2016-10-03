#include <utility>
#include <iostream>
#include "math.h"
#include <vector>
using namespace std;

typedef long long int lli;
typedef pair<int,int > ii;
typedef vector<int > vi;
vi prime(int a){
    vi prime(0);
    for(int i=2;i<a;++i){
        bool ok=1;
        for(int p:prime)if(i%p==0||p>(1+sqrt(a))){ok=i%p;break;}
        if(ok)prime.push_back(i);
    }
    return prime;
}
//Input: Number A
//Output: All prime vector array smaller than A
//Note: This should not be submitted since the complexity is terrible

ii gcd(int a,int b){
    if(a%b==0)return ii(0,1);
    else{
        ii d=gcd(b, a%b);
        return ii(d.second,d.first-a/b*d.second);
    }
}
#define prime 4999999
int inverse(int base){
    return (gcd(base,prime).first+prime)%prime;//用gcd() 扣的簡潔有力又不拖泥帶水！！！
}

//Input: two integer a,b
//Output: x,y in the font of pair<int,int> s.t. ax+by=gcd(a,b)

lli findmod(lli base,lli power,lli mod){
    if( power==0 ) return 1;
    else{
        lli ans=findmod(base, power/2, mod);
        ans=(ans*ans)%mod*(power%2?base:1);
        return ans%mod;
    }
}

//Input: three long long int base, power, mod
//Output: (base^power)%mod
