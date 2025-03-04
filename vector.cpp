#include<bits/stdc++.h>
using namespace std;
template<class T>
class cvec{
public:
    int size,mxsize;
    T*val=nullptr;

    cvec(int num=0,T va=0):
//无参构造就缺省处理
//缺省num为0,初始内存是10,采用max(10,2*num)
    size(num),mxsize(max(10,2*num)){
        val=new T[mxsize];
//memset适用于简单填充
        for(int i=0;i<size;i++){
            val[i]=va;
        }
    }
//深拷贝和赋值用来实现复杂结构的嵌套
    cvec(const cvec&b):
    size(b.size),mxsize(b.mxsize){
        val=new T[mxsize];
        for(int i=0;i<size;i++){
            val[i]=b[i];
        }
    }
    cvec& operator=(const cvec&b){
        if(this==&b)return *this;
//判断地址是不是自己本身,不能自己给自己赋值
        delete[] val;
        size=b.size;
        mxsize=b.mxsize;
        val=new T[mxsize];
        for (int i = 0; i < size; ++i) {
            val[i] = b[i];
        }
        return *this;
//返回本身
    }
    ~cvec(){
        delete []val;
//delete []val    
    }
    void push_back(T va){
        if(size>=mxsize){
            T*nv=new T[2*mxsize];
            for(int i=0;i<size;i++){
                nv[i]=val[i];
            }
            delete []val;
//delete []val 
            mxsize=2*mxsize;
//更新mxsize
            val=nv;
        }
        val[size]=va;
        size++;
    }
    void pop_back(){
        if(size>0)size--;
    }
    T&operator[](int i){
        return val[i];
    }
//实现for(auto t:) 
//需要begin和end函数普通还有const版本的,复杂
    T*begin(){
        return val;
    }
    T*end(){
        return val+size;
    }
    const T*begin()const{
        return val;
    }
    const T*end()const{
        return val+size;
    }
    const T& operator[](int i) const {
        return val[i];
    }
    void clear(){
        size=0;
    }
};
signed main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cvec<int>a;
    cvec<char>b(2,'A');
    for(int i=1;i<=25;i++){
        a.push_back(i);
        b.push_back(i+'A');
    }
	b.pop_back();
/*    for(auto t:b){
        cout<<t<<" ";
auto写法需要普通和const版本的begin与end
    }*/
   cvec<cvec<int>>vec(2,cvec<int>(2,0));
//想要实现双层需要深拷贝和赋值
//赋值也要有const写法
   for(auto i:vec){
        for(auto t:i){
            cout<<t<<" ";
        }cout<<endl;
   }

}
