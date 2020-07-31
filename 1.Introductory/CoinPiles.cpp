#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int a, b;
    cin>>a>>b;
    if(a<b) swap(a, b); ///A es el mayor
    int dif = a-b;
    a-=2*dif;
    b-=dif;
    if(a<0 || b<0)
        return false;
    return !(a%3);
}

int main(){
    int t; cin>>t;
    while(t--){
        if(solve())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
