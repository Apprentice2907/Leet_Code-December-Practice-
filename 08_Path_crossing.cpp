
// Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

// Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

 

// Example 1:


// Input: path = "NES"
// Output: false 
// Explanation: Notice that the path doesn't cross any point more than once.
// Example 2:


// Input: path = "NESWW"
// Output: true
// Explanation: Notice that the path visits the origin twice.







// Optimal Solution 

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int,int>> moves = {
        {'N', {0, 1}},
        {'S', {0, -1}},
        {'E', {1, 0}},
        {'W', {-1, 0}}
        };

        int x = 0, y = 0;
        set<pair<int,int>> visited;
        visited.insert({0, 0});

        for (auto &ch : path) {
            x += moves[ch].first;
            y += moves[ch].second;

            if (visited.count({x, y})) {
                return true;
            }

            visited.insert({x, y});
        }

        return false;
    }
};