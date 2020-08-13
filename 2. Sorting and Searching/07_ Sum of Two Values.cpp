#include <bits/stdc++.h>
using namespace std;

map <int, int> complement;

int main(){
    int n; cin>>n;
    int x; cin>>x;

    for(int i=1; i<=n; i++){
        int a; cin>>a;
        int b = x-a;
        if(complement.find(b) == complement.end()){
            complement[a] = i;
        }
        else {
            cout<<complement[b]<<" "<<i<<"\n";
            return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";

    return 0;
}
