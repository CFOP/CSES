#include <bits/stdc++.h>
using namespace std;

int main(){
    string a; cin>>a;
    int ans = 0;
    char last = 'L';
    int actual = 0;

    for(char c : a){ //AAAAAAAAAA
        if(last != c){
            ans = max(actual, ans);
            actual = 1;
            last = c;
        }
        else actual++;
    }
    ans = max(ans, actual);

    cout<<ans<<"\n";

    return 0;
}
