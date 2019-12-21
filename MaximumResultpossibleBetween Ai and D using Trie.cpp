#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int p;
struct node
{
    int val;
    node *child[2];
};

void insert(node *trie, int x, int id)
{   
    if(id < 0) {
        return;
    }
    int k=(x>>id)&1;

    if(!trie->child[k]) {
        trie->child[k]=new node;
    }
    insert(trie->child[k], x, id-1);
}

void find(node *trie, int x, int id)
{   
    if(id<0) {
        return;
    }

    int k=(x>>id)&1;
    k^=1;

    if(!trie->child[k]) {
        k^=1;
    }
    p=p<<1|k;
    find(trie->child[k], x, id-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin>>n;
    int ar[n];
    map<LL,LL> mp;
    for(int i=0;i<n;i++) {
        cin>>ar[i];
        mp[ar[i]]=i+1;
    }

    node *trie = new node;
    for(int i=0;i<n;i++) {
        insert(trie,ar[i],31);
    }

    int t,tt=1;
    cin>>t;
    while(t--) {
    	LL x;
        cin>>x;
        p=0;
        find(trie,x,31);
        LL res=p^x;
        cout<<"Query "<<tt++<<": ";
        cout<<mp[p]<<" "<<res<<endl;
    }

    return 0;
}
