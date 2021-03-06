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
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 2e5+5;
vi g[N];
int dist[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int t,n,m,a,b; cin>>t;
    while(t--) {
        cin>>n>>m;
        FOR(i, 0, n) {
            g[i].clear();
            dist[i] = -1;
        }
        FOR(i, 0, m) {
            cin>>a>>b; a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        queue<int> q; q.push(0); dist[0] = 0;
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(int nxt : g[curr]) {
                if(dist[nxt] == -1) {
                    dist[nxt] = dist[curr] + 1;
                    q.push(nxt);
                }
            }
        }
        vi odds, evens;
        FOR(i, 0, n) {
            if(dist[i] & 1) {
                odds.pb(i);
            } else evens.pb(i);
        }
        if(evens.size() < odds.size()) swap(evens, odds);
        cout<<odds.size()<<endl;
        for(int a : odds) cout<<a+1<<" ";
        cout<<endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}