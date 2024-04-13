#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() { 
    int Q;
    cin >> Q;
    deque<int> deck;

    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            deck.push_front(x);
        } else if (t == 2) {
            deck.push_back(x);
        } else {
            cout << deck[x - 1] << endl;
        }
    }

    return 0;
}
