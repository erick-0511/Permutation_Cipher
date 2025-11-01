# PERMUTATION CIPHER

## Description
C++ program that implements permutation cipher. The permutation cipher replace one element of the original message with another.

To encrypt, a permutation permutation is used:

<div align="center">P: x -> x</div>

To decrypt, a permutation is used:

<div align="center">P<sup>-1</sup>: x -> x</div>

Where:
- The permutation takes a value from P and changes it to another value of P

## Characteristics
- Read a file text (message) without extension (It's assumed to be .txt)
- Read a permutation (for example: 4 5 2 1 3)
- If the message size and the permutation aren't multiples, padding is used
- The ciphertext is saved in a text file

## Compilation
g++ PermutationCipher.cpp -o PermutationCipher