#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to find and print the most frequent character in a string
void findMostFrequentCharacter(const string& input) {
    string uppercaseInput = input;
    
    // Convert string to uppercase for consistency
    for (char& c : uppercaseInput) {
        c = toupper(c);
    }

    // Initialize a vector for counting occurrences of each ASCII character
    vector<int> indexes(128, 0);

    // Iterate over each character
    for (char c : uppercaseInput) {
        // Add a counter for each character
        indexes[(int)c]++;
    }

    // Find character with the highest counter
    int maxIndex = 0;
    for (int i = 1; i < 128; i++) {
        if (indexes[i] > indexes[maxIndex]) {
            maxIndex = i;
        }
    }

    // Print character with its count
    char most_common = (char)maxIndex;
    cout << "For input: \"" << input << "\" -> '" << most_common << "' appears " << indexes[maxIndex] << " times." << endl;
}

int main() {
    // Test Case 1: "banana"
    string testCase1 = "banana";
    findMostFrequentCharacter(testCase1);

    // Test Case 2: "Mississippi"
    string testCase2 = "Mississippi";
    findMostFrequentCharacter(testCase2);

    return 0;
}
