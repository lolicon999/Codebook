#include <iostream>
#include <utility>
#include <stack>
using namespace std;
typedef pair<int, int> ii;
int DP[50][50]={0};
ii path[50][50];
string a,b;
int LCS(int i,int j){
    if(i==-1||j==-1)return 0;
    if(DP[i][j]!=-1)return DP[i][j];
    if(a[i]==b[j]){
        path[i][j]=ii(i-1,j-1);
        return DP[i][j]=LCS(i-1, j-1)+1;
    }
    if(LCS(i, j-1)>LCS(i-1, j)){
        path[i][j]=ii(i,j-1);
        return DP[i][j]=LCS(i, j-1);
    }
        path[i][j]=ii(i-1,j);
        return DP[i][j]=LCS(i-1, j);
}

int main(){
    for(int i=0;i<50;++i)for(int j=0;j<50;++j)DP[i][j]=-1;
    cin>>a>>b;
    cout<<LCS(a.size()-1,b.size()-1)<<'\n';
    int i=a.size()-1,j=b.size()-1;
    stack<char> st;
    while(i!=-1||j!=-1){
        if(a[i]==b[j])st.push(a[i]);
        ii p=path[i][j];i=p.first,j=p.second;
    }
    while (!st.empty()) {printf("%c",st.top());st.pop();}
}
