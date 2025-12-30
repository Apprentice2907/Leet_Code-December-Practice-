// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

// Return any such subsequence as an integer array of length k.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: nums = [2,1,3,3], k = 2
// Output: [3,3]
// Explanation:
// The subsequence has the largest sum of 3 + 3 = 6.
// Example 2:

// Input: nums = [-1,-2,3,4], k = 3
// Output: [-1,3,4]
// Explanation: 
// The subsequence has the largest sum of -1 + 3 + 4 = 6.
// Example 3:

// Input: nums = [3,4,3,3], k = 2
// Output: [3,4]
// Explanation:
// The subsequence has the largest sum of 3 + 4 = 7. 
// Another possible subsequence is [4, 3].








// solution and optimal solution also but chatGPT

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> minheap;

        for(int i=0;i<nums.size();i++){
            minheap.push({nums[i],i});

            if(minheap.size()>k) minheap.pop();
        }
        vector<pair<int,int>> temp;
        while(!minheap.empty()){
            temp.push_back(minheap.top());
            minheap.pop();
        }

        sort(temp.begin(),temp.end(),[](auto &a,auto &b){
            return a.second<b.second;
        });

        vector<int> ans;
        for(auto &p: temp) ans.push_back(p.first);
        return ans;
    }
};