#include <iostream>
#include <fstream>
#include <functional>

#include "UBST.hpp"
#include "treeTraversalCmds.hpp"

int main(int argc, char* argv[])
{
  using namespace skuratov;
  UBST< int, std::string > map;
  try
  {
    if (argc > 1)
    {
      std::ifstream filename(argv[2]);
      if (!filename)
      {
        std::cerr << "Error reading file" << '\n';
        return 1;
      }
      while (!filename.eof())
      {
        filename.clear();
        int keyNum = {};
        std::string value = {};
        while (filename >> keyNum >> value)
        {
          map.insert(keyNum, value);
        }
      }
    }
  }
  catch (...)
  {
    std::cerr << "Not enough arguments" << '\n';
    return 1;
  }

  UBST< std::string, std::function< std::pair< int, std::string >(UBST< int, std::string >&) > > cmds;
  cmds["ascending"] = isAscending;
  cmds["descending"] = isDescending;
  cmds["breadth"] = isBreadth;

  try
  {
    std::string cmd = argv[1];
    std::pair< int, std::string > pair;
    pair = cmds.at(cmd)(map);
    std::cout << pair.first << pair.second << '\n';
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "<INVALID COMMAND>" << '\n';
    return 1;
  }
  catch (const std::overflow_error&)
  {
    std::cerr << "<OVERFLOW>" << '\n';
    return 1;
  }
  catch (const std::logic_error&)
  {
    std::cout << "<EMPTY>" << '\n';
  }
  return 0;
}
