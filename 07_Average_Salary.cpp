// You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
// Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

// Example 1:

// Input: salary = [4000,3000,1000,2000]
// Output: 2500.00000
// Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
// Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
// Example 2:

// Input: salary = [1000,2000,3000]
// Output: 2000.00000
// Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
// Average salary excluding minimum and maximum salary is (2000) / 1 = 2000










// Optimal solution

class Solution {
public:
    double average(vector<int>& salary) {
        int mn = INT_MAX, mx = INT_MIN;

        for(int s : salary) {
            mn = min(mn, s);
            mx = max(mx, s);
        }

        double sum = 0;
        int count = 0;
        for(int s : salary) {
            if(s != mn && s != mx) {
                sum += s;
                count++;
            }
        }
        return sum / count;
    }
};





// another small code with same time

class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double sum = 0;
        for(int i = 1; i < salary.size()-1;i++){
            sum += salary[i];
        }
        return sum / (salary.size()-2);
    }
};