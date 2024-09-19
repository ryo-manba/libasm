#include <string.h>
#include <stdio.h>
#include <stdbool.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char* s1, const char *s2);

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

bool test_strcmp(void) {
  const char *s1 = "hello world";
  const char *s2 = "hello world";
  const char *s3 = "HELLO WORLD";

  const int std_res1 = strcmp(s1, s2);
  const int std_res2 = strcmp(s1, s3);
  const int std_res3 = strcmp(s3, s1);

  const int ft_res1 = ft_strcmp(s1, s2);
  const int ft_res2 = ft_strcmp(s1, s3);
  const int ft_res3 = ft_strcmp(s3, s1);

  printf("std_res1: %d, std_res2: %d, std_res3: %d\n", std_res1, std_res2, std_res3);
  printf("ft_res1: %d, ft_res2: %d, ft_res3: %d\n", ft_res1, ft_res2, ft_res3);

  return std_res1 == ft_res1 && std_res2 == ft_res2 && std_res3 == ft_res3;
}

int main(void) {
  const int res = test_strcmp();
  printf("-------------\n result: %d\n", res);
}