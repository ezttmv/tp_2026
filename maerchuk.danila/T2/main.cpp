#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>
#include "data_struct.hpp"

int main()
{
  using nspace::DataStruct;
  std::vector< DataStruct > data;

  std::copy(
        std::istream_iterator<DataStruct>(std::cin),
        std::istream_iterator<DataStruct>(),
        std::back_inserter(data)
    );

  if (!std::cin.eof() && std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

  // Сортировка [cite: 6, 10]
  std::sort(data.begin(), data.end());

  if (!data.empty())
  {
    std::copy(
      data.begin(),
      data.end(),
      std::ostream_iterator< DataStruct >(std::cout, "\n")
    );
  }

  return 0;
}
