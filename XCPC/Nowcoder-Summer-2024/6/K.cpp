#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end())){
        cout << "0\n";
        return;
    }
    vector<int> divisors;
    auto work = [&](int x) {
        for(int i = 1; i * i <= x; i++){
            if(x % i == 0){
                divisors.push_back(i);
                divisors.push_back(x / i);
            }
        }
    };
    work(a[0]), work(a[n - 1]);
    int g = 0;
    for(int i = 1; i < n; i++)
        g = gcd(g, a[i] - a[i - 1]);
    work(g);
    ranges::unique(divisors);
    ranges::sort(divisors, greater<>());
    auto check = [&](int d) {
        /*
        如果有不能整除的 那一定需要加上一个数字
        不整除的中间有能整除的 肯定不行
        并且只能 % d 的值相等
        */
        int x = 0, e = 0;
        for(int i = 0; i < n; i++){
            if(a[i] % d){
                if(!x){
                    x = a[i] % d;
                }else{
                    if((x != (a[i] % d)) || e)
                        return false;
                }
            }else{
                if(x)
                    e = 1;
            }
        }
        return true;
    };
    for(auto d : divisors){
        // cerr << d << '\n';
        if(check(d)){
            cout << d << '\n';
            return;
        }
    }
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    // freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t; cin >> t; while(t--)
    {solve();} return 0;
}