#include <bits/stdc++.h>
using namespace std;

typedef long long ull;

map <ull, ull> last;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ull n; cin>>n;

    ull sum = 0;
    ull ans = 0;
    last[0] = 1;
    for(int i=0; i<n; i++){
            int z; cin>>z;
            sum+=z;
            ans += last[sum%n];
            if(sum>0)
                ans += last[-(n-sum%n)];
            else if(sum<0)
                ans += last[-(-n-sum%n)];
            last[sum%n]++;
    }

    cout<<ans<<"\n";

    return 0;
}
