#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int p[N];
int Find(int x){return x==p[x]?x:Find(p[x]);}
void Union(int x,int y){x=Find(x);y=Find(y);p[x]=y;}
vector<pair<int,pair<int,int>>>ed,mst;
int main()
{
    int n,m,sum=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        ed.push_back({w,{x,y}});
    }
    sort(ed.begin(),ed.end());
    for(auto&e:ed){
        int w=e.first,x=e.second.first,y=e.second.second;
        if(Find(x)!=Find(y)){
            Union(x,y);
            mst.push_back(e);
            sum+=w;
        }
    }
    printf("%d\n",sum);
    for(auto&x:mst){
        printf("%d %d %d\n",x.second.first,x.second.second,x.first);
    }
    return 0;
}
