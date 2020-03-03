#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>permutation(N);
    for(int i=0;i<N;i++){
        permutation[i]=i;
    }
    //random shuffle
    shuffle(permutation.begin(),permutation.end(),rng);
    //random number in interval [0,N]
    int rand=uniform_int_distribution<int>(0,N)(rng);
    return 0;
}