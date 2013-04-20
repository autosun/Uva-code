/**
 * Skew Binary
 */

#include <iostream>

using namespace std;

int main() {
    string n;

    while(cin >> n) {
        if (n.size() == 1 && n[0] == '0')
            break;

        unsigned long result = 0;
        unsigned int p = 1;
        for (int i = n.size() - 1; i >= 0; --i, ++p) {
            unsigned int r = n[i] - '0';
            if (r != 0)
                result += r * ((1 << p) - 1);
        }
        cout << result << endl;
    }
}

