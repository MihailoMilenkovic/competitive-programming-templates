//currently using edmond-karp, need to change it

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e3+5;
const int oo=1e9+7;
int n,m,sq,dep[N],deg[N],par[N],level[N];
bool vis[N];
vector<vector<int>>g,capacity,flow;
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

bool BFSlevels(int source,int sink){
    queue<int>q;
    memset(level,-1,sizeof(level));
    q.push(source);
    level[source]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto y:g[x]){
            if(level[y]==-1&&flow[x][y]<capacity[x][y]){
                level[y]=level[x]+1;
                q.push(y);
            }
        }
    }
    return level[sink]>-1;
}
int sendFlow(int x,int sink,int start[],int flo=oo){
    if(x==sink){
        return flo;
    }
    for(;start[x]<g[x].size();start[x]++){
        int y=g[x][start[x]];
        if(level[y]==level[x]+1&&flow[x][y]<capacity[x][y]){
            int currFlow=min(flo,capacity[x][y]-flow[x][y]);
            int tempFlow=sendFlow(y,sink,start,currFlow);
            if(tempFlow>0){
                flow[x][y]+=tempFlow;
                flow[y][x]-=tempFlow;
                return tempFlow;
            }
        }
    }
    return 0;
}
int dinicMaxFlow(int source,int sink){
    int total=0;
    while(BFSlevels(source,sink)){
        int *start=new int[N];
        while(int flo=sendFlow(source,sink,start)){
            total+=flo;
        }
    }
    return total;
}
int main(){
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    g.resize(n+2);
    capacity.resize(n+2);
    flow.resize(n+2);
    for(int i=0;i<=n+1;i++){
        capacity[i].resize(n+2);
        flow[i].resize(n+2);
    }
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].pb(y);
        g[y].pb(x);
        capacity[x][y]=w;
        deg[x]++;
        deg[y]++;
    }
    g[0].pb(1);g[1].pb(0);
    g[n+1].pb(n);g[n].pb(n+1);
    capacity[0][1]=oo;
    capacity[n][n+1]=oo;
    int flow=dinicMaxFlow(0,n+1);
    cout<<flow<<"\n";
    return 0;
}
/*
6 9
1 2 7
1 3 4
2 4 5
2 5 3
3 2 3
3 5 2
5 4 3
4 6 8
5 6 5
*/