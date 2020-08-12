#include <bits/stdc++.h>
using namespace std;

multiset <int, greater<int>> ticket;

int main(){
    int n, m;
    cin>>n>>m;
    while(n--){
        int a; cin>>a;
        ticket.insert(a);
    }

    while(m--){
        int a; cin>>a;
        auto ans = ticket.lower_bound(a);
        if(ans != ticket.end()){
            cout<<*ans<<"\n";
            ticket.erase(ans);
        }
        else cout<<-1<<"\n";
    }

    return 0;
}
