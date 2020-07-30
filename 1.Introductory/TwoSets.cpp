#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    vector <int> *a, *b;
    a = new vector<int>();
    b = new vector<int>();
    for(int i=n; i>1; i-=2){
        a->push_back(i);
        b->push_back(i-1);
        swap(a, b);
    }
    if(n%2)
        a->push_back(1);
    /*if(a->size()>b->size())
        swap(a, b);*/

    long long sumA=0, sumB=0;
    for(int i : *a) sumA +=i;
    for(int i : *b) sumB +=i;

    if(sumA == sumB){
        cout<<"YES\n";
        cout<<a->size()<<"\n";
        for(int i : *a) cout<<i<<" ";
        cout<<"\n";

        cout<<b->size()<<"\n";
        for(int i : *b) cout<<i<<" ";
        cout<<"\n";
    }
    else cout<<"NO\n";
    return 0;
}
