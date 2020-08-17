#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    long long y, x;
    while(t--){
        long long ans;
        long long actual;
        cin>>x>>y;
        actual = max(y,x) -1 ;
        ans = actual * actual;
        if(actual%2){//impar
            if(y>x){
                ans += x;
            }
            else {
                ans += x;
                ans += x-y;
            }
        }
        else {
            if(y<x){
                ans += y;
            }
            else {
                ans += y;
                ans += y-x;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
