#include <bits/stdc++.h>
using namespace std;
#define MAX 200100

int p[MAX];

int main(){
    int n, x;
    cin>>n>>x;

    for(int i=0; i<n; i++)
        cin>>p[i];

    sort(p, p+n);

    int ans = 0;
    for(int i=0, j=n-1; i<=j; j--){
        if(p[i]+p[j]<=x){
            ans++;
            i++;
        }
        else{
            ans++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
