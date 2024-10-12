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

int main() {
    ll N;
    cin >> N;
    vpll people(N);
    ll sum = 0;
    rep(i, N) {
        cin >> people[i].first >> people[i].second;
        sum += people[i].second;
    }

    vll cSum(N + 1, 0);
    rep(i, N) {
        cSum[i + 1] = cSum[i] + people[i].second;
    }

    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<vvll> dp(N + 1, vvll(sum / 3 + 1, vll(sum / 3 + 1, INF)));
    dp.at(0).at(0).at(0) = 0;
    rep(i, N) {
        rep(j, sum / 3 + 1) {
            rep(k, sum / 3 + 1) {
                if (j + people[i].second <= sum / 3) {
                    if (people[i].first == 1) {
                        dp.at(i + 1).at(j + people[i].second).at(k) = min(dp.at(i + 1).at(j + people[i].second).at(k), dp.at(i).at(j).at(k));
                    } else {
                        dp.at(i + 1).at(j + people[i].second).at(k) = min(dp.at(i + 1).at(j + people[i].second).at(k), dp.at(i).at(j).at(k) + 1);
                    }
                }
                if (k + people[i].second <= sum / 3) {
                    if (people[i].first == 2) {
                        dp.at(i + 1).at(j).at(k + people[i].second) = min(dp.at(i + 1).at(j).at(k + people[i].second), dp.at(i).at(j).at(k));
                    } else {
                        dp.at(i + 1).at(j).at(k + people[i].second) = min(dp.at(i + 1).at(j).at(k + people[i].second), dp.at(i).at(j).at(k) + 1);
                    }
                }
                ll rest = cSum[i] - j - k;
                if (rest + people[i].second <= sum / 3) {
                    if (people[i].first == 3) {
                        dp.at(i + 1).at(j).at(k) = min(dp.at(i + 1).at(j).at(k), dp.at(i).at(j).at(k));
                    } else {
                        dp.at(i + 1).at(j).at(k) = min(dp.at(i + 1).at(j).at(k), dp.at(i).at(j).at(k) + 1);
                    }
                }
            }
        }
    }

    ll ans = dp.at(N).at(sum / 3).at(sum / 3);
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
