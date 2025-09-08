#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
	int n; LL k;
	cin >> n >> k;
	priority_queue<pair<int, int>> q;
	for(int i = 1; i <= n; i++){
		int c, w, f;
		cin >> c >> w >> f;
		q.push({f, w * c});
	}
	LL ans = 0, x = 0;
	while(q.size()){
		auto [f, c] = q.top(); q.pop();
		if(x == 0) ans += f;
		if(x + c >= k){
			// cerr << x << " " << c << " " << k << '\n';
			c -= k - x;
			LL t = (c + k - 1) / k;
			ans += t * f;
			x = c % k;
		}else{
			x += c;
		}
	}
	cout << ans << '\n';
}
int main()
{
	freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}