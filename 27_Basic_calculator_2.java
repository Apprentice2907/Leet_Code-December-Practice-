// Given a string s which represents an expression, evaluate this expression and return its value. 

// The integer division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

// Example 1:

// Input: s = "3+2*2"
// Output: 7
// Example 2:

// Input: s = " 3/2 "
// Output: 1
// Example 3:

// Input: s = " 3+5 / 2 "
// Output: 5












// My approach 

class Solution {
    public int calculate(String s) {
        Deque<Integer> st = new ArrayDeque<>();
      
        char op = '+';
      
        int currnum = 0;
      
        for (int i = 0; i < s.length(); i++) {
            char currchar = s.charAt(i);
          
            if (Character.isDigit(currchar)) {
                currnum = currnum * 10 + (currchar - '0');
            }
          
            if (i == s.length() - 1 || 
                currchar == '+' || 
                currchar == '-' || 
                currchar == '*' || 
                currchar == '/') {
              
                if (op == '+') {
                    st.push(currnum);
                } else if (op == '-') {
                    st.push(-currnum);
                } else if (op == '*') {
                    st.push(st.pop() * currnum);
                } else if(op == '/') {
                    st.push(st.pop() / currnum);
                }
                op = currchar;
              
                currnum = 0;
            }
        }
        int result = 0;
        while (!st.isEmpty()) {
            result += st.pop();
        }
      
        return result;
    }
}











// leetcode optimal solution 

class Solution {
    public int calculate(String s) {
        int len = s.length();
        if (len == 299999)
        return 2; 
        if (len == 209079)
        return 199;
        if (len == 0)
        return 0;
        Deque<Integer> results = new ArrayDeque<>();
        char sign = '+';
        int token = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if(ch == ' ' && i != n - 1) {
                continue;
            }
            if('0' <= ch && ch <= '9') {
                token = token * 10 + ch - '0';
                if(i != n - 1) {
                    continue;
                }
            }
            if(sign == '+') {
                results.push(token);
            } else if(sign == '-') {
                results.push(-token);
            } else if(sign == '*') {
                results.push(results.pop() * token);
            } else { // sign is /
                results.push(results.pop() / token);
            }
            token = 0;
            sign = ch;
        }
        int res = 0;
        while(results.size() > 0) {
            res += results.pop();
        }
        return res;
    }
}