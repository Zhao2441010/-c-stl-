#include<iostream>
using namespace std;
template <class T>
struct node{
    T val;
    node<T>*pre=nullptr;
    node<T>*next=nullptr;
    node(T va):val(va){}
    bool operator()(node<T>b){
        return val>b.val;
    }
};
template<class T>
class clist{
public:
    node<T>*root=nullptr;
    node<T>*tail=nullptr;
    int size=0;
    clist(){}
    ~clist(){
            node<T>*now=root;
            while(1){
                if(now==nullptr){
                    break;
                }else{
                    node<T>*t=now;
                    now=now->next;
                    delete t;
                }
            }
    }
    void push_back(T val){
        node<T>*t=new node<T>(val);
        if(root==nullptr){
            root=t;
            tail=t;
        }else{
            t->pre=tail;
            tail->next=t;
            tail=t;
        }
        size++;
    }
    void push_front(T val){
        node<T>*t=new node<T>(val);
        if(root==nullptr){
            root=t;
            tail=t;
        }else{
            node<T>*l=root;
            l->pre=t;
            t->next=l;
            root=t;
        }
        size++;
    }
    void pop_back(){
        if(root!=nullptr){
            tail=tail->pre;
            delete tail->next;
            tail->next=nullptr;
//恢复末尾为nullptr,避免出错
            size--;
        }
        if(size==0){
            root=tail=nullptr;
        }
    }
    void pop_front(){
        if(root!=nullptr){
            node<T>*t=root;
            root=root->next;
            delete t;
            size--;
        }
        if(size==0)root=tail=nullptr;
    }
    node<T>*indx(int i){
    //返回下标为i的地址
        if(0<=i&&i<size){
            node<T>*t=root;
            while(i--){
                t=t->next;
            }
            return t;
        }
    }
    T& operator[](int i){
        if(0<=i&&i<size){
            return indx(i)->val;
        }
    }
    void insert(int i,T val){
        if(i==0)this->push_front(val);
        else if(i==size)this->push_back(val);
    //i是size-1是在size-1位置插入而不是直接在后
//注意是else if 避免0也是size-1的情况     
//单独考虑首尾        
        else{
            node<T>*t=new node<T>(val);
            node<T>*q=this->indx(i-1);
            node<T>*x=q->next;
            t->pre=q;
            t->next=x;
            q->next=t;
            x->pre=t;
            size++;
        }
    }
    void pop(int i){
        if(i==0)this->pop_front();
        else if(i==size-1)this->pop_back();
        else{
        node<T>*wait=this->indx(i);
        wait->pre->next=wait->next;
        wait->next->pre=wait->pre;
//修复后也修复前        
        delete wait;
        size--;
        }
    }
    int find(T&val){
        int ind=0;
        node<T>*now=root;
        while(1){
            if(now->val==val){
                return ind;
            }else {
                now=now->next;
                ind++;
            }
            if(ind==this->size)return ind;
        }
    }
    void show(){
        if(root==nullptr){
            cout << "empty" << endl;
            return;
        }
        node<T>*now=root;
        while(1){
            cout <<now->val<< " ";
            if(now->next==nullptr)break;
            now=now->next;
        }
        cout << endl;
    }
};
template <class T>
void swap_ele(node<T> a,node<T> b){
    node<T>t=a;
    a.val=b.val;
    b.val=t.val;
}
template<class T>
node<T>* advance(node<T>*a,int num){
    if(a==nullptr){
        cout<<"empty"<<endl;
    }
    else if(num>=0){
        while(num--){
            if(a->next==nullptr)break;
            a=a->next;
        }
        if(num>0){
            cout<<"out size"<<endl;
        }else{
            return a;
        }
    }else if(num<0){
        while(num++){
            if(a->pre==nullptr)break;
            a=a->pre;
        }
        if(num<0){
            cout<<"out size"<<endl;
        }else{
            return a;
        }
    }
}
int main(){
ios::sync_with_stdio(0),cin.tie(0);
    
    
}