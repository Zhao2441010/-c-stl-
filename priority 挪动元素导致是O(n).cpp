#include<bits/stdc++.h>
using namespace std;
template<class T,class compare=less<T>>
class cpr_queue{
public:
    compare cmp;
    int size=0,mxsize=10;
    T*val=new T[10];
    cpr_queue(){}
    ~cpr_queue(){
        delete []val;
    }
    void push(T va){
        if(size>=mxsize){
            T* nv=new T[2*mxsize];
            for(int i=0;i<size;i++){
                nv[i]=val[i];
            }
            delete []val;
            val=nv;
            mxsize*=2;
        }
/*        int i=0;
        while(i<size&&cmp(val[i],va))i++;
//i要小于size才能保证初始时也是正确的

*/
//二分优化
        int l=0,r=size-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(cmp(val[mid],va))l=mid+1;
            else r=mid-1;
        }
        int i=l;
        if(i==size){
            val[size]=va;
            size++;
        }
        else{
            for(int j=size+1;j>i;j--){
                val[j]=val[j-1];
            }
            val[i]=va;
            size++;
        }
    }
    T&top(){
        if(size)return val[size-1];
    }
    void pop(){
        if(size)size--;
    }
};
signed main(){
priority_queue<int,vector<int>,less<int>>p;
cpr_queue<int,greater<int>>q;
for(int i=1;i<=10;i++)q.push(i);
q.pop();
while(q.size){
    cout<<q.top()<<" ";
    q.pop();
}
    
}