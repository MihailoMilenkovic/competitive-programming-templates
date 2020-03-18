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

struct Matrix{
    int sz,step;
    vector<vector<int>>m;
    void init(int _sz){
        sz=_sz;
        m.resize(sz);
        for(int i=0;i<sz;i++){
            m[i].resize(sz);
        }
    }
    void makeOne(){
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                if(i==j){
                    m[i][j]=1;
                }
                else{
                    m[i][j]=0;
                }
            }
        }
    }
    void read(){
        cin>>sz;
        //cin>>step;
        init(sz);
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                cin>>m[i][j];
            }
        }
    }
    void write(){
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                cout<<m[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    Matrix mul(Matrix oth){
        Matrix ans;
        ans.init(sz);
        //ans.makeOne();
        for(int i=0;i<sz;i++){
            for(int k=0;k<sz;k++){
                for(int j=0;j<sz;j++){
                    ans.m[i][k]+=m[i][j]*oth.m[j][k];
                }
            }
        }
        return ans;
    }
    Matrix exp(int st){
        Matrix ans,curr;
        ans.init(sz);
        curr.init(sz);
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                curr.m[i][j]=m[i][j];
            }
        }
        ans.makeOne();
        for(int i=1;i<=st;i*=2){
            if(st&i){
                ans=ans.mul(curr);
            }
            curr=curr.mul(curr);
        }
        return ans;
    }
};
int main(){
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Matrix mat1;
    mat1.read();
    Matrix ans4=mat1.exp(3);
    cout<<"mat1^3\n";
    ans4.write();
    return 0;
}
/*
2
1 2
3 4
2
2 0
1 2

ans1:
4 4
10 8
ans2:
2 4
7 10


*/