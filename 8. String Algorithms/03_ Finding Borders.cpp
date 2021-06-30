#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    vector<int> border_pattern(s.size(), 0);
    int j = 0;
    for(int i=1; i<s.size(); i++){
        while(j>0 and s[j]!=s[i])
            j = border_pattern[j-1];
        if(s[j]==s[i])
            j++;
        border_pattern[i] = j;
    }

    vector<int> ans;
    int i = s.size()-1;
    while(border_pattern[i]){
        ans.push_back(border_pattern[i]);
        i = border_pattern[i]-1;
    }
    reverse(ans.begin(), ans.end());

    for(auto k : ans)
        cout<<k<<" ";
    cout<<"\n";
    return 0;
}
