#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    for(long long i=1; i<=n; i++){
        //long long ans
        cout<< (i*i*(i*i-1)-4*2-8*3-4*4-4*(i-4)*4-4*(i-4)*6-(i-4)*(i-4)*8)/2 <<"\n";
    }
    return 0;
}
