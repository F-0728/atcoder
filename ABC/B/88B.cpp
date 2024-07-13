#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() { 
    int N;
    cin >> N;
    vector<int> cards;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int card;
        cin >> card;
        cards.push_back(card);
    }
    sort(cards.rbegin(), cards.rend());
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0){
            ans += cards[i];
        } else {
            ans -= cards[i];
        }
    }
    cout << ans << endl;

    return 0;
}
