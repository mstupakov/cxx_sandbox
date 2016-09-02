/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

/* If you don't like how some STD function works, here is you can override it with your implementation. 
 * Also, here is you can implement any requred STD functions. The folder could be a link to some folder inside your application. */

/* Exemple of an extension. 
 * The following example overrides framework's printf() function. Please uncomment and recompile the code. 
 * To see the output, the "dmesg" command should be used. 
 * */

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <k_io.h>

int printf(const char *format, ...) {
  int n = 0;
  void* p = 0;
  char* str = "~~~ EXTENSION: ";

  va_list args;
  va_start(args, format);

  p = malloc(strlen(format) + strlen(str) + 1);
  if (p) {
    sprintf(p, "%s %s", str, format);
    n = __k_vprintf(p, args);
    free(p);
  } else {
    n = __k_vprintf(format, args);
  }

  va_end(args);
  return n;  
}
*/

