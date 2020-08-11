#include <bits/stdc++.h>
using namespace std;

bool d[20]; //x+y
bool d2[20]; // y-x+8
bool l[10]; //y

char m[10][10];

long long ans;

long long bsk(int x=0){
    if(x==8)
        return 1;

    long long sum = 0;
    for(int y=0; y<8; y++){
        if(d[y+x] || d2[y-x+8] || l[y])
            continue;
        if(m[y][x]=='*') continue;
        d[y+x] = d2[y-x+8] = l[y] = true;

        sum += bsk(x+1);

        d[y+x] = d2[y-x+8] = l[y] = false;

    }
    return sum;
}

int main(){
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            cin>>m[i][j];

    cout<<bsk()<<"\n";
    return 0;
}
