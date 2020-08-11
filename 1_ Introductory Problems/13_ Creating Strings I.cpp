#include <bits/stdc++.h>
using namespace std;
string a;
unordered_set <string> permutaciones;
vector <string> ans;

void permutar(int i=0){
    if(i==a.size()){
        permutaciones.insert(a);
        return;
    }
    for(int j=i; j<a.size(); j++){
        swap(a[j], a[i]);
        permutar(i+1);
        swap(a[j], a[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    sort(a.begin(), a.end());
    permutar();

    cout<<permutaciones.size()<<"\n";
    for(string s : permutaciones)
        ans.push_back(s);
    sort(ans.begin(), ans.end());
    for(string s : ans)
        cout<<s<<"\n";

    return 0;
}
