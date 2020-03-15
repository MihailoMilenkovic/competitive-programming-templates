#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> factor(ll a){
	vector<ll> factors;
	for(ll i=2;i*i<=a;i++){
		if(a%i==0){
			factors.push_back(i);
			while(a%i==0){
				a/=i;
			}
		}
	}
	if(a!=1)
		factors.push_back(a);
	return factors;
}
int n,sol;
map<ll,int> v;
vector<ll> o;
set<ll> tried;
void test(ll a){
	if(a<=1)
		return;
	auto f=factor(a);
	for(auto p:f)
		if(!tried.count(p)){
			ll tr=0;
			for(auto d:v){
				tr+=min(d.first/p==0?LLONG_MAX:d.first%p,p-d.first%p)*d.second;
				if(tr>=sol)
					break;
			}
			if(tr<sol)
				sol=tr;
			tried.insert(p);
		}
}
int main()
{
	ll st=clock(),a;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&a),v[a]++,sol+=a&1,o.push_back(a);
	while(clock()-st<2400)
		a=o[rng()%o.size()],test(a),test(a-1),test(a+1);
	printf("%i\n",sol);
	return 0;
}