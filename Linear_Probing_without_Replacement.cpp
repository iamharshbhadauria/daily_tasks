#include<bits/stdc++.h>
using namespace std;

vector<int> par(10000,0);
void findpar(int u){
	if(u==par[u]) {
		return;
	}

	cout<<par[u]<<" ";
	findpar(par[u]);

}

int main(){
	int n,m;
	cin>>m>>n;

	vector<vector<pair<int,int>>> adj(n+1);
	set<vector<int>> st;
	for(int i=1;i<=n;i++)par[i]=i;
	vector<int> dis(n+1,1e8);

	for(int i=0;i<m;i++){
		int wt,u,v;
		cin >> wt >> u>>v;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}

	dis[1]=0;
	st.insert({0,1});
	
	while(!st.empty()){
		auto it=st.begin();
		int wt=(*it)[0];
		int node=(*it)[1];
		st.erase(it);
		for(auto itt : adj[node]){
			if(dis[itt.first]>itt.second+dis[node]){
				dis[itt.first]=itt.second+dis[node];
				par[itt.first]=node;
				st.insert({itt.second+dis[node],itt.first});
			}
		}
	}

	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";


	for(int i=1;i<=n;i++){
		cout<<i<<": ";
		findpar(i);
		cout<<endl;
	}


}