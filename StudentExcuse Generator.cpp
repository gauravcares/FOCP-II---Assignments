#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to replace {name}
string replaceName(string text, string name) {
    size_t pos;
    while ((pos = text.find("{name}")) != string::npos) {
        text.replace(pos, 6, name);
    }
    return text;
}

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // Seed random generator
    srand(time(0));

    // Excuse templates (starting directly as excuses)
    vector<string> excuses = {
        "forgot to bring the homework because my alarm didn’t ring.",
        "couldn't complete the assignment due to a sudden power cut.",
        "accidentally deleted the file at the last moment.",
        "was feeling unwell and couldn't focus on the work.",
        "had a family emergency and couldn't finish it on time.",
        "misunderstood the deadline and thought it was next week.",
        "lost the notebook while traveling.",
        "completed it but forgot to submit it.",
        "had internet issues while trying to upload it.",
        "system crashed while working on it."
    };

    // Select random excuse
    int randomIndex = rand() % excuses.size();
    string selectedExcuse = excuses[randomIndex];

    // Replace placeholder if used
    string finalExcuse = replaceName(selectedExcuse, name);

    // Output in required format
    cout << "\n--- Generated Excuse ---\n";
    cout << name << " " << finalExcuse << endl;

    return 0;
}
