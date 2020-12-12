#include <bits/stdc++.h>
using namespace std;

typedef long long ull;

struct Range{

    ull min_sum;
    ull max_sum;
    ull sum;
    ull max_range;

    Range() : min_sum(0), max_sum(0), sum(0), max_range(0) {}
    Range(ull value) : sum(value), min_sum(value), max_sum(value), max_range(value){}
    Range(ull sum, ull min_sum, ull max_sum, ull max_range) : sum(sum), min_sum(min_sum), max_sum(max_sum), max_range(max_range){}
};

inline Range join_range(Range a, Range b){
    return Range(
                 a.sum + b.sum, //sum
                 min(a.min_sum, b.min_sum+a.sum), //min_sum
                 max(a.max_sum, b.max_sum+a.sum), //max_sum
                 max( {a.max_range, b.max_range, b.max_sum + a.sum - a.min_sum} ) //max_range
    );
}

template<typename T = Range> struct ST{
    int l, r;
    T acum;

    ST *left, *right;

    T none = Range();

    T operation(T a, T b){
        return join_range(a, b);
    }

    ST(int l, int r, vector<T> &arr): l(l), r(r){
        if(l >= arr.size())
            acum = none;
        else if(l==r)
            acum = arr[r];
        else {
            int m = (l+r)/2;
            left = new ST(l, m, arr);
            right = new ST(m+1, r, arr);
            acum = operation(left->acum,  right->acum);
        }
    }

    T get(int l, int r){
        if(this->l > r || this->r < l)
            return none;
        //cout<<this->l<<" "<<this->r<<" "<<this->acum<<"\n";
        if(this->l >= l && this->r <= r)
            return acum;
        int m = (l+r)/2;
        return operation(left->get(l, r), right->get(l, r));
    }

    T update(int i, T v){
        if(i > r || i < l)
            return acum;

        if(i>=l && i<=r){
            if(l==r)
                return acum = v;
            acum = operation(left->update(i, v), right->update(i, v));
        }
        return acum;
    }

};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin>>n>>m;

    vector<Range> v;
    v.push_back(Range());
    for(int i=1; i<=n; i++){
        ull x; cin>>x;
        v.push_back(Range(x));
    }

    ST<Range> st(0, n, v);

    /*const int sz = 1;
    for(int i=1; i+sz-1<=n; i++)
        cout<<st.get(i, i+sz-1).max_sum<<" ";
    cout<<"#\n";*/

    while(m--){
        ull k, x; cin>>k>>x;
        st.update(k, Range(x));

        cout<<st.get(0, n).max_range<<"\n";
    }

    return 0;
}
