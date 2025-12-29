// Write a Program for an infix
// expression and convert it to
// postfix notation. Use a queue to
// implement the Shunting Yard
// Algorithm for expression
// conversion.






// ChatGPT code

import java.util.*;

public class Shunting_Yard_Algo {

    // Function to return precedence of operators
    public static int precedence(char c) {
        switch (c) {
            case '^': return 3;
            case '*': 
            case '/': return 2;
            case '+': 
            case '-': return 1;
        }
        return 0;
    }

    // Check if char is operator
    public static boolean isOperator(char c) {
        return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
    }

    // Function to convert infix to postfix using Shunting Yard algorithm
    public static String infixToPostfix(String infix) {
        Stack<Character> stack = new Stack<>();     // operator stack
        Queue<Character> output = new LinkedList<>(); // queue for postfix output

        for (char c : infix.toCharArray()) {

            if (Character.isLetterOrDigit(c)) { // operand → directly to queue
                output.add(c);
            }
            else if (c == '(') {
                stack.push(c);
            }
            else if (c == ')') {
                while (!stack.empty() && stack.peek() != '(') {
                    output.add(stack.pop());
                }
                stack.pop(); // remove '('
            }
            else if (isOperator(c)) {
                while (!stack.empty() && precedence(stack.peek()) >= precedence(c)) {
                    output.add(stack.pop());
                }
                stack.push(c);
            }
        }

        // Pop remaining operators from stack
        while (!stack.empty()) {
            output.add(stack.pop());
        }

        // Convert queue to string
        StringBuilder postfix = new StringBuilder();
        while (!output.isEmpty()) {
            postfix.append(output.poll());
        }

        return postfix.toString();
    }

    // Driver Code
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Infix Expression: ");
        String infix = sc.nextLine();

        System.out.println("Postfix Expression: " + infixToPostfix(infix));
        sc.close();
    }
}
