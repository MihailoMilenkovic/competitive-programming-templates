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
int n,m,sq,dep[N],deg[N],par[N];
bool vis[N];
vector<vector<int>>capacity;
vector<vector<int>>g;
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
int bfs(int source,int sink,vector<int>&parent){
    fill(parent.begin(),parent.end(),-1);
    parent[source]=-2;
    queue<pii>q;
    q.push(mp(source,oo));
    while(!q.empty()){
        int curr=q.front().f,flow=q.front().s;
        q.pop();
        for(auto next:g[curr]){
            if(parent[next]==-1&&capacity[curr][next]){
                parent[next]=curr;
                int new_flow=min(flow,capacity[curr][next]);
                if(next==sink){
                    return new_flow;
                }
                q.push(mp(next,new_flow));
            }
        }
    }
    return 0;
}
int maxFlow(int source,int sink){
    int flow=0;
    vector<int>parent(n+2);
    int newFlow;
    while(newFlow=bfs(source,sink,parent)){
        flow+=newFlow;
        int curr=sink;
        while(curr!=source){
            int prev=parent[curr];
            capacity[prev][curr]-=newFlow;
            capacity[curr][prev]+=newFlow;
            curr=prev;
        }
    }
    return flow;
}
int main(){
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    g.resize(n+2);
    capacity.resize(n+2);
    for(int i=0;i<=n+1;i++){
        capacity[i].resize(n+2);
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
    int flow=maxFlow(0,n+1);
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