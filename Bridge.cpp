#include <iostream>
class Shape
{
  public:
    virtual void draw() = 0;
};
class Renderer
{
  public:
    virtual void render() = 0;
};
class VectorRenderer : public Renderer
{
  public:
    void render() override
    {
        std::cout << "Rendering as a vector" << std::endl;
    }
};
class RasterRenderer : public Renderer
{
  public:
    void render() override
    {
        std::cout << "Rendering as a raster" << std::endl;
    }
};
class Circle : public Shape
{
  public:
    Circle(Renderer &renderer) : renderer(renderer)
    {
    }
    void draw() override
    {
        std::cout << "Drawing a circle";
        renderer.render();
    }

  private:
    Renderer &renderer;
};
class Square : public Shape
{
  public:
    Square(Renderer &renderer) : renderer(renderer)
    {
    }
    void draw() override
    {
        std::cout << "Drawing a square";
        renderer.render();
    }

  private:
    Renderer &renderer;
};
int main()
{
    VectorRenderer vectorRenderer;
    RasterRenderer rasterRenderer;

    Circle circle(vectorRenderer);
    Square square(rasterRenderer);

    circle.draw();
    square.draw();

    return 0;
}
