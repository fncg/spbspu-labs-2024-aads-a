#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <limits>
#include <list>

template < typename T >
class Queue
{
public:
  void push(T rhs);
  T drop();
private:
};

template < typename T >
class Stack
{
public:
  Stack()
  {
    stack_list();
  }
  ~Stack() = default;
  bool empty() const
  {
    return stack_list.empty();
  }
  size_t size() const
  {
    return stack_list.size();
  }
  T & top()
  {
    return stack_list.back();
  }
  const T & top() const
  {
    return stack_list.back();
  }
  void push(const T & rhs)
  {
    stack_list.push_back(rhs);
  }
  void pop()
  {
    stack_list.pop_back();
  }
private:
  std::list<T> stack_list;
};

int main(int argc, char ** argv)
{
  std::vector<int> ints;
  if (argc == 1)
  {
    std::copy(
        std::istream_iterator<int>{std::cin},
        std::istream_iterator<int>{},
        std::back_inserter(ints)
      );
      if (!std::cin && !std::cin.eof())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
  }
  else if (argc == 2)
  {
    std::ifstream input(argv[1]);
    while (!input.eof())
    {
      std::copy(
        std::istream_iterator<int>{input},
        std::istream_iterator<int>{},
        std::back_inserter(ints)
      );
      if (!input && !input.eof())
      {
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }
  }
  for (auto i = ints.begin(); i != ints.end(); ++i)
  {
    std::cout << *i << '\n';
  }
}
