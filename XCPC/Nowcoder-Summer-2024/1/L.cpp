#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = int(4e5) + 55;
int b[N];
int lowbit(int x) {return (x) & (-x);}
void add(int i, int x)
{
    while(i && i < N){
        b[i] += x;
        i += lowbit(i);
    }
}
int query(int i)
{
    int res = 0;
    while(i > 0){
        res += b[i];
        i -= lowbit(i);
    }
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> p(q), v(q);
    for(int i = 0; i < q; i++)
        cin >> p[i] >> v[i];

    vector<ll> vec(a.begin() + 1, a.end());
    {
        vector<ll> b(a);
        for(int i = 0; i < q; i++){
            b[p[i]] += v[i];
            vec.push_back(b[p[i]]);
        }
        ranges::sort(vec);
        ranges::unique(vec);
    }
    auto get_id = [&](ll x) -> int{
        return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
    };
    
    for(int i = 1; i <= n; i++){
        ll num = get_id(a[i]);
        add(num, 1);
    }
    
    for(int i = 0; i < q; i++){
        ll num = get_id(a[p[i]]);
        add(num, -1);
        a[p[i]] += v[i];
        add(num, 1);
        auto get_num = [&](){
            int lo = 0, hi = N;
            while(lo < hi - 1){
                int mid = (lo + hi) >> 1;
                if(query(mid) <= n - n / 2)
                    lo = mid;
                else hi = mid;
            }
            return query(lo);
        };
        cout << get_num() << '\n';
    }
    for(int i = 1; i <= n; i++)
        add(get_id(a[i]), -1);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}