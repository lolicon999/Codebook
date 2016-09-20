#include <iostream>
#include <vector>
class UF{
private:std::vector<int>  p,r;
public:
    int size;
    UF(int i) {p.resize(size=i),r.assign(i,0); for(int j=0;j<i;++j)p[j]=j; }
    int find(int i) {return p[i]==i?i:p[i]=find(p[i]);}
    bool S(int i,int j){return find(i)==find(j);}
    void US(int i,int j){
        int x=find(i),y=find(j);
        if(x!=y){--size;
            if(r[x]>r[y])p[y]=x;
            else{p[x]=y;r[y]+=(int)(r[x]==r[y]);}
        }
    }
};
