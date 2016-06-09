#include <stdio.h>
#include <ustl.h>

namespace std {
using namespace ustl;
}

using namespace ustl;

void test_cpp(void);

class A {
public:
    A() {printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);}
   ~A() {printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);}

  void m1() {printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);}
};


void my_func() {


   char* arr;
    arr = (char*)malloc(450);
    vector<vector<int> > m;
    vector<int> a;
    printf("a1\n");
    printf("size - %d\n", m.size());
    printf("a2\n");
    m.resize(1);
    //m.push_back(a);
    printf("a3\n");
    m[0].resize(2);
    //m.resize(1);
    //m[0].resize(1);
    printf("a4\n");
    m.resize(2);
    printf("a5\n");

    free(arr);
  




  std::vector<A> my_vec;
  std::bitset<10> my_bitset;
  std::string my_str("Hello World!!!!!");
  std::map<int,ustl::string> my_map;

  my_map[5] = "Hello!";

  printf("Str: %s, %s\r\n", my_str.c_str(), my_map[5].c_str());

  std::cout << "Func: " << __PRETTY_FUNCTION__ << "    " << my_map[5] << ustl::endl;
  std::cout << "-=-=-=-=-=-=-=-= Hi, All!!!! =-=-=-=-=-=-=-=-" << ustl::endl;


  std::vector<std::vector<int> > my_vec2;

  my_vec2.resize(1);
  my_vec2[0].resize(7);

  my_vec2[0][0] = 5;

  //std::cout << "Str: " << my_map[5] << "Int: " << sizeof(my_vec) << ustl::endl;
  std::cout << "Value: " << 777 << ustl::endl;
}

void test_cpp(void) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);


  A* p = new A();

  p->m1();



  my_func();
}
