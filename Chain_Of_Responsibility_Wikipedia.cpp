#include <iostream>
#include <memory>
typedef int Topic;
constexpr Topic NO_HELP_TOPIC = -1;
class HelpHandler
{
  public:
    HelpHandler(HelpHandler *h = nullptr, Topic t = NO_HELP_TOPIC) : successor(h), topic(t)
    {
    }
    virtual bool hasHelp()
    {
        return topic != NO_HELP_TOPIC;
    }
    virtual void setHandler(HelpHandler *, Topic)
    {
    }
    virtual void handleHelp()
    {
        std::cout << "HelpHandler::handleHelp\n";
        if (successor != nullptr)
        {
            successor->handleHelp();
        }
    }

    virtual ~HelpHandler() = default;
    HelpHandler(const HelpHandler &) = delete;
    HelpHandler &operator=(const HelpHandler &) = delete;

  private:
    HelpHandler *successor;
    Topic topic;
};
class Widget : public HelpHandler
{
  public:
    Widget(const Widget &) = delete;
    Widget &operator=(const Widget &) = delete;

  protected:
    Widget(Widget *w, Topic t = NO_HELP_TOPIC) : HelpHandler(w, t), parent(nullptr)
    {
        parent = w;
    }

  private:
    Widget *parent;
};
class Button : public Widget
{
  public:
    Button(std::shared_ptr<Widget> h, Topic t = NO_HELP_TOPIC) : Widget(h.get(), t)
    {
    }
    virtual void handleHelp()
    {
        std::cout << "Button::handleHelp\n";
        if (hasHelp())
        {
        }
        else
        {
            HelpHandler::handleHelp();
        }
    }
};
class Dialog : public Widget
{
  public:
    Dialog(std::shared_ptr<HelpHandler>h, Topic t = NO_HELP_TOPIC) : Widget(nullptr)
    {
        setHandler(h.get(), t);
    }
    virtual void handleHelp()
    {
        std::cout << "Dialog::handleHelp\n";
        if (hasHelp())
        {
        }
        else
        {
            HelpHandler::handleHelp();
        }
    }
};
class Application : public HelpHandler
{
  public:
    Application(Topic t) : HelpHandler(nullptr, t)
    {
    }
    virtual void handeleHelp()
    {
        std::cout << "Application::handleJelp\n";
    }
};
int main()
{
    constexpr Topic PRINT_TOPIC = 1;
    constexpr Topic PAPER_ORGANIZATION_TOPIC = 2;
    constexpr Topic Application_TOPIC = 3;

    std::shared_ptr<Application> application = std::make_shared<Application>(Application_TOPIC);
    std::shared_ptr<Dialog> dialog = std::make_shared<Dialog>(application, PRINT_TOPIC);
    std::shared_ptr<Button> button = std::make_shared<Button>(dialog, PAPER_ORGANIZATION_TOPIC);

    button->handleHelp();

    return 0;
}
