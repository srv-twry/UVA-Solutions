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

int n,m,x,y; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
vii bridges;
int timer,cnt=0,starter;

const int FINDSIZE = 500043;;
int p[FINDSIZE],sizes[FINDSIZE];

// bridge tree edges.
vi g[FINDSIZE];
int d[FINDSIZE];

//if it is the representative then return itself otherwise return parent of it's immediate parent
int findSet(int i){
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}
bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}
void join(int i, int j){
	if (!isSameSet(i,j))
	{
		int x = findSet(i),y = findSet(j);
		if(sizes[x] < sizes[y]){
			p[x] = y;
			sizes[y]+=sizes[x];
			
		}else{
			p[y] = x;
			sizes[x]+=sizes[y];
		}

	}
}
void initialiseUnionFind(){
	for(int i=0;i<FINDSIZE;i++){
		p[i] = i;
		sizes[i] = 1;
	}
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.push_back({v, to});
            else {
            	join(v, to); // same bridge component.
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void buildBridgeTree() {
	for(auto e : bridges) {
		tie(x,y) = e;
		int s1 = findSet(x);
		int s2 = findSet(y);
		starter = s1;
		g[s1].push_back(s2);
		g[s2].push_back(s1);
	}
}

pair<int, int> bfs(int x)
{
	for(int i = 0; i < n; i++)
		d[i] = n + 1;
	d[x] = 0;
	queue<int> q;
	q.push(x);
	int last = 0;
	while(!q.empty())
	{
	 	last = q.front();
	 	q.pop();
	 	for(auto y : g[last])
	 		if(d[y] > d[last] + 1)
	 		{
	 		 	d[y] = d[last] + 1;
	 		 	q.push(y);
	 		}
	}
	return make_pair(last, d[last]);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    initialiseUnionFind();
    adj.resize(n);
    FOR(i, 0, m) {
    	cin>>x>>y;
    	x--; y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
	find_bridges();
	buildBridgeTree();
	ii p1 = bfs(starter);
	ii p2 = bfs(p1.first);
	cout<<p2.second;

    return 0;
}