// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.
// Example 1:

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
// Example 2:

// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 






// My approach but time limit exceeded

class Solution {

    static int isUgly(int n){
        if (n==1) return 1;
        if(n<=0) return 0;

        if(n%2==0) return isUgly((n/2));
        if(n%3==0) return isUgly((n/3));
        if(n%5==0) return isUgly((n/5));

        return 0;
    }

    public int nthUglyNumber(int n) {
        int count=0;
        int i=1;
        while(true){
            if(isUgly(i)==1){
                count++;
                if(count==n) return i;
            }
            i++;
        }
    }
}










// ChatGPT optimal solution 

class Solution {
    public int nthUglyNumber(int n) {
        int[] ugly = new int[n];
        ugly[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;
        int next2 = 2, next3 = 3, next5 = 5;

        for (int i = 1; i < n; i++) {
            int next = Math.min(next2, Math.min(next3, next5));
            ugly[i] = next;

            if (next == next2) next2 = 2 * ugly[++i2];
            if (next == next3) next3 = 3 * ugly[++i3];
            if (next == next5) next5 = 5 * ugly[++i5];
        }

        return ugly[n - 1];
    }
}





// Algomonster code but not optimal using hashmap

class Solution {
    public int nthUglyNumber(int n) {
        Set<Long> visitedNumbers = new HashSet<>();
        PriorityQueue<Long> minHeap = new PriorityQueue<>();
        int[] primeFactors = new int[] {2, 3, 5};

        minHeap.offer(1L);
        visitedNumbers.add(1L);

        long currentUglyNumber = 0;

        while (n-- > 0) {
            currentUglyNumber = minHeap.poll();

            for (int factor : primeFactors) {
                long nextUglyNumber = currentUglyNumber * factor;

                if (visitedNumbers.add(nextUglyNumber)) {
                    minHeap.offer(nextUglyNumber);
                }
            }
        }

        return (int) currentUglyNumber;
    }
}
