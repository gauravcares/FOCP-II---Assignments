#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    int* arr = new int[T];
    int max = 0;

    for (int i = 0; i < T; i++) {
        cin >> arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    char* FactorCount = new char[max + 1];

    for (int i = 0; i <= max; i++) {
        FactorCount[i] = 0;
    }

    for (int i = 2; i <= max; i++) {
        if (FactorCount[i] == 0) {
            for (int j = i; j <= max; j += i) {
                FactorCount[j]++;
            }
        }
    }

    for (int i = 0; i < T; i++) {
        int k = FactorCount[arr[i]];

        int PairCount = 1;
        for (int j = 0; j < k; j++) {
            PairCount *= 2;
        }

        cout << PairCount << '\n';
    }

    delete[] FactorCount;
    delete[] arr;

    return 0;
}
