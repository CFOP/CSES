#include <iostream>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

int ans[MAX];

int main(){
    int n; cin>>n;

    ans[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=1; j<=6; j++){
            ans[i+j] += ans[i];
            ans[i+j] %= MOD;
        }
    }

    cout<<ans[n]<<"\n";
    return 0;
}
