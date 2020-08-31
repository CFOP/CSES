#include <bits/stdc++.h>
using namespace std;

map<long long, long long, greater<long long>> dp; //time, money
set <pair<pair<long long, long long>, long long>> project; //end, start, reward

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;

    for(int i=0; i<n; i++){
        long long a, b, p;
        cin>>a>>b>>p;
        project.insert( { {b, a}, p} );
    }

    for(auto p : project){
        //cout<<p.second<<"# ";
        if(dp.upper_bound(p.first.second) == dp.end() && (!dp.size() || p.second > dp.begin()->first) ){
            dp[p.first.first] = max((long long)dp[p.first.first], (long long)p.second);
        }
        else if(dp.upper_bound(p.first.second) != dp.end()){
            long long time = p.first.first;
            long long money = dp.upper_bound(p.first.second)->second + p.second;
            if(dp.lower_bound(time) == dp.end() || dp.lower_bound(time)->second < money){
                dp[time] = money;
                auto k = dp.find(time);
                while(k != dp.begin() && money > k->second){
                    dp.erase(--k);
                    k = dp.find(time);
                }
                if(dp.begin()->second < money)
                    dp.erase(dp.begin());
            }
        }
        /*for(auto k : dp)
            cout<<k.first<<","<<k.second<<" ";
        cout<<"\n";*/
    }

    cout<<dp.begin()->second<<"\n";;

    return 0;
}
