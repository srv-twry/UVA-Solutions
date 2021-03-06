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

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
vii g[N];
vi ans;
bool visited[N];

bool dfs(int curr, int maxrep) {
	visited[curr]=true;
	bool lower=false;
	F(i, 0, g[curr].size()) {
		int next = g[curr][i].first, t = g[curr][i].second;
		if(!visited[next]) {
			int nextrep = -1;
			if(t == 2) {
				lower = true;
				nextrep = next+1;
			}
			lower |= dfs(next, nextrep);
		}
 	}

 	if(!lower && maxrep != -1) {
 		ans.push_back(maxrep);
 	}

 	return lower;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n,u,v,t;
    cin>>n;

    F(i, 0, n-1) {
    	cin>>u>>v>>t;
    	u--; v--;
    	g[u].push_back({v, t});
    	g[v].push_back({u, t});
    }

    memset(visited, false, sizeof(visited));
    dfs(0, -1);
    cout<<ans.size()<<endl;
    F(i, 0, ans.size()) {
    	if(i)
    		cout<<" ";
    	cout<<ans[i];
    }

    return 0;
}/*

*/
