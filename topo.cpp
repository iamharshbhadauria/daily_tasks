#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << "Give number of vertices and edges in your graph : " << endl;
    int n , m1;
    cin >> n >> m1;
    map<int , int> m;

    for(int i=0 ; i<m1 ; ++i){
        cout << "Enter your vertices first one directing and second one directed : " << endl;
        int x , y;
        cin >> x >> y;
        m[y]++;
        m[x];
    }
    vector<pair<int , int>> v;
    for(auto it:m){
        v.push_back({it.second , it.first});
    }
    sort(v.begin() , v.end());

    cout << "Topological sort is  :  " ;
    for(int i=0 ; i<n ; ++i){
        cout << v[i].second << "  ";
    }
    return 0;
}