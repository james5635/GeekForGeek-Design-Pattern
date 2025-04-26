#include <bits/stdc++.h>

class SoringStrategy
{
  public:
    virtual void sort(std::vector<int> &arr) = 0;
    virtual ~SoringStrategy() = default;
};
class BubbleSort : public SoringStrategy
{
  public:
    void sort(std::vector<int> &arr) override
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};
class QuickSort : public SoringStrategy
{
  public:
    void sort(std::vector<int> &arr) override
    {
        std::sort(arr.begin(), arr.end());
    }
};
class MergeSort : public SoringStrategy
{
  public:
    void sort(std::vector<int> &arr) override
    {
        std::stable_sort(arr.begin(), arr.end());
    }
};
class SortContext
{
  private:
    SoringStrategy *strategy;

  public:
    void setStrategy(SoringStrategy *newStrategy)
    {
        strategy = newStrategy;
    }
    void sort(std::vector<int> &arr)
    {
        strategy->sort(arr);
    }
};
int main()
{
    SortContext context;
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};

    context.setStrategy(new BubbleSort());
    context.sort(arr);
    std::cout << "Bubble Sort: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    arr = {5, 2, 9, 1, 5, 6}; // Reset array
    context.setStrategy(new QuickSort());
    context.sort(arr);
    std::cout << "Quick Sort: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    arr = {5, 2, 9, 1, 5, 6}; // Reset array
    context.setStrategy(new MergeSort());
    context.sort(arr);
    std::cout << "Merge Sort: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}