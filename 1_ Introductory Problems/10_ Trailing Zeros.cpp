#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int p = 0;
    while(n){
        p+=n/5;
        n/=5;
    }
    cout<<p<<"\n";
    return 0;
}
