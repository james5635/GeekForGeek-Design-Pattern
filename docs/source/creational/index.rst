Creational Design Pattern
=========================

.. code-block:: cpp

    enum Direction {North, South, East, West};

    class MapSite {
    public:
        virtual void Enter() = 0;
    };

    class Room : public MapSite {
    public:
        Room(int roomNo);
        MapSite* GetSide(Direction) const;
        void SetSide(Direction, MapSite*);
        virtual void Enter();
    private:
        MapSite* _sides[4];
        int _roomNumber;
    };

    class Wall : public MapSite {
    public:
        Wall() ;
        virtual void Enter();
    };
    class Door : public MapSite {
    public:
        Door(Room* = 0, Room* = 0);
        virtual void Enter();
        Room* OtherSideFrom(Room*);
    private:
        Room* _rooml;
        Room* _room2;
        bool _isOpen;
    };

    class Maze {
    public:
        Maze();
        void AddRoom(Room* ) ;
        Room* RoomNo(int) const;
    private:
        // . . .
    };

    Maze* MazeGame::CreateMaze () {
        Maze* aMaze = new Maze;
        Room* rl = new Room(l);
        Room* r2 = new Room (2);
        Door* theDoor = new Door(rl, r2);
        aMaze->AddRoom(rl);
        aMaze->AddRoom(r2);
        rl->SetSide(North, new Wall);
        rl->SetSide(East, theDoor);
        rl->SetSide(South, new Wall);
        rl->SetSide(West, new Wall);
        r2->SetSide(North, new Wall);
        r2->SetSide(East, new Wall);
        r2->SetSide(South, new Wall);
        r2->SetSide(West, theDoor);
        return aMaze;
    }

.. toctree::

    abstract-factory
    builder