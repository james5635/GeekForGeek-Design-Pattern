#include <iostream>
#include <string>
class AuthenticationHandler
{
  public:
    virtual void setNextHandler(AuthenticationHandler *hander) = 0;
    virtual void handleRequest(const std ::string &request) = 0;
};
class UsernamePasswordHander : public AuthenticationHandler
{
  private:
    AuthenticationHandler *nextHandler;

  public:
    void setNextHandler(AuthenticationHandler *handler) override
    {
        nextHandler = handler;
    }
    void handleRequest(const std::string &request) override
    {
        if (request == "username_password")
        {
            std::cout << "Authenticated using username and password" << std::endl;
        }
        else if (nextHandler != nullptr)
        {
            nextHandler->handleRequest(request);
        }
        else
        {
            std::cout << "Invalid authentication method" << std::endl;
        }
    }
};
class OAuthHandler : public AuthenticationHandler
{
  private:
    AuthenticationHandler *nextHander;

  public:
    void setNextHandler(AuthenticationHandler *handle) override
    {
        nextHander = handle;
    }
    void handleRequest(const std::string &request) override
    {
        if (request == "oauth_token")
        {
            std::cout << "Authenticated using OAuth token" << std::endl;
        }
        else if (nextHander != nullptr)
        {
            nextHander->handleRequest(request);
        }
        else
        {
            std::cout << "Invalid authentication method\n";
        }
    }
};
int main()
{
    AuthenticationHandler *usernamePasswordHandler = new UsernamePasswordHander();
    AuthenticationHandler *oAuthHandler = new OAuthHandler();
    usernamePasswordHandler->setNextHandler(oAuthHandler);

    usernamePasswordHandler->handleRequest("oauth_token");
    usernamePasswordHandler->handleRequest("username_password");
    usernamePasswordHandler->handleRequest("invalid_method");
    delete usernamePasswordHandler;
    delete oAuthHandler;
    return 0;
}