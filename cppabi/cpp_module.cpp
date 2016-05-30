//#include <new>
//#include <vector>
//#include <string>
//#include <list>
#include <stdio.h>
//#include <ustl.h>


extern void (*__init_array_start []) (int, char **, char **);
extern void (*__init_array_end []) (int, char **, char **);
extern void (*__fini_array_start []) (void);
extern void (*__fini_array_end []) (void);

int _start  = 7;

#define KERN_INFO "\0016! "
extern "C" int printk(const char* fmt, ...);

void test_cpp(void);
void stl_cpp(void);


//std::vector<int> my_vec_1;
//static std::vector<int> my_vec_2;
int my_a = 9;

class B {
public:
  B(){volatile int i = 7;

  printk("File: %s, func: %s, line: %u, i: %d, my_a: %d\r\n", __FILE__, __PRETTY_FUNCTION__, __LINE__, i, my_a);
}

 ~B() {
  printk("File: %s, func: %s, line: %u\r\n", __FILE__, __PRETTY_FUNCTION__, __LINE__);
 }
};

B bbb;



class A {
public:
  static int i;

  int x;
  A() { x= i++; printk("File: %s, func: %s, line: %u, i: %d\r\n", __FILE__, __PRETTY_FUNCTION__, __LINE__, x); }
 ~A() { printk("File: %s, func: %s, line: %u, i: %d\r\n", __FILE__, __PRETTY_FUNCTION__, __LINE__, x); }
};

int A::i = 1;

A a_1;
A a_2;

A a_arr[5];


static A aaaa[7];


//std::list<int> my_list;



void my_func() {
  static A aaaa[3];

}



extern "C" {


int cpp_module_init(void *param)
{
  my_func();
  my_func();
  printk("Hello World! %d\r\n",__init_array_end - __init_array_start);

  static A a_7;

  for (size_t i = 0; i < __init_array_end - __init_array_start; i++) {
    __init_array_start[i](0, 0, 0);
  }


  test_cpp();
//  stl_cpp();
  return 0;
}

int cpp_module_deinit(void *param)
{
  size_t i = __fini_array_end - __fini_array_start;

  while (i--) {
    __fini_array_start[i]();
  }
}

} /* extern "C" */
