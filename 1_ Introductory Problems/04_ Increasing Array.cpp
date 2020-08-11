#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    long long a, b;
    cin>>n;
    cin>>a;
    n--;
    long long ans =0;
    while(n--){
        cin>>b;
        if(a>b)ans+=a-b;
        else a= b;
    }
    cout<<ans<<"\n";
    return 0;
}
