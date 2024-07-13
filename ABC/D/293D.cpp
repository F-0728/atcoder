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
    ll N, M;
    cin >> N >> M;
    vvll G(2 * N);
    dsu D(2 * N);
    rep(i, M) {
        ll a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        if (b == 'R') {
            if (d == 'R') {
                G.at(2 * a).push_back(2 * c);
                G.at(2 * c).push_back(2 * a);
                D.merge(2 * a, 2 * c);
            } else {
                G.at(2 * a).push_back(2 * c + 1);
                G.at(2 * c + 1).push_back(2 * a);
                D.merge(2 * a, 2 * c + 1);
            }
        } else {
            if (d == 'R') {
                G.at(2 * a + 1).push_back(2 * c);
                G.at(2 * c).push_back(2 * a + 1);
                D.merge(2 * a + 1, 2 * c);
            } else {
                G.at(2 * a + 1).push_back(2 * c + 1);
                G.at(2 * c + 1).push_back(2 * a + 1);
                D.merge(2 * a + 1, 2 * c + 1);
            }
        }
    }
    rep(i, N) {
        G.at(2 * i).push_back(2 * i + 1);
        G.at(2 * i + 1).push_back(2 * i);
        D.merge(2 * i, 2 * i + 1);
    }
    auto groups = D.groups();
    // rep(i, groups.size()) {
    //     outv(groups.at(i));
    // }
    ll cyclic = 0;
    for (auto group : groups) {
        bool is_cyclic = true;
        for (auto node : group) {
            if (G.at(node).size() < 2) {
                is_cyclic = false;
                break;
            }
        }
        if (is_cyclic) {
            cyclic++;
        }
    }
    cout << cyclic << " " << (ll)groups.size() - cyclic << endl;
    

    return 0;
}
