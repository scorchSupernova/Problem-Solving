#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int no_of_chars = 256; 

LL findSubString(string str, string pat) 
{ 
	LL len1 = str.length(); 
	LL len2 = pat.length(); 
	LL hash_pat[no_of_chars] = {0}; 
	LL hash_str[no_of_chars] = {0}; 
	for (int i = 0; i < len2; i++) 
		{hash_pat[pat[i]]++;} 
	LL start = 0, start_index = -1, min_len = INT_MAX; 
	LL count = 0;
	for (int j = 0; j < len1 ; j++) 
	{ 
		hash_str[str[j]]++; 
		if (hash_pat[str[j]] != 0 && 
			hash_str[str[j]] <= hash_pat[str[j]] ) 
			count++; 
		if (count == len2) 
		{ 
			while ( hash_str[str[start]] > hash_pat[str[start]] 
				|| hash_pat[str[start]] == 0) 
			{ 

				if (hash_str[str[start]] > hash_pat[str[start]]) 
					hash_str[str[start]]--; 
				start++; 
			} 
			LL len_window = j - start + 1; 
			if (min_len > len_window) 
			{ 
				min_len = len_window; 
				start_index = start; 
			} 
		} 
	} 
	LL res=((start_index+min_len-1))-start_index;
	return res;
} 

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s,s1;
	cin>>s>>s1;
	if(s.length()<s1.length()) cout<<0<<endl;
	else
	cout<<findSubString(s,s1)<<endl;
	//cout<<sm<<endl;
	return 0;
}
