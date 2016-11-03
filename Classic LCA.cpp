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
