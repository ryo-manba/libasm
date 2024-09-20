#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char* s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, const void *buf, size_t nbyte);
char *ft_strdup(const char *s1);

void check(const bool f) {
  const char *msg = f? "[PASS]" : "[FAIL]";
  printf("%s\n", msg);
}

bool run_strlen(const char *s) {
  return strlen(s) == ft_strlen(s);
}

void test_strlen(void) {
  puts("--- [ft_strlen] ---");
  check(run_strlen(""));
  check(run_strlen("a"));
  check(run_strlen("Hello, World!"));
  check(run_strlen("あいうえお"));
  check(run_strlen("42東京"));
  check(run_strlen("01234567890"));
  check(run_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit."));
}

bool run_strcpy(const char *s) {
  char std_buf[1024];
  char ft_buf[1024];

  const char *std_res = strcpy(std_buf, s);
  const char *ft_res = ft_strcpy(ft_buf, s);
  return strcmp(std_res, ft_res) == 0 && strcmp(std_buf, ft_buf) == 0;
}

void test_strcpy(void) {
  puts("--- [ft_strcpy] ---");
  check(run_strcpy(""));
  check(run_strcpy("a"));
  check(run_strcpy("Hello, World!"));
  check(run_strcpy("あいうえお"));
  check(run_strcpy("42東京"));
  check(run_strcpy("01234567890"));
  check(run_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit."));
}

bool run_strcmp(const char *s1, const char *s2) {
  const int std_res = strcmp(s1, s2);
  const int ft_res = ft_strcmp(s1, s2);
  return std_res == ft_res;
}

void test_strcmp(void) {
  puts("--- [ft_strcmp] ---");
  check(run_strcmp("Hello World", "Hello World"));
  check(run_strcmp("Hello World", "Hello Worl"));
  check(run_strcmp("Hello Worl", "Hello World"));
  check(run_strcmp("hello world", "Hello World"));
  check(run_strcmp("", ""));
  check(run_strcmp("a", ""));
  check(run_strcmp("", "a"));
  check(run_strcmp("あいうえお", "あいうえお"));
  check(run_strcmp("あいうえお", "あいうえ"));
  check(run_strcmp("あいうえ", "あいうえお"));
}

void test_write(void) {
  const char *s1 = "hello";
  const char *s2 = "world";

  const ssize_t std_res1 = write(1, s1, strlen(s1));
  const ssize_t std_res2 = write(2, s2, strlen(s2));
  const ssize_t std_res3 = write(1, "\n", 1);

  const ssize_t ft_res1 = ft_write(1, s1, strlen(s1));
  const ssize_t ft_res2 = ft_write(2, s2, strlen(s2));
  const ssize_t ft_res3 = ft_write(1, "\n", 1);

  // error case
  printf("1. errno: %d\n", errno);
  const ssize_t std_res4 = write(4242, s1, strlen(s1));
  printf("2. errno: %d\n", errno);
  errno = 0;
  printf("3. errno: %d\n", errno);
  const ssize_t ft_res4 = ft_write(4242, s1, strlen(s1));
  printf("4. errno: %d\n", errno);

  printf("std_res1: %zd, std_res2: %zd, std_res3: %zd, std_res4: %zd\n", std_res1, std_res2, std_res3, std_res4);
  printf("ft_res1: %zd, ft_res2: %zd, ft_res3: %zd, ft_res4: %zd\n", ft_res1, ft_res2, ft_res3, ft_res4);
}

void test_read(void) {
  char std_buf[1024];
  char ft_buf[1024];
  memset(std_buf, '\0', sizeof(std_buf));
  // memset(ft_buf, '\0', sizeof(ft_buf));

  const int fd1 = open("./testfiles/hello1.txt", O_RDONLY);
  const int fd2 = open("./testfiles/hello2.txt", O_RDONLY);
  if (fd1 < 0 || fd2 < 0) {
    printf("failed to open");
    return;
  }
  int std_res;
  int ft_res;
  int i = 0;
  while (i++ < 3) {
    std_res = read(fd1, std_buf, 10);
    ft_res = ft_read(fd2, ft_buf, 10);
    printf("std_res: %d, buf: %s\n", std_res, std_buf);
    printf("ft_res : %d, buf: %s\n", ft_res, ft_buf);
  }

  // error case
  printf("1.errno: %d\n", errno);
  std_res = read(42, std_buf, 10);
  printf("2.errno: %d\n", errno);
  errno = 0;
  printf("3.errno: %d\n", errno);
  ft_res = ft_read(42, ft_buf, 10);
  printf("4.errno: %d\n", errno);

  printf("std_res: %d, buf: %s\n", std_res, std_buf);
  printf("ft_res : %d, buf: %s\n", ft_res, ft_buf);
}

void test_strdup(void) {
  const char *s = "hello world";

  {
    char *std_buf = strdup(s);
    char *ft_buf = ft_strdup(s);
    printf("std_buf: %s\n", std_buf);
    printf("ft_buf : %s\n", ft_buf);
    free(std_buf);
    free(ft_buf);

  }
  {
    char *std_buf = strdup("hello world");
    char *ft_buf = ft_strdup(s);
    printf("std_buf: %s\n", std_buf);
    printf("ft_buf : %s\n", ft_buf);
    free(std_buf);
    free(ft_buf);
  }
}

int main(void) {
  test_strlen();
  test_strcpy();
  test_strcmp();
}