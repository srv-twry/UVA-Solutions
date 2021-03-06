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

const int N = 2e5+5;
int freq[N] = {0}, arr[N];
vector<iii> ans;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;

    FOR(i, 0, n) {
    	cin>>arr[i];
    	freq[arr[i]]++;
    }

    int maxm = max_element(freq, freq+N) - freq;
    int maxi;
    FOR(i, 0, n) {
    	if(arr[i] == maxm) {
    		maxi = i;
    		break;
    	}
    }

    RFOR(i, maxi-1, 0) {
    	if(arr[i] == maxm) continue;
    	int op = 1;
    	if(arr[i] > arr[i+1]) op = 2;
    	ans.push_back({op, {i+1, i+2}});
    	arr[i] = maxm;
    }

    FOR(i, maxi+1, n) {
    	if(arr[i] == maxm) continue;
    	int op = 1;
    	if(arr[i] > arr[i-1]) op = 2;
    	ans.push_back({op, {i+1, i}});
    	arr[i] = maxm;
    }

    cout<<ans.size()<<endl;
    FOR(i, 0, ans.size()) {
    	cout<<ans[i].ff<<" "<<ans[i].ss.ff<<" "<<ans[i].ss.ss<<endl;
    }

    return 0;
}