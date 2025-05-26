#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(1e6);
int minp[N + 1], cx[N + 1], cy[N + 1];

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    set<int> px, py;
    while (x != 1) {
        int p = minp[x];
        // cerr << format("divsor of x : {}\n", p);
        cx[p] = 0;
        while (x % p == 0)
            x /= p, cx[p]++;
        px.insert(p);
    }
    while (y != 1) {
        int p = minp[y];
        cy[p] = 0;
        // cerr << format("divsor of y : {}\n", p);
        while (y % p == 0)
            y /= p, cy[p]++;
        px.insert(p);
        // py.insert(p);
    }
    int ans = 0;
    vector<int> X, Y;
    for (auto p : px) {
        // cerr << format("p: {}, cx[p]: {}, cy[p]: {}\n", p, cx[p], cy[p]);
        if (cx[p] < cy[p]) {
            // 需要乘一些东西了
            if (p > k) {
                ans = -1;
                break;
            }
            int z = cy[p] - cx[p];
            for (int i = 1; i <= z; i++)
                X.push_back(p);
        }else if (cx[p] > cy[p]) {
            if (p > k) {
                ans = -1;
                break;
            }
            int z = cx[p] - cy[p];
            for (int i = 1; i <= z; i++)
                Y.push_back(p);
        }
        // cx[p] = cy[p] = 0;
    }
    for (auto p : px)
        cx[p] = cy[p] = 0;
    if (ans == -1) {
        cout << "-1\n";
        return;
    }
    auto calc = [&](vector<int> vec, int siz) {
        priority_queue<ll, vector<ll>, greater<>> pq;
        reverse(vec.begin(), vec.end());
        // multiset<ll> st;
        for (int i = 0; i < siz; i++) {
            pq.push(vec[i]);
            // st.insert(vec[i]);
        }
        for (int i = siz; i < vec.size(); i++) {
            // int x = k / vec[i] + 1;
            // if (*st.begin() * vec[i] > k) return false;
            // auto it = prev(st.lower_bound(x));
            // ll val = *it;
            // st.erase(it);
            // st.insert(val * vec[i]);
            auto val = pq.top();
            // cerr << val <<" " << vec[i]<< '\n';
            pq.pop();
            if (val * vec[i] > k) return false;
            pq.push(val * vec[i]);
        }
        // cerr << format("true and siz = {}\n", siz);
        return true;
    };
    // for (auto p : X)
    //     cerr << p << ' ';
    // cerr << '\n';
    // for (auto p : Y)
    //     cerr << p << ' ';
    // cerr << '\n';
    // cerr << calc(X, 6) << '\n';
    for (int i = 1; i <= X.size(); i++) {
        if (calc(X, i)) {
            ans += i;
            break;
        }
    }
    if (X.size()) assert(ans);
    // cerr << Y.size() << '\n';
    for (int i = 1; i <= Y.size(); i++) {
        if (calc(Y, i)) {
            ans += i;
            break;
        }
    }
    if (Y.size()) assert(ans);
    cout << ans << '\n';
    // /*
    // * 2 3 3 3 5
    // * 5 3
    // * 15
    // *
    // * 2 2 2 2 3 , 3 3 5 5 7 13
    // * 13, 7, 5, 5, 3, 3
    //   13, 9, 7, 5, 5, 3
    //
    // */
}

int main() {
    // freopen("1.out", "w", stdout);
    for (int i = 2; i <= N; i++) {
        if (minp[i]) continue;
        minp[i] = i;
        if (ll(i) * i > N) continue;
        for (int j = i * i; j <= N; j += i)
            minp[j] = i;
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}