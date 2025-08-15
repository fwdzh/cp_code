#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> seg(m);
    for(int i = 0; i < m; i++)
        cin >> seg[i].first >> seg[i].second;
    ranges::sort(seg, [](pair<int, int> x, pair<int, int> y){
        return x.second == y.second ? x.first < y.first : x.second < y.second;
    });
    /*
    什么情况不能在一个地方放左括号？
    后缀需要用的左括号不够了

    而前缀的左括号太少则必须放左括号
    俄 至于后缀最少需要用多少个左括号……
    好像也并非最少///

    好难受阿
    像这个题这样的 我完全不知道从哪里开始思考

    如果有大于 n 的 L， 我们肯定要拿左括号过去
    那么一个左括号覆盖更多的段总是更优的

    但是如果把末尾的左括号拿走了，可能又会让前半部分的 L 无法被覆盖

    那么综合一下来考虑 其实可能全部的段都希望一个左括号能覆盖到更多吧

    是这样吗？
    
    那代码怎么写？。。
    */
    vector<int> s(2 * n + 1);
    // 1010101010
    // 我们可以知道前缀的左括号至少要多少个
    vector<vector<int>> R(2 * n + 1);
    for(auto [l, r] : seg){
        R[r].push_back(l);
    }
    for(int i = 1; i <= 2 * n; i++){
        ranges::sort(R[i]);
        bool need = false;
        for(auto l : R[i]){
            if(s[i] - s[l - 1] == 0)
                need = true;
        }
        if(need) s[i] = 1;
        s[i] = s[i] + s[i - 1];
        cerr << s[i] << " \n" [i == 2 * n];
    }
    if(s[2 * n] > n){
        cout << "-1\n";
        return;
    }
    int cnt = n - s[2 * n];
    string ans;
    for(int i = 1, pre = 0; i <= 2 * n; i++){
        if(s[i] - s[i - 1])
            ans.push_back('(');
        else if(cnt)
            ans.push_back('('), cnt--;
        else
            ans.push_back(')');
        if(ans.back() == '(')
            pre++;
        if(pre * 2 < i){
            cout << "-1\n";
            return;
        }
    }
    cout << ans << '\n';
}
int main()
{
    freopen("1.out", "w", stdout);
    freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}