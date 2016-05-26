int __cxa_guard_acquire(void*);
void __cxa_guard_release (void*);
void __cxa_guard_abort (void*);
void __cxa_pure_virtual(void);
int __cxa_atexit(void (*func) (void *), void * arg, void * dso_handle);
int __aeabi_atexit (void *obj, void (*func) (void *), void *d);

void *__dso_handle;

int __cxa_guard_acquire(void* p) {return 0;}
void __cxa_guard_release (void* p) {}
void __cxa_guard_abort (void* p) {}
void __cxa_pure_virtual(void) {}
int __cxa_atexit(void (*func) (void *), void * arg, void * dso_handle) {return 0;}
int __aeabi_atexit (void *obj, void (*func) (void *), void *d) {return 0;}
