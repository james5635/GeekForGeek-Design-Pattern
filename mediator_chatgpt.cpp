#include <iostream>
#include <string>
#include <vector>
// Mediator Interface
class Participant;
class ChatRoom
{
  public:
    virtual void sendMessage(const std::string &message, Participant *sender) = 0;
    virtual ~ChatRoom() = default;
};
// Colleague Interface  and Concrete class
class Participant
{
  protected:
    ChatRoom *chatRoom;
    std::string name;

  public:
    Participant(ChatRoom *chatRoom, const std::string &name) : chatRoom(chatRoom), name(name)
    {
    }
    virtual void send(const std::string &message)
    {
        chatRoom->sendMessage(message, this);
    }
    virtual void receive(const std::string &message)
    {
        std::cout << name << " received: " << message << std::endl;
    }
    virtual ~Participant() = default;
    std::string getName() const
    {
        return name;
    }
};
// Concrete Mediator
class ConcreteChatRoom : public ChatRoom
{
  private:
    std::vector<Participant *> participants;

  public:
    void addParticipant(Participant *participant)
    {
        participants.push_back(participant);
    }
    void sendMessage(const std::string &message, Participant *sender) override
    {
        for (auto participant : participants)
        {
            if (participant != sender)
            {
                participant->receive(sender->getName() + ": " + message);
            }
        }
    }
};

int main()
{
    ConcreteChatRoom chatRoom;

    Participant *alice = new Participant(&chatRoom, "Alice");
    Participant *bob = new Participant(&chatRoom, "Bob");
    Participant *charlie = new Participant(&chatRoom, "Charlie");

    chatRoom.addParticipant(alice);
    chatRoom.addParticipant(bob);
    chatRoom.addParticipant(charlie);

    alice->send("Hello, everyone!");
    bob->send("Hi, Alice!");

    delete alice;
    delete bob;
    delete charlie;

    return 0;
}