// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:

// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".








// Brute force method using DFS and recursion 

class Solution {
public:

    bool dfs(int i, int j, string s, string p) {
        if (i >= s.length() && j >= p.length()) return true;
        if (j >= p.length()) return false;

        bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.length() && p[j + 1] == '*') {
            return dfs(i, j + 2, s, p) || (match && dfs(i + 1, j, s, p));
        }

        if (match) {
            return dfs(i + 1, j + 1, s, p);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return dfs(0, 0, s, p);
    }
};








// Optimal solution internet

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        // dp[i][j] = does s[0..i-1] match p[0..j-1]
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;

        // Initialize for patterns like a*, a*b*, a*b*c*
        for (int j = 1; j < m; j++) {
            if (p[j] == '*')
                dp[0][j+1] = dp[0][j-1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Case 1: characters match or pattern has '.'
                if (p[j-1] == s[i-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }

                // Case 2: star pattern like a* or .*
                else if (p[j-1] == '*') {
                    // Zero occurrence of previous char
                    dp[i][j] = dp[i][j-2];

                    // One or more occurrences, previous char must match
                    if (p[j-2] == s[i-1] || p[j-2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }

        return dp[n][m];
    }
};
