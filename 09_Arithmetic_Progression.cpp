// A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
// Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

// Example 1:

// Input: arr = [3,5,1]
// Output: true
// Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
// Example 2:

// Input: arr = [1,2,4]
// Output: false
// Explanation: There is no way to reorder the elements to obtain an arithmetic progression.







// Brute force type logic but optimal

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff=arr[1]-arr[0];

        for(int i=0;i<arr.size()-1;i++){
            if((arr[i+1]-arr[i])!=diff) 
                return false;
        }
        return true;
    }
};





// Recursive function logic chatGPT coded

class Solution {
public:
    bool checkRec(vector<int>& arr, int diff, int i) {
        // base case: reached last pair
        if (i == arr.size() - 1)
            return true;

        // if mismatch found, return false
        if (arr[i+1] - arr[i] != diff)
            return false;

        // recursive call to next index
        return checkRec(arr, diff, i + 1);
    }

    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        
        return checkRec(arr, diff, 0);
    }
};


