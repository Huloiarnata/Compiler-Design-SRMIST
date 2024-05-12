#include <iostream>
#include <string>
#include <stack>
#include <cctype>

struct Node {
    char data;
    Node *left, *right;
    Node(char data) : data(data), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Node* constructSyntaxTree(const std::string& postfix) {
    std::stack<Node*> stack;
    for (char c : postfix) {
        Node* node = new Node(c);
        if (isOperator(c)) {
            node->right = stack.top();
            stack.pop();
            node->left = stack.top();
            stack.pop();
        }
        stack.push(node);
    }
    return stack.top();
}

int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0; // Handle invalid operator gracefully
    }
}

int evaluateSyntaxTree(Node* root) {
    if (!root) return 0;
    if (std::isdigit(root->data)) return root->data - '0';
    return performOperation(root->data,
                            evaluateSyntaxTree(root->left),
                            evaluateSyntaxTree(root->right));
}

int main() {
    std::string postfix;
    std::cout << "Enter a postfix expression: ";
    std::cin >> postfix;
    Node* root = constructSyntaxTree(postfix);
    std::cout << "Result: " << evaluateSyntaxTree(root) << std::endl;
    return 0;
}
