#include<bits/stdc++.h>
using namespace std;

class mst{
    
    int n , m;
    int id[100];
    int arr[100][100];
    bool visited[100];
    vector<pair<int , pair<int , int>>> v;
    public:
        mst(){
            for(int i=0 ; i<100 ; ++i){
                visited[i] = false;
                id[i] = i;
                    for(int j=0 ; j<100 ; ++j) arr[i][j] = 0;
            }
            n = m = 0;
        }
        int root(int);
        void input();
        int Union(int , int);
        void Krushkal();
        void Prims();
};

void mst:: input(){
    cout << "Enter no of vertices and edges in ur graph : " << endl;
    //int n , m;
    cin >> n >> m;
    for(int i=0 ; i<m ; ++i){
        cout << "Eneter verices and weight of edge : ";
        int x , y , w;
        cin >> x >> y >> w;
        arr[x][y] = w;
        arr[y][x] = w;
        v.push_back({w , {x , y}});
    }
}

int mst:: root(int x){
    if(id[x] == x) return x;
    else root(id[x]);
}

int mst:: Union(int x , int y){
    id[x] = id[y];
}

void mst:: Krushkal(){
    int mincost = 0;
    sort(v.begin() , v.end());
    // int m = v.size();
    for(int i=0 ; i<m ; ++i){
        int x = v[i].second.first;
        int y = v[i].second.second;
        int w = v[i].first;
        if(root(x) != root(y)){
            cout << "Nodes : " << x << "  " << y << " Weight : " << w << endl;
            mincost += w;
            Union(x , y); 
        }
    }
    cout << "Total cost by Krushkals is : " << mincost << endl;
    return;
}

void mst:: Prims(){
    visited[1] = true;
    int mincost = 0;
    for(int k=0 ; k<n-1 ; ++k){
        int mn = INT_MAX , start , end;
        for(int i=1 ; i<=n ; ++i){
            if(visited[i] == false) continue;
            for(int j=1 ; j<=n ; ++j){
                if(arr[i][j] == 0 || visited[j] == true) continue;
                if(arr[i][j] < mn){
                    start = i;
                    end = j;
                    mn = arr[i][j];
                }
            }
        }
        visited[end] = true;
        mincost += arr[start][end];
        cout << "Nodes : " << start << "  " << end << " Weight : " << arr[start][end] << endl;
    }
    cout << "Total cost by Prims is : " << mincost << endl;
    return;
}


int main()
{
    int in;
    mst t;
    do
    {
        cout << "----------------------------------------------------" << endl;
        cout << "1. ENTER INPUT " << endl;
        cout << "2. KRUSHKALS " << endl;
        cout << "3. PRIMS" << endl;
        cout << "0. EXIT" << endl;
        cout << "----------------------------------------------------" << endl;
        cin >> in;
        switch (in)
        {
        case 1:
            t.input();
            break;
        case 2:
            t.Krushkal();
            break;
        case 3:
            t.Prims();
            break;
        default:
            cout << "END" << endl;
        }
    } while (in);
}

