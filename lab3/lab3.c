#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() {
  char *input = NULL;
  char *arr[MAX];
  size_t len = 0;
  int i = 0;
  while (1) {
    printf("Enter input: ");
    ssize_t line = getline(&input, &len, stdin);
    arr[i] = strdup(input);
    i++;

    if (strcmp(input, "print\n") == 0) {
      int k = 0;
      int l = i;
      if (l > 5) {
        k = l - 5;
        l = 5;
      }
      for (int r = k; r < k + l; r++) {
        printf("%s", arr[r]);
      }
    }
  }
  for (int h = 0; h < i; h++) {
    free(arr[h]);
  }
  free(input);
  free(arr);
  return 0;
}
