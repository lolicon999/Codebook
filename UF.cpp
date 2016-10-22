#define MAXN 1000000
int parent(int p){
    if(P[p]==p)return p;
    else return P[p]=parent(P[p]);
}
inline void UN(int a,int b){
    int A=parent(a),B=parent(b);
    if(A==B) return;
    if(R[A]<R[B]){P[A]=P[B];}
    else R[A]+=R[A]==R[B],P[B]=P[A];
}
