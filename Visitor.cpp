#include <iostream>
#include <vector>

class Circle;
class Square;

// Visitor interface
class ShapeVisitor
{
  public:
    virtual void visit(Circle &circle) = 0;
    virtual void visit(Square &square) = 0;
};

// Element interface
class Shape
{
  public:
    virtual void accept(ShapeVisitor &visitor) = 0;
};

// Concrete Element: Circle
class Circle : public Shape
{
  public:
    void accept(ShapeVisitor &visitor) override
    {
        visitor.visit(*this);
    }
    void draw()
    {
        std::cout << "Drawing Circle" << std::endl;
    }
};
// Concrete Element: Square
class Square : public Shape
{
  public:
    void accept(ShapeVisitor &visitor) override
    {
        visitor.visit(*this);
    }
    void draw()
    {
        std::cout << "Drawing Square" << std::endl;
    }
};
// Concrete Visitor: DrawingVisitor
class DrawingVisitor : public ShapeVisitor
{
  public:
    void visit(Circle &circle) override
    {
        std::cout << "Visiting Circle" << std::endl;
        circle.draw();
    }
    void visit(Square &square) override
    {
        std::cout << "Visiting Square" << std::endl;
        square.draw();
    }
};
// Concrete Visitor: AreaVisitor
class AreaVisitor : public ShapeVisitor
{
  public:
    void visit(Circle &circle) override
    {

        std::cout << "Calculating area of Circle" << std::endl;
    }
    void visit(Square &square) override
    {
        std::cout << "Calculating area of Square" << std::endl;
    }
};
// Object Structure
class ShapeCollection
{
  private:
    std::vector<Shape *> shapes;

  public:
    void addShape(Shape *shape)
    {
        shapes.push_back(shape);
    }
    void performOperations(ShapeVisitor &visitor)
    {
        for (auto shape : shapes)
        {
            shape->accept(visitor);
        }
    }
};
int main()
{
    ShapeCollection collection;
    Circle circle;
    Square square;

    collection.addShape(&circle);
    collection.addShape(&square);

    DrawingVisitor drawingVisitor;
    AreaVisitor areaVisitor;

    collection.performOperations(drawingVisitor);

    collection.performOperations(areaVisitor);

    return 0;
}