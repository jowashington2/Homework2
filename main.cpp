#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // 1. Ask user for string
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    // Convert string to uppercase for consistency
    for (char& c : input) {
        c = toupper(c);
    }

    // Initialize a vector for counting occurrences of each ASCII character
    vector<int> indexes(128, 0);

    // 2. Iterate over each character
    for (char c : input) {
        // - Add a counter for each character
        indexes[(int)c]++;
    }

    // 3. Find character with highest counter
    int maxIndex = 0;
    for (int i = 1; i < 128; i++) {
        if (indexes[i] > indexes[maxIndex]) {
            maxIndex = i;
        }
    }

    // 4. Print character with its count
    char most_common = (char)maxIndex;
    cout << "'" << most_common << "' appears " << indexes[maxIndex] << " times." << endl;

    return 0;
}
