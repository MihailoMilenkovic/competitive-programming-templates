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
const int N=2e5+5,oo=1e9+1e8+7,mod=1e9+7;

template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
struct query{
    int l,r,id;
};
int sq;
bool cmp(query a,query b){
    if((a.l/sq)!=(b.l/sq))return (a.l/sq)<(b.l/sq);
    return a.r>b.r;
}
query qu[N];
int n,q,a[N];
int main(){
    freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    sq=sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=q;i++){
        cin>>qu[i].l>>qu[i].r;
        qu[i].id=i;
    }
    sort(qu+1,qu+q+1,cmp);
    /*for(int i=1;i<=q;i++){
        cout<<qu[i].l<<" "<<qu[i].r<<"\n";
    }*/
    set<int>st;
    int currl=-1,currr=-1;
    for(int i=1;i<=q;i++){
        int ql=qu[i].l,qr=qu[i].r;
        if(i==1){
            for(int i=ql;i<=qr;i++){
                st.insert(a[i]);
            }
            currl=ql;
            currr=qr;
        }
        while(currl!=ql){
            if(currl<ql){
                st.erase(a[currl]);
                currl++;
            }
            else{
                currl--;
                st.insert(a[currl]);  
            }
        }
        while(currr!=qr){
            if(currr<qr){
                currr++;
                st.insert(a[currr]);   
            }
            else{
                st.erase(a[currr]);
                currr--;
            }
        }
        cout<<st<<"\n";
    }
    return 0;
}