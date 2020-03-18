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
const int N=1e5+5;
int n,m,sq,dep[N],deg[N],par[N];
bool vis[N];
vector<int>g[N];
stack<int>st;
int idx[N],low[N],cmp[N],dp[N],currIdx,currComp;
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
void tarjan(int u){
    low[u]=idx[u]=++currIdx;
    st.push(u);
    cmp[u]=-2;
    for(auto&v:g[u]){
        if(!idx[v]||cmp[v]==-2){
            if(!idx[v]){
                tarjan(v);
            }
            low[u]=min(low[u],low[v]);
        }
    }
   if(low[u]==idx[u]){
        ++currComp;
        int x;
        do{
            x=st.top();
            cmp[x]=currComp;
            st.pop();
        }while(x!=u);
   }
}
void scc(){
    for(int i=1;i<=n;i++){
        if(idx[i]==0){
            tarjan(i);
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        deg[x]++;
    }
    scc();
    for(int i=1;i<=n;i++){
        cout<<"i:"<<i<<" comp[i]:"<<cmp[i]<<"\n";
    }
    return 0;
}
/*
4 5
3 1
1 2
2 4
4 1
2 3

///
3 3
1 2
1 3
2 3
*/