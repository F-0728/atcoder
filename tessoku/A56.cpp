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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vll T(N);
    rep(i, N) {
        T.at(i) = S.at(i) - 'a';
    }

    vvll query(Q);
    rep(i, Q) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        query.at(i) = {a, b, c, d};
    }

    ll MOD = (1LL << 31) - 1;
    ll B = 100;
    vll powB(N + 1);
    powB.at(0) = 1;
    rep(i, N) {
        powB.at(i + 1) = powB.at(i) * B % MOD;
    }

    vll hash(N + 1);
    hash.at(0) = 0;
    rep(i, N) {
        hash.at(i + 1) = (hash.at(i) * B + T.at(i)) % MOD;
    }

    rep(i, Q) {
        ll a, b, c, d;
        a = query.at(i).at(0);
        b = query.at(i).at(1);
        c = query.at(i).at(2);
        d = query.at(i).at(3);
        ll len = d - c + 1;
        ll hash1 = (hash.at(b + 1) - hash.at(a) * powB.at(len) + MOD) % MOD;
        if (hash1 < 0) {
            hash1 += MOD;
        }
        ll hash2 = (hash.at(d + 1) - hash.at(c) * powB.at(len) + MOD) % MOD;
        if (hash2 < 0) {
            hash2 += MOD;
        }
        if (hash1 == hash2) {
            Yes;
        } else {
            No;
        }
    }

    return 0;
}
