#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int findMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    string inputLine;
    getline(cin, inputLine);  

    stringstream ss(inputLine);
    string token;
    vector<int> numbers;

    while (getline(ss, token, ',')) {
        numbers.push_back(stoi(token));  
    }

    if (!numbers.empty()) {
        cout << findMax(numbers) << endl;
    }

    return 0;
}
