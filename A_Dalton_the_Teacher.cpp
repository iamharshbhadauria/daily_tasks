#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    int arr[n];
    int count =0;
    for(int i=0 ; i<n ; ++i) cin >> arr[i];
    for(int i=0 ; i<n ; ++i){
        if(arr[i] == i+1) count++;
    }
    cout << (count + 1)/2 << endl;
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