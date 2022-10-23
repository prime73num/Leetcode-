







#include <iostream>
#include <vector>
#include <list>

using namespace std;


void print(list<int>& test){
  for (auto& i: test) {
    printf("%d ", i);
  }
  printf("\n");
}

int main (int argc, char *argv[])
{
  list<int> test;
  test.push_back(2);
  test.push_back(4);
  test.push_back(9);
  test.push_back(0);

  auto it = test.begin();

  print(test);
  auto next = test.erase(it);
  it = test.insert(next, *it);
  print(test);

  print(test);
  next = test.erase(it);
  it = test.insert(next, *it);
  it++;
  print(test);

  print(test);
  next = test.erase(it);
  it = test.insert(next, *it);
  it++;
  print(test);

  print(test);
  next = test.erase(it);
  it = test.insert(next, *it);
  it++;
  print(test);
 
  it = test.end();
  print(test);
  it = test.insert(it, 2);
  print(test);

  return 0;
}

