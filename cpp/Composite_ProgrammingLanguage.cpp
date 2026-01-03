// Author: Sou Chanrojame
#include <iostream>
#include <memory>
#include <vector>
template <typename T>
concept Integer = std::is_integral<T>::value;
;
template <typename T>
concept StringLike = std::is_convertible<T, std::string>::value;
template <typename T>
concept ContainerLike = requires(T t) {
    typename T::value_type;                              // Must have a value_type
    { t.begin() } -> std::same_as<typename T::iterator>; // Must have begin()
    { t.end() } -> std::same_as<typename T::iterator>;   // Must have end()
    { t.size() } -> std::convertible_to<std::size_t>;    // Must have size()
};

// An Interface
template <StringLike NameType, Integer YearType, StringLike AuthortType> class ProgrammingLanguage
{
  public:
    virtual ~ProgrammingLanguage() = default;
    ProgrammingLanguage() = default;
    // getter
    virtual NameType getName() = 0;

    virtual YearType getYearCreated() = 0;
    virtual AuthortType getAuthor() = 0;
    // setter
    virtual void setName(NameType name_) = 0;
    virtual void setYearCreated(YearType yearCreated_) = 0;
    virtual void setAuthor(AuthortType author_) = 0;

    virtual void info() = 0;
};

template <class NameType, class YearType, class AuthortType>
class CPlusPlus : public ProgrammingLanguage<NameType, YearType, AuthortType>
{
  public:
    CPlusPlus(NameType n, YearType y, AuthortType a) : name{n}, yearCreated{y}, author{a}
    {
    }
    ~CPlusPlus() override = default;
    // getter
    NameType getName() override
    {
        return name;
    }
    YearType getYearCreated() override
    {
        return yearCreated;
    }
    AuthortType getAuthor() override
    {
        return author;
    }
    // setter
    void setName(NameType name_) override
    {
        name = name_;
    }
    void setYearCreated(YearType yearCreated_) override
    {
        yearCreated = yearCreated_;
    }
    void setAuthor(AuthortType author_) override
    {
        author = author_;
    }

    void info() override
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Year Created: " << yearCreated << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

  private:
    NameType name;
    YearType yearCreated;
    AuthortType author;
};

template <class NameType, class YearType, class AuthortType>
class C : public ProgrammingLanguage<NameType, YearType, AuthortType>
{
  public:
    C(NameType n, YearType y, AuthortType a) : name{n}, yearCreated{y}, author{a}
    {
    }
    ~C() override = default;
    // getter
    NameType getName() override
    {
        return name;
    }
    YearType getYearCreated() override
    {
        return yearCreated;
    }
    AuthortType getAuthor() override
    {
        return author;
    }
    // setter
    void setName(NameType name_) override
    {
        name = name_;
    }
    void setYearCreated(YearType yearCreated_) override
    {
        yearCreated = yearCreated_;
    }
    void setAuthor(AuthortType author_) override
    {
        author = author_;
    }

    void info() override
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Year Created: " << yearCreated << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

  private:
    NameType name;
    YearType yearCreated;
    AuthortType author;
};
template <class NameType, class YearType, class AuthortType>
class Python : public ProgrammingLanguage<NameType, YearType, AuthortType>
{
  public:
    Python(NameType n, YearType y, AuthortType a) : name{n}, yearCreated{y}, author{a}
    {
    }
    ~Python() override = default;
    // getter
    NameType getName() override
    {
        return name;
    }
    YearType getYearCreated() override
    {
        return yearCreated;
    }
    AuthortType getAuthor() override
    {
        return author;
    }
    // setter
    void setName(NameType name_) override
    {
        name = name_;
    }
    void setYearCreated(YearType yearCreated_) override
    {
        yearCreated = yearCreated_;
    }
    void setAuthor(AuthortType author_) override
    {
        author = author_;
    }

    void info() override
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Year Created: " << yearCreated << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

  private:
    NameType name;
    YearType yearCreated;
    AuthortType author;
};
template <class NameType, class YearType, class AuthortType>
class Rust : public ProgrammingLanguage<NameType, YearType, AuthortType>
{
  public:
    Rust(NameType n, YearType y, AuthortType a) : name{n}, yearCreated{y}, author{a}
    {
    }
    ~Rust() override = default;
    // getter
    NameType getName() override
    {
        return name;
    }
    YearType getYearCreated() override
    {
        return yearCreated;
    }
    AuthortType getAuthor() override
    {
        return author;
    }
    // setter
    void setName(NameType name_) override
    {
        name = name_;
    }
    void setYearCreated(YearType yearCreated_) override
    {
        yearCreated = yearCreated_;
    }
    void setAuthor(AuthortType author_) override
    {
        author = author_;
    }

    void info() override
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Year Created: " << yearCreated << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

  private:
    NameType name;
    YearType yearCreated;
    AuthortType author;
};
template <class NameType, class YearType, class AuthortType>
class Typescript : public ProgrammingLanguage<NameType, YearType, AuthortType>
{
  public:
    Typescript(NameType n, YearType y, AuthortType a) : name{n}, yearCreated{y}, author{a}
    {
    }
    ~Typescript() override = default;
    // getter
    NameType getName() override
    {
        return name;
    }
    YearType getYearCreated() override
    {
        return yearCreated;
    }
    AuthortType getAuthor() override
    {
        return author;
    }
    // setter
    void setName(NameType name_) override
    {
        name = name_;
    }
    void setYearCreated(YearType yearCreated_) override
    {
        yearCreated = yearCreated_;
    }
    void setAuthor(AuthortType author_) override
    {
        author = author_;
    }

    void info() override
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Year Created: " << yearCreated << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

  private:
    NameType name;
    YearType yearCreated;
    AuthortType author;
};

template <class NameType, class YearType, class AuthortType>
class Java : public ProgrammingLanguage<NameType, YearType, AuthortType>
{
  public:
    Java(NameType n, YearType y, AuthortType a) : name{n}, yearCreated{y}, author{a}
    {
    }
    ~Java() override = default;
    // getter
    NameType getName() override
    {
        return name;
    }
    YearType getYearCreated() override
    {
        return yearCreated;
    }
    AuthortType getAuthor() override
    {
        return author;
    }
    // setter
    void setName(NameType name_) override
    {
        name = name_;
    }
    void setYearCreated(YearType yearCreated_) override
    {
        yearCreated = yearCreated_;
    }
    void setAuthor(AuthortType author_) override
    {
        author = author_;
    }

    void info() override
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Year Created: " << yearCreated << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

  private:
    NameType name;
    YearType yearCreated;
    AuthortType author;
};
template <class NameType, class YearType, class AuthortType, class ProgrammingLanguageList>
    requires ContainerLike<ProgrammingLanguageList>
class ObjectOrientedProgramingLanguage : public ProgrammingLanguage<NameType, YearType, AuthortType>
{
  public:
    ObjectOrientedProgramingLanguage(NameType n, YearType y, AuthortType a)
        : name{n}, yearCreated{y}, author{a}, programmingLanguageList{}
    {
    }

    ~ObjectOrientedProgramingLanguage() override = default;
    // getter
    NameType getName() override
    {
        return name;
    }
    YearType getYearCreated() override
    {

        return yearCreated;
    }
    AuthortType getAuthor() override
    {
        return author;
    }
    // setter
    void setName(NameType name_) override
    {
        name = name_;
    }
    void setYearCreated(YearType yearCreated_) override
    {
        yearCreated = yearCreated_;
    }
    void setAuthor(AuthortType author_) override
    {
        author = author_;
    }
    void add(std::shared_ptr<ProgrammingLanguage<NameType, YearType, AuthortType>> p)
    {
        this->programmingLanguageList.push_back(p);
    }
    void remove(std::shared_ptr<ProgrammingLanguage<NameType, YearType, AuthortType>> p)
    {
        this->programmingLanguageList.remove(p);
    }
    void info() override
    {
        std::cout << "===================================================" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Year Created: " << yearCreated << std::endl;
        std::cout << "Author: " << author << " 😃" << std::endl;
        std::cout << "===================================================" << std::endl;
        std::cout << "********** List of Programming Languages **********" << std::endl;
        for (auto &&p : programmingLanguageList)
        {
            p->info();
            if (p != programmingLanguageList.back())
            {
                std::cout << "" << std::endl;
            }
        }
    }

  private:
    NameType name;
    YearType yearCreated;
    AuthortType author;
    ProgrammingLanguageList programmingLanguageList;
};

template <class NameType, class YearType, class AuthortType>
class CSharp : public ProgrammingLanguage<NameType, YearType, AuthortType>
{
  public:
    CSharp(NameType n, YearType y, AuthortType a) : name{n}, yearCreated{y}, author{a}
    {
    }
    ~CSharp() override = default;
    // getter
    NameType getName() override
    {
        return name;
    }
    YearType getYearCreated() override
    {
        return yearCreated;
    }
    AuthortType getAuthor() override
    {
        return author;
    }
    // setter
    void setName(NameType name_) override
    {
        name = name_;
    }
    void setYearCreated(YearType yearCreated_) override
    {
        yearCreated = yearCreated_;
    }
    void setAuthor(AuthortType author_) override
    {
        author = author_;
    }

    void info() override
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Year Created: " << yearCreated << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

  private:
    NameType name;
    YearType yearCreated;
    AuthortType author;
};

template <class NameType, class YearType, class AuthortType>
class Go : public ProgrammingLanguage<NameType, YearType, AuthortType>
{
  public:
    Go(NameType n, YearType y, AuthortType a) : name{n}, yearCreated{y}, author{a}
    {
    }
    ~Go() override = default;
    // getter
    NameType getName() override
    {
        return name;
    }
    YearType getYearCreated() override
    {
        return yearCreated;
    }
    AuthortType getAuthor() override
    {
        return author;
    }
    // setter
    void setName(NameType name_) override
    {
        name = name_;
    }
    void setYearCreated(YearType yearCreated_) override
    {
        yearCreated = yearCreated_;
    }
    void setAuthor(AuthortType author_) override
    {
        author = author_;
    }

    void info() override
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Year Created: " << yearCreated << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

  private:
    NameType name;
    YearType yearCreated;
    AuthortType author;
};
int main()
{
    std::shared_ptr<ProgrammingLanguage<std::string, int, std::string>> c89 =
        std::make_shared<C<std::string, int, std::string>>("C89", 1989, "Dennis Ritchie");
    std::shared_ptr<ProgrammingLanguage<std::string, int, std::string>> cPlusPlus85 =
        std::make_shared<CPlusPlus<std::string, int, std::string>>("C++85", 1985, "Bjarne Stroustrup");
    std::shared_ptr<ProgrammingLanguage<std::string, int, std::string>> cPlusPlus20 =
        std::make_shared<CPlusPlus<std::string, int, std::string>>("C++20", 2020, "Bjarne Stroustrup");
    std::shared_ptr<ProgrammingLanguage<std::string, int, std::string>> python =
        std::make_shared<Python<std::string, int, std::string>>("Python3", 2008, "Guido van Rossum");
    std::shared_ptr<ProgrammingLanguage<std::string, int, std::string>> rust =
        std::make_shared<Rust<std::string, int, std::string>>("Rust", 2010, "Graydon Hoare");
    std::shared_ptr<ProgrammingLanguage<std::string, int, std::string>> typescript =
        std::make_shared<Typescript<std::string, int, std::string>>("Typescript", 2012, "Anders Hejlsberg");
    std::shared_ptr<ProgrammingLanguage<std::string, int, std::string>> java =
        std::make_shared<Java<std::string, int, std::string>>("Java", 1995, "James Gosling");
    std::shared_ptr<ProgrammingLanguage<std::string, int, std::string>> cSharp =
        std::make_shared<CSharp<std::string, int, std::string>>("C#", 2000, "Microsoft");
    std::shared_ptr<ProgrammingLanguage<std::string, int, std::string>> go =
        std::make_shared<Go<std::string, int, std::string>>("Go", 2009, "Robert Griesemer");
    ObjectOrientedProgramingLanguage<std::string, int, std::string,
                                     std::vector<std::shared_ptr<ProgrammingLanguage<std::string, int, std::string>>>>
        myoop("My Object Oriented Programming", 2015, "Sou Chanrojame");
    myoop.add(c89);
    myoop.add(cPlusPlus85);
    myoop.add(cPlusPlus20);
    myoop.add(rust);
    myoop.add(python);
    myoop.add(typescript);
    myoop.add(java);
    myoop.add(cSharp);
    myoop.add(go);
    myoop.info();
    return 0;
}