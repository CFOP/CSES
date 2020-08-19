#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi; //duration, deadline

class comp{
public:
    bool operator()(const pi &a, const pi &b)const{
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

priority_queue <pi, vector<pi>, comp> next;

int main(){
    int n; cin>>n;
    while(n--){
        int a, d; cin>>a>>d;
        ::next.push({a, d});
    }

    long long ans = 0;
    long long time = 0;
    while(::next.size()){
        auto next = ::next.top(); ::next.pop();
        ans += next.second - (time + next.first);
        time += next.first;
        //cout<<time<<" "<<ans<<"\n";
    }

    cout<<ans<<"\n";

    return 0;
}
