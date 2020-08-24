#include <bits/stdc++.h>
using namespace std;

typedef long long ull;
vector <ull> x;
int k;

bool posible(ull m){
    int k = ::k;
    ull sum = 0;
    for(ull x : ::x){
        while(sum+x > m){
            k--;
            if(!k) return false;
            sum = 0;
        }
        sum+=x;
    }
    return true;
}

//000000000000000000111111111111111111111
ull bS(ull left = 0, ull right = LLONG_MAX){ //(left, right]
    if(left+1>=right)
        return right;
    ull m = (right-left)/2 + left;
    if(posible(m))
        return bS(left, m);
    return bS(m, right);
}

int main(){
    int n; cin>>n>>k;

    while(n--){
        ull z; cin>>z;
        x.push_back(z);
    }

    cout<<bS()<<"\n";
    return 0;
}
