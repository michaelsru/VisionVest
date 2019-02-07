#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

using namespace boost::interprocess;

int main()
{
  shared_memory_object shdmem{open_or_create, "Boost", read_write};
  shdmem.truncate(1024);
  mapped_region region{shdmem, read_write};
  int i = 0;
  while (true) {
    char* res_string = "hello world";
    std::strcpy(static_cast<char* >(region.get_address()), res_string);
    //~ *i1 = i;
    //~ std::cout << "writing " << *i1 << '\n';
    //~ i += 1;
    //~ if (i==100){
      //~ i = 0;
    //~ }
  }
}
