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
    ll N, L, R;
    cin >> N >> L >> R;
    vll A(N);
    rep(i, N) cin >> A.at(i);
    vll cSumL(N + 1), cSumR(N + 1);
    cSumL.at(0) = 0;
    cSumR.at(0) = 0;
    rep(i, N) {
        cSumL.at(i + 1) = cSumL.at(i) + A.at(i);
        cSumR.at(i + 1) = cSumR.at(i) + A.at(N - i - 1);
    }
    vll Al(N + 1), Ar(N + 1);
    Al.at(0) = 0;
    Ar.at(0) = 0;
    rep(i, N) {
        Al.at(i + 1) = min(L * (i + 1), Al.at(i) + A.at(i));
        Ar.at(i + 1) = min(R * (i + 1), Ar.at(i) + A.at(N - i - 1));
        // if (cSumL.at(i + 1) > L * (i + 1)) {
        //     Al.at(i + 1) = L * (i + 1);
        // } else {
        //     Al.at(i + 1) = Al.at(i) + A.at(i);
        // }
        // if (cSumR.at(i + 1) > R * (i + 1)) {
        //     Ar.at(i + 1) = R * (i + 1);
        // } else {
        //     Ar.at(i + 1) = Ar.at(i) + A.at(N - i - 1);
        // }
    }
    ll ans = INF;
    rep(i, N + 1) {
        ans = min(ans, Al.at(i) + Ar.at(N - i));
    }
    // outv(Al);
    // outv(Ar);
    cout << ans << endl;


    return 0;
}
