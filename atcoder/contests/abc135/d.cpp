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

const int N = 1e5+5;
ll dp[N][15];
int n;
string s;

ll solve(int curr, int sofar) {
	ll &res = dp[curr][sofar];
	if(res >= 0) return res;
	res = 0;
	if(curr == n) {
		return res = (sofar == 5);
	}
	if(s[curr] == '?') {
		int tmp;
		FOR(dig, 0, 10) {
			tmp = (sofar * 10 + dig) % 13;
			res += solve(curr+1, tmp);
			res %= MOD;
		}
	} else {
		int dig = s[curr] - '0';
		sofar = (sofar * 10 + dig) % 13;
		res += solve(curr+1, sofar);
		res %= MOD;
	}
	return res % MOD;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>s; n = s.size();
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, 0);
    return 0;
}