#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 12500;

int ask(const vector<int> &a)
{
    cout << "? " << a.size() << " ";
    for(auto x : a)
        cout << x << " ";
    cout << endl;
    int res; cin >> res; return res;
}
pair<int, int> pa[32];
void solve()
{
    int x = ask(vector<int>(31, N));
    assert(x == 0 || x == 31 || x == 16 || x == 11 || x == 8 || x == 7 || x == 6 || x == 4);
    vector<int> s;
    if(x == 0){
        //
    }
    auto [L, R] = pa[x];
    for(int i = 1; i + L <= R; i++)
        s.push_back(i), s.push_back(L);
    x = ask(s);
    cout << L + x - int(s.size()) << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    pa[0] = {1, N - 1};
    pa[31] = {N, 2 * N - 1};
    pa[16] = {2 * N, 3 * N - 1};
    pa[11] = {3 * N, 4 * N - 1};
    pa[8] = {4 * N, 5 * N - 1};
    pa[7] = {5 * N, 6 * N - 1};
    pa[6] = {6 * N, 7 * N - 1};
    pa[4] = {8 * N, 8 * N};
    int t; cin >> t; while(t--)
    {solve();} return 0;
}
/*
[1, N - 1], 0
[N, 2N - 1], 31
[2N, 3N - 1], 16
[3N, 4N - 1], 11
[4N, 5N - 1], 8
[5N, 6N - 1], 7
[6N, 7N - 1], 6
[7N, 8N - 1], 5
8N, 4
*/