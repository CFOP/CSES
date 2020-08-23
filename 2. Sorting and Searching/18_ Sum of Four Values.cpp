#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin>>n>>x;
    vector<int> a; //value, id
    map <int, vector<pair<int, int>>> value; //value, id

    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }

    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; j++){
            value[a[i]+a[j]].push_back({i+1, j+1});
        }
    }

    for(auto p = value.begin(); p!=value.end(); p++){
        int sum = p->first;
        auto next = value.find(x-sum);
        if(next!=value.end()){

                auto pr = p->second[0];
                for(auto ans : next->second){
                    if(ans.first != pr.first && ans.first != pr.second && ans.second != pr.first && ans.second != pr.second){
                        cout<<ans.first<<" "<<ans.second<<" "<<pr.first<<" "<<pr.second<<"\n";
                        return 0;
                    }
                }

                pr = next->second[0];
                for(auto ans : p->second){
                    if(ans.first != pr.first && ans.first != pr.second && ans.second != pr.first && ans.second != pr.second){
                        cout<<ans.first<<" "<<ans.second<<" "<<pr.first<<" "<<pr.second<<"\n";
                        return 0;
                    }
                }

                if(p->second.size()>1){
                    pr = p->second[0];
                    for(auto ans : next->second){
                        if(ans.first != pr.first && ans.first != pr.second && ans.second != pr.first && ans.second != pr.second){
                            cout<<ans.first<<" "<<ans.second<<" "<<pr.first<<" "<<pr.second<<"\n";
                            return 0;
                        }
                    }
                }

                if(next->second.size()>1){
                    pr = next->second[0];
                    for(auto ans : p->second){
                        if(ans.first != pr.first && ans.first != pr.second && ans.second != pr.first && ans.second != pr.second){
                            cout<<ans.first<<" "<<ans.second<<" "<<pr.first<<" "<<pr.second<<"\n";
                            return 0;
                        }
                    }
                }

        }
    }

    cout<<"IMPOSSIBLE\n";

    return 0;
}
