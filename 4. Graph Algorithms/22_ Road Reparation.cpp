#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ull;
typedef pair<ull, pair<int, int>> pii;

struct UF{
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) {return find(a) == find(b);}
    int size(int x) {return -e[find(x)];}
    int find(int x) {return e[x] < 0 ? x : e[x] = find(e[x]);}
    bool join(int a, int b){
        a = find(a), b = find(b);
        if(a==b) return false;
        if(e[a]>e[b]) swap(a, b);
        e[a]+=e[b]; e[b] = a;
        return true;
    }
};

int main(){

    int n, m; cin>>n>>m;

    UF uf(n+5);
    priority_queue<pii, vector<pii>, greater<pii>> nxt;

    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        nxt.push({c, {a, b}});
    }

    ull ans = 0;
    while(nxt.size()){
        int a = nxt.top().second.first, b = nxt.top().second.second;
        ull c = nxt.top().first;
        nxt.pop();

        if(uf.sameSet(a, b)) continue;
        uf.join(a, b);
        ans += c;
    }

    int st = uf.find(1);
    for(int i = 1; i<=n; i++){
        if(uf.find(i)!=st){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
