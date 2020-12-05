#include <bits/stdc++.h>
using namespace std;

typedef int ull;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key

orderedMultiSet oms;
multiset<int> ms;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin>>n>>q;
    vector<int> p; p.push_back(0);
    for(int i=0; i<n; i++){
        int z; cin>>z;
        p.push_back(z);
        ms.insert(z);
        oms.insert(z);
    }

    while(q--){
        char c; cin>>c;

        if(c=='!'){
            int k, x; cin>>k>>x;
            ms.erase(ms.find(p[k]));
            //cout<<p[k]<<"\n";

            //cout<<oms.size()<<"\n";
            oms.erase(oms.find_by_order(oms.order_of_key(p[k])));
            //cout<<oms.size()<<"\n";

            p[k] = x;
            ms.insert(x);
            oms.insert(x);
        }
        else {
            int a, b; cin>>a>>b;
            int sz = 0;
            if(ms.upper_bound(b)!=ms.end() && ms.upper_bound(a)!=ms.end())
                sz = oms.order_of_key(*ms.upper_bound(b)) - oms.order_of_key(*ms.lower_bound(a));
            else if(ms.upper_bound(b)==ms.end() && ms.upper_bound(a)!=ms.end())
                sz = n - oms.order_of_key(*ms.lower_bound(a));
            //cout<<*ms.upper_bound(b)<<" "<<oms.order_of_key(*ms.lower_bound(a))<<"\n";
            cout<<sz<<"\n";
        }

    }


}
