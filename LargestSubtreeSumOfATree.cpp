#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mxn=1e5+7;
vector<LL> adj[mxn],nude,po;
LL par[mxn];
bool vis[mxn];

void dfs(LL str){
	vis[str]=true;
	par[str]=1;
	stack<LL> st;
	st.push(str);
	while(!st.empty()){
		LL t=st.top();
		nude.push_back(t);
		st.pop();
		for(LL i=0;i<adj[t].size();i++){
			LL child=adj[t][i];
			if(!vis[child]){
				vis[child]=true;
				par[child]=t;
				st.push(child);
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	po.push_back(INT_MAX);
	for(LL i=1;i<=n;i++){
		LL k;
		cin>>k;
		po.push_back(k);
	}
	for(LL i=0;i<n-1;i++){
		LL u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	map<LL,LL> mark;
	for(LL i=1;i<=n;i++){
		mark[i]=1;
	}
	LL mx=INT_MIN,id,idmn=INT_MIN;
	for(LL i=nude.size()-1;i>=0;i--){
		//cout<<nude[i]<<endl;
		//if(po[nude[i]]>=0){
			if(par[nude[i]]!=nude[i]){
				//LL res=po[par[nude[i]]],res1=mark[par[nude[i]]];
				if(po[par[nude[i]]]+po[nude[i]]>=po[par[nude[i]]]){
					po[par[nude[i]]]+=po[nude[i]];
				mark[par[nude[i]]]+=mark[nude[i]];
				//cout<<po[par[nude[i]]]<<" "<<mark[par[nude[i]]]<<endl;
				if(po[par[nude[i]]]>mx){
					mx=po[par[nude[i]]];
					id=mark[par[nude[i]]];
				}
				else if(po[par[nude[i]]]==mx){
					mx=po[par[nude[i]]];
					if(mark[par[nude[i]]]>idmn){
						idmn=mark[par[nude[i]]];
						id=mark[par[nude[i]]];
					}	
				}
			}
		}
		//}
	}
	//cout<<mx<<" "<<endl;
	for(LL i=0;i<nude.size();i++){
		if(po[nude[i]]>mx){
			mx=po[nude[i]];
			id=1;
		}
	}
	//if(mx<0) cout<<0<<" "<<0<<endl;
	 cout<<mx<<" "<<id<<endl;
	return 0;
}