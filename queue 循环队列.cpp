#include<bits/stdc++.h>
using namespace std;
template<class T>
class cqueue{
public:
    int mxsize=10;
    T*val=new T[10];
    int f=0,b=0;
//�ȹ���,������
    cqueue(){}
    ~cqueue(){
        delete val;
    }
    void push(T va){
        if((b+1)%mxsize==f){
//ע����(b+1)%mxsize==f
//�����޷��ж�f����0�����
            T*nv=new T[2*mxsize];
            for(int i=f;i<mxsize;i++){
//�ȴ�f��mxsize,�ٴ�0��b
//ע��nv�����д��
                nv[i-f]=val[i];
            }
            for(int i=0;i<f;i++){
                nv[mxsize-f+i]=val[i];
            }
//�����µ�mxsize
            mxsize*=2;
            delete []val;
            val=nv;
        }
        val[b]=va;
//�ȸ�ֵ,������
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