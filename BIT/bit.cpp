#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=400050;
const int M=10000050;
const int L=27;
int a[N];
struct BIT{
	static const int NSZ=10000050;
	int sum[NSZ],cnt;
	void init(int mx){for(int i=0;i<min(M,mx+10);i++)sum[i]=0;cnt=0;}
	void Set(int i,int f){cnt^=f;for(i++;i<NSZ;i+=i&-i)sum[i]^=f;}
	int Get(int i){i=min(i,M-5);int ans=0;for(i++;i;i-=i&-i)ans^=sum[i];return ans;}
}BT;
int main(){
	return 0;
}