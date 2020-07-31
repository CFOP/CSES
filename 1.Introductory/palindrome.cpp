#include <bits/stdc++.h>
using namespace std;

int times[300];

int main(){
    string a;
    cin>>a;
    char s = 0;
    string ans;

    for(char c:a)
        times[c]++;

    for(char c = 'A'; c<='Z'; c++){
        if(times[c]%2){
            if(!s) s = c;
            else {
                cout<<"NO SOLUTION\n";
                return 0;
            }
            times[c]--;
        }
        for(int i=0; i<times[c]; i+=2)
            ans+=c;
    }

    if(s && !(a.size()%2)){
        cout<<"NO SOLUTION\n";
        return 0;
    }

    cout<<ans;
    if(s)cout<<s;
    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
}

//AABACACA
