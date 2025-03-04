#include<bits/stdc++.h>
using namespace std;
template<class T>
class cqueue{
public:
    int mxsize=10;
    T*val=new T[10];
    int f=0,b=0;
//先构造,后析构
    cqueue(){}
    ~cqueue(){
        delete val;
    }
    void push(T va){
        if((b+1)%mxsize==f){
//注意是(b+1)%mxsize==f
//否则无法判断f还是0的情况
            T*nv=new T[2*mxsize];
            for(int i=f;i<mxsize;i++){
//先从f到mxsize,再从0到b
//注意nv里面的写法
                nv[i-f]=val[i];
            }
            for(int i=0;i<f;i++){
                nv[mxsize-f+i]=val[i];
            }
//更新新的mxsize
            mxsize*=2;
            delete []val;
            val=nv;
        }
        val[b]=va;
//先赋值,后增加
        b=(b+1)%mxsize;
    }
    void pop(){
        if(f==b)return ;
        f=(f+1)%mxsize;
    }
    T& front(){
        if(f!=b)
        return val[f];
    }
    T& back(){
        if(f!=b)
        return val[b];
    }
    int size(){
        return f<b?b-f:f-b;
    }
};
signed main(){
    cqueue<char>q;
    for(int i=0;i<26;i++){
        q.push(i+'a');
    }
    while(q.size()){
        cout<<q.front()<<" ";
        q.pop();
    }
}