#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

using namespace boost::interprocess;

int main()
{
  shared_memory_object shdmem{open_only, "Boost", read_only};
  mapped_region region2{shdmem, read_only};
  while (true){
    int *i2 = static_cast<int*>(region2.get_address());
    std::cout << "reading " << *i2 << '\n';
  }
}
