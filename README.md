<p align="center">
  <img alt="BigInt" src="logo.png">
</p>
<h3 align="center">Big Integer class for Cpp</h3>

---
#### BigInteger class is used for mathematical operation which involves very big integer calculations that are outside the limit of all available primitive data types.
---

:construction: Work in progress :construction:

### Contents

* [Usage](#usage)
* [Features](#features)

## Usage

1. Download the bigInt.cpp file to a location under
    your include path. Then `#include` it in your code:
    ```c++
    #include "BigInt.cpp"   // the actual path may vary
    ```

1. Create objects of the `BigInt` class, and do what you got to do!
    ```c++
    bigInt big1 = 1234567890, big2;
    big2 = "9876543210123456789098765432101234567890";

    std::cout << big1 * big2 * 123456 << "\n";
    // Output: 1505331490682966620443288524512589666204282352096057600
    ```

## Features

### Operators

* #### Assignment: `=`
  The second operand can either be a `bigInt`, an integer (up to `long long`)
  or a string (`std::string` or a string literal).
  ```c++
  big1 = 1234567890;
  big1 = "123456789012345678901234567890";
  big1 = big2;
  ```

* #### Unary arithmetic: `+`, `-`
  ```c++
  big1 = +big2;   // doesn't return the absolute value
  big1 = -big2;
  ```

* #### Binary arithmetic: `+`, `-`, `*`, `/`, `%`
  One of the operands has to be a `bigInt` and the other can be a `bigInt`, an
  integer (up to `long long`) or a string (`std::string` or a string literal).
  ```c++
  big1 = big2 + 1234567890;
  big1 = big2 - "123456789012345678901234567890";
  big1 = big2 * big3;
  big1 = 1234567890 / big2;
  big1 = "123456789012345678901234567890" % big2;
  ```

* #### Arithmetic-assignment: `+=`, `-=`, `*=`, `/=`, `%=`
  The second operand can either be a `bigInt`, an integer (up to `long long`)
  or a string (`std::string` or a string literal).
  ```c++
  big1 += big2;
  big1 -= 1234567890;
  big1 *= "123456789012345678901234567890";
  big1 /= big2;
  big1 %= 1234567890;
  ```

* #### Increment and decrement: `++`, `--`
  Increment and Decrement can be done as it is done with general integer types of variables.
  ```c++
  big1 = ++big2;   // pre-increment
  big1 = --big2;   // pre-decrement

  big1 = big2++;   // post-increment
  big1 = big2--;   // post-decrement
  ```

* #### Relational: `<`, `>`, `<=`, `>=`, `==`, `!=`
  One of the operands has to be a `bigInt` and the other can be a `bigInt`, an
  integer (up to `long long`) or a string (`std::string` or a string literal).
  ```c++
  if (big1 < 1234567890
      or big1 > "123456789012345678901234567890"
      or big1 <= big2
      or 1234567890 >= big1
      or "123456789012345678901234567890" == big1
      or big1 != big3) {
      ...
  }
  ```

* #### I/O stream: `<<`, `>>`
  ```c++
  std::cout << big1 << ", " << big2 << "\n";
  output_file << big1 << ", " << big2 << "\n";

  std::cin >> big1 >> big2;
  input_file >> big1 >> big2;
  ```

## Credit

This Big Int class was created by [sujon hasan](https://web.facebook.com/profile.php?id=100058892555448)
and [farid islam](https://web.facebook.com/farid.0point/)