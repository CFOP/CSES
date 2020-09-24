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
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin>>n>>m;

    UF uf(n+5);
    int max_sz = 1;

    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;

        if(!uf.sameSet(a, b)){
            uf.join(a, b);
            max_sz = max(max_sz, uf.size(a));
            n--;
        }

        cout<<n<<" "<<max_sz<<"\n";
    }

    return 0;
}
