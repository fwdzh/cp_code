#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek() // Date: 2025-04-14
{                      // Time: 16:54:03 
    int n;
    cin>>n;
    vector<int>a(n+1),c(n+1);
    vector<ll>b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    sort(c.begin()+1,c.end());
    auto check=[&](ll H){
        vector<int>pre(n+1),suf(n+1);
        //pre表示x的下标小于等于i才满足 suf表示下标大于等于i才满足
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                ll need=(H-b[i])/a[i]; //找大于等于这个的
                if(H-b[i]>0&&(H-b[i])%a[i]) need++;
                int idx=lower_bound(c.begin()+1,c.end(),need)-c.begin();
                if(idx<=n) suf[idx]++;
            }else if(a[i]<0){
                ll need=(H-b[i])/a[i];
                if(H-b[i]>0&&(H-b[i])%a[i]) need--;
                int idx=upper_bound(c.begin()+1,c.end(),need)-c.begin()-1;
                if(idx>=1) pre[idx]++;
            }else if(b[i]>=H) pre[n]++;
        }//1 0 1 0
        // for(int i=1;i<=n;i++) cerr<<pre[i]<<" \n"[i==n]; for(int i=1;i<=n;i++) cerr<<suf[i]<<" \n"[i==n];
        ll sum=0,xum=0;
        for(int i=1;i<=n;i++) sum+=pre[i];
        for(int i=1;i<=n;i++){
            xum=min(xum+pre[i],ll(i));
            sum-=pre[i];//要前面的贡献加上后面的贡献
            pre[i]=min(xum+sum,ll(i));
            pre[i]=max(pre[i],pre[i-1]);
        }
        for(int i=1;i<=n;i++) sum+=suf[i];
        xum=0;
        for(int i=n;i>=1;i--){
            xum=min(xum+suf[i],ll(n-i+1));
            sum-=suf[i];
            suf[i]=min(xum+sum,ll(n-i+1));
            if(i<n) suf[i]=max(suf[i],suf[i+1]);
        }
        // for(int i=1;i<=n;i++) cerr<<pre[i]<<" \n"[i==n]; for(int i=1;i<=n;i++) cerr<<suf[i]<<" \n"[i==n];
        if(suf[1]>=(n+1)/2||pre[n]>=(n+1)/2) return true;
        for(int i=1;i+1<=n;i++)
            if(pre[i]+suf[i+1]>=(n+1)/2) return true;
        return false;
    };
    ll l=-2e18,r=2e18,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid))
            l=mid+1,ans=mid;
        else
            r=mid-1;
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}