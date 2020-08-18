#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> pi;

vector<ull> k;
int n, t;

bool posible(ull m){
    ull realT = 0;
    for(ull k : ::k){
        realT += m/k;
    }
    return realT>=t;
}

//0000000000000000000000000000000001111111111111111111111111111111 search first true
ull bs(ull left = 0, ull right = ULLONG_MAX){ //right inclusive
    if(left+1 >= right)
        return right;
    ull m = (right-left)/2 + left;
    if(posible(m))
        return bs(left, m);
    return bs(m, right);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie();

    cin>>n>>t;
    while(n--){
        int k; cin>>k;
        ::k.push_back(k);
    }

    cout<<bs()<<"\n";

    return 0;
}
