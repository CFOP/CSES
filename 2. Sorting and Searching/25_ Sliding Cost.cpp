#include <bits/stdc++.h>
using namespace std;

typedef long long ull;
queue <int> q;

inline int mid(int k){
    return (k-1)/2+1;
}

int main(){
    int n, k; cin>>n>>k;
    long long cost = 0;

    if(k==1){
        while(n--) cout<<0<<" ";
        return 0;
    }

    vector <int> aux;
    ull sumL = 0, sumR = 0;
    for(int i=0; i<k; i++){
        int z; cin>>z;
        q.push(z);
        aux.push_back(z);
        sumR += z;
    }
    sort(aux.begin(), aux.end());

    for(int i=0; i<mid(k); i++)
        sumL += aux[i];
    sumR -= sumL;

    multiset<int>left, right;
    for(int i=0; i<mid(k); i++)
        left.insert(aux[i]);
    for(int i=mid(k); i<k; i++)
        right.insert(aux[i]);

    //cout<<mid(k)<<"#\n";
    cout<< (*left.rbegin()*left.size() - sumL) + (sumR - *left.rbegin()*right.size()) <<" ";

    for(int i=k; i<n; i++){

        /*for(int x : left)
            cout<<x<<" ";
        cout<<" ## ";
        for(int x : right)
            cout<<x<<" ";
        cout<<"\n";*/

        //delete first element
        if(right.find(q.front())==right.end()){
            left.erase(left.find(q.front()));
            sumL -= q.front();
        }
        else{
            right.erase(right.find(q.front()));
            sumR -= q.front();
        }
        q.pop();

        //insert new element
        int z; cin>>z;
        left.insert(z);
        q.push(z);
        sumL+=z;

        //balance set
        if(mid(k)<left.size()){
            auto toDelete = left.end();
            toDelete--;
            sumL -= *toDelete;
            sumR += *toDelete;
            right.insert(*toDelete);
            left.erase(toDelete);
        }
        if(*left.rbegin() > *right.begin()){
            sumL -= *left.rbegin();
            sumL += *right.begin();
            left.insert(*right.begin());

            sumR -= *right.begin();
            sumR += *left.rbegin();
            right.insert(*left.rbegin());

            right.erase(right.begin());
            auto p = left.end();
            left.erase(--p);
        }

        //cout<<left.size()<<" "<<right.size()<<" "<<sumL<<" "<<sumR<<" "<<*left.rbegin()<<"\n";
        cout<< (*left.rbegin()*left.size() - sumL) + (sumR - *left.rbegin()*right.size()) <<" ";

    }


    return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10

8 3
2 4 3 5 8 1 2 1

8 4
2 4 3 5 8 1 2 1

4 6 9 10 8

4 4
8 1 2 1
*/
