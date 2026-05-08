#include <iostream>
#include <string>
using namespace std;

const int MAX_USERS = 1000;

class Bank {
private:
    bool userExists[MAX_USERS];
    int userBalance[MAX_USERS];

public:
    Bank() {
        for (int i = 0; i < MAX_USERS; i++) {
            userExists[i] = false;
            userBalance[i] = 0;
        }
    }

    bool CREATE(int X, int Y) {
        if (userExists[X] == false) {
            userExists[X] = true;
            userBalance[X] = Y;
            return true;
        }
        else {
            userBalance[X] = userBalance[X] + Y;
            return false;
        }
    }

    bool DEBIT(int X, int Y) {
        if (userExists[X] == false || userBalance[X] < Y)
            return false;

        userBalance[X] = userBalance[X] - Y;
        return true;
    }

    bool CREDIT(int X, int Y) {
        if (userExists[X] == false)
            return false;

        userBalance[X] = userBalance[X] + Y;
        return true;
    }

    int BALANCE(int X) {
        if (userExists[X] == false)
            return -1;

        return userBalance[X];
    }

    void Queries() {
        int Q;
        cin >> Q;

        while (Q--) {
            string query;
            cin >> query;

            if (query == "CREATE") {
                int X, Y;
                cin >> X >> Y;
                cout << CREATE(X, Y) << endl;
            }

            else if (query == "DEBIT") {
                int X, Y;
                cin >> X >> Y;
                cout << DEBIT(X, Y) << endl;
            }

            else if (query == "CREDIT") {
                int X, Y;
                cin >> X >> Y;
                cout << CREDIT(X, Y) << endl;
            }

            else if (query == "BALANCE") {
                int X;
                cin >> X;
                cout << BALANCE(X) << endl;
            }
        }
    }
};

int main() {
    Bank obj;
    obj.Queries();
    return 0;
}
