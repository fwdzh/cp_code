#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    /*
     * 假设前面是 x 个朝下的，k - x 个朝上
     * 后面是 k - x 个朝上的
     */
    cout << string(k, '1') + string(n - k, '4') << '\n';
    return 0;
}