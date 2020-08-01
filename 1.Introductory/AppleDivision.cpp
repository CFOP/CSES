#include <bits/stdc++.h>
using namespace std;

vector <int> p;
long long m;

void bsk(long long a=0, long long b=0, int i=0){
    if(i==p.size()){
        m = min(m, abs(a-b));
        return;
    }
    bsk(a+p[i], b, i+1);
    bsk(a, b+p[i], i+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        p.push_back(a);
    }
    m = LONG_MAX;
    bsk();
    cout<<m<<"\n";
    return 0;
}
