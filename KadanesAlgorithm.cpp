#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL kadane1(LL ar[],LL a){
	LL max_cur=ar[0];
	LL max_glo=ar[0];
	for(int i=1;i<a-1;i++){
		max_cur=max(ar[i],max_cur+ar[i]);
		max_glo=max(max_cur,max_glo);
	}
	return max_glo;
}
LL kadane2(LL ar[],LL a){
	LL max_cur=ar[1];
	LL max_glo=ar[1];
	for(int i=2;i<a;i++){
		max_cur=max(ar[i],max_cur+ar[i]);
		max_glo=max(max_glo,max_cur);
	}
	return max_glo;
}
int main(int argc, char const *argv[]){
	int t;
	cin>>t;
	while(t--){
		int a;
		cin>>a;
		LL ar[a];
		LL sum=0;
		for(int i=0;i<a;i++){
			cin>>ar[i];
			sum+=ar[i];
		}
		LL res=kadane1(ar,a);
		//cout<<res<<endl;
		LL ress=kadane2(ar,a);
		//cout<<ress<<endl;
		if(max(res,ress)<sum) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
