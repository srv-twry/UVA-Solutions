#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 998244353;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

const int N = 1e6+2;
ll fact[N],n;

ll power(ll x,ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

ll modInverse(ll a, ll m){
	return power(a,m-2,m);
}


int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    fact[0] = 1;
    F(i, 1, N) {
    	fact[i] = i * fact[i-1];
    	fact[i] %= MOD;
    }

    cin>>n;
    ll ans = fact[n] * n; ans %= MOD;

    F(i, 1, n) {
    	ll tmp = fact[n];
    	tmp *= modInverse(fact[i], MOD);
    	tmp %= MOD;
    	ans = (ans - tmp + MOD) % MOD;
    }
    cout<<ans;
    return 0;
}/*

*/
