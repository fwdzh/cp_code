#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> a(3, vector<int> (3));
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int j = 0; j < 3; j++){
            if(a[j][0] >= x){
                a[j][0]++;
                a[j][1]++;
                a[j][2] = 0;
                x = INT_MAX;
            }else{
                a[j][2]++;
                if(a[j][2] == 3){
                    a[j][0] += 2;
                    a[j][2] = 0;
                }
            }
        }
    }
    for(int i = 0; i < 3; i++)
        cout << a[i][1] << " \n" [i == 2];
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}