#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dst, const char *src);
extern int ft_strcmp(const char* s1, const char *s2);
extern ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
extern ssize_t ft_read(int fildes, const void *buf, size_t nbyte);
extern char *ft_strdup(const char *s1);

void print_result(const bool f) {
  if (f) {
    puts("[PASS]");
  } else {
    puts("[FAIL]");
  }
}

bool run_strlen(const char *s) {
  return strlen(s) == ft_strlen(s);
}

void test_strlen(void) {
  puts("--- [ft_strlen] ---");
  print_result(run_strlen(""));
  print_result(run_strlen("a"));
  print_result(run_strlen("Hello, World!"));
  print_result(run_strlen("あいうえお"));
  print_result(run_strlen("42東京"));
  print_result(run_strlen("01234567890"));
  print_result(run_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit."));
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
  print_result(run_strcpy(""));
  print_result(run_strcpy("a"));
  print_result(run_strcpy("Hello, World!"));
  print_result(run_strcpy("あいうえお"));
  print_result(run_strcpy("42東京"));
  print_result(run_strcpy("01234567890"));
  print_result(run_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit."));
}

bool run_strcmp(const char *s1, const char *s2) {
  const int std_res = strcmp(s1, s2);
  const int ft_res = ft_strcmp(s1, s2);
  return std_res == ft_res;
}

void test_strcmp(void) {
  puts("--- [ft_strcmp] ---");
  print_result(run_strcmp("Hello World", "Hello World"));
  print_result(run_strcmp("Hello World", "Hello Worl"));
  print_result(run_strcmp("Hello Worl", "Hello World"));
  print_result(run_strcmp("hello world", "Hello World"));
  print_result(run_strcmp("", ""));
  print_result(run_strcmp("a", ""));
  print_result(run_strcmp("", "a"));
  print_result(run_strcmp("あいうえお", "あいうえお"));
  print_result(run_strcmp("あいうえお", "あいうえ"));
  print_result(run_strcmp("あいうえ", "あいうえお"));
}

void test_write(void) {
  puts("--- [ft_write] ---");

  const char *s1 = "hello ";
  const char *s2 = "world\n";

  ssize_t std_res1 = write(1, s1, strlen(s1));
  ssize_t std_res2 = write(2, s2, strlen(s2));
  ssize_t ft_res1 = ft_write(1, s1, strlen(s1));
  ssize_t ft_res2 = ft_write(2, s2, strlen(s2));

  printf("std_res1: %zd, ft_res1: %zd\n", std_res1, ft_res1);
  printf("std_res2: %zd, ft_res2: %zd\n", std_res2, ft_res2);

  // error cases
  errno = 0;
  printf("errno before:    %d\n", errno);
  ssize_t std_res_err = write(4242, s1, strlen(s1));
  printf("errno after std: %d\n", errno);

  errno = 0;
  printf("errno before:    %d\n", errno);
  ssize_t ft_res_err = ft_write(4242, s1, strlen(s1));
  printf("errno after ft:  %d\n", errno);

  printf("std_res_err: %zd, ft_res_err: %zd\n", std_res_err, ft_res_err);
}

void test_read(void) {
  puts("--- [ft_read] ---");

  const int BUFSIZE = 1024;
  char std_buf[BUFSIZE];
  char ft_buf[BUFSIZE];
  memset(std_buf, '\0', BUFSIZE);
  memset(ft_buf, '\0', BUFSIZE);

  const int fd1 = open("./testfiles/hello1.txt", O_RDONLY);
  const int fd2 = open("./testfiles/hello2.txt", O_RDONLY);
  if (fd1 < 0 || fd2 < 0) {
    printf("failed to open");
    return;
  }

  const int READ_SIZE = 10;
  int std_res;
  int ft_res;
  int i = 0;
  while (i++ < 3) {
    std_res = read(fd1, std_buf, READ_SIZE);
    ft_res = ft_read(fd2, ft_buf, READ_SIZE);
    printf("std_res: %d, buf: %s\n", std_res, std_buf);
    printf("ft_res : %d, buf: %s\n", ft_res, ft_buf);
  }

  // error cases
  errno = 0;
  printf("errno before:    %d\n", errno);
  std_res = read(42, std_buf, 10);
  printf("errno after std: %d\n", errno);
  errno = 0;
  printf("errno before:    %d\n", errno);
  ft_res = ft_read(42, ft_buf, 10);
  printf("errno after ft:  %d\n", errno);

  printf("std_res: %d, buf: %s\n", std_res, std_buf);
  printf("ft_res : %d, buf: %s\n", ft_res, ft_buf);
}

void test_strdup(void) {
  puts("--- [ft_strdup] ---");

  const char *s = "hello world";

  {
    char *std_buf = strdup(s);
    char *ft_buf = ft_strdup(s);
    print_result(strcmp(std_buf, ft_buf) == 0);
    free(std_buf);
    free(ft_buf);
  }
  {
    char *std_buf = strdup("hello world");
    char *ft_buf = ft_strdup("hello world");
    print_result(strcmp(std_buf, ft_buf) == 0);
    free(std_buf);
    free(ft_buf);
  }
  {
    char *std_buf = strdup("あいうえお");
    char *ft_buf = ft_strdup("あいうえお");
    print_result(strcmp(std_buf, ft_buf) == 0);
    free(std_buf);
    free(ft_buf);
  }
  {
    char *std_buf = strdup("");
    char *ft_buf = ft_strdup("");
    print_result(strcmp(std_buf, ft_buf) == 0);
    free(std_buf);
    free(ft_buf);
  }
}

int main(void) {
  test_strlen();
  test_strcpy();
  test_strcmp();
  test_write();
  test_read();
  test_strdup();
}