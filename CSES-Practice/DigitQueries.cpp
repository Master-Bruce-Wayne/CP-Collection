#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
// #define set(x, y) memset(x, y, sizeof(x))
#define sortall(x) sort(all(x))
#define revsortall(x) sort(x.rbegin(), x.rend())
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))
#define sz(x) (ll)(x).size()
#define PI 3.1415926535897932384626
#define INF 1e18
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pyes cout<<"Yes"
#define pno cout<<"No"


typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


#define whatis(x)   cout << #x << " is " << x << "\n";
#define debug(x)     cout << #x << ": " << x << endl;
#define debugTwo(x,y)   cout << #x << ": " << x << ", " << #y << ": " << y << endl; 
#define debugThree(x,y,z)  cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl; 
#define debug_p(x)   cout << #x << ": " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << ": "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << ": "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}


// const ll MOD = 1e9 + 7;
// ************* Code Starts ****************** //

 
// *** Sujal Agarwal *** // 
// *** NIT DGP'28  *** // 
 
// Important Points ->
// 1. upper_bound points to first value > val
// 2. lower_bound me equal to bhi aata hai (>=)


vl powTen(19,1);
void solve() {
    ll n; cin>>n;
    ll d1=0, d2=0;
    ll digits=0;
    for(ll i=1; i<19; i++) {
        d1+= (powTen[i]-powTen[i-1])*i;  // naya block
        if(d1>=n) {
            digits=i; break;
        }
        d2=d1;
    }

    // number dhundna
    ll lo=powTen[digits-1], hi=powTen[digits]-1;
    ll val=0, pos=0;
    while(lo<=hi) {
        ll mid=(lo+hi)/2;
        ll spos = d2+1+ (mid-powTen[digits-1])*digits;
        if(spos <= n) {
            if(mid>val) { val=mid; pos=spos; }
            lo=mid+1;
        }  
        else  hi=mid-1;
    }

    string num = to_string(val);
    cout<<num[n-pos];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(ll i=1; i<19; i++)  powTen[i]=powTen[i-1]*10;


    ll t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }

    return 0;
}