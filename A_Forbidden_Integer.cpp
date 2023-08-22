#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n , k , x;
    cin >> n >> k >> x;
    if(x == 1){
        if(k == 1){
            cout << "NO" << endl;
            return;
        }
        if(k < 3) if(n%2 == 1){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        cout << n/2 << endl;
        if(n % 2 == 0) cout << 2 << " ";
        else cout << 3 << " ";
        for(int i=1 ; i<n/2 ; ++i){
            cout << 2 << " ";
        }
        cout << endl;
        return;
    }
    cout << "YES" << endl;
    cout << n << endl;
    for(int i=0 ; i<n ; ++i){
        cout << 1 << " ";
    }
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