#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char* s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, const void *buf, size_t nbyte);

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


int main(void) {
  test_read();
}