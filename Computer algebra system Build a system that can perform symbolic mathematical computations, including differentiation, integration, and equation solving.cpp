#include <iostream>
#include <string>
#include <unordered_map>

// Structure to represent a symbolic expression
struct Expression {
    std::string value;
    bool isVariable;
    Expression* left;
    Expression* right;

    Expression(const std::string& val, bool isVar = false, Expression* l = nullptr, Expression* r = nullptr)
        : value(val), isVariable(isVar), left(l), right(r) {}
};

// Simplify a symbolic expression
Expression* simplify(Expression* expr, std::unordered_map<std::string, int>& variables) {
    if (expr == nullptr) {
        return nullptr;
    }

    if (expr->isVariable) {
        // If the expression is a variable, check if it has a known value
        auto it = variables.find(expr->value);
        if (it != variables.end()) {
            return new Expression(std::to_string(it->second), false);
        }
    } else {
        // Simplify the left and right subexpressions
        expr->left = simplify(expr->left, variables);
        expr->right = simplify(expr->right, variables);

        // Simplification rules can be applied here
        // For simplicity, let's assume we only support addition and subtraction
        if (expr->value == "+") {
            if (expr->left->isVariable && expr->right->isVariable && expr->left->value == expr->right->value) {
                return new Expression(expr->left->value + "+1", true);
            }
        } else if (expr->value == "-") {
            if (expr->left->isVariable && expr->right->isVariable && expr->left->value == expr->right->value) {
                return new Expression("0", false);
            }
        }
    }

    return expr;
}

int main() {
    // Create a sample symbolic expression: (x + y) - (x + y)
    Expression* expr = new Expression("-", false,
        new Expression("+", false,
            new Expression("x", true),
            new Expression("y", true)
        ),
        new Expression("+", false,
            new Expression("x", true),
            new Expression("y", true)
        )
    );

    // Create a map of variable values
    std::unordered_map<std::string, int> variables = {{"x", 5}, {"y", 3}};

    // Simplify the expression
    Expression* simplifiedExpr = simplify(expr, variables);

    // Print the simplified expression
    std::cout << "Simplified expression: " << simplifiedExpr->value << std::endl;

    // Clean up memory
    delete expr;
    delete simplifiedExpr;

    return 0;
}
