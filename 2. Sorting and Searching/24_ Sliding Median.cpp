#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin>>n>>k;
    multiset<int> first;
    multiset<int> last;
    vector<int> x;

    for(int i=0; i<k; i++){
        int z; cin>>z;
        last.insert(z);
        x.push_back(z);
    }

    for(int i =0 ; i<(k-1)/2+1; i++){
        first.insert(*last.begin());
        last.erase(last.begin());
    }
    cout<<*first.rbegin()<<" ";

    for(int i=k; i<n; i++){
        int z; cin>>z;
        x.push_back(z);
        //cout<<x[i-k]<<" ";
        if(last.find(x[i-k])!=last.end()){
            last.erase(last.find(x[i-k]));
        }
        else{
            first.erase(first.find(x[i-k]));
            if(k>1){
                first.insert(*last.begin());
                last.erase(last.begin());
            }
        }

        first.insert(z);
        if(first.size()>(k-1)/2+1){
            last.insert(*first.rbegin());
            auto p = first.end();
            p--;
            first.erase(p);
        }

        cout<<*first.rbegin() <<" ";
    }
    cout<<"\n";

    return 0;
}
