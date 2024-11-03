#include <atcoder/all>
#include <chrono>
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
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
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

int main() {
    ll N, C;
    cin >> N >> C;
    vpll opr(N);
    // 1...AND, 2...OR, 3...XOR
    rep(i, N) { cin >> opr[i].first >> opr[i].second; }

    // iビット目について，j番目まで通っていて，初期値がkのとき，いくつになるか
    vector<vvll> dp(30, vvll(N, vll(2)));
    rep(i, 30) {
        ll t = opr[0].first;
        ll bit = (opr[0].second >> i) & 1;
        rep(k, 2) {
            if (t == 1) {
                dp.at(i).at(0).at(k) = bit & k;
            } else if (t == 2) {
                dp.at(i).at(0).at(k) = bit | k;
            } else {
                dp.at(i).at(0).at(k) = bit ^ k;
            }
        }
    }
    rep(i, 30) {
        rep(j, N - 1) {
            ll t = opr[j + 1].first;
            ll bit = (opr[j + 1].second >> i) & 1;
            rep(k, 2) {
                if (t == 1) {
                    dp.at(i).at(j + 1).at(k) = dp.at(i).at(j).at(k) & bit;
                } else if (t == 2) {
                    dp.at(i).at(j + 1).at(k) = dp.at(i).at(j).at(k) | bit;
                } else {
                    dp.at(i).at(j + 1).at(k) = dp.at(i).at(j).at(k) ^ bit;
                }
            }
        }
    }

    vll ans(N, 0);
    rep(i, 30) {
        ll now = (C >> i) & 1;
        rep(j, N) {
            ans[j] += (dp.at(i).at(j).at(now)) << i;
            now = dp.at(i).at(j).at(now);
        }
    }

    rep(i, N) {
        cout << ans[i] << endl;
    }

    return 0;
}
