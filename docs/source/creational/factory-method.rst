Factory Method Design Pattern
=============================

Introduction
------------

Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.

Factory Method pattern is also known as Virtual Constructor.

UML Class Diagram
-----------------

Participant
-----------

- Product
- ConcreteProduct
- Creator
- ConcreteCreator

Usage
-----

Use the Factory Method pattern when:

- a class can't anticipate the class of objects it must create.
- a class wants its subclasses to specify the objects it creates.
- classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate.

Consequence
-----------

- Eliminate the need to bind application-specific classes
- Might have to subclass the Creator class
- Provides hooks for subclasses
- Connects parallel class hierarchies

Implementation
--------------

- Two major varieties
- Parameterized factory methods
- Language-specific variants and issues
- Using templates to avoid subclassing
- Naming conventions

Sample Code
-----------

.. code-block:: cpp

    class MazeGame {
    public:
        Maze* CreateMaze();

    // factory methods:

        virtual Maze* MakeMaze() const
            { return new Maze; }
        virtual Room* MakeRoom(int n) const
            { return new Room(n); }
        virtual Wall* MakeWall() const
            { return new Wall; }
        virtual Door* MakeDoor(Room* r1, Room* r2) const
            { return new Door(r1, r2); }
    };

    Maze* MazeGame::CreateMaze () {
        Maze* aMaze = MakeMaze();

        Room* r1 = MakeRoom(1);
        Room* r2 = MakeRoom(2);
        Door* theDoor = MakeDoor(r1, r2);

        aMaze->AddRoom(r1);
        aMaze->AddRoom(r2);

        r1->SetSide(North, MakeWall());
        r1->SetSide(East, theDoor);
        r1->SetSide(South, MakeWall());
        r1->SetSide(West, MakeWall());
        r2->SetSide(East, MakeWall());
        r2->SetSide(South, MakeWall());
        r2->SetSide(South, MakeWall());
        r2->SetSide(South, MakeWall());
        r2->SetSide(South, MakeWall());
        r2->SetSide(South, MakeWall());
        r2->SetSide(West, theDoor);

        return aMaze;
    }

    class BombedMazeGame : public MazeGame {
    public:
        BombedMazeGame();
        virtual Wall* MakeWall() const
            { return new BombedWall; }
        virtual Room* MakeRoom(int n) const
            { return new RoomWithABomb(n); }
    };

    class EnchantedMazeGame : public MazeGame {
    public:
        EnchantedMazeGame();
        virtual Room* MakeRoom(int n) const
            { return new EnchantedRoom(n, CastSpell()); }
        virtual Door* MakeDoor(Room* rl, Room* r2) const
            { return new DoorNeedingSpell(rl, r2); }
    protected:
        Spell* CastSpell() const;
    };

Example
-------