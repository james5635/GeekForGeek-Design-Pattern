#include <iostream>
#include <string>
class Context
{
};
class Expression
{
  public:
    virtual int interpret(Context &context) = 0;
    virtual ~Expression()
    {
    }
};
class NumberExpression : public Expression
{
  private:
    int number_;

  public:
    NumberExpression(int number) : number_(number)
    {
    }
    int interpret(Context &context) override
    {
        return number_;
    }
};
class AdditionExpression : public Expression
{
  private:
    Expression *left_;
    Expression *right_;

  public:
    AdditionExpression(Expression *left, Expression *right) : left_(left), right_(right)
    {
    }
    int interpret(Context &context) override
    {
        return left_->interpret(context) + right_->interpret(context);
    }
    ~AdditionExpression()
    {
        delete left_;
        delete right_;
    }
};
class MultiplicationExpression : public Expression
{
  private:
    Expression *left_;
    Expression *right_;

  public:
    MultiplicationExpression(Expression *left, Expression *right) : left_(left), right_(right)
    {
    }
    int interpret(Context &context) override
    {
        return left_->interpret(context) * right_->interpret(context);
    }
    ~MultiplicationExpression()
    {
        delete left_;
        delete right_;
    }
};
class Interpreter
{
  private:
    Context* context_;

  public:
    Interpreter(Context *context) : context_(context)
    {
    }
    int interpret(const std::string &expression){
      Expression* expressionTree = builfExpressionTree(expression);
      int result = expressionTree->interpret(*context_);
      delete expressionTree;
      return result;
    }
  private:
    Expression* builfExpressionTree(const std::string &expression){
      // This is a placeholder for the actual implementation
      // In a real scenario, you would parse the expression and build the tree accordingly
      return new AdditionExpression(
          new NumberExpression(5),
          new MultiplicationExpression(
              new NumberExpression(10),
              new NumberExpression(2)
          )
      );
    }
};
int main()
{
    Context * context = new Context();
    Interpreter interpreter(context);
    std::string expression = "5 + 10 * 2"; // Example expression
    int result = interpreter.interpret(expression);
    std::cout << "Result: " << result << std::endl; // Output: Result: 25
    delete context;
    return 0;
}
// Output: Result: 25