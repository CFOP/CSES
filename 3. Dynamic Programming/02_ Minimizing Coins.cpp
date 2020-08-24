#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100

long long ans[MAX];
vector <int> c;

int main(){
    int n; cin>>n;
    int x; cin>>x;

    while(n--){
        int z; cin>>z;
        c.push_back(z);
        ans[z] = 1;
    }

    for(int i=0; i<=x; i++){
        if(!ans[i]) continue;
        for(int c : ::c){
            if(i+c <= x){
                if(!ans[i+c])ans[i+c] = ans[i]+1;
                ans[i+c] = min(ans[i+c], ans[i]+1);
            }
        }
    }

    if(ans[x])
        cout<<ans[x]<<"\n";
    else cout<<-1<<"\n";
    return 0;
}

