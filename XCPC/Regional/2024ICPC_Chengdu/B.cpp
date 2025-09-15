#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-12 18:53:59
int dp[3][301][301], ndp[3][301][301], ans[301][301][301];
constexpr int mod = 1000000007;
void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = " " + s;
    
    //dp a,x,y 表示当前字符是 a,用了x个a，y个b的方案数量
    // dp[0][0][0] = dp[1][0][0] = dp[2][0][0] = 1;
    int cnt = 0; // 已经填好的字符的数量
    if(s[1] == '?'){
        dp[0][1][0] = dp[1][0][1] = dp[2][0][0] = 1;
        cnt = 1;
    }else{
        dp[s[1] - 'a'][0][0] = 1;
    }
    for(int i = 2; i <= n; i++){
        // memset(ndp, 0, sizeof(ndp));
        if(s[i] != '?'){
            // 当前结尾
            int c = s[i] - 'a';
            for(int last = 0; last < 3; last++){
                if(last == c) continue;
                for(int x = 0; x <= cnt; x++){
                    for(int y = 0; y + x <= cnt; y++){
                        ndp[c][x][y] = (ndp[c][x][y] + dp[last][x][y]) % mod;
                    }
                }
            }
        }else{
            for(int now = 0; now < 3; now++){
                for(int last = 0; last < 3; last++){
                    if(now == last) continue;
                    // if(s[i - 1] != '?' && s[i - 1] - 'a' != last) continue;
                    for(int x = 0; x <= cnt; x++){
                        for(int y = 0; x + y <= cnt; y++){
                            if(now == 0)
                                ndp[0][x + 1][y] = (ndp[0][x + 1][y] + dp[last][x][y]) % mod;
                            else if(now == 1)
                                ndp[1][x][y + 1] = (ndp[1][x][y + 1] + dp[last][x][y]) % mod;
                            else
                                ndp[2][x][y] = (ndp[2][x][y] + dp[last][x][y]) % mod;
                        }
                    }
                }
            }
            ++cnt;
        }
        for(int now = 0; now < 3; now++){
            for(int x = 0; x <= cnt; x++){
                for(int y = 0; y + x <= cnt; y++){
                    dp[now][x][y] = ndp[now][x][y];
                    ndp[now][x][y] = 0;
                }
            }
        }
    }
    for(int c = 0; c < 3; c++){
        for(int x = 0; x <= cnt; x++){
            for(int y = 0; x + y <= cnt; y++){
                int z = cnt - x - y;
                ans[x][y][z] = (ans[x][y][z] + dp[c][x][y]) % mod;
                // if(dp[c][x][y]){
                //     cerr << format("dp : {}, [c,x,y] : [{}, {}, {}]\n", dp[c][x][y], c, x, y);
                // }
            }
        }
    }
    // 不对。。。
    for(int x = 1; x <= 300; x++)
    for(int y = 0; y <= 300; y++)
    for(int z = 0; z <= 300; z++)
        ans[x][y][z] = (ans[x][y][z] + ans[x - 1][y][z]) % mod;
    for(int y = 1; y <= 300; y++)
    for(int x = 0; x <= 300; x++)
    for(int z = 0; z <= 300; z++)
        ans[x][y][z] = (ans[x][y][z] + ans[x][y - 1][z]) % mod;
    for(int z = 1; z <= 300; z++)
    for(int x = 0; x <= 300; x++)
    for(int y = 0; y <= 300; y++)
        ans[x][y][z] = (ans[x][y][z] + ans[x][y][z - 1]) % mod;
    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        cout << ans[x][y][z] << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}