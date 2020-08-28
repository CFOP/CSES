#include <bits/stdc++.h>
using namespace std;

#define MAX 1001000
#define MOD 1000000007

int steps[MAX];

int main(){
    int n; cin>>n;
    fill(steps, steps+MAX, -1);
    steps[n] = 0;
    for(int i=n; i>0; i--){
        if(steps[i]==-1)continue;
        string s = to_string(i);
        //cout<<i<<"# "<<steps[i]<<"\n";
        for(char c : s){
            int v = c-'0';
            if(i-v >= 0){
                if(steps[i-v]==-1) steps[i-v] = steps[i] + 1;
                steps[i-v] = min(steps[i-v], steps[i] + 1);
            }
        }
    }
    cout<<steps[0]<<"\n";
}
