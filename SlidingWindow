#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

deque<LL> q,qq;
vector<LL> v,vv;
LL mn=INT_MAX,mx=INT_MIN,id,id1;
void slidingWindow(LL ar[],int a,int b){
    for(int i=0;i<b;i++){
        while(!q.empty() and ar[i]>=ar[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        while(!qq.empty() and ar[i]<=ar[qq.back()]){
            qq.pop_back();
        }
        qq.push_back(i);
    }
    for(int i=b;i<a;i++){
        LL res=ar[q.front()]-ar[qq.front()];
        if(res<mn){
            mn=res;
            id=i-b;
        }
        if(res>mx){
            mx=res;
            id1=i-b;
        }
        while(!q.empty() and q.front()<=i-b){
            q.pop_front();
        }
        while(!qq.empty() and qq.front()<=i-b){
            qq.pop_front();
        }
        while(!q.empty() and ar[i]>=ar[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        while(!qq.empty() and ar[i]<=ar[qq.back()]){
            qq.pop_back();
        }
        qq.push_back(i);
    }
    LL res=ar[q.front()]-ar[qq.front()];
    if(res<mn){
        mn=res;
        id=a-(b);
    }
    if(res>mx){
        mx=res;
        id1=(a-(b));
    }
    
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a,b;
    cin>>a>>b;
    LL ar[a];
    for(int i=0;i<a;i++){
        cin>>ar[i];
    }
    slidingWindow(ar,a,b);
    cout<<id+1<<" "<<id1+1<<endl;
   // v.push_back(ar[q.front()]-ar[qq.front()]);
    //for(LL i=0;i<v.size();i++) cout<<v[i]<<" ";
    return 0;
}
