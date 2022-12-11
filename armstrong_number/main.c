#include stdio.h
#include math.h

int main() {
   Prompt the user to enter a number
  int n;
  printf(Enter a number );
  scanf(%d, &n);

   Calculate the number of digits in the number
  int num_digits = log10(n) + 1;

   Initialize a variable to store the sum of the digits
  int sum = 0;

   Loop through each digit of the number and add it to the sum
  int temp = n;
  for (int i = 0; i  num_digits; i++) {
    int digit = temp % 10;
    sum += pow(digit, num_digits);
    temp = 10;
  }

   Check if the sum is equal to the original number
  if (sum == n) {
    printf(%d is an Armstrong number.n, n);
  } else {
    printf(%d is not an Armstrong number.n, n);
  }

  return 0;
}
