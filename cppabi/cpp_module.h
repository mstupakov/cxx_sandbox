#ifndef __CPP_MODULE_H__
#define __CPP_MODULE_H__

#ifdef __cplusplus
extern "C" {
#endif

extern int cpp_module_init(void *param);
extern int cpp_module_deinit(void *param);

#ifdef __cplusplus
}
#endif

#endif /* __CPP_MODULE_H__ */
