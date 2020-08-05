#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;

int main(){
    int n, m, k;
    cin>>n>>m;
    cin>>k;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        ::a.push_back(a);
    }
    for(int i=0; i<m; i++){
        int b; cin>>b;
        ::b.push_back(b);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int s =0;
    for(int i=0, j=0; i<b.size() && j<a.size(); ){
        //cout<<i<<" "<<j<<"\n";
        if(a[j]-k<=b[i] && a[j]+k>=b[i]){
            s++;
            i++;
            j++;
        }
        else if(a[j]+k<b[i])
            j++;
        else i++;
    }
    cout<<s<<"\n";

    return 0;
}
