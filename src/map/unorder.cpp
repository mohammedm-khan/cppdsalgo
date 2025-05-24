#include <string>
#include <unordered_map>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency map for characters in t
        unordered_map<char, int> freqMap;
        for (char c : t) {
            freqMap[c]++;
        }

        int left = 0;              // Left pointer of the window
        int minLen = INT_MAX;      // Minimum window length
        int minStart = 0;          // Starting index of the minimum window
        int count = t.size();      // Number of characters to be matched
        int n = s.size();

        for (int right = 0; right < n; right++) {
            char currentChar = s[right];

            // If the current character is in t, decrement its count in the frequency map
            if (freqMap.find(currentChar) != freqMap.end()) {
                if (freqMap[currentChar] > 0) {
                    count--; // Decrement the number of characters to be matched
                }
                freqMap[currentChar]--;
            }

            // When all characters of t are matched, try to shrink the window
            while (count == 0) {
                // Update the minimum window if the current window is smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                // Move the left pointer to shrink the window
                char leftChar = s[left];
                if (freqMap.find(leftChar) != freqMap.end()) {
                    freqMap[leftChar]++;
                    if (freqMap[leftChar] > 0) {
                        count++; // Increment the number of characters to be matched
                    }
                }
                left++;
            }
        }

        // If no valid window is found, return an empty string
        if (minLen == INT_MAX) {
            return "";
        }

        // Return the minimum window substring
        return s.substr(minStart, minLen);
    }
};

// Example usage:
#include <iostream>
int main() {
    Solution solution;

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << solution.minWindow(s1, t1) << endl; // Output: "BANC"

    string s2 = "a";
    string t2 = "a";
    cout << solution.minWindow(s2, t2) << endl; // Output: "a"

    string s3 = "a";
    string t3 = "aa";
    cout << solution.minWindow(s3, t3) << endl; // Output: ""

    return 0;
}