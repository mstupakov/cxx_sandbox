/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <k_misc.h>

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ctype.h>
#include <linux/sched.h>
#include <linux/random.h>

void __k_dumpstack(void) {
  dump_stack();
}

int __k_isalnum(int x) {
  return isalnum(x);
}

int __k_isalpha(int x) {
  return isalpha(x);
}

int __k_isascii(int x) {
  return isascii(x);
}

int __k_iscntrl(int x) {
  return iscntrl(x);
}

int __k_isdigit(int x) {
  return isdigit(x);
}

int __k_isgraph(int x) {
  return isgraph(x);
}

int __k_islower(int x) {
  return islower(x);
}

int __k_isprint(int x) {
  return isprint(x);
}

int __k_ispunct(int x) {
  return ispunct(x);
}

int __k_isspace(int x) {
  return isspace(x);
}

int __k_isupper(int x) {
  return isupper(x);
}

int __k_isxdigit(int x) {
  return isxdigit(x);
}

int __k_tolower(int x) {
  return tolower(x);
}

int __k_taskid_get(void) {
  return current->pid;
}

void __k_get_random_bytes(void *buf, int nbytes) {
  get_random_bytes(buf, nbytes);
}
