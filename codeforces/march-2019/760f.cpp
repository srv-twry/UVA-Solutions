#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 5005;
ll dp[N][26], totalsum[N],last[26]={-1},n,sz;
string s,t;

const int MAXN = 1e4+5;
ll factorial[MAXN], inverse[MAXN];

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

void pre() {
    factorial[0] = 1LL; inverse[0] = modInverse(factorial[0], MOD);
    for (int i = 1; i < MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inverse[i] = modInverse(factorial[i], MOD);
    }
}

ll binomial_coefficient(ll n, ll k) {
    return factorial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>sz>>t;
    pre();
    s = "";
    char prev = t[0];
    FOR(i, 1, t.size()) {
    	if(t[i]==prev) continue;
    	s.push_back(prev);
    	prev = t[i];
    }
    s.push_back(prev);
    memset(dp, 0, sizeof(dp));
    memset(totalsum, 0, sizeof(totalsum));
    memset(last, -1, sizeof(last));
    n = s.size();
    totalsum[0]=1;

   	FOR(i, 0, n) {
   		int val = s[i]-'a';
   		FOR(j, 1, i+2) {
   			totalsum[j] = (totalsum[j] - dp[j][val] + MOD)%MOD;
			totalsum[j] = totalsum[j] + (totalsum[j-1] - dp[j-1][val] + MOD)%MOD; 
			dp[j][val] = (totalsum[j-1] - dp[j-1][val] + MOD)%MOD;
   		}
   	}

    ll ans = 0;
    FOR(i, 1, n+1) {
		ans += (totalsum[i] * binomial_coefficient(sz - 1, i - 1))%MOD;
		ans %= MOD;	
    }
    cout<<ans;

    return 0;
}