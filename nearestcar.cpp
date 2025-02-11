#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class car{
    public:
    int dist;
    int indx;
    car(int dist,int indx){
        this->dist=dist;
        this->indx=indx;
    }
    bool operator < (const car &obj)const{
        return this->dist > obj.dist;
    }
    };
void nearcar(vector<pair<int ,int >>pos,int k){
    vector<car> cars;
    for(int i=0;i<pos.size();i++){
        int dist= (pos[i].first * pos[i].first)+(pos[i].second+pos[i].second);
        cars.push_back(car(dist,i));
    } 
    priority_queue<car> pq(cars.begin(),cars.end());  //O(n)
    for(int i=0;i<k;i++){
        cout<<pq.top().indx<<endl;
        pq.pop();
    }
}
int main(){
    vector<pair<int,int>> pq;
    pq.push_back(make_pair(1,2));
    pq.push_back(make_pair(2,2));
    pq.push_back(make_pair(3,4));
    pq.push_back(make_pair(-1,2));
    pq.push_back(make_pair(-5,2));
    nearcar(pq,1);
    return 0;

}