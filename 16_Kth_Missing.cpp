// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

// Example 1:

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
// Example 2:

// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.









// My approach using set but not optimal class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s(arr.begin(), arr.end());

        int num = 1;
        while (true) {
            if (s.find(num) == s.end()) {
                k--;
                if (k == 0)
                    return num;
            }
            num++;
        }
    }
};







// ChatGPT approach

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left + k;
    }
};










// Leetcode optimal solution

class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(k);
        int i=0,j=0;
        int count=1;
        
        while(j<k){
            if(i<n && nums[i]==count){
                count++;     
                i++;
            }
            else{
                ans[j]=count;
                j++;
                count++;
            }
        }
        return ans[j-1];
    }
};