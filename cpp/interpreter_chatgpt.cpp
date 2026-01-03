#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
class Context
{
  public:
    std::unordered_map<std::string, int> variables;
    int get(const std::string &name)
    {
        return variables[name];
    }
};
// Define Expression Interface

class Expression
{
  public:
    virtual int interpret(Context &context) = 0;
    virtual ~Expression() = default;
};
// 2. Terminal Expression
class Number : public Expression
{
  private:
    int value;

  public:
    Number(int v) : value(v)
    {
    }
    int interpret(Context &context) override
    {
        return value;
    }
};
class Variable : public Expression
{
  private:
    std::string name;

  public:
    Variable(const std::string &n) : name(std::move(n))
    {
    }
    int interpret(Context &context) override
    {
        return context.get(name);
    }
};
// Non-terminal Expression
class Add: public Expression
{
  private:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

  public:
    Add(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) : left(std::move(l)), right(std::move(r))
    {
    }
    int interpret(Context &context) override
    {
        return left->interpret(context) + right->interpret(context);
    }
};
class Subtract: public Expression
{
  private:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

  public:
    Subtract(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) : left(std::move(l)), right(std::move(r))
    {
    }
    int interpret(Context &context) override
    {
        return left->interpret(context) - right->interpret(context);
    }
};
class Multiply: public Expression
{
  private:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

  public:
    Multiply(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) : left(std::move(l)), right(std::move(r))
    {
    }
    int interpret(Context &context) override
    {
        return left->interpret(context) * right->interpret(context);
    }
};
// 4. Usage
int main()
{
    Context context;
    context.variables["x"] = 5;
    context.variables["y"] = 10;

    // (x + y) * 2
    std::unique_ptr<Expression> expression = std::make_unique<Multiply>(
        std::make_unique<Add>(
            std::make_unique<Variable>("x"),
            std::make_unique<Variable>("y")
        ),
        std::make_unique<Number>(2)
    );

    int result = expression->interpret(context);
    std::cout << "Result: " << result << std::endl; // Output: Result: 30

    return 0;
}