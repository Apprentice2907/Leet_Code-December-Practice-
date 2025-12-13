// You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

// Return the shuffled string.

// Example 1:


// Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
// Output: "leetcode"
// Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
// Example 2:

// Input: s = "abc", indices = [0,1,2]
// Output: "abc"
// Explanation: After shuffling, each character remains in its position.








// My approach optimal but not spacewise

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string res(n, ' '); 

        for (int i = 0; i < n; i++) {
            res[indices[i]] = s[i];
        }

        return res;
    }
};










// My approach only but spacewise optimal too

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string res(n, ' ');

        int i = 0;
        while (i < n) {
            int start = i;
            int idxStart = indices[i];

            while (i + 1 < n && indices[i + 1] == indices[i] + 1) {
                i++;
            }

            int len = i - start + 1;

            for (int k = 0; k < len; k++) {
                res[idxStart + k] = s[start + k];
            }

            i++;
        }

        return res;
    }
};
