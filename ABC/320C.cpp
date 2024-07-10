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

int main() {
    ll M;
    cin >> M;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vvll slot(3);
    rep(i, M) {
        slot.at(0).push_back(s1.at(i) - '0');
        slot.at(1).push_back(s2.at(i) - '0');
        slot.at(2).push_back(s3.at(i) - '0');
    }
    ll ans = INF;
    rep(i, 10) {
        if (find(slot.at(0).begin(), slot.at(0).end(), i) == slot.at(0).end() ||
            find(slot.at(1).begin(), slot.at(1).end(), i) == slot.at(1).end() ||
            find(slot.at(2).begin(), slot.at(2).end(), i) == slot.at(2).end()) {
            continue;
        }
        vvll orders = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                       {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
        for (vll order : orders) {
            ll count = 0;
            while (slot.at(order.at(0)).at(count % M) != i) {
                count++;
            }
            count++;
            while (slot.at(order.at(1)).at(count % M) != i) {
                count++;
            }
            count++;
            while (slot.at(order.at(2)).at(count % M) != i) {
                count++;
            }
            ans = min(ans, count);
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
