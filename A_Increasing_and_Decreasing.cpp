#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int x , y , n;
    cin >> x >> y >> n;

    int diff = y-x;
    int a = (n*(n-1))/2;
    if(diff < a){
        cout << -1 << endl;
        return;
    }
    int arr[n];
    arr[n-1] = y;
    arr[0] = x;
    int count = 1;
    for(int i=n-2 ; i>0 ; --i){
        arr[i] = arr[i+1] - count;
        count++;
    }
    for(int i=0 ; i<n ; ++i) cout << arr[i] << " ";
    cout << endl;
    return;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    auto Harsh_Bhadauria = chrono::high_resolution_clock::now();

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}