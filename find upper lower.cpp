#include<bits/stdc++.h>
using namespace std;
template<class T>
int find(T val,T*a,int mxsize){
    int l=0,r=mxsize-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]>val)r=mid-1;
        else l=mid+1;
    }
    if(a[r]==val)return r;
    else return -1;
}
template<class T>
int lower(T val,T*a,int mxsize){
//ǡ��С��,rʧ��
    if(a[0]>val)return -1e9;
    int l=0,r=mxsize-1;    
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]>=val)r=mid-1;
        else l=mid+1;
    }
    return a[r];
}

template<class T>
int upper(T val,T*a,int mxsize){
//ǡ�ô���,lʧ��
    if(val>a[mxsize-1])return -1e9;
    int l=0,r=mxsize-1;    
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]>val)r=mid-1;
        else l=mid+1;
    }
    return a[l];
}
signed main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a[12]={1,7,7,15,23,78,99,100};
	cout<<upper(7,a,8);
}
