#include <new>
#include <vector>
#include <string>
#include <stdio.h>

extern "C" {

int cpp_module_init(void)
{
  printf( "Enter: %s\n", __PRETTY_FUNCTION__);

  {
    int *my_int = new int(777);
    printf( "My int: %d\n", *my_int);
  }

  printf("aaa %s, 12121 %u\n wwwww 0x%x\n", "hahaha", 15, 3424);

  {
    std::string my_string_1("Hello World");
    my_string_1.c_str();

    std::string my_string_2 = my_string_1;
  }

  return 0;
}

void cpp_module_deinit(void)
{
  printf( "Enter: %s\n", __PRETTY_FUNCTION__);
}

} /* extern "C" */
