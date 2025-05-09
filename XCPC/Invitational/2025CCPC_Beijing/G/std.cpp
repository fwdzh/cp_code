/*
质因子分解表：线性筛 + 最小质因子 = 质因子分解表（不断压榨）

状态降维DP（非i为节点遍历，特殊变量）：在所有候选答案中，找到最长的，然后去更新，维护最大和次大
eg：不互质，颜色不同...
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dwn(i,a,b) for(int i = a; i >= b; i--)
#define vi vector<int>
typedef long long ll;
const int N = 5e5+10;
int n, w[N], c[N],spf[N+1], cur, curbest, ans;

//质因子分解表：线性筛 + 最小质因子 = 质因子分解表（不断%/）
void build_spf(){
    vector<int> prime;
    for(int i = 2; i <= N; i++){
        if(!spf[i]){
            spf[i] = i;
            prime.push_back(i);
        }
        
        for(auto p : prime){
            if(i*p > N)break;
            spf[p*i] = p;
            if(i%p == 0)break;
        }
    }
}

vector<int> factor(int x){
    vector<int> fs;
    while(x>1){
        int p = spf[x];
        fs.pb(p);
        while(x%p == 0) x/=p;
    }
    return fs;
}

struct Node{
    int len, col;
}best1[N], best2[N];

void solve(){
    cin >> n;
    rep(i,1,n) cin >> w[i];
    rep(i,1,n) cin >> c[i];

    for(int i = 1; i <= n; i++){
        curbest = 0;
        auto fs = factor(w[i]);

        for(auto p : fs){
            if(c[i] != best1[p].col) curbest = max(curbest, best1[p].len);
            else curbest = max(curbest, best2[p].len);
        }

        cur = curbest + 1;
        ans = max(cur, ans);

        for(auto p : fs){
            if(c[i] == best1[p].col){
                best1[p].len = max(cur, best1[p].len);
            }else{
                if(cur > best1[p].len){
                    best2[p] = best1[p];
                    best1[p] = {cur, c[i]};
                }else if(cur > best2[p].len){
                    best2[p] = {cur, c[i]}; //接上去
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    build_spf();
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//int _;cin>>_;while(_--)
	solve();return 0;
}
