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
int n,deg[N],vis[N];
pair<pii,int> ed[N];
vector<int>g[N];

template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
map<pii,int>pos;
int val[N];
bool got[N];
int main(){
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
        deg[x]++;
        deg[y]++;
        pos[mp(x,y)]=i;
        pos[mp(y,x)]=i;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(deg[i]==1){
            q.push(i);
            vis[i]=true;
        }
    }
    int curr=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto y:g[x]){
            if(!vis[y]){
                deg[y]--;
                val[pos[mp(x,y)]]=curr++;
                got[pos[mp(x,y)]]=true;
                if(deg[y]==1){
                    q.push(y);
                    vis[y]=true;
                }
            }
        }
    }
    for(int i=1;i<=n-1;i++){
        if(!got[i]){
            val[i]=curr++;
        }
    }
    for(int i=1;i<=n-1;i++){
        cout<<val[i]<<"\n";
    }
    return 0;
}