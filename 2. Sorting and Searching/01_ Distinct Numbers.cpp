#include <bits/stdc++.h>
using namespace std;

vector <int> x;

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        x.push_back(a);
    }
    sort(x.begin(), x.end());
    int s = 1;
    for(int i=1; i<n; i++)
        s += x[i-1]!=x[i];
    cout<<s<<"\n";
    return 0;
}
