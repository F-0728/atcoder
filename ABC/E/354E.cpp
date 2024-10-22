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

int main() {
    ll N;
    cin >> N;
    vpll cards(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        cards.at(i) = {a, b};
    }

    vector<bool> canWin(1 << N, true);
    canWin.at(0) = false;
    rep(i, 1 << N) {
        if (!canWin.at(i)) continue;
        if (popcount(unsigned(i)) == 1) {
            canWin.at(i) = false;
            continue;
        }
        vll bitup;
        rep(j, N) {
            if ((i >> j) & 1) {
                bitup.push_back(j);
            }
        }
        bool ok = false;
        rep(j, bitup.size()) {
            rep(k, bitup.size()) {
                if (j == k) continue;
                if (cards.at(bitup.at(j)).first == cards.at(bitup.at(k)).first || cards.at(bitup.at(j)).second == cards.at(bitup.at(k)).second) {
                    if (!canWin.at(i ^ (1 << bitup.at(j)) ^ (1 << bitup.at(k)))) {
                        ok = true;
                        break;
                    }
                }
            }
        }
        if (ok) {
            canWin.at(i) = true;
        } else {
            canWin.at(i) = false;
        }
    }

    if (canWin.at((1 << N) - 1)) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }


    return 0;
}
