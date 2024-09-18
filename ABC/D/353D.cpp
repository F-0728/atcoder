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
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    mint ans = 0;
    rep(i, N) {
        ans += A[i] * i;
    }

    vll digits(N);

    map<ll, ll> digit;
    rep(i, N) {
        ll d = 0;
        ll a = A[i];
        while(a > 0) {
            a /= 10;
            d++;
        }
        digit[d]++;
        digits[i] = d;
    }

    rep(i, N) {
        ll d = digits[i];
        mint a = A[i];
        vector<mint> pow;
        pow.push_back(A[i]);
        rep(i, 10) {
            pow.push_back(pow.back() * 10);
        }
        for (auto [key, value] : digit) {
            if (d == key) {
                digit[key]--;
            }
            ans += pow[key] * digit[key];
        }
    }

    cout << ans.val() << endl;

    return 0;
}
