#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef vector<ll> vl;
typedef vector<vl> vvl;

const ll MOD = 1e9 + 7;

// ************* Code Starts ****************** //

class DSU {
    vl rank,parent,size;
    public:
    DSU(ll n) {
        rank.resize(n+1,0); parent.resize(n+1); size.resize(n+1);
        for(ll i=0; i<=n; i++) { parent[i]=i; size[i]=1; }
    }

    ll findUltPar(ll node) {   // path-compression
        if(node==parent[node]) { return node; }
        return parent[node]=findUltPar(parent[node]);
    }

    void unionByRank(ll u,ll v) {
        ll ulp_u=findUltPar(u), ulp_v=findUltPar(v);
        if(ulp_u==ulp_v)  return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v]=ulp_u;
        }
        else {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(ll u,ll v) {
        ll ulp_u=findUltPar(u), ulp_v=findUltPar(v);
        if(ulp_u==ulp_v)  return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
