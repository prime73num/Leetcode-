


#include <iostream>
#include <vector>


int main (int argc, char *argv[])
{
  std::string s("hello");
  std::cout << s << std::endl;
  std::string test(s, 0,2);
  std::cout << test << std::endl;
  return 0;
}
