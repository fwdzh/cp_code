#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<>> R;
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        L.push(num);
        //123
        //12 3
        while(L.size() > R.size() + 1){
            auto x = L.top(); L.pop();
            R.push(x);
        }
        while(L.size() && R.size() && L.top() > R.top()){
            auto x = L.top(), y = R.top();
            L.pop(), R.pop();
            L.push(y), R.push(x);
        }
        // if(i >= 2)
        // cerr << L.top() << " " << R.top() << '\n';
        if(i & 1)
            cout << L.top() << ' ';
        else
            cout << (L.top() + R.top()) / 2 << " ";
    }
}