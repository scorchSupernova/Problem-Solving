#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL gcdExtended(LL a, LL b, LL *x, LL *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    LL x1, y1;
    LL gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
void modInverse(LL a, LL m)
{
    LL x, y;
    LL g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout<<-1<<endl;
    else
    {
        LL res = (x%m + m) % m;
        if(res==0){
            res+=m;
        }
        cout<<res<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL t;
    cin>>t;
    while(t--){
    LL a,b;
    cin>>a>>b;
    modInverse(a,b);
    }
    return 0;
}
