#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
void solve()
{
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> a(n + 1);
    for(int  i = 1; i <= n; i++)
        cin >> a[i];
    ll sum = accumulate(a.begin() + 1, a.begin() + k + 1, 0LL);
    priority_queue<ll, vector<ll>, greater<>> pq;
    priority_queue<ll> pq1;
    for(int i = k; i >= 1; i--){
        pq.push(a[i] + 1LL * (k - i) * c);
    }
    for(int i = k + 1; i <= n; i++){
        pq1.push(a[i] - 1LL * (i - k) * c);
    }
    while(pq1.size() && pq.size() && pq1.top() >= pq.top()){
        // cerr << pq1.top() << " " << pq.top() << '\n';
        sum += pq1.top() - pq.top();
        pq1.pop(), pq.pop();
    }
    cout << sum << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}