#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-17 16:29:49
using LL = long long;
void solve(){
    int n, q, L, R;
    cin >> n >> q >> L >> R;
    vector<int> a(n + 1);
    vector<array<int, 2>> b(q + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++){
        cin >> b[i][0];
        b[i][1] = i - 1;
    }
    vector<int> cnt(q);
    vector<LL> sum(q);
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    priority_queue<int, vector<int>, greater<>> pq;
    LL s = 0;
    // 先把左边的 且距离小于等于 L 的，减掉
    for(int i = 1, j = 1; i <= q; i++){
        while(j <= n && a[j] <= b[i][0]){
            pq.push(a[j]);
            s += a[j];
            j++;
        }
        while(pq.size() && b[i][0] - pq.top() > L){
            s -= pq.top();
            pq.pop();
        }
        cnt[b[i][1]] -= pq.size();
        sum[b[i][1]] -= LL(pq.size()) * b[i][0] - s;
    }
    while(!pq.empty()) pq.pop();
    s = 0;
    // 加上左边距离小于等于 R 的
    for(int i = 1, j = 1; i <= q; i++){
        while(j <= n && a[j] <= b[i][0]){
            pq.push(a[j]);
            s += a[j];
            j++;
        }
        while(pq.size() && b[i][0] - pq.top() > R){
            s -= pq.top();
            pq.pop();
        }
        cnt[b[i][1]] += pq.size();
        sum[b[i][1]] += LL(pq.size()) * b[i][0] - s;
    }
    // 右边的，距离小于等于L 的，减去
    priority_queue<int> pq1;
    s = 0;
    for(int i = q, j = n; i >= 1; i--){
        while(j >= 1 && a[j] >= b[i][0]){
            s += a[j];
            pq1.push(a[j]);
            j--;
        }
        while(!pq1.empty() && pq1.top() - b[i][0] > L){
            s -= pq1.top();
            pq1.pop();
        }
        cnt[b[i][1]] -= int(pq1.size());
        sum[b[i][1]] -= s - LL(pq1.size()) * b[i][0];
    }
    // 右边的，距离小于等于R
    while(!pq1.empty()) pq1.pop();
    s = 0;
    for(int i = q, j = n; i >= 1; i--){
        while(j >= 1 && a[j] >= b[i][0]){
            s += a[j];
            pq1.push(a[j]);
            j--;
        }
        while(!pq1.empty() && pq1.top() - b[i][0] > R){
            s -= pq1.top();
            pq1.pop();
        }
        cnt[b[i][1]] += int(pq1.size());
        sum[b[i][1]] += s - LL(pq1.size()) * b[i][0];
    }
    for(int i = 0; i < q; i++)
        cout << cnt[i] << " " << sum[i] << "\n";
}
int main(){
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}