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
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000009;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x << endl; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
ll mulmod(ll a, ll b, ll m) { ll q = (ll)(((ld)a*(ld)b) / (ld)m); ll r = a*b - q*m; if (r>m)r %= m; if (r<0)r += m; return r; }
template <typename T, typename S>T expo(T e, S n) { T x = 1, p = e; while (n) { if (n & 1)x = x*p; p = p*p; n >>= 1; }return x; }
template <typename T>T power(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mod(x*p, m); p = mod(p*p, m); n >>= 1; }return x; }
template <typename T>T powerL(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; }return x; }
template <typename T> T InverseEuler(T a, T & m) { return (a == 1 ? 1 : power(a, m - 2, m)); }

inline int two(int n) { return 1 << n; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
/*----------------------------------------------------------------------*/

string s,res;
int dp[1003][1003],n;
int bstart[1003][1003],bend[1003][1003];

int solve(int l, int r) {
	if (l > r)
	{
		return 0;
	} else if (l == r)
	{
		return 1;
	}

	if(dp[l][r] != -1) {
		return dp[l][r];
	}

	int start, end;
	int best = -1, bs=-1, be=-1;
	char bchar;

	for(char c = 'a'; c <= 'z'; c++) {
		start = -1, end = -1;
		F(i, l, r+1) {
			if(s[i] == c) {
				start = i;
				break;
			}
		}

		RF(i, r, l) {
			if(s[i] == c) {
				end = i;
				break;
			}
		}

		if(start == -1) {
			continue;
		}

		int res = solve(start+1, end-1) + ((start == end) ? 1 : 2);
		if(res > best) {
			best = res;
			bchar = c;
			bs = start; be = end;
		}
	}

	bstart[l][r] = bs;
	bend[l][r] = be;

	return dp[l][r] = best;
}

void buildOutput(int l, int r) {
	if (l > r)
	{
		return;
	} else if (l == r)
	{
		res.push_back(s[l]);
	} else {
		res.push_back(s[bstart[l][r]]);
		buildOutput(bstart[l][r]+1, bend[l][r]-1);
		if(bstart[l][r] != bend[l][r]) {
			res.push_back(s[bend[l][r]]);
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    while(cin>>s) {
    	memset(dp, -1, sizeof(dp));
    	memset(bstart, -1, sizeof(bstart));
    	memset(bend, -1, sizeof(bend));

    	n = s.size();
    	res.clear();

    	solve(0, n-1);
    	buildOutput(0, n-1);
    	cout<<res<<endl;
    }

    return 0;          
}/*
    
*/
