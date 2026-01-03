#include <iostream>
#include <unordered_map>
class Character
{
  public:
    Character(char intrinsicState) : _intrinsicState(intrinsicState)
    {
    }
    void draw(int extrinsicState)
    {
        std::cout << "Drawing character " << _intrinsicState << " at position " << extrinsicState << std::endl;
    }

  private:
    char _intrinsicState;
};
class CharacterFactory
{
  public:
    Character *getCharacter(char key)
    {
        if (m_characters.find(key) == m_characters.end())

        {
            m_characters[key] = new Character(key);
        }
        return m_characters[key];
    }

  private:
    std::unordered_map<char, Character *> m_characters;
};
int main()
{
    CharacterFactory characterFactory;

    int position = 0;
    characterFactory.getCharacter('A')->draw(position++);
    characterFactory.getCharacter('B')->draw(position++);
    characterFactory.getCharacter('C')->draw(position++);
    characterFactory.getCharacter('C')->draw(position++);
    return 0;
}