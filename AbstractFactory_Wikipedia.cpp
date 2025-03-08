#include <iostream>
#include <print>
enum class Direction
{
    North,
    South,
    East,
    West
};
// Specializing std::formatter for Direction
template <> struct std::formatter<Direction> : std::formatter<std::string>
{
    auto format(Direction d, std::format_context &ctx) const
    {
        std::string_view name = "Unknown";
        switch (d)
        {
        case Direction::North:
            name = "North";
            break;
        case Direction::South:
            name = "South";
            break;
        case Direction::East:
            name = "East";
            break;
        case Direction::West:
            name = "West";
            break;
        }
        return std::formatter<std::string>::format(std::string{name}, ctx);
    }
};

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
        std::println("Room::setside {} {}", d, static_cast<void *>(mp));
    }
    virtual void enter()
    {
    }
    Room(const Room &) = delete;
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
        std::println("Maze::addRoom {}", static_cast<void *>(r));
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
        r2->setSide(Direction ::West, aDoor);
        return aMaze;
    }
};
int main()
{
    MazeGame game;
    MazeFactory factory;
    game.createMaze(factory);
}