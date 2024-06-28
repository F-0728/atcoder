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
    ll N, S;
    cin >> N >> S;
    vpll cards(N);
    rep(i, N) {
        ll A, B;
        cin >> A >> B;
        cards.at(i) = make_pair(A, B);
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp.at(0).at(0) = true;
    rep(i, N) {
        rep(j, S + 1) {
            if (dp.at(i).at(j)) {
                if (j + cards.at(i).first <= S) {
                    dp.at(i + 1).at(j + cards.at(i).first) = true;
                }
                if (j + cards.at(i).second <= S) {
                    dp.at(i + 1).at(j + cards.at(i).second) = true;
                }
            }
        }
    }
    if (!dp.at(N).at(S)) {
        No;
        return 0;
    }
    Yes;
    string ans = "";
    ll current = S;
    for (ll i = N - 1; i >= 0; i--) {
        if (current - cards.at(i).first >= 0 && dp.at(i).at(current - cards.at(i).first)) {
            ans = "H" + ans;
            current -= cards.at(i).first;
        } else {
            ans = "T" + ans;
            current -= cards.at(i).second;
        }
    }
    cout << ans << endl;

    return 0;
}
