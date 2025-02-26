#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5;
bitset<N+1>is;
std::vector<int> primes;
void solve()
{
	
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i=2;i<=N;i++){
        if(!is[i]){
            primes.push_back(i);
            cerr<<i<<'\n';
            for(int j=i*i;j<=N;j+=i){
                is[j]=true;
            }
        }
    }
    cout<<primes.size()<<'\n';
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}