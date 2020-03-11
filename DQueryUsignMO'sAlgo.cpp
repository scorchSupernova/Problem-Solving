#include "bits/stdc++.h"
#define SIZE          1000005
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
int sz,res[SIZE],ar[SIZE],cnt[SIZE],couunt=0;
struct QQuery{
	int id,l,r;
	bool operator<(const QQuery &extra) const{
		int mine=l/sz,oth=extra.l/sz;
		if(mine==oth) return r<extra.r;
		else return mine<oth;
	}
}query[SIZE];

void add(int index){
	cnt[ar[index]]++;
	if(cnt[ar[index]]==1) couunt++;
}
void minu(int index){
	cnt[ar[index]]--;
	if(cnt[ar[index]]==0) couunt--;
}
 
int main(){
	FAST;
	//freopen("test.in","r",stdin);
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>ar[i];
	}
	sz=sqrt(a);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>query[i].l>>query[i].r;
		query[i].l--;
		query[i].r--;
		query[i].id=i;
	}
	sort(query,query+q);
	int L1=0,R=-1;
	for(int i=0;i<q;i++){
		int ind=query[i].id;
		while(L1<query[i].l){
			minu(L1++);
		}
		while(L1>query[i].l){
			add(--L1);
		}
		while(R<query[i].r){
			add(++R);
		}
		while(R>query[i].r){
			minu(R--);
		}
		res[ind]=couunt;
	}
	for(int i=0;i<q;i++){
		cout<<res[i]<<endl;
	}

	//cerr<<"time elapsed:"<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<"\n";
	return 0;
}


