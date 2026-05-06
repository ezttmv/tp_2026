#include "data_struct.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

int main()
{
  using nspace::DataStruct;
  std::vector< DataStruct > data;

  while (!std::cin.eof())
  {
    DataStruct temp;
    if (std::cin >> temp)
    {
      data.push_back(temp);
    }
    else
    {
      if (std::cin.eof()) break;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  std::sort(data.begin(), data.end());

  std::cout << "DataStruct:\n";
  std::copy(
    std::begin(data),
    std::end(data),
    std::ostream_iterator< DataStruct >(std::cout, "\n")
  );

  return 0;
}
