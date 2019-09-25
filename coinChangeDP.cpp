#include <bits/stdc++.h>
using namespace std;
#define mod 100000009
int dp[55][7500];
int coin[55];
int koibar[55];
int am,n;
long long isPossible(int i,int amount)
{
    if(i>5)
    {
        if(amount==0)
            return 1;
            else
            return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int ret1 =0,ret2=0;
    for(int j=1; j<=koibar[i]; j++)
    {
        if(amount-coin[i]*j>=0)
        ret1 = isPossible(i+1,amount-(coin[i]*j))%mod;
        else
        break;
    }

        ret2 = isPossible(i+1,amount)%mod;
        return dp[i][amount] = (long long)ret1+ret2;
}
int main()
{
    int t;
    memset(dp,-1,sizeof(dp));
    cin>>t;
    while(t--)
    {
        int i,c;
        cin>>n>>am;
        for(i=1; i<=n; i++)
            cin>>coin[i];
         for(i=1; i<=n; i++){
                cin>>koibar[i];
                }
        cout<<isPossible(1,am)<<endl;
    }
}
© 2019 GitHub, Inc.
