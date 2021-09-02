#include "isocline.c"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

//------------------------------------------------------------------------------

void *null_ptr() { return (((void *)0)); }

bool is_null_ptr(void *p) { return (p == NULL ? true : false); }

char *ptr_string_to_string(void *str) {
  assert(str != NULL);
  return ((char *)str);
}

void *string_to_ptr_string(const char *str) {
  assert(str != NULL);
  return (void *)str;
}

//------------------------------------------------------------------------------

ic_completion_env_t *mk_ic_completion_env() {
  ic_completion_env_t *p =
      (ic_completion_env_t *)malloc(sizeof(ic_completion_env_t));
  assert(p != NULL);
  return p;
}

void rm_ic_completion_env(ic_completion_env_t *ic_completion_env) {
  assert(ic_completion_env != NULL);
  free(ic_completion_env);
}
