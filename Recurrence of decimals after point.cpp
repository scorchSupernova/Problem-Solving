#include <bits/stdc++.h> 
using namespace std; 


string fractionToDecimal(int numr, int denr) 
{ 
	string res;
	map <int, int> mp; 
	mp.clear(); 
	int rem = numr%denr; 
	while ( (rem!=0) && (mp.find(rem) == mp.end()) ) 
	{ 
		mp[rem] = res.length(); 
		rem = rem*10; 
		int res_part = rem / denr; 
		res += to_string(res_part); 
		rem = rem % denr; 
	} 

	return (rem == 0)? "" : res.substr(mp[rem]); 
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--){ 
		int n;
		cin>>n;
	string res=fractionToDecimal(1, n); 
	if (res == "") 
		cout << "No"<<endl; 
	else
		cout << "Yes"<<endl;} 
	return 0; 
} 

