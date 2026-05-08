#include<iostream>
#include<string>
using namespace std;

class LightController {
private:
    int TotalBulbs, MaxOperations;
    string Lights;

    bool CanTurnOff(int SegmentLength) {
        int OperationsUsed = 0;
        int CurrentIndex = 0;

        while(CurrentIndex < TotalBulbs) {
            if(Lights[CurrentIndex] == '1') {
                OperationsUsed++;

                if(OperationsUsed > MaxOperations)
                    return false;

                CurrentIndex += SegmentLength;
            } else {
                CurrentIndex++;
            }
        }
        return true;
    }

public:
    void Input() {
        cin >> TotalBulbs >> MaxOperations;
        cin >> Lights;
    }

    int MinSegmentLength() {
        int low = 1, high = TotalBulbs;
        int Answer = TotalBulbs;

        while(low <= high) {
            int Mid = (low + high) / 2;

            if(CanTurnOff(Mid)) {
                Answer = Mid;
                high = Mid - 1;
            } else {
                low = Mid + 1;
            }
        }
        return Answer;
    }

    void Output() {
        cout << MinSegmentLength() << '\n';
    }
};

int main() {
    LightController solver;
    solver.Input();
    solver.Output();
    return 0;
}
