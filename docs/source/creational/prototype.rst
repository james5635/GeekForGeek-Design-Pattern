Prototype Design Pattern
========================

Introduction
------------

Specify the kinds of objects to create using a prototypical instance, and create new objects by copying this prototype.

UML Class Diagram
-----------------

TODO 📝

Participant
-----------

- Prototype
- ConcretePrototype
- Client

Usage
-----

Use the Prototype pattern when a system should be independent of how its products are created, composed, and represented; and

- when the classes to instantiate are specified at run-time, for example, by dynamic loading; or
- to avoid building a class hierarchy of factories that parallels the class hierarchy of products; or
- when instances of a class can have one of only a few different combinations of state. It may be more convenient to install a corresponding number of prototypes and clone them rather than instantiating the class manually, each time with the appropriate state.

Consequence
-----------

- Hides the concrete product classes from the client
- Let a client work with application-specific classes without modification
- Adding and removing products at run-time
- Specifying new objects by varying values
- Specifying new objects by varying structure
- Reduced subclassing
- Configuring an application with classes dynamically

Implementation
--------------

- Using a prototype manager
- Implementing the Clone operation
- Initializing clones

Sample Code
-----------

.. code-block:: cpp

    // Client
    class MazePrototypeFactory : public MazeFactory {
    public:
        MazePrototypeFactory (Maze*, Wall*, Room*, Door*),-
        virtual Maze* MakeMaze() const;
        virtual Room* MakeRoom(int) const;
        virtual Wall* MakeWall() const;
        virtual Door* MakeDoor(Room*, Room*) const;
    private:
        Maze* _prototypeMaze;
        Room* _prototypeRoom;
        Wall* _prototypeWall;
        Door* _prototypeDoor;

    MazePrototypeFactory::MazePrototypeFactory (
        Maze* m, Wall* w, Room* r, Door* d
    ) {
        _prototypeMaze = m;
        _prototypeWall = w;
        __prototypeRoom = r;
        _prototypeDoor = d;
    }

    Wall* MazePrototypeFactory::MakeWall () const {
        return _prototypeWall->Clone();
    }
    Door* MazePrototypeFactory::MakeDoor (Room* rl, Room *r2) const {
        Door* door = _prototypeDoor->Clone();
        door->Initialize(rl, r2);
        return door;
    }

    MazeGame game;
    MazePrototypeFactory simpleMazeFactory(
        new Maze, new Wall, new Room, new Door
    );
    Maze* maze = game.CreateMaze(simpleMazeFactory);

    MazePrototypeFactory bombedMazeFactory(
        new Maze, new BombedWall,
        new RoomWithABomb, new Door
    );

    // Prototype
    class Door : public MapSite {
    public:
        Door();
        Door(const Door&);
        virtual void Initialize(Room*, Room*);
        virtual Door* Clone() const;
        virtual void Enter();
        Room* OtherSideFrom(Room*);
    private:
        Room* _room1;
        Room* _room2;
    };

    Door::Door (const Door& other) {
        _room1 = other._room1;
        _room2 = other._room2;
    }

    void Door::Initialize (Room* r1, Room* r2) {
        _room1 = r1;
        _room2 = r2;
    }

    Door* Door::Clone () const {
        return new Door(*this);
    }

    // ConcretePrototype
    class BombedWall : public Wall {
    public:
        BombedWall();
        BombedWall(const BombedWall&);

        virtual Wall* Clone() const;
        bool HasBomb();
    private:
        bool _bomb;
    };

    BombedWall::BombedWall (const BombedWall& other) : Wall(other) {
        _bomb = other._bomb;
    }

    Wall* BombedWall::Clone () const {
        return new BombedWall(*this);
    }

Example
-------

1. Shape Cloning in a Graphics Editor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In a vector graphics editor like Inkscape or a simple drawing app, users often duplicate shapes (e.g., circles or rectangles) to create complex designs. Creating each shape from scratch is inefficient if they share similar properties. The Prototype pattern allows cloning existing shapes, modifying only what's needed, to avoid redundant initialization.

.. code-block:: java

    import java.util.HashMap;
    import java.util.Map;

    // Prototype Interface
    interface Shape extends Cloneable {
        Shape clone();
        void draw();
    }

    // Concrete Prototypes
    class Circle implements Shape {
        private int radius;
        private String color;

        public Circle(int radius, String color) {
            this.radius = radius;
            this.color = color;
        }

        @Override
        public Shape clone() {
            try {
                return (Shape) super.clone(); // shallow copy/shallow clone
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        @Override
        public void draw() {
            System.out.println("🟢 Drawing Circle [Radius: " + radius + ", Color: " + color + "]");
        }

        public void setRadius(int radius) { this.radius = radius; }
        public void setColor(String color) { this.color = color; }
    }

    class Rectangle implements Shape {
        private int width;
        private int height;
        private String color;

        public Rectangle(int width, int height, String color) {
            this.width = width;
            this.height = height;
            this.color = color;
        }

        @Override
        public Shape clone() {
            try {
                return (Shape) super.clone(); // shallow copy/shallow clone
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        @Override
        public void draw() {
            System.out.println("🟥 Drawing Rectangle [Width: " + width + ", Height: " + height + ", Color: " + color + "]");
        }

        public void setWidth(int width) { this.width = width; }
        public void setHeight(int height) { this.height = height; }
        public void setColor(String color) { this.color = color; }
    }

    // Prototype Registry (optional for caching prototypes)
    class ShapeRegistry {
        private Map<String, Shape> prototypes = new HashMap<>();

        public void addPrototype(String key, Shape prototype) {
            prototypes.put(key, prototype);
        }

        public Shape getPrototype(String key) {
            Shape prototype = prototypes.get(key);
            return prototype != null ? prototype.clone() : null;
        }
    }

    // Client
    public class Main {
        public static void main(String[] args) {
            ShapeRegistry registry = new ShapeRegistry();

            // Create and register prototypes
            Circle circleProto = new Circle(10, "Red");
            registry.addPrototype("circle", circleProto);

            Rectangle rectProto = new Rectangle(20, 15, "Blue");
            registry.addPrototype("rectangle", rectProto);

            // Clone and modify
            Circle clonedCircle = (Circle) registry.getPrototype("circle");
            clonedCircle.setRadius(15);
            clonedCircle.setColor("Green");
            clonedCircle.draw();

            Rectangle clonedRect = (Rectangle) registry.getPrototype("rectangle");
            clonedRect.setWidth(30);
            clonedRect.draw();
        }
    }

2. Document Template Cloning in a Word Processor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In a document management system like Microsoft Word or Google Docs, users create new documents based on templates (e.g., resume or invoice). Instead of building from scratch each time, the Prototype pattern clones a pre-configured template, allowing customization without affecting the original.

.. code-block:: java

    import java.util.ArrayList;
    import java.util.List;

    // Prototype Interface
    interface Document extends Cloneable {
        Document clone();
        void display();
        void addSection(String section);
    }

    // Concrete Prototype
    class Resume implements Document {
        private String title;
        private List<String> sections = new ArrayList<>();

        public Resume(String title) {
            this.title = title;
            // Default sections (expensive to initialize if complex)
            sections.add("Personal Info");
            sections.add("Education");
            sections.add("Experience");
        }

        @Override
        public Document clone() {
            try {
                Resume clone = (Resume) super.clone();
                clone.sections = new ArrayList<>(this.sections); // deep copy/deep clone
                return clone;
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        @Override
        public void display() {
            System.out.println("📄 Resume: " + title);
            System.out.println("Sections: " + sections);
        }

        @Override
        public void addSection(String section) {
            sections.add(section);
        }

        public void setTitle(String title) { this.title = title; }
    }

    // Client
    public class Main {
        public static void main(String[] args) {
            // Original prototype
            Resume template = new Resume("Standard Resume Template");

            // Clone for new user
            Resume johnResume = (Resume) template.clone();
            johnResume.setTitle("John Doe's Resume");
            johnResume.addSection("Skills");
            johnResume.display();

            // Another clone
            Resume janeResume = (Resume) template.clone();
            janeResume.setTitle("Jane Smith's Resume");
            janeResume.addSection("Projects");
            janeResume.display();

            // Original remains unchanged
            template.display();
        }
    }

3. Product Variant Cloning in an E-commerce Inventory System
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

An online store like Amazon manages product variants (e.g., a shirt in different colors/sizes). Creating each variant from scratch is redundant since they share base attributes. The Prototype pattern clones a base product prototype, then customizes variants, reducing creation overhead.

.. code-block:: java

    import java.util.HashMap;
    import java.util.Map;

    // Prototype Interface
    interface Product extends Cloneable {
        Product clone();
        void showDetails();
    }

    // Concrete Prototype
    class Shirt implements Product {
        private String name;
        private double price;
        private String material;
        private Map<String, String> variants = new HashMap<>(); // e.g., color, size

        public Shirt(String name, double price, String material) {
            this.name = name;
            this.price = price;
            this.material = material;
            // Default variants (could be loaded from DB, expensive)
            variants.put("Color", "White");
            variants.put("Size", "M");
        }

        @Override
        public Product clone() {
            try {
                Shirt clone = (Shirt) super.clone();
                clone.variants = new HashMap<>(this.variants); // deep copy/deep clone
                return clone;
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        @Override
        public void showDetails() {
            System.out.println("👕 Shirt: " + name + " [Price: $" + price + ", Material: " + material + ", Variants: " + variants + "]");
        }

        public void setVariant(String key, String value) {
            variants.put(key, value);
        }

        public void setPrice(double price) { this.price = price; }
    }

    // Client
    public class Main {
        public static void main(String[] args) {
            // Base prototype
            Shirt baseShirt = new Shirt("Basic T-Shirt", 19.99, "Cotton");

            // Clone for variant 1
            Shirt redLarge = (Shirt) baseShirt.clone();
            redLarge.setVariant("Color", "Red");
            redLarge.setVariant("Size", "L");
            redLarge.setPrice(21.99);
            redLarge.showDetails();

            // Clone for variant 2
            Shirt blueSmall = (Shirt) baseShirt.clone();
            blueSmall.setVariant("Color", "Blue");
            blueSmall.setVariant("Size", "S");
            blueSmall.showDetails();

            // Original unchanged
            baseShirt.showDetails();
        }
    }