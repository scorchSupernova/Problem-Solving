#include <bits/stdc++.h>
using namespace std;

struct node{
    node* next[27];
    bool endmark;
    node(){
        endmark = false;
    for(int i=0; i<26; i++)
        next[i] = NULL;
    }

}*root;

void insert(char *str, int len)
{
    node* curr = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool search(char *str,int len)
{
    node* curr = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i]-'a';
        if(curr->next[id]==NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

int main()
{
    root = new node();
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        char str[50];
        cin>>str;
        insert(str,strlen(str));
    }
    int q;
    cin>>q;
    while(q--)
    {
        char q_val[100];
        cin>>q_val;
        if(search(q_val,strlen(q_val)))
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;
    }
}
