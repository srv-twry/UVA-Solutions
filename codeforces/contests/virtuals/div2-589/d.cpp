#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
set<int> g[N];
int vset[N];
vector<int> vsetelements[3];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n,m,u,v; cin>>n>>m;
	memset(vset, -1, sizeof(vset));
	FOR(i, 0, m) {
		cin>>u>>v; u--; v--;
		g[u].insert(v); g[v].insert(u);
	}
	int idx = 0,tot = 0;
	FOR(i, 0, n) {
		if(vset[i] >= 0) continue;
		vset[i] = idx; tot++;
		vsetelements[idx].push_back(i);

		FOR(j, i+1, n) {
			if(vset[j] >= 0) continue;
			if(g[i].find(j) == g[i].end()) {
				tot++;
				vset[j] = idx;
				vsetelements[idx].push_back(j);
			}
		}

		++idx; if(idx == 3) idx = 0;
	}
	if(tot != n || !vsetelements[0].size() || !vsetelements[1].size() || !vsetelements[2].size()) {
		cout<<-1; return 0;
	}
	ll totsize = 1LL * vsetelements[0].size() * vsetelements[1].size();
	totsize += 1LL * vsetelements[0].size() * vsetelements[2].size();
	totsize += 1LL * vsetelements[1].size() * vsetelements[2].size();

	// imp check. Prevents the below for loop from going n^2.
	if(m != (totsize)) {
		cout<<-1; return 0;
	}

	// runs in O(m) because of the above check.
	vii tmp = {{0,1}, {1, 2}, {0, 2}};
	FOR(tm, 0, 3) {
		tie(u,v) = tmp[tm];
		for(int a : vsetelements[u]) {
			for(int b : vsetelements[v]) {
				if(g[a].find(b) == g[a].end()) {
					cout<<-1;
					return 0;
				}
			}
		}
	}

	FOR(i, 0, n) {
		cout<<vset[i]+1<<" ";
	}
    return 0;
}