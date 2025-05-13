#include<bits/stdc++.h>
using namespace std;

// mt19937_64 rng(time(NULL));

// int rand_interger(int l,int r)
// {
//     uniform_int_distribution<int>dis(l, r);
//     return dis(rng);
// }
void solve()
{
    int n;
    cin >> n;
    // n = rand_interger(90000,100000);
    // cout << n << '\n';
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        // a[i] = rand_interger(1, int(1e9));
    }
    if(*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end())){
        cout << "0\n";
        return;
    }
    vector<int> b(a);
    for(int t = 1;t <= n; t++){
        int mx = 0, mn = int(2e9);
        for(int j = 0; j < n; j++){
            a[j] |= b[(j + t) % n];
            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
        }
        if(mx == mn){
            cout << t << '\n';
            return;
        }
        b = a;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}