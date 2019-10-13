#include <bits/stdc++.h>
using namespace std;
typedef long long LL; 

LL n,ar[100005];
LL solve(LL S[],LL m,LL n) {  
    LL dp[n + 1][m],x,y; 
    for(LL i=0;i<m;i++){
    	dp[0][i]=1;
    } 
    for(LL i=1;i<n+1;i++){ 
        for (LL j=0;j<m;j++){
            if(i-S[j]>=0){
            	x=dp[i-S[j]][j];
            } 
            else x=0;
            if(j>=1){
            	y=dp[i][j-1];
            }
            else y=0;
            dp[i][j] = x + y; 
        } 
    } 
    return dp[n][m - 1]; 
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>n){
		int i=1,j=0;
		while(i*i*i<=n){
			//cout<<i*i*i<<" ";
			ar[j++]=i*i*i;
			i++;
		}
		cout<<solve(ar,j,n)<<endl;

	}
	return 0;
}
