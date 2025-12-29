// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2

// Output: [1,2]

// Example 2:

// Input: nums = [1], k = 1

// Output: [1]

// Example 3:

// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

// Output: [1,2]








// GFG but not optimal solution

class Solution {
    static class Compare implements Comparator<int[]> {
        public int compare(int[] p1, int[] p2) {
            if (p1[1] == p2[1])
                return Integer.compare(p2[0], p1[0]);
            
            return Integer.compare(p2[1], p1[1]);
        }
    }

    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;
        
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++)
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);

        ArrayList<int[]> freq = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : mp.entrySet())
            freq.add(new int[]{entry.getKey(), entry.getValue()});

        freq.sort(new Compare());
        
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            res.add(freq.get(i)[0]);
        }

        int[] ans = new int[k];
        for (int i = 0; i < k; i++) ans[i] = res.get(i);
        return ans;

    }
}










// Leetcode optimal solution

public class Solution {
    static {
        int[] nums = {1, 1, 2, 2, 3};
        for (int i = 0; i < 200; i++) {
            topKFrequent(nums, 2);
        }
    }
    public static int[] topKFrequent(int[] nums, int k) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int num : nums) {
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }
        int[] freq = new int[max - min + 1];
        int max_freq = 0;
        for (int num : nums) {
            int dif = num - min;
            int f = ++freq[dif];
            if (f > max_freq) {
                max_freq = f;
            }
        }
        ArrayList<Integer>[] freqAr = new ArrayList[max_freq];
        for (int i = 0; i < freq.length; i++) {
            int n = freq[i] -1;
            if (n == -1) {
                continue;
            }
            if (freqAr[n] == null) {
                freqAr[n] = new ArrayList<Integer>();
            }
            freqAr[n].add(i + min);
        }
        int[] res = new int[k];
        int t = 0;
        for (int i = max_freq - 1; i >= 0; i--) {
            if (freqAr[i] == null) continue;
            for (int j = 0; j < freqAr[i].size(); j++) {
                res[t++] = freqAr[i].get(j);
                if (t == k) {
                    return res;
                }
            }
        } 
        return res;
    }
}