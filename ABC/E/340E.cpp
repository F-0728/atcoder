#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

ll op(ll a, ll b) { return min(a, b); }
ll e() { return INF; }
ll mapping(ll f, ll x) { return f + x; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }

int main() { 
    ll N, M;
    cin >> N >> M;
    vll A(N);
    rep(i, N) cin >> A[i];
    lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(A);
    rep(i, M) {
        ll b;
        cin >> b;
        ll balls = seg.get(b);
        seg.set(b, 0);
        if (b + balls < N) {
            seg.apply(b + 1, b + balls + 1, 1);
        } else {
            seg.apply(b + 1, N, 1);
            balls -= N - b - 1;
            ll q = balls / N;
            seg.apply(0, N, q);
            balls -= q * N;
            if (balls > 0) {
                seg.apply(0, balls, 1);
            }
        }
        // rep(i, N) {
        //     cout << seg.get(i) << " ";
        // }
        // cout << endl;
    }
    rep(i, N) {
        cout << seg.get(i) << " ";
    }
    cout << endl;

    return 0; 
    
}
