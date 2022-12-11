#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

// Define a constant for the maximum number of prime numbers to find
#define MAX_PRIMES 1000000

// Define a constant for the size of the wheel
#define WHEEL_SIZE 100

// Define an array of offsets for the wheel
const int wheel_offsets[WHEEL_SIZE] = {1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59, 61, 67, 71, 73, 79, 83, 89, 91, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 169, 173, 179, 181,
                                       191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
                                       419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 529};

// Define an array of moduli for the modulo wheel
const int moduli[3] = {2, 3, 5};

// Define a constant for the block size
#define BLOCK_SIZE 10000

int main() {
  // Prompt the user to enter a number
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  // Initialize an array of prime numbers
  int primes[MAX_PRIMES];
  int num_primes = 0;

  // Use the Sieve of Eratosthenes to find all prime numbers up to sqrt(n)
  int limit = (int) sqrt(n);
  bool is_prime[limit + 1];
  for (int i = 2; i <= limit; i++) {
    is_prime[i] = true;
  }
  for (int i = 2; i <= limit; i++) {
    if (is_prime[i]) {
      primes[num_primes++] = i;
      // Mark all multiples of i as non-prime
      for (int j = i * i; j <= limit; j += i) {
        is_prime[j] = false;
      }
    }
  }

  // Use the Segmented Sieve of Eratosthenes to find all prime numbers in the range [sqrt(n), n]
  int low = limit;
  int high = limit * 2;
  while (low < n) {
    // Initialize an array to represent the sieve for the current block
    int sieve_size = (high - low) / BLOCK_SIZE + 1;
    uint64_t is_prime[sieve_size][BLOCK_SIZE / 64 + 1];
    for (int i = 0; i < sieve_size; i++) {
        for (int j = 0; j <= BLOCK_SIZE / 64; j++) {
        is_prime[i][j] = 0;
        }
    }
    // Use wheel factorization to skip non-prime numbers
    for (int i = 0; i < WHEEL_SIZE; i++) {
  // Skip non-prime numbers
        int current = wheel_offsets[i];
        while (current < BLOCK_SIZE) {
            int block = (current - low) / BLOCK_SIZE;
            int index = (current - low) % BLOCK_SIZE;
            is_prime[block][index / 64] &= ~(1ull << (index % 64));
            current += wheel_offsets[i];
        }
    }

// Use modulo wheel to skip more non-prime numbers
    for (int i = 0; i < 3; i++) {
        int current = moduli[i] - low % moduli[i];
        while (current < BLOCK_SIZE) {
            int block = (current - low) / BLOCK_SIZE;
            int index = (current - low) % BLOCK_SIZE;
            is_prime[block][index / 64] &= ~(1ull << (index % 64));
            current += moduli[i];
         }
    }

// Mark all multiples of known primes as non-prime
    for (int i = 0; i < num_primes; i++) {
        int lo_lim = (low / primes[i]) * primes[i];
        if (lo_lim < low) {
            lo_lim += primes[i];
        }
    for (int j = lo_lim; j <= high; j += primes[i]) {
        int block = (j - low) / BLOCK_SIZE;
        int index = (j - low) % BLOCK_SIZE;
        is_prime[block[index / 64] &= ~(1ull << (index % 64));
    }
  }
  
// Output all prime numbers in the current range
for (int i = 0; i < sieve_size; i++) {
  for (int j = 0; j <= BLOCK_SIZE / 64; j++) {
    for (int k = 0; k < 64; k++) {
      if (!(is_prime[i][j] & (1ull << k))) {
        int num = i * BLOCK_SIZE + j * 64 + k + low;
        if (num > limit) {
          printf("%d is a prime number.\n", num);
        }
      }
    }
  }
}

// Move to the next range
low += limit;
high += limit;
  