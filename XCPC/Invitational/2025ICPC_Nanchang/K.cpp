//
// Created by ilyha on 25-5-20.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>>n;
    int cnt[]{0, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    if (cnt[0] == n) {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; ; i++) {
        int tnc[4];
        for (int j = 0; j < 4; j++) {
            tnc[(j + i) % 4] = cnt[j];
        }
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += tnc[j] * j;
        }
        if (sum <= i) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}