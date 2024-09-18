#include <string.h>
#include <stdio.h>
#include <stdbool.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);

bool test_strlen(void) {
  const char *s = "hello world";

  const size_t expected = strlen(s);
  const size_t actual = ft_strlen(s);

  printf("s: %s, expected: %zu, actual: %zu\n", s, expected, actual);
  return expected == actual;
}

bool test_strcpy(void) {
  char std_buf[10];
  char ft_buf[10];
  const char *src = "123456789";

  const char *std_res = strcpy(std_buf, src);
  const char *ft_res = ft_strcpy(ft_buf, src);

  printf("std_res: %s, ft_res: %s\n", std_res, ft_res);
  printf("src: %s, expected: %s, actual: %s\n", src, std_buf, ft_buf);

  return strcmp(std_res, ft_res) == 0 && strcmp(std_buf, ft_buf) == 0;
}

int main(void) {
  test_strcpy();
}