#include<bits/stdc++.h>
using namespace std;
template<class T>
class cvec{
public:
    int size,mxsize;
    T*val=nullptr;

    cvec(int num=0,T va=0):
//�޲ι����ȱʡ����
//ȱʡnumΪ0,��ʼ�ڴ���10,����max(10,2*num)
    size(num),mxsize(max(10,2*num)){
        val=new T[mxsize];
//memset�����ڼ����
        for(int i=0;i<size;i++){
            val[i]=va;
        }
    }
//����͸�ֵ����ʵ�ָ��ӽṹ��Ƕ��
    cvec(const cvec&b):
    size(b.size),mxsize(b.mxsize){
        val=new T[mxsize];
        for(int i=0;i<size;i++){
            val[i]=b[i];
        }
    }
    cvec& operator=(const cvec&b){
        if(this==&b)return *this;
//�жϵ�ַ�ǲ����Լ�����,�����Լ����Լ���ֵ
        delete[] val;
        size=b.size;
        mxsize=b.mxsize;
        val=new T[mxsize];
        for (int i = 0; i < size; ++i) {
            val[i] = b[i];
        }
        return *this;
//���ر���
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
//����mxsize
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
//ʵ��for(auto t:) 
//��Ҫbegin��end������ͨ����const�汾��,����
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
autoд����Ҫ��ͨ��const�汾��begin��end
    }*/
   cvec<cvec<int>>vec(2,cvec<int>(2,0));
//��Ҫʵ��˫����Ҫ����͸�ֵ
//��ֵҲҪ��constд��
   for(auto i:vec){
        for(auto t:i){
            cout<<t<<" ";
        }cout<<endl;
   }

}
