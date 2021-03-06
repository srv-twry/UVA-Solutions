/**
    __author__ : srv_twry
**/

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

bool ge(const ll& a, const ll& b) { return a >= b; }
bool le(const ll& a, const ll& b) { return a <= b; }
bool eq(const ll& a, const ll& b) { return a == b; }
bool gt(const ll& a, const ll& b) { return a > b; }
bool lt(const ll& a, const ll& b) { return a < b; }
int sgn(const ll& x) { return le(x, 0) ? eq(x, 0) ? 0 : -1 : 1; }
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
ll pos[N], p;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n; cin>>n;
	FOR(i, 0, n) {
		cin>>p; p--;
		pos[p] = i;
	}
	multiset<ll> ms; ms.insert(-1); ms.insert(-1); ms.insert(n); ms.insert(n);
	ll res = 0;

	// iterate in decreasing value.
	RFOR(i, n-1, 0) {
		ms.insert(pos[i]);
		auto itr = ms.find(pos[i]);
		ll s1,s2,b1,b2;
		--itr; s1 = *itr; // larger value to the left.
		--itr; s2 = *itr; // larger value to the left of the larger value.
		++itr; ++itr; ++itr;
		b1 = *itr; // larger value to the right.
		++itr; b2 = *itr;

		ll tmp = 1LL * (s1 - s2) * (b1 - pos[i]);
		tmp += 1LL * (b2 - b1) * (pos[i] - s1);

		res += tmp * (i + 1);
	}
	cout<<res;
    return 0;
}