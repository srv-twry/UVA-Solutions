#include<bits/stdc++.h>
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
const double eps = 1e-9;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
/*----------------------------------------------------------------------*/

const int N = 1005;
int y[N],n;
bool visited[N];

bool check(double slope, int c) {
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	F(i, 0, n) {
		if(y[i]-c==1LL*slope*i) {
			visited[i]=true;
			cnt++;
		}
	}
	if(cnt == n) return false;
	if(cnt == n-1) return true;
	int pos=-1;
	F(i, 0, n) {
		if(!visited[i]) {
			pos = i;
			visited[i]=true;
			break;
		}
	}
	F(i, pos+1, n) {
		if(visited[i]) continue;
		if (fabs((double)(y[i]-y[pos])/(i-pos)-slope)>eps) return false;
	}

	return true;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    F(i, 0, n) {
    	cin>>y[i];
    }

    bool ans = false;
    ans|=check(1.0*(y[1]-y[0]),y[0]);
	ans|=check(0.5*(y[2]-y[0]),y[0]);
	ans|=check(1.0*(y[2]-y[1]),y[1]*2-y[2]);
    if(ans) {
    	cout<<"Yes";
    } else {
    	cout<<"No";
    }

    return 0;
}/*

*/
