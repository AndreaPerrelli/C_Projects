# Documentation for Fibonacci Series Program

## Introduction

This program prints the first 12 terms of the Fibonacci series using iteration. The Fibonacci series is a sequence of numbers where each term is the sum of the two previous terms, starting with 0 and 1. This program uses an optimized implementation that calculates each term in the series using a simple formula and iterates over the remaining terms to generate the series.

## Algorithm

The algorithm used in this program is based on the formula for calculating the nth term of the Fibonacci series, which is given by the following equation:

f(n) = f(n-1) + f(n-2)

where f(n) is the nth term of the series, f(n-1) is the previous term, and f(n-2) is the term before that. This formula can be used to calculate each term in the series by starting with the first two terms (0 and 1) and then iterating over the remaining terms to generate the series.

To implement this algorithm in the program, we first initialize two variables `a` and `b` to 0 and 1, respectively, which represent the first two terms of the series. Then we print these two terms to the console.

Next, we use a `for` loop to iterate over the remaining terms of the series. Inside the loop, we calculate the next term in the series using the formula above, and then print the result to the console. We also shift the values of `a` and `b` so that the previous terms are preserved and can be used to calculate the next term in the series.

## Advantages and Disadvantages

| Advantages                                    | Disadvantages                                |
|-----------------------------------------------|----------------------------------------------|
| Simple and easy to understand                  | Limited to printing the first 12 terms of the series |
| Uses a simple and optimized formula for calculation | Does not allow for flexible input or customization |
| Generates the series quickly and efficiently   | Not suitable for finding specific terms of the series |

