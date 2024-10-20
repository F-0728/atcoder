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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

bool isABetweenBC(ll a, ll b, ll c) {
    return (a - b) * (b - c) * (c - a) > 0;
}

ll distance(ll a, ll b, ll N) {
    if (a <= b) {
        return b - a;
    } else {
        return N - a + b;
    }
}


int main() {
    ll N, M;
    cin >> N >> M;
    vll X(M);
    rep(i, M) {
        cin >> X[i];
        X[i]--;
    }

    vll bridges(N);
    ll sum = 0;

    auto distAdd = [&](ll from, ll to, ll d) {
        if (from <= to) {
            bridges[from] += d;
            bridges[to] -= d;
        } else {
            bridges[from] += d;
            bridges[0] += d;
            bridges[to] -= d;
        }
    };
    rep(i, M - 1) {
        distAdd(X[i], X[i + 1], distance(X[i + 1], X[i], N));
        distAdd(X[i + 1], X[i], distance(X[i], X[i + 1], N));
    }

    // outv(bridges);

    rep(i, N - 1) {
        bridges[i + 1] += bridges[i];
    }

    ll ans = INF;
    rep(i, N) {
        ans = min(ans, bridges[i]);
    }

    cout << ans << endl;

    return 0;
}
