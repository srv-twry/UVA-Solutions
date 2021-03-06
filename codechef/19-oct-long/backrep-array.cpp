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
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using maxpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using minpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

int n, q;
deque<int> dq;

void shift() {
    dq.push_front(0); // insert 0 in the beginning.
    int lst = dq.back(); dq.pop_back();
    int lst2 = dq.back(); dq.pop_back();
    dq.push_back(lst + lst2);
}

void print() {
    FOR(i, 0, n) cout<<dq[i]<<" ";
    cout<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>q; /// assuming n >= 2 for now.
    int arr[n];
    FOR(i, 0, n) {
        cin>>arr[i];
        dq.push_back(arr[i]);
    }
    char c; int u,v;
    while(q--) {
        shift();
        cin>>c>>v; v--;
        if(c == '?') {
            cout<<dq[v]<<endl;
        } else {
            cin>>u;
            dq[v] = u;
        }
        print();
    }
    return 0;
}