 #include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
 
struct node{
	map<char,node>children;
	void insert(string s,int i=0){
		if(i==s.size())return;
		children[s[i]].insert(s,i+1);
	}
	void traverse(string curr=""){
		cout<<curr<<"\n";
		//D(wins());
		for(auto x:children){
			x.s.traverse(curr+x.f);
		}
	}
	bool wins(bool fi){
		if(children.size()== 0)return fi;
		for(auto ch:children){
			if(!ch.s.wins(fi))return true;
		}
		return false;
	}
};

int main()
{
	//freopen("in.txt","r",stdin);
	node root;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		string inp;
		cin>>inp;
		root.insert(inp);
	}
	//root.traverse();
	//D(root.wins());
	if(root.wins(false)&&(root.wins(true)||k%2==1)){
		cout<<"First\n";
	}else{
		cout<<"Second\n";
	}
	return 0;
}