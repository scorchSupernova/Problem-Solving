#include <bits/stdc++.h>
#define SIZE          10000007
#define REM           1000000007
#define PI            2*acos(0.0)
#define L             long
#define LL            long long
#define UL            unsigned long
#define ULL           unsigned long long
#define TERMINATE     return 0
#define FAST          ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
template <class T> inline T bigmod1(T p,T e,T M){
    LL ret=1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
} 
template <class T> inline T gcode(T a,T b){if(b==0)return a;return gcode(b,a%b);}
template <class T> inline T modularinv(T a,T M){return bigmod1(a,M-2,M);} 
bool SA(const pair<string,string> &a, const pair<string,string> &b){
   return a.second<b.second;
}
bool FA(const pair<string,string> &a, const pair<string,string> &b){
   return a.first<b.first;
}
bool SD(const pair<LL,LL> &a, const pair<LL,LL> &b){
   return a.second>b.second;
}
bool FD(const pair<int,int> &a, const pair<int,int> &b){
   return a.first>b.first;
}
//int dirA[8]={0,0,1,-1,1,-1,1,-1};
//int dirB[8]={1,-1,0,0,1,-1,-1,1};
//int dirA[4]={0,0,1,-1};
//int dirB[4]={1,-1,0,0};
//int kingsA[8]={0,0,1,-1,-1,1,-1,1};  //Kings Move
//int kingsB[8]={-1,1,0,0,1,1,-1,-1};  //Kings Move
//int knightsA[8]={-2,-2,-1,-1,1,1,2,2};  //Knights Move
//int knightsB[8]={-1,1,-2,2,-2,2,-1,1};  //Knights Move
int tree[4*10005];
int ar[10005];
void buildTree(int node,int b,int e){
	if(b==e) {
		tree[node]=ar[b];
		//cout<<ar[b]<<endl;
		return ;
	}
	int bam=node*2,dan=node*2+1;
	int majh=(b+e)/2;
	buildTree(bam,b,majh);
	buildTree(dan,majh+1,e);
	tree[node]=max(tree[bam],tree[dan]);
	//cout<<tree[node]<<endl;
}
int cnt[10004];
int que(int node,int b,int e,int l,int r){
	//cout<<b<<" "<<e<<" "<<l<<" "<<r<<endl;
	if(l>e or r<b) return INT_MIN;
	if(b>=l and e<=r) {
		//cout<<tree[node]<<endl;
		return tree[node];
		//cnt[tree[node]]++;
	}
	int bam=node*2,dan=node*2+1;
	int majh=(b+e)/2;
	int w=que(bam,b,majh,l,r);
	int q=que(dan,majh+1,e,l,r);
	LL mx=max(w,q);
	
	return mx;
}
unordered_map< int, vector<int> > store; 
int findFrequency(int arr[], int n, int left, 
                      int right, int element) 
{
    int a = lower_bound(store[element].begin(), 
                        store[element].end(), 
                        left) 
            - store[element].begin(); 
 
    int b = upper_bound(store[element].begin(), 
                        store[element].end(), 
                        right) 
            - store[element].begin(); 
  
    return b-a; 
} 
int main(){
	int t,tt=1;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&ar[i]);
			store[ar[i]].push_back(i);
		}
		printf("Case %d:\n",tt++);
		buildTree(1,0,n-1);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			int k=que(1,0,n-1,a,b);
			int res=findFrequency(ar,n,a,b,k);
			printf("%d\n",res);
		}
		store.clear();
	}
	TERMINATE;
}
