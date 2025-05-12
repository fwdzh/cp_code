#include<bits/stdc++.h>
using namespace std;

constexpr int INF = 1061109567;

int dis[110][210][5][5][5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(2 * n + 1));
    // vector<vector<int>> dis(n + 1, vector<int>(2 * n + 1, int(1e9)));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * i - 1; j++){
            cin >> a[i][j];
        }
    }
    auto cmp = [&](array<int, 6> x, array<int, 6> y){
        return x[0] > y[0];
    };
    priority_queue<array<int, 6>,vector<array<int, 6>>, decltype(cmp)>pq(cmp);
    memset(dis, 0x3f, sizeof dis);
    // cout << dis[0][0][0][0][0] << '\n';
    dis[1][1][1][3][2] = 0;
    pq.push({0, 1, 1, 1, 3, 2});
    int sx, sy;
    cin >> sx >> sy;
    int ans = INF;
    while(!pq.empty()){
        auto [dist, i, j, left, right, mid] = pq.top();
        // cerr << i << " " << j << " " << dist <<" " <<mid<< '\n';
        pq.pop();
        if(i == sx && j == sy){
            ans = min(ans, dist);
        }
        if((j % 2 == 0) && (i - 1) > 0){
            if(mid == a[i - 1][j - 1] && dist + 1 < dis[i - 1][j - 1][left][right][a[i][j]]){
                dis[i - 1][j][left][right][a[i][j]] = dist + 1;
                pq.push({dist + 1, i - 1, j - 1, left, 
                    right, a[i][j]});
            }
        }
        if((j & 1) && (i + 1 <= n)){
            if(mid == a[i + 1][j + 1] && dist + 1 < dis[i + 1][j + 1][left][right][a[i][j]]){
                dis[i + 1][j + 1][left][right][a[i][j]] = dist + 1;
                pq.push({dist + 1, i + 1, j + 1, left, 
                    right, a[i][j]});
            }         
        }
        if(j - 1 > 0){
            // 向左走
            if(a[i][j - 1] == left){
                
                if(j & 1){ // 奇数列的
                    if(dis[i][j - 1][mid][a[i][j]][right] > dist + 1){
                        dis[i][j - 1][mid][a[i][j]][right] = dist + 1;
                        pq.push({dist + 1, i, j - 1, mid, a[i][j], right});
                    }
                }else{
                    if(dis[i][j - 1][mid][a[i][j]][right] > dist + 1){
                        dis[i][j - 1][mid][a[i][j]][right] = dist + 1;
                        pq.push({dist + 1, i, j - 1, mid, a[i][j], right});
                    }
                }
            }
        }
        if(j + 1 <= 2 * i - 1){
            if(a[i][j + 1] == right){
                if(j & 1){
                    if(dis[i][j + 1][a[i][j]][mid][left] > dist + 1){
                        dis[i][j + 1][a[i][j]][mid][left] = dist + 1;
                        pq.push({dist + 1, i, j + 1, a[i][j], mid, left});
                    }
                }else{
                    if(dis[i][j + 1][a[i][j]][mid][left] > dist + 1){
                        dis[i][j + 1][a[i][j]][mid][left] = dist + 1;
                        pq.push({dist + 1, i, j + 1, a[i][j], mid, left});
                    }
                }
            }
        }
    }
    // cout << "-1\n";
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}