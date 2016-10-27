#define MAXN 100000
int p[MAXN],r[MAXN];
int parent(int i){
    if(p[i]==i)return i;
    else return p[i]=parent(p[i]);
}
inline void UN(int a,int b){
    int A=parent(a),B=parent(b);
    if(A==B) return;
    if(r[A]<r[B]){p[A]=p[B];}
    else r[A]+=r[A]==r[B],p[B]=p[A];
}
