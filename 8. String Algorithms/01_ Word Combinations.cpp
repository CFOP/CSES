#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

struct Trie{
    unordered_map<char, Trie*> children;
    ll ends;

    Trie(){
        ends = 0;
    }
};

int main(){
    string s; cin>>s;
    int k; cin>>k;
    Trie *head = new Trie();
    while(k--){
        string t; cin>>t;
        Trie *current = head;
        for(char c : t){
            if(current->children.find(c) == current->children.end())
                current->children[c] = new Trie();
            current = current->children[c];
        }
        current->ends++;
    }

    vector<ll> ans(s.size(), 0);
    ans.push_back(1);
    for(int i=s.size()-1; i>=0; i--){
        Trie *current = head;
        for(int j=i; j<s.size() and current->children.find(s[j]) != current->children.end(); j++){
            current = current->children[s[j]];
            ans[i] += (ans[j+1]*current->ends)%MOD;
            ans[i] %= MOD;
        }
    }

    cout<<ans[0]<<"\n";
}
