#define MAXN 1000
int P[MAXN],R[MAXN];
int parent(int p){
    if(P[p]==p)return p;
    else return P[p]=parent(P[p]);
}
inline void UN(int a,int b){
    if(R[parent(a)]<R[parent(b)])P[a]=P[b];
    else{
        R[P[b]]+=R[P[a]]==R[P[b]];
        P[b]=P[a];
    }
}
