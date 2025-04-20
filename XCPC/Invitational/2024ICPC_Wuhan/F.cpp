#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    k=n*n-k+1;
    auto ask=[&](int i,int j,int x){
        cout<<"? "<<i<<" "<<j<<" "<<x<<endl;
        int res; cin >> res;
        return res;
    };
    auto check=[&](int x){
        int r=n,c=1,cnt=0;
        while(r>0&&c<=n){
            if(ask(r,c,x)) cnt+=r,c++;
            else r--;
        }
        return cnt>=k;
    };
    int lo=0,hi=n*n+1;
    while(lo<hi-1){
        int mid=(lo+hi)>>1;
        if(check(mid)) hi=mid;
        else lo=mid;
        // cerr<<lo<<" "<<hi<<endl;
    }
    cout<<"! "<<hi<<endl;
    return 0;
}