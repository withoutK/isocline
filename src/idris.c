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

ic_highlight_env_t *mk_ic_highlight_env() {
  ic_highlight_env_t *p =
      (ic_highlight_env_t *)malloc(sizeof(ic_highlight_env_t));
  assert(p != NULL);
  return p;
}

void rm_ic_highlight_env(ic_highlight_env_t *ic_highlight_env) {
  assert(ic_highlight_env != NULL);
  free(ic_highlight_env);
}

//------------------------------------------------------------------------------

char *idr_ic_readline_ex_00(const char *prompt_text, void *completer_arg,
                            void *highlighter_arg) {
  return ic_readline_ex(prompt_text, NULL, completer_arg, NULL,
                        highlighter_arg);
}

char *idr_ic_readline_ex_01(const char *prompt_text, void *completer_arg,
                            ic_highlight_fun_t *highlighter,
                            void *highlighter_arg) {
  return ic_readline_ex(prompt_text, NULL, completer_arg, highlighter,
                        highlighter_arg);
}

char *idr_ic_readline_ex_10(const char *prompt_text,
                            ic_completer_fun_t *completer, void *completer_arg,
                            void *highlighter_arg) {
  return ic_readline_ex(prompt_text, completer, completer_arg, NULL,
                        highlighter_arg);
}

char *idr_ic_readline_ex_11(const char *prompt_text,
                            ic_completer_fun_t *completer, void *completer_arg,
                            ic_highlight_fun_t *highlighter,
                            void *highlighter_arg) {
  return ic_readline_ex(prompt_text, completer, completer_arg, highlighter,
                        highlighter_arg);
}
