#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    set<pi, greater<pi>> Kotivalo; //time, id
    set<pi, greater<pi>> Justina; //time, id

    for(int i=0; i<n; i++){
        int z; cin>>z;
        Kotivalo.insert({z, i});
        Justina.insert({z, i});
    }

    int j=-1, k=-1;
    long long ansJ = 0;
    long long ansK = 0;
    while(Kotivalo.size() || Justina.size()){
        if(!Justina.size() || (Kotivalo.size() && ansK <= ansJ)){
            if(Kotivalo.begin()->second!=j){ // no lo esta leyendo Justina
                k = Kotivalo.begin()->second;
                ansK += Kotivalo.begin()->first;
                Kotivalo.erase(Kotivalo.begin());
            }
            else {
                auto p = Kotivalo.begin();
                p++;
                if(p==Kotivalo.end()){
                    ansK = ansJ;
                    p--;
                }
                ansK += p->first;
                k = p->second;
                Kotivalo.erase(*p);
            }
        }
        else {
            if(Justina.rbegin()->second!=k){ // no lo esta leyendo Justina
                j = Justina.rbegin()->second;
                ansJ += Justina.rbegin()->first;
                Justina.erase(*Justina.rbegin());
            }
            else {
                auto p = Justina.rbegin();
                p++;
                if(p==Justina.rend()){
                    ansJ = ansK;
                    p--;
                }
                ansJ += p->first;
                j = p->second;
                Justina.erase(*p);
            }
        }
        //cout<<j<<" "<<k<<" ";
        //cout<<ansJ<<" "<<ansK<<" ";
        //cout<<Justina.size()<<" "<<Kotivalo.size()<<"\n";
    }
    cout<< max(ansK, ansJ)<<"\n";
    return 0;

}
