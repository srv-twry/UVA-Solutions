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

const int N = 105;
string s;
int par[N][N],n,dp[N][N];
map<char, char> opposites = { 
	{'{', '}'},
	{'(', ')'},
	{'[', ']'},
	{']', '['},
	{')', '('},
	{'}', '{'}
};
set<char> openers = {'[', '(', '{'};

bool isOpening(char c) {
	return openers.find(c) != openers.end();
}

void printSolution(int i, int j) {
	if(i > j) return;
	if(i == j) {
		if(isOpening(s[i])) {
			cout<<s[i]<<opposites[s[i]];
		} else {
			cout<<opposites[s[i]]<<s[i];
		}
		return;
	}
	if(par[i][j] == -1) {
		cout<<s[i];
		printSolution(i+1, j-1);
		cout<<s[j];
	} else {
		printSolution(i, par[i][j]-1);
		printSolution(par[i][j], j);
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>s;
    n = s.size();
    FOR(i, 0, n) {
    	dp[i][i]=1;
    	FOR(j, i+1, n) {
			dp[i][j] = INF;
    	}
    }
    memset(par, -1, sizeof(par));

    RFOR(i, n-2, 0) {
    	FOR(j, i+1, n) {
    		if(s[i] == opposites[s[j]] && isOpening(s[i])) {
    			dp[i][j] = dp[i+1][j-1];
    			par[i][j] = -1;
    		}

    		FOR(k, i+1, j+1) {
    			if(dp[i][j] > dp[i][k-1] + dp[k][j]) {
    				dp[i][j] = dp[i][k-1] + dp[k][j];
    				par[i][j] = k;
    			}
    		}
    	}
    }
    printSolution(0, n-1);

    return 0;
}