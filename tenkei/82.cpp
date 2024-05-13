#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

mint sum(__int128_t x) {
    mint a = x;
    mint b = x + 1;
    mint c = a * b / 2;
    return c;
}

int main() {

    vector<__int128_t> pow10(20);
    pow10[0] = 1;
    rep(i, 19) {
        pow10[i + 1] = pow10[i] * 10;
    }

    ll L, R;
    cin >> L >> R;
    string Lstr = to_string(L);
    string Rstr = to_string(R);

    mint ans = 0;
    ll left, right;

    left = Lstr.length();
    right = Rstr.length();

    if (left == right) {
        ans += (sum(R) - sum(L - 1)) * left;
        cout << ans.val() << endl;

        return 0;
    }

    rep(i, right - left - 1) {
        ans += (left + i + 1) * (sum(pow10[left + i + 1] - 1) -
                                 sum(pow10[left + i] - 1));
    }
    ans += (sum(pow10[left] - 1) - sum(L - 1)) * left;
    ans += (sum(R) - sum(pow10[right-1] - 1)) * right;

    cout << ans.val() << endl;

    return 0;
}
