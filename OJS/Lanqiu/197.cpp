#include <iostream>
#include<algorithm>
using namespace std;
int n,d,k;
int b[100005];
struct node{
  int ts;
  int id;
};
node arr[100005];
bool a[100005];
bool cmp(node x,node y){
  return x.ts<y.ts;
}

int main()
{
  cin>>n>>d>>k;
  for(int i=1;i<=n;i++)
  cin>>arr[i].ts>>arr[i].id;
   sort(arr+1,arr+1+n,cmp);
   int l=1;
   for(int i=1;i<=n;i++)
   { 
     b[arr[i].id]++;
     while(arr[i].ts>=arr[l].ts+d)b[arr[l++].id]--;
     if(b[arr[i].id]>=k)a[arr[i].id]=true;
     

    /*
    奶龙陈俊杰
    */



   }
   for (int i=0;i<=100004;i++)
   if(a[i]){
     cout<<i<<endl;
   }
  // 请在此输入您的代码
  return 0;
}