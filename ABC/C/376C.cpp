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
    vll A(N);
    rep(i, N) cin >> A[i];
    vll B(N - 1);
    rep(i, N - 1) cin >> B[i];

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    // outv(A);
    // outv(B);

    ll idx = -1;
    rep(i, N - 1) {
        if (A[i] > B[i]) {
            idx = i;
            break;
        }
    }
    // cout << idx << endl;
    if (idx == -1) {
        cout << A[N - 1] << endl;
        return 0;
    }

    for (ll i = idx + 1; i < N; i++) {
        if (A[i] > B[i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << A[idx] << endl;


    return 0;
}
