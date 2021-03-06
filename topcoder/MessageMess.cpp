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

class MessageMess {
public:
	string restore(vector <string>, string);
};

bool check(int idx, string &message, string &dictionary) {
	int sz = dictionary.size(); bool ret = true;
	RFOR(i, idx - 1, 0) {
		if(!sz) break;
		if(message[i] != dictionary[sz-1]) return false;
		sz--;
	}
	return ret;
}

void build_out(string &ret, string &message, int par[]) {
	int target = par[message.size()], idx = message.size();
	while(target != -1) {
		ret.push_back(message[idx-1]);
		idx--;
		if(idx == target) {
			ret.push_back(' ');
			target = par[target];
		}
	}
	ret.pop_back();
	reverse(ret.begin(), ret.end());
}

string MessageMess::restore(vector <string> dictionary, string message) {
	int m = dictionary.size(), n = message.size();
	int dp[n+1],par[n+1]; string ret;
	memset(dp, 0, sizeof(dp)); memset(par, -1, sizeof(par));
	dp[0]=1;
	FOR(i, 1, n+1) {
		FOR(j, 0, m) {
			int sz = dictionary[j].size();
			if(i < sz) continue;
			if(check(i, message, dictionary[j]) && dp[i-sz]) {
				dp[i] += dp[i - sz];
				par[i] = i - sz;
			}
		}
	}
	if(dp[n] == 0) {
		ret = "IMPOSSIBLE!";
	} else if(dp[n] > 1) {
		ret = "AMBIGUOUS!";
	} else {
		build_out(ret, message, par);
	}

	return ret;
}


//Powered by [KawigiEdit] 2.0!
