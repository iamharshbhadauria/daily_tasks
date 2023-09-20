#include<bits/stdc++.h>
using namespace std;
int visited[1001][1001];

int main(){
    int n , m;
    cin >> n >> m;

    int arr[n][m];
    for(int i=0 ; i<n;  ++i) for(int j=0 ; j<m ; ++j) cin >> arr[i][j];
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<m ; ++j){
            dfs(arr[i][j])
        }
    }

}