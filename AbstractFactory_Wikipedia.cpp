#include <iostream>
#include <string>
#include <string_view>

enum class Direction
{
    North,
    South,
    East,
    West
};

// Helper function to convert Direction to string
std::string directionToString(Direction d)
{
    switch (d)
    {
    case Direction::North:
        return "North";
    case Direction::South:
        return "South";
    case Direction::East:
        return "East";
    case Direction::West:
        return "West";
    default:
        return "Unknown";
    }
}

class MapSite
{
  public:
    virtual void enter() = 0;
    virtual ~MapSite() = default;
};

class Room : public MapSite
{
  public:
    Room() : roomNumber(0)
    {
    }
    Room(int n) : roomNumber(n)
    {
    }
    void setSide(Direction d, MapSite *mp)
    {
        std::cout << "Room::setSide " << directionToString(d) << " " << mp << std::endl;
    }
    virtual void enter()
    {
    }
    // copy constructor
    Room(const Room &) = delete;
    // assignment operator
    Room &operator=(const Room &) = delete;

  private:
    int roomNumber;
};

class Wall : public MapSite
{
  public:
    Wall()
    {
    }
    virtual void enter()
    {
    }
};

class Door : public MapSite
{
  public:
    Door(Room *r1 = nullptr, Room *r2 = nullptr) : room1(r1), room2(r2)
    {
    }
    virtual void enter()
    {
    }
    Door(const Door &) = delete;
    Door &operator=(const Door &) = delete;

  private:
    Room *room1;
    Room *room2;
};

class Maze
{
  public:
    void addRoom(Room *r)
    {
        std::cout << "Maze::addRoom " << r << std::endl;
    }
    Room *roomNo(int) const
    {
        return nullptr;
    }
};

class MazeFactory
{
  public:
    MazeFactory() = default;
    virtual ~MazeFactory() = default;
    virtual Maze *makeMaze() const
    {
        return new Maze();
    }
    virtual Wall *makeWall() const
    {
        return new Wall();
    }
    virtual Room *makeRoom(int n) const
    {
        return new Room(n);
    }
    virtual Door *makeDoor(Room *r1, Room *r2)
    {
        return new Door(r1, r2);
    }
};

class MazeGame
{
  public:
    Maze *createMaze(MazeFactory &factory)
    {
        Maze *aMaze = factory.makeMaze();
        Room *r1 = factory.makeRoom(1);
        Room *r2 = factory.makeRoom(2);
        Door *aDoor = factory.makeDoor(r1, r2);
        aMaze->addRoom(r1);
        aMaze->addRoom(r2);
        r1->setSide(Direction::North, factory.makeWall());
        r1->setSide(Direction::East, aDoor);
        r1->setSide(Direction::South, factory.makeWall());
        r2->setSide(Direction::North, factory.makeWall());
        r2->setSide(Direction::East, factory.makeWall());
        r2->setSide(Direction::South, factory.makeWall());
        r2->setSide(Direction::West, aDoor);
        return aMaze;
    }
};

int main()
{
    MazeGame game;
    MazeFactory factory;
    game.createMaze(factory);
}