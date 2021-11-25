// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int i, int n){
    int lar = i;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if(l<n && a[l]>a[lar]){
        lar=l;
    }
    if(r<n && a[r]>a[lar]){
        lar=r;
    }
    
    if(lar!=i){
        swap(a[i],a[lar]);
        heapify(a, lar, n);
    }
}
void buildHeap(vector<int> &a, int n){
    
    int startindex=(n/2)-1;
    
    for(int i=startindex; i>=0; i--){
        heapify(a, i, n);
    }
}
void heapSort(vector<int>&a, int n){
    buildHeap(a, n);
    for(auto e:a){
        cout<<e<<" ";
    }
    cout<<endl;
    for(int i=n-1; i>0; i--){
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
    
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(auto e:a){
        cout<<e<<" ";
    }cout<<endl;
    heapSort(a, n);
    for(auto e:a){
        cout<<e<<" ";
    }
    return 0;
}
