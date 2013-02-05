/*
 * 294 - Divisors
 * Reference: http://chchwy.blogspot.tw/2010/01/acmuva-294-divisors.html
 */

#include <iostream>
#include <cmath>

#define MAX 1000000001
#define MAX_SQRT (int)sqrt(MAX)

using namespace std;

bool *prime_table = new bool[MAX_SQRT + 1];

int getFactoryNum(int num) {
    /* simple case. */
    if (num == 1)
        return 1;
    else if (num <= MAX_SQRT && !prime_table[num])
        return 2;

    int value = 1;
    int bound = (int) sqrt(num);
    for (int i = 2; num != 1 && i <= bound; ++i) {
        int count = 1;
        while (!prime_table[i] && num % i == 0) {
            num /= i;
            ++count;
        }
        value *= count;
        if (num <= MAX_SQRT && !prime_table[num]) {
            value *= 2;
            break;
        }
    }
    return value;
}

int main () {
    int n;

    /* Get prime table. */
    prime_table[0] = prime_table[1] = true;
    for (int i = 2; i <= MAX_SQRT; ++i)
        if (!prime_table[i])
            for (int j = i + i; j <= MAX_SQRT; j += i)
                prime_table[j] = true;

    cin >> n;
    while (n--) {
        int range_begin, range_end, value;
        cin >> range_begin >> range_end;
        int max_num = 1, max_value = 1;
        for (int i = range_begin; i <= range_end; ++i) {
            value = getFactoryNum(i);
            if (value > max_value) {
                max_num = i;
                max_value = value;
            }
        }
        cout << "Between " << range_begin << " and " << range_end << ", "
            << max_num << " has a maximum of " << max_value << " divisors." << endl;
    }

    return 0;
}

