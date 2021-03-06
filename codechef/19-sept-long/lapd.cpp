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

#define FOR(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
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

int main(){
    int A,B,C,res; int t; scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &A, &B, &C);
        res = 0;
        if(A > C) swap(A, C);
        A--; C--;
        if(!A) {
            printf("0\n");
            continue;
        }
        ll tot = (1LL*A*C);
        if(tot >= MOD) tot -= MOD;
        FOR(b, 1, B+1) {
            int target = b * b;
            if(target > (1LL * A * C)) break;
            int cnt = 0;
            FOR(alpha, 1, min(A, b) + 1) {
                int beta = target / alpha;
                if(!beta) break;
                if(alpha * alpha <= target) cnt++;
                if(beta > alpha) {
                    int lo = alpha + 1;
                    int hi = min(C, beta);
                    if(lo <= hi) {
                        cnt += (hi - lo + 1);
                        if(cnt >= MOD) cnt -= MOD;
                    }
                    hi = min(A, beta);
                    if(lo <= hi) {
                        cnt += (hi - lo + 1);
                        if(cnt >= MOD) cnt -= MOD;
                    }
                } else if(beta < alpha) break;
            }
            res += (tot - cnt + MOD) % MOD;
            if(res >= MOD) res -= MOD;
        }
        printf("%d\n", res);
    }
    return 0;
}