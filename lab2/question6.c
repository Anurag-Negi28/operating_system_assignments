#include <stdio.h>
#include<stdio.h>

int main() {
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

  if (number % 2 == 0) {
    printf("The number is even.\n");
  } else {
    printf("The number is odd.\n");
  }

  for (int i = 1; i <= number; i++) {
    printf("%d ", i);
  }
  printf("\n");

  int counter = 0;
  while (counter < number) {
    printf("Hello, world!\n");
    counter++;
  }

  return 0;
}

