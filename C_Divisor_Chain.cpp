#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
vector<bool> prime(N , true);
vector<int> final;

void is_prime(){
    for (int i=2; i*i<=N; ++i) if (prime[i] == true) for (int j = i*2 ; j <=N ; j += i) prime[j] = false;
    for (int i=2; i<=N; ++i) if (prime[i]) final.push_back(i);
    // for (int i=0; i<=final.size(); ++i) if (prime[i]) cout << final[i] << " ";
}


void solve(){
    int n;
    cin >> n;
    vector<int> v;
    map<int , int> mp;
    while(n>1){
        int x , y=final.size() , a=0;
        while(y--){
            if(n%final[a] == 0){
                x = final[a];
                break;
            }
            a++;
            if(final[a] >= n){
                y = 0;
                break;
            }
        } 
        if(y == 0){
            x = 1;
        }
        int z = n/x;
        v.push_back(n); 
        int u = n - z;
        int v = n - x;
        if(prime[u] == true){
            if(mp[x] > 0){
                n -= z;
                mp[z]++;
            }
            else{
                if(mp[x] == 2){
                    n -= z;
                    mp[z]++;
                }
                else{
                    n -= x;
                    mp[x]++;
                }
            }
        }
        else{
            if(mp[z] > 0){
                n -= x;
                mp[x]++;
            }
            else{
                if(mp[z] == 2){
                    n -= x;
                    mp[x]++;
                }
                else{
                    n -= z;
                    mp[z]++;
                }
            }
        }
    }

    cout << v.size() + 1 << endl;
    for(int i=0 ; i<v.size() ; ++i) cout << v[i] << " ";
    cout << 1 << endl;
    return;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    auto Harsh_Bhadauria = chrono::high_resolution_clock::now();
    is_prime();

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}