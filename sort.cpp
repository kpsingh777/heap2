#include<iostream>
#include<vector>
using namespace std;
void heapify(int i,vector<int> &vec,int n){
    
    int left=i*2+1;
    int right=i*2+2;
    int max=i;
    if(left<n && vec[left]>vec[max]){
        max=left;
    }
    if(right<n && vec[right]>vec[max]){
        max=right;
    }
    if(max!=i){
        swap(vec[i],vec[max]);
        heapify(max,vec,n);
    }
}
void heapsort(vector<int> &vec){
    int n=vec.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(i,vec,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(vec[0],vec[i]);
        heapify(0,vec,i);
    }
}
int main(){
    vector<int> vec={1,4,2,3,5};
    heapsort(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}