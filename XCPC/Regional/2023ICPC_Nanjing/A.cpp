#include<bits/stdc++.h>
using namespace std;

#define test solve()
#define testm int T; cin >> T; while(T--) solve()

#define rep(i, k, n) for(int i = (k); i <= (n); i++) 
#define srep(i, k, n) for(int i = (k); i >= (n); i--)
#define ms(a, b) memset(a, (b), sizeof(a))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#define quit(x) {cout << (x) << '\n'; return;}
#define yn_quit(x) {cout << ((x) ? "Yes" : "No") << '\n'; return;}


void solve() { 
    int n, m;
    cin >> n >> m;
    vector<string> grid(n + 1);
    rep(i, 1, n) {
        cin >> grid[i];
        grid[i] = ' ' + grid[i];
    }
    auto check = [&](int x, int y){
        return x > 0 && y > 0 && x <= n && y <= m;
    };
    vector<vector<bool>> vis(n + 1, vector<bool> (m + 1));
    vector<vector<pii>> r;
    auto dfs = [&](auto &&self, int x, int y) -> void {
        // cerr << x << " " << y << '\n';
        vis[x][y] = true;
        if(grid[x][y] == 'O') return;
        r[r.size() - 1].push_back({x, y});
        if(check(x - 1, y) && !vis[x - 1][y]) self(self, x - 1, y);
        if(check(x + 1, y) && !vis[x + 1][y]) self(self, x + 1, y);
        if(check(x, y - 1) && !vis[x][y - 1]) self(self, x, y - 1);
        if(check(x, y + 1) && !vis[x][y + 1]) self(self, x, y + 1);
    };
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(grid[i][j] == '.' && !vis[i][j]){
                r.push_back(vector<pii> ());
                dfs(dfs, i, j);
            }
        }
    int ans = 0;
    for(int i = 0; i < r.size(); i++){
        set<pii> st;
        for(int j = 0; j < r.size(); j++)
            if(j != i){
                for(auto [x, y] : r[j])
                    st.insert({x, y});
            }
        auto [x0, y0] = r[i][0];
        for(auto [x, y] : r[i]){
            int dx = x - x0, dy = y - y0;
            vector<pii> tmp;
            for(auto [nx, ny] : st){
                if((!check(nx + dx, ny + dy)) || grid[nx + dx][ny + dy] == 'O')
                    tmp.push_back({nx, ny});
            }
            for(auto [nx, ny] : tmp)
                st.erase({nx, ny});
        }
        if(st.empty()) ans += r[i].size();
    }
    quit(ans);
}

int main() {
    // freopen("1.in", "r", stdin);
    IOS;
    testm;
}