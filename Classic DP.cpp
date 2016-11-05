#include <utility>
#include <stack>
#include <algorithm>
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

int s[100]={2,3,4,7,6};
int pa[100]={0};
int length[100]={1,0};
int LMS(int n){
    if(length[n]!=0)return length[n];
    int max=1;
    for(int i=0;i<n;++i){
        if(s[i]<s[n])
            if(LMS(i)+1>max)
                max=LMS(i)+1,pa[n]=i;
    }
    return length[n]=max;
}
//maxium increasing subsequence containing s[n]
void back(int n){
    if(pa[n]!=n)back(pa[n]);
    printf("%d ",s[n]);
}
