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

vll pow2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

int main() {
    string S;
    cin >> S;
    ll N = S.size();
    vpll parity(N);
    parity.at(0) = {pow2.at(S.at(0) - '0'), 0};
    rep(i, N) {
        if (i == 0) continue;
        parity.at(i).first = parity.at(i - 1).first ^ pow2.at(S.at(i) - '0');
        parity.at(i).second = i;
    }
    ll ans = 0;
    vvll idxcount(2048);
    rep(i, N) {
        idxcount.at(parity.at(i).first).push_back(parity.at(i).second);
    }
    rep(i, 2048) {
        // if (idxcount.at(i).size() != 0) outv(idxcount.at(i));
        ans += idxcount.at(i).size() * (idxcount.at(i).size() - 1) / 2;
    }
    if (idxcount.at(0).size() != 0 && idxcount.at(0).at(0) != 0) {
        ans += idxcount.at(0).size();
    }
    cout << ans << endl;
    return 0;
}
