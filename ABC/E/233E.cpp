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
    string N;
    cin >> N;
    vll ansDigits(N.size() + 1, 0);
    ansDigits.at(0) = 0;
    rep(i, N.size()) {
        ll digit = N.at(i) - '0';
        ansDigits.at(i + 1) = digit + ansDigits.at(i);
    }
    string ansStr = "";
    rep(i, ansDigits.size() - 1) {
        ansStr += to_string(ansDigits.at(N.size() - i) % 10);
        ansDigits.at(N.size() - i - 1) += ansDigits.at(N.size() - i) / 10;
    }
    reverse(ansStr.begin(), ansStr.end());
    // string ans = to_string(ansDigits.at(ansDigits.size() - 1)) + ansStr;
    if (ansDigits.at(0) != 0) {
        cout << ansDigits.at(0);
    }
    cout << ansStr << endl;

    return 0;
}
