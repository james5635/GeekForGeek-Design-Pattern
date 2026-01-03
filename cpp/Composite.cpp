#include <iostream>
#include <vector>
using namespace std;

class PageObject
{
  public:
    virtual void Add(PageObject     ageobject)
    {
    }
    virtual void Remove()
    {
    }
    virtual void Delete()
    {
    }
};
class Page : public PageObject
{
  public:
    void Add(PageObject a)
    {
        cout << "Something is added to the page" << endl;
    }
    void Remove()
    {
        cout << "Something is removed from the page" << endl;
    }
    void Delete()
    {
        cout << "Something is deleted from the page" << endl;
    }
};
class Copy : public PageObject
{
    vector<PageObject> copyPages;

  public:
    void AddElement(PageObject a)
    {
        copyPages.push_back(a);
    }
    void Add(PageObject a)
    {
        cout << "Something is added to the copy" << endl;
    }
    void Remove()
    {
        cout << "Something is removed from the copy" << endl;
    }
    void Delete()
    {
        cout << "Something is deleted from the copy" << endl;
    }
};
int main()
{
    Page a;
    Page b;
    Copy allcopy;
    allcopy.AddElement(a);
    allcopy.AddElement(b);

    allcopy.Add(a);
    a.Add(b);

    allcopy.Remove();
    b.Remove();
    return 0;
}