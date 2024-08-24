#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <random>
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
    
    vll hashR(N + 1);
    hashR.at(0) = 0;
    vll hashL(N + 1);
    hashL.at(0) = 0;

    random_device rnd;
    ll B = rnd() % 100 + 127;
    ll MOD = (1LL << 31) - 1;

    vll powB(N + 1);
    powB.at(0) = 1;
    rep(i, N) {
        powB.at(i + 1) = powB.at(i) * B % MOD;
    }

    rep(i, N) {
        hashR.at(i + 1) = (hashR.at(i) * B + S.at(i)) % MOD;
    }

    string T = S;
    reverse(T.begin(), T.end());
    rep(i, N) {
        hashL.at(i + 1) = (hashL.at(i) * B + T.at(i)) % MOD;
    }

    // outv(hashR);
    // outv(hashL);

    rep(i, Q) {
        ll l, r;
        cin >> l >> r;
        l--;
        ll hash1 = (hashR.at(r) - hashR.at(l) * powB.at(r - l) % MOD + MOD) % MOD;
        ll L = N - l;
        ll R = N - r;
        ll hash2 = (hashL.at(L) - hashL.at(R) * powB.at(L - R) % MOD + MOD) % MOD;
        // cout << hash1 << " " << hash2 << endl;
        if (hash1 == hash2) {
            Yes;
        } else {
            No;
        }
    }


    return 0;
}
