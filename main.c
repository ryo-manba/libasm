#include <string.h>
#include <stdio.h>

size_t ft_strlen(const char *s);

int main(void) {
  const char *s = "hello world";

  const size_t expected = strlen(s);
  const size_t actual = ft_strlen(s);

  printf("s: %s, expected: %zu, actual: %zu\n", s, expected, actual);
}