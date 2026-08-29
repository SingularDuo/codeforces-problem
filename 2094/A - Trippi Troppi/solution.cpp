#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
 
vector<string> generateAbbreviations(vector<string> &inputStrings) {
    vector<string> outputStrings;
    for (const string &str : inputStrings) {
        stringstream ss(str);
        string word, abbreviation;
        while (ss >> word) {
            abbreviation += word[0];
        }
        outputStrings.push_back(abbreviation);
    }
    return outputStrings;
}
 
int main() {
    int N;  // Number of input strings
    cin >> N;
    cin.ignore(); // To ignore the newline character after the integer input
    vector<string> inputStrings(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, inputStrings[i]);  // Reading the input strings
    }
 
    vector<string> outputStrings = generateAbbreviations(inputStrings);
 
    // Output the abbreviated strings
    for (const string &abbr : outputStrings) {
        cout << abbr << endl;
    }
 
    return 0;
}