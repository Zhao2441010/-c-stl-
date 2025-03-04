#include<bits/stdc++.h>
using namespace std;
template<class T,class cmp=less<T>>
//预置比较类(结构体重载()运算符)
void kp(T*begin,T*end,cmp func=cmp()){

    if(begin>end)return;
    T* mid=(begin+end)>>1;
    T* l=begin;
    T* r=end;
    while (l<r){
        while(func(*l,*mid))l++;
        while(func(*mid,*r))r--;
        if(l<r){
            T t=*l;
            *l=*r;
            *r=t;
        }
    }
    kp(begin,--r,func);
    kp(++l,end,func);
}
//传普通函数需要删掉比较类,在函数参数表加上
//返回类型 (*func)(类型,类型)
template<class T>
void kp(T*begin,T*end,bool(*func)(T,T)){

    if(begin>end)return;
    T* mid=(begin+end)>>1;
    T* l=begin;
    T* r=end;
    while (l<r){
        while(func(*l,*mid))l++;
        while(func(*mid,*r))r--;
        if(l<r){
            T t=*l;
            *l=*r;
            *r=t;
        }
    }
    kp(begin,--r,func);
    kp(++l,end,func);
}
signed main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a[12]={12,11,10,9,8,7,6,5,4,3,2,1};
    sort(a,a+12);
    for(int i=0;i<12;i++){
        cout<<a[i]<<" ";
    }
}
