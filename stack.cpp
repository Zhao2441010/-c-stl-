#include<bits/stdc++.h>
using namespace std;
template<class T>
class cstack{
public:
    int size=0,mxsize=9;
    T*val=nullptr;
    cstack(){
        val=new T[10];
    }
    ~cstack(){
        delete []val;
    }
    void pop(){
        if(size==0) return;
        size--;
    }
    void push(T b){
        if(size>=mxsize){
            T*nv=new T[2*mxsize];
            for(int i=1;i<=mxsize;i++){
                nv[i]=val[i];
            }
            mxsize=2*mxsize-1;
//通过减一保证不会越界            
            delete[]val;
            val=nv;
        }
        size++;
        val[size]=b;
    }
    T& top(){
        return val[size];
    }
    void clear(){
        size=0;
    }
};
signed main(){
    cstack<int>s;
    s.push(5);
    cout <<s.top()<< endl;
    s.pop();
    if(!s.size)cout << "ok" << endl;
}