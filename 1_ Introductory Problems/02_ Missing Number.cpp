#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

bool number[MAX];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int a; cin>>a;
        number[a]=true;
    }
    for(int i=1; i<=n; i++){
        if(!number[i]){
            cout<<i<<"\n";
            return 0;
        }
    }
    return 0;
}
