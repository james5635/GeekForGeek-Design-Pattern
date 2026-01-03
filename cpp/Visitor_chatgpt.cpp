#include <iostream>
#include <memory>

class ExprVisitor;

class Expr
{
  public:
    virtual void accept(ExprVisitor &v) = 0;
    virtual ~Expr() = default;
};
class NumberExpr : public Expr
{
  public:
    NumberExpr(double value) : value(value)
    {
    }
    void accept(ExprVisitor &v) override;

    double value;
};

class BinaryExpr : public Expr
{
  public:
    char op;
    std::shared_ptr<Expr> left;
    std::shared_ptr<Expr> right;
    BinaryExpr(char op, std::shared_ptr<Expr> left, std::shared_ptr<Expr> right) : op(op), left(left), right(right)
    {
    }
    void accept(ExprVisitor &v) override;
};

class ExprVisitor
{
  public:
    virtual void visit(NumberExpr &e) = 0;
    virtual void visit(BinaryExpr &e) = 0;
    virtual ~ExprVisitor() = default;
};

class PrintVisitor : public ExprVisitor
{
  public:
    void visit(NumberExpr &e) override
    {
        std::cout << e.value;
    }
    void visit(BinaryExpr &e) override
    {
        std::cout << "(";
        e.left->accept(*this);
        std::cout << " " << e.op << " ";
        e.right->accept(*this);
        std::cout << ")";
    }
};

class EvalVisitor : public ExprVisitor
{
  public:
    double result;
    void visit(NumberExpr &e) override
    {
        result = e.value;
    }
    void visit(BinaryExpr &e) override
    {
        e.left->accept(*this);
        double left = result;
        e.right->accept(*this);
        double right = result;

        // switch only used with integral types and enum types
        switch (e.op)
        {
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            result = left / right;
            break;
        }

    }
};
void NumberExpr::accept(ExprVisitor &v)
{
    v.visit(*this);
}
void BinaryExpr::accept(ExprVisitor &v)
{
    v.visit(*this);
}
int main()
{
    // Create an expression: (1 + 2) * 3
    std::shared_ptr<Expr> expr = std::make_shared<BinaryExpr>(
        '*',
        std::make_shared<BinaryExpr>(
            '+',
            std::make_shared<NumberExpr>(1),
            std::make_shared<NumberExpr>(2)),
        std::make_shared<NumberExpr>(3));

    // Print the expression
    PrintVisitor printVisitor;
    std::cout << "Expression: ";
    expr->accept(printVisitor);
    std::cout << std::endl;

    // Evaluate the expression
    EvalVisitor evalVisitor;
    expr->accept(evalVisitor);
    std::cout << "Result: " << evalVisitor.result << std::endl;

    return 0;
}