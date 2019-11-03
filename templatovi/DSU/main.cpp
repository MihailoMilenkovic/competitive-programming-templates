#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int p[N];
int Find(int x){return x==p[x]?x:Find(p[x]);}
void Union(int x,int y){x=Find(x);y=Find(y);p[x]=y;}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    return 0;
}
