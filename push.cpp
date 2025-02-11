#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int>vec;
    public:
    void push(int val){
        vec.push_back(val);
        int child=vec.size()-1;
        int par=(child-1)/2;
        while(par>=0 && vec[child]>vec[par]){
            swap(vec[child],vec[par]);
            child=par;
            par=(child-1)/2;
        }
    }
    void heapify(int i){
        if(i>vec.size()){
            return ;
        }
        int l=i*2+1;
        int r=i*2+2;
        int max=i;
        if(l>vec.size() && vec[l]>vec[max]){
            max=l;
                }
        if(r>vec.size() && vec[r]>vec[max]){
            max=r;
        }
        swap(vec[i],vec[max]);
        if(max!=i){
            heapify(max);
        }
    }
    void pop(){
        swap(vec[0],vec[vec.size()-1]);
        vec.pop_back();
        heapify(0);
    }
    int top(){
        return vec[0];
    }
    bool empty(){
        return vec.size()==0;
    }
};
int main(){
    Heap heap;
    heap.push(50);
    heap.push(20);
    heap.push(100);
    cout<<heap.top()<<endl;
    heap.pop();
    cout<<heap.top();
    return 0;
}