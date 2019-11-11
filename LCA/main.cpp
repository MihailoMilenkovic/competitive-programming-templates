#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int LOGN=30;
vector<int>g[N];
int n,q,dep[N];
int par[N][LOGN];
void dfs(int x,int d){
    dep[x]=d;
    for(auto&y:g[x]){
        if(dep[y]==-1){
            dfs(y,d+1);
            par[y][0]=x;
        }
    }
}
void preprocess(){
    for(int lv=1;lv<LOGN;lv++){
        for(int i=1;i<=n;i++){
            if(par[i][lv-1]!=-1){
                par[i][lv]=par[par[i][lv-1]][lv-1];
            }
        }
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    int diff=dep[x]-dep[y];
    for(int i=LOGN-1;i>=0;i--){
        if(diff&(1<<i)){
            x=par[x][i];
        }
    }
    if(x==y){
        return x;
    }
    for(int i=LOGN-1;i>=0;i--){
        if(par[x][i]!=par[y][i]){
            x=par[x][i];
            y=par[y][i];
        }
    }
    return par[x][0];
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<N;i++){
        dep[i]=-1;
        for(int j=0;j<LOGN;j++){
            par[i][j]=-1;
        }
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    preprocess();
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",x,y,lca(x,y));
    }
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<=3;j++){
            printf("par[%d][%d]:%d\n",i,j,par[i][j]);
        }
    }*/
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("lca(%d,%d):%d\n",i,j,lca(i,j));
        }
    }*/
    return 0;
}
/*
8 1
1 2
1 3
2 4
2 5
2 6
3 7
3 8
1 8

4 7
4 6
*/
