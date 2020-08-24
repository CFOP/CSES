#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int main(){
    int n, x; cin>>n>>x;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }

    int j = 0, k = 0;
    long long sum = 0;
    int ans = 0;
    while(j<n && k<n){
        sum+=a[k];
        ans += sum==x;
        if(sum<x || j==k)
            k++;
        else {
            sum-=a[j++];
            sum-=a[k];
        }
    }

    cout<<ans<<"\n";
    return 0;
}
