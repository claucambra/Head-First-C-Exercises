#include <stdio.h>

int main() {
  char first_name[20];
  char last_name[20];
  printf("Enter first name and last name:\n");
  scanf("%19s %19s", first_name, last_name);
  printf("First: %s\t Last:%s\n", first_name, last_name);
}
