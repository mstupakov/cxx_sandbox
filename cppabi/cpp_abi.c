void* __dso_handle;

int __cxa_guard_acquire(void* p) {
  return 0;
}

void __cxa_guard_release(void* p) {
}

void __cxa_guard_abort(void* p) {
}

void __cxa_pure_virtual(void) {
}

int __cxa_atexit(void (*func) (void*), void* arg, void* dso_handle) {
  return 0;
}

int __aeabi_atexit(void *obj, void (*func) (void*), void* d) {
  return 0;
}


#define KERN_INFO "\0016! "
int printk(const char* fmt, ...);


int atexit(void (*function)(void)) {
  printk("File: %s, func: %s, line: %u, %p\r\n", __FILE__, __PRETTY_FUNCTION__, __LINE__, function);
  return 0;
}
