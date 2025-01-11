#include <climits>
#include<iostream>
using namespace std;

struct List{
    struct linklist{
        int data;
        linklist* next;
        linklist(int val):data(val),next(nullptr){}
    };//定义结构体
    linklist* L;//作为头结点
    List(){
        L=new linklist(0);
        L->next=nullptr;
    }

    List(int a[],int l,int r){
        L=new linklist(0);
        linklist* curr=L;
        for(int i=l;i<=r;i++){
            linklist* now=new linklist(a[i]);
            curr->next=now;
            curr=now;
        }
    }

    void reverse(){
        //反转单链表
        //思路是把每一个结点的next指向原本的前驱
        linklist* prev=nullptr;
        linklist* curr=L->next;
        linklist* next=nullptr;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        L->next=prev;
        //curr表示当前的结点，prev表示前一个结点，next表示下一个结点
        //每次把当前结点的后继改成原本的前驱，就能反转
        //最后把最后一个结点摄制成最后一个结点
    }

    int min_val(){
        //查找最小值
        int res=INT_MAX;
        linklist* p=L->next;
        while(p!=nullptr){
            res=min(res,p->data);
            p=p->next;
        }
        return res;
    }

    void print(){
        linklist* p=L->next;
        while(p!=nullptr){
            cout<<p->data<<' ';
            p=p->next;
        }
        cout<<'\n';
    }

    ~List(){
        delete L;
    }
};
int main()
{
    // int n;
    // cin>>n;
    // int* a=new int[n+1];
    int a[]={0,6,7,8,9,10};
    // for(int i=1;i<=n;i++)
    //     cin>>a[i];
    List L(a,1,5);
    L.print();
    L.reverse();
    L.print();
    cout<<L.min_val()<<'\n';
}