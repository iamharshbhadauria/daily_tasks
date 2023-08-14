#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
vector<int> g[N];
int vis[N];
int lvl[N];
int parent[N]; 

void bfs(int ver){
    queue<int> q;
    q.push(ver);
    vis[ver] = 1;

    while(!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for(int child: g[curr]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                lvl[child] = lvl[curr] + 1;
            }
        }
    }
    return;
}

int main(){
    int n;
    cout << "Enter no of vertices in ur Tree : ";
    cin >> n;
    for(int i=0 ; i<n-1 ; ++i){
        int x ,  y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    return 0;
}