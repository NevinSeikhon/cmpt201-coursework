#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 128

struct header {
  uint64_t size;
  struct header *next;
};
void handle_error(char *error_mes) {
  write(STDERR_FILENO, error_mes, strlen(error_mes));
  exit(1);
}

void print_out(char *format, void *data, size_t data_size) {
  char buf[BUF_SIZE];
  ssize_t len = snprintf(buf, BUF_SIZE, format,
                         data_size == sizeof(uint64_t) ? *(uint64_t *)data
                                                       : *(void **)data);
  if (len < 0) {
    handle_error("snprintf");
  }
  write(STDOUT_FILENO, buf, len);
}

int main() {
  void *block = sbrk(256);
  struct header *first = (struct header *)block;

  first->size = 128;
  first->next = NULL;

  print_out("first block:        %p\n", first, sizeof(first));
  print_out("first block size    %lu\n", &first->size, sizeof(first->size));
  print_out("first block next:   %p\n", &first->next, sizeof(first->next));
}
