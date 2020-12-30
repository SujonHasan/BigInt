// ***Bismillahir Rahmanir Rahim***
// Date and Time: 15-12-2020 : 23:01:15
// Author: Sujon Hasan

/*
    ===========================================================================
    bigInt
    ===========================================================================
    Definition for the bigInt class.
*/

#include <iostream>
#include <algorithm>

class bigInt
{
private:
    /* data */
    std::string number;
    char sign;

    void headZero(std::string &number);
    bool isValidNumber(const std::string &num);
    int string_compare(std::string &num1, std::string &num2);
    void swaping(std::string &num1, std::string &num2, int &sign_check);
    // Binary arithmetic operation function:
    std::string addition(std::string num1, std::string num2);
    std::string subtraction(std::string num1, std::string num2);
    std::string multiplication(std::string num1, std::string num2);
    std::string division(std::string num1, std::string divisor);
    std::string mod(std::string num1, std::string num2);

public:
    // Constructors:
    bigInt();
    bigInt(const bigInt &);
    bigInt(const long long &);
    bigInt(const std::string &);

    // Assignment operators:
    bigInt &operator=(const bigInt &);
    bigInt &operator=(const long long &);
    bigInt &operator=(const std::string &);

    // Unary arithmetic operator:
    bigInt operator+() const; // unary +
    bigInt operator-() const; //unary -;

    // Binary arithmetic operators
    bigInt operator+(const bigInt &obj);
    bigInt operator-(const bigInt &obj);
    bigInt operator*(const bigInt &obj);
    bigInt operator/(const bigInt &obj);
    bigInt operator%(const bigInt &obj);
    bigInt operator+(const long long &);
    bigInt operator-(const long long &);
    bigInt operator*(const long long &);
    bigInt operator/(const long long &);
    bigInt operator%(const long long &);
    bigInt operator+(const std::string &);
    bigInt operator-(const std::string &);
    bigInt operator*(const std::string &);
    bigInt operator/(const std::string &);
    bigInt operator%(const std::string &);

    // Increment and decrement operators:
    bigInt &operator++();   // pre- increment
    bigInt operator++(int); // post-increment
    bigInt &operator--();   // pre- decrement
    bigInt operator--(int); // post- decrement

    // Arithmatic- assignment operator
    bigInt &operator+=(const bigInt &);
    bigInt &operator-=(const bigInt &);
    bigInt &operator*=(const bigInt &);
    bigInt &operator/=(const bigInt &);
    bigInt &operator%=(const bigInt &);
    bigInt &operator+=(const long long &);
    bigInt &operator-=(const long long &);
    bigInt &operator*=(const long long &);
    bigInt &operator/=(const long long &);
    bigInt &operator%=(const long long &);
    bigInt &operator+=(const std::string &);
    bigInt &operator-=(const std::string &);
    bigInt &operator*=(const std::string &);
    bigInt &operator/=(const std::string &);
    bigInt &operator%=(const std::string &);

    // Relational operator
    bool operator==(const bigInt &) const;
    bool operator<(const bigInt &) const;
    bool operator>(const bigInt &) const;
    bool operator>=(const bigInt &) const;
    bool operator<=(const bigInt &) const;
    bool operator!=(const bigInt &) const;
    bool operator==(const long long &) const;
    bool operator!=(const long long &) const;
    bool operator<(const long long &) const;
    bool operator>(const long long &) const;
    bool operator<=(const long long &) const;
    bool operator>=(const long long &) const;
    bool operator==(const std::string &) const;
    bool operator!=(const std::string &) const;
    bool operator<(const std::string &) const;
    bool operator>(const std::string &) const;
    bool operator>=(const std::string &) const;
    bool operator<=(const std::string &) const;

    // Logical operator
    bool operator&&(bigInt &obj);
    bool operator||(bigInt &obj);
    bool operator!();

    // Subscript operator
    bigInt operator[](int index);

    // iostrem and ostream overloding
    friend std::istream &operator>>(std::istream &input, bigInt &obj);
    friend std::ostream &operator<<(std::ostream &output, const bigInt &obj);

    ~bigInt();
};

/*
    is_valid_number
    ---------------
    Checks whether the given string is a valid integer.
*/

bool bigInt::isValidNumber(const std::string &num)
{
    for (char digit : num)
        if (digit < '0' or digit > '9')
            return false;

    return true;
}

/*
    head Zero
    --------------------
    headZero from a number represented as a string.
*/

void bigInt::headZero(std::string &number)
{
    int i = 0;

    while (number[i] == '0')
    {
        i++;
    }

    number = number.substr(i, number.size() - i);

    if (!number.size())
    {
        number = "0";
    }
}

//    *************  Constructor  *****************

// Default constructor
//--------------------

bigInt::bigInt()
{
    number = "0";
    sign = '+';
}

// Copy constructor
//--------------------

bigInt::bigInt(const bigInt &obj)
{
    number = obj.number;
    sign = obj.sign;
}

// Integer to BigInt
//--------------------

bigInt::bigInt(const long long &input)
{
    // cout << "2\n";
    number = std::to_string(input);

    if (input < 0)
    {
        sign = '-';
        number = number.substr(1);
    }
    else
    {
        sign = '+';
    }
}

// String to BigInt
//--------------------

bigInt::bigInt(const std::string &input)
{
    if (input[0] == '+' || input[0] == '-') // check for sign
    {
        std::string digit = input.substr(1);

        if (isValidNumber(digit))
        {
            number = digit;
            sign = input[0];
        }
        else
        {
            std::cout << "Expected an integer, got " << input << std::endl;
            exit(1);
        }
    }
    else // if no sign in specified
    {
        if (isValidNumber(input))
        {
            number = input;
            sign = '+'; // positive by default
        }
        else
        {
            std::cout << "Expected an integer, got " << input << std::endl;
            exit(1);
        }
    }

    // Remove head  Zeros (number);
    headZero(number);

    if (number == "0")
    {
        sign = '+';
    }
}

//    *************  Assignment operators  *****************

// BigInt = BigInt
//----------------

bigInt &bigInt ::operator=(const bigInt &num)
{
    number = num.number;
    sign = num.sign;

    return *this;
}

// BigInt = Integer
//-----------------------

bigInt &bigInt ::operator=(const long long &num)
{
    bigInt obj(num);

    number = obj.number;
    sign = obj.sign;

    return *this;
}

// BigInt = String
//-----------------------

bigInt &bigInt::operator=(const std::string &input)
{
    std::string str = input;
    bigInt obj(str);

    number = obj.number;
    sign = obj.sign;

    return *this;
}

// ************** Unary arithmetic operator************

/*
    +BigInt 

    Returns the value of a BigInt

*/

bigInt bigInt ::operator+() const
{
    return *this;
}

// -BigInt
// Returns the negative of a BigInt.

bigInt bigInt::operator-() const
{
    bigInt obj;

    obj.number = number;
    if (number != "0")
    {
        if (sign == '+')
        {
            obj.sign = '-';
        }
        else
        {
            obj.sign = '+';
        }
    }

    return obj;
}

// *************** Increment and decrement operators**********

// pre-increment
// ++BigInt

bigInt &bigInt::operator++() // preincrement
{
    *this += 1;

    return *this;
}

// post-increment
// BigInt++

bigInt bigInt::operator++(int)
{
    bigInt object = *this;

    *this += 1;

    return object;
}

// pre-decrement
// --BigInt

bigInt &bigInt::operator--()
{
    *this -= 1;

    return *this;
}

// post-decrement
// BigInt--

bigInt bigInt::operator--(int)
{
    bigInt object = *this;

    *this -= 1;

    return object;
}

// *****************  Arithmetic- assignment operator *************

// BigInt += BigInt
//-----------------

bigInt &bigInt::operator+=(const bigInt &obj)
{
    return *this = *this + obj;
}

// BigInt -= BigInt
//-----------------

bigInt &bigInt::operator-=(const bigInt &obj)
{
    return *this = *this - obj;
}

// BigInt *= BigInt
//-----------------

bigInt &bigInt::operator*=(const bigInt &obj)
{
    return *this = *this * obj;
}

// BigInt /= BigInt
//--------------------

bigInt &bigInt::operator/=(const bigInt &obj)
{
    return *this = *this / obj;
}

// BigInt %= BigInt
//-----------------

bigInt &bigInt::operator%=(const bigInt &obj)
{
    return *this = *this % obj;
}

// BigInt += Integer
//------------------

bigInt &bigInt ::operator+=(const long long &num)
{
    *this = *this + bigInt(num);

    return *this;
}

// Bigint -= Integer
//-------------------

bigInt &bigInt ::operator-=(const long long &num)
{
    *this = *this - bigInt(num);
    return *this;
}

// BigInt *= Integer
//------------------

bigInt &bigInt ::operator*=(const long long &num)
{
    *this = *this * bigInt(num);

    return *this;
}

// BigInt /= Integer
//-----------------

bigInt &bigInt ::operator/=(const long long &num)
{
    *this = *this / bigInt(num);
    return *this;
}

// BigInt %= Integer
//------------------

bigInt &bigInt ::operator%=(const long long &num)
{
    *this = *this % bigInt(num);
    return *this;
}

// BigInt += string
//------------------

bigInt &bigInt ::operator+=(const std::string &num)
{
    *this = *this + bigInt(num);
    return *this;
}

// BigInt -= string
//------------------

bigInt &bigInt ::operator-=(const std::string &num)
{
    *this = *this - bigInt(num);
    return *this;
}

// BigInt *= string
//------------------

bigInt &bigInt ::operator*=(const std::string &num)
{
    *this = *this * bigInt(num);
    return *this;
}

// BigInt /= string
//------------------

bigInt &bigInt ::operator/=(const std::string &num)
{
    *this = *this / bigInt(num);
    return *this;
}

// BigInt %= string
//------------------

bigInt &bigInt ::operator%=(const std::string &num)
{
    *this = *this % bigInt(num);
    return *this;
}

// ****************** Relational operators***************

// BigInt == BigInt
//-----------------

bool bigInt::operator==(const bigInt &obj) const
{
    return (sign == obj.sign) and (number == obj.number);
}

// BigInt < BigInt
//----------------

bool bigInt::operator<(const bigInt &obj) const
{
    if (sign == obj.sign)
    {
        if (sign == '+')
        {
            if (number.length() == obj.number.length())
            {
                return number < obj.number;
            }
            else
            {
                return number.length() < obj.number.length();
            }
        }
        else
        {
            if (number.length() == obj.number.length())
            {
                return number > obj.number;
            }
            else
            {
                return number.length() > obj.number.length();
            }
        }
    }
    else
    {
        return sign == '-';
    }
}

// BigInt > BigInt
//---------------

bool bigInt::operator>(const bigInt &obj) const
{
    return !((*this < obj) || (*this == obj));
}

// BigInt >= BigInt
//----------------

bool bigInt ::operator>=(const bigInt &obj) const
{
    return !(*this < obj);
}

// BigInt <= BigInt
//-----------------

bool bigInt ::operator<=(const bigInt &obj) const
{
    return !(*this > obj);
}

// BigInt != BigInt
//----------------

bool bigInt ::operator!=(const bigInt &obj) const
{
    if (*this == obj)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// BigInt == Integer
//---------------

bool bigInt::operator==(const long long &num) const
{
    return *this == bigInt(num);
}

// Integer == BigInt
//------------------

bool operator==(const long long &number, const bigInt &obj)
{
    return bigInt(number) == obj;
}

// BigInt != Integer
//------------------

bool bigInt::operator!=(const long long &num) const
{
    return !(*this == bigInt(num));
}

// Integer != BigInt
//------------------

bool operator!=(const long long &number, const bigInt &obj)
{
    return bigInt(number) != obj;
}

// BigInt < Integer
//------------------

bool bigInt ::operator<(const long long &num) const
{
    return *this < bigInt(num);
}

// Integer < BigInt
//-----------------

bool operator<(const long long &number, const bigInt &obj)
{
    return bigInt(number) < obj;
}

// BigInt > Integer
//-----------------

bool bigInt ::operator>(const long long &num) const
{
    return *this > bigInt(num);
}

// Integer > BigInt
//------------------

bool operator>(const long long &number, const bigInt &obj)
{
    return bigInt(number) > obj;
}

// BigInt <= Integer
//--------------------

bool bigInt ::operator<=(const long long &num) const
{
    return !(*this > bigInt(num));
}

// Integer <= BigInt
//------------------

bool operator<=(const long long &number, const bigInt &obj)
{
    return bigInt(number) <= obj;
}

// BigInt >= Integer
//------------------

bool bigInt ::operator>=(const long long &num) const
{
    return !(*this < bigInt(num));
}

// Integer >= BigInt
//-----------------

bool operator>=(const long long &number, const bigInt &obj)
{
    return bigInt(number) >= obj;
}

// BigInt == string
//-----------------

bool bigInt::operator==(const std::string &num) const
{
    return *this == bigInt(num);
}

// string == BigInt
//-----------------

bool operator==(const std::string &num, const bigInt &obj)
{
    return bigInt(num) == obj;
}

// BigInt != string
//------------------

bool bigInt::operator!=(const std::string &num) const
{
    return !(*this == bigInt(num));
}

// string != BigInt
//-----------------

bool operator!=(const std::string &num, const bigInt &obj)
{
    return bigInt(num) != obj;
}

// BigInt < string
//-----------------

bool bigInt::operator<(const std::string &num) const
{
    return *this < bigInt(num);
}

// string < BigInt
//----------------

bool operator<(const std::string &num, const bigInt &obj)
{
    return bigInt(num) < obj;
}

// BigInt > string
//----------------

bool bigInt::operator>(const std::string &num) const
{
    return *this > bigInt(num);
}

// string > BigInt
//------------------

bool operator>(const std::string &num, const bigInt &obj)
{
    return bigInt(num) > obj;
}

// BigInt <= string
//------------------

bool bigInt::operator<=(const std::string &num) const
{
    return !(*this > bigInt(num));
}

// string <= BigInt
//------------------

bool operator<=(const std::string &num, const bigInt &obj)
{
    return bigInt(num) <= obj;
}

// BigInt >= string
//-----------------

bool bigInt::operator>=(const std::string &num) const
{
    return !(*this < bigInt(num));
}

// string >= BigInt
//-----------------

bool operator>=(const std::string &num, const bigInt &obj)
{
    return bigInt(num) >= obj;
}

// ******************logical operators*****************

// logical && operator
//------------------

bool bigInt::operator&&(bigInt &obj)
{
    if (this->number != "0" && obj.number != "0")
    {
        return true;
    }
    else
    {
        return false;
    }
}

// logical || operator
//--------------------

bool bigInt::operator||(bigInt &obj)
{
    if (this->number != "0" || obj.number != "0")
    {
        return true;
    }
    else
    {
        return false;
    }
}

// logical NOT operator
//--------------------

bool bigInt ::operator!()
{
    if (this->number == "0")
    {
        return true;
    }
    else
    {
        return false;
    }
}

//*******************subscript operator********************

bigInt bigInt::operator[](int index)
{
    if (index > (this->number.size() - 1))
    {
        std::cout << "Index out of bounds\n";
        exit(1);
    }

    bigInt temp;
    temp.number = this->number[index];

    return temp;
}

// two number check and swaping
//-----------------------------

void bigInt::swaping(std::string &num1, std::string &num2, int &sign_check)
{
    if (num1.size() < num2.size())
    {
        swap(num1, num2);
        sign_check = 1;
    }
    else if (num1.size() == num2.size())
    {
        for (int i = 0; num1[i] != '\0'; i++)
        {
            if (num1[i] < num2[i])
            {
                swap(num1, num2);
                sign_check = 1;
                break;
            }
        }
    }
}

// two number compare and return value
//-----------------------------------

int bigInt::string_compare(std::string &num1, std::string &num2)
{
    int len1 = num1.size();
    int len2 = num2.size();

    if (len1 > len2)
    {
        return 1;
    }
    else if (len1 < len2)
    {
        return -1;
    }
    else
    {
        return num1.compare(num2);
    }
}

// ************ Binary arithmetic operators***********

// BigInt + BigInt
//----------------

bigInt bigInt::operator+(const bigInt &obj)
{
    /* algorith of + operator function

        a. input two object.
        b. assign new two stirng .
        c. check large and small string .
        d. reverse two string .
        e. first if check two object addition function. and call function
        d. second else if check two object subtraction function. and call function.
        e. return object.

    */
    bigInt object;
    object.sign = '+';

    std::string num1 = this->number;
    std::string num2 = obj.number;

    int sign_check = 0;

    swaping(num1, num2, sign_check);

    if (this->sign == obj.sign)
    {
        object.number = addition(num1, num2);

        if (this->sign == '-' && obj.sign == '-')
        {
            object.sign = '-';
        }
    }
    else
    {
        object.number = subtraction(num1, num2);

        if (sign_check == 1 && obj.sign == '-')
        {
            object.sign = '-';
        }
        else if (sign_check == 0 && this->sign == '-')
        {
            object.sign = '-';
        }
    }

    if (object.sign == '-' && object.number == "0")
    {
        object.sign = '+';
    }

    return object;
}

// BigInt - BigInt
//----------------

bigInt bigInt::operator-(const bigInt &obj)
{
    /* algorith of - operator function

        a. input two object.
        b. assign new two stirng .
        c. check large and small string .
        d. reverse two string .
        e. first if check two object subtraction function. and call function
        d. second else if check two object addition function. and call function.
        e. return object.

    */

    bigInt object;
    object.sign = '+';

    // assign two number.
    std::string num1 = this->number;
    std::string num2 = obj.number;
    int sign_check = 0;

    swaping(num1, num2, sign_check);

    if (this->sign == obj.sign)
    {
        object.number = subtraction(num1, num2);

        if (sign_check == 0 && this->sign == '-')
        {
            object.sign = '-';
        }
        else if (sign_check == 1 && obj.sign == '+')
        {
            object.sign = '-';
        }
    }
    else
    {
        object.number = addition(num1, num2);

        if (sign_check == 0 && this->sign == '-')
        {
            object.sign = '-';
        }
        else if (sign_check == 1 && obj.sign == '-')
        {
            object.sign = '+';
        }
        else if (sign_check == 1 && obj.sign == '+')
        {
            object.sign = '-';
        }
    }

    if (object.sign == '-' && object.number == "0")
    {
        object.sign = '+';
    }

    return object;
}

// BigInt * BigInt
//----------------

bigInt bigInt::operator*(const bigInt &obj)
{
    /*algorith of multiplication operator overload function

        a. input two object.
        b. call multiplication function. return result.
        c. than sign check .
        d. return object

    */
    bigInt object;
    object.sign = '+';

    object.number = multiplication(this->number, obj.number);

    if (this->sign == '-' && obj.sign == '-')
    {
        object.sign = '+';
    }
    else if (this->sign == '-' || obj.sign == '-')
    {
        object.sign = '-';
    }

    if (object.number == "0")
    {
        object.sign = '+';
    }

    return object;
}

// BigInt / BigInt
//-----------------

bigInt bigInt::operator/(const bigInt &obj)
{
    /*algorith of division operator overload function

        a. input two object.
        b. call division function. return result.
        c. than sign check .
        d. return object

    */
    bigInt object;
    object.sign = '+';

    object.number = division(this->number, obj.number);

    if (this->sign == '-' && obj.sign == '-')
    {
        object.sign = '+';
    }
    else if (this->sign == '-' || obj.sign == '-')
    {
        object.sign = '-';
    }

    if (object.number == "0")
    {
        object.sign = '+';
    }

    return object;
}

// BigInt % BigInt
//-----------------

bigInt bigInt::operator%(const bigInt &obj)
{
    /*algorith of modulus operator overload function

        a. input two object.
        b. call modulus function. return result.
        c. than sign check .
        d. return object

    */
    bigInt object;
    object.sign = '+';

    object.number = mod(this->number, obj.number);

    if (this->sign == '-')
    {
        object.sign = '-';
    }

    if (object.number == "0")
    {
        object.sign = '+';
    }

    return object;
}

/*
    BigInt + Integer
    ----------------
*/

bigInt bigInt::operator+(const long long &num)
{
    return *this + bigInt(num);
}

/*
    Integer + BigInt
    ----------------
*/

bigInt operator+(const long long &num, const bigInt &obj)
{
    return bigInt(num) + obj;
}

/*
    BigInt - Integer
    ----------------
*/

bigInt bigInt::operator-(const long long &num)
{
    return *this - bigInt(num);
}

/*
    Integer - BigInt
    ----------------
*/

bigInt operator-(const long long &num, const bigInt &obj)
{
    return bigInt(num) - obj;
}

/*
    BigInt * Integer
    ----------------
*/

bigInt bigInt::operator*(const long long &num)
{
    return *this * bigInt(num);
}

/*
    Integer * BigInt
    ----------------
*/

bigInt operator*(const long long &num, const bigInt &obj)
{
    return bigInt(num) * obj;
}

/*
    BigInt / Integer
    ----------------
*/

bigInt bigInt::operator/(const long long &num)
{
    return *this / bigInt(num);
}

/*
    Integer / BigInt
    ----------------
*/

bigInt operator/(const long long &num, const bigInt &obj)
{
    return bigInt(num) / obj;
}

/*
    BigInt % Integer
    ----------------
*/

bigInt bigInt::operator%(const long long &num)
{
    return *this % bigInt(num);
}

/*
    Integer % BigInt
    ----------------
*/

bigInt operator%(const long long &num, const bigInt &obj)
{
    return bigInt(num) % obj;
}

/*
    BigInt + string
    ----------------
*/

bigInt bigInt::operator+(const std::string &num)
{
    return *this + bigInt(num);
}

/*
    String + BigInt
    ----------------
*/

bigInt operator+(const std::string &num, const bigInt &obj)
{
    return bigInt(num) + obj;
}

/*
    BigInt - string
    ----------------
*/

bigInt bigInt::operator-(const std::string &num)
{
    return *this - bigInt(num);
}

/*
    String - BigInt
    ----------------
*/

bigInt operator-(const std::string &num, const bigInt &obj)
{
    return bigInt(num) - obj;
}

/*
    BigInt * string
    ----------------
*/

bigInt bigInt::operator*(const std::string &num)
{
    return *this * bigInt(num);
}

/*
    String * BigInt
    ----------------
*/

bigInt operator*(const std::string &num, const bigInt &obj)
{
    return bigInt(num) * obj;
}

/*
    BigInt / string
    ----------------
*/

bigInt bigInt::operator/(const std::string &num)
{
    return *this / bigInt(num);
}

/*
    String / BigInt
    ----------------
*/

bigInt operator/(const std::string &num, const bigInt &obj)
{
    return bigInt(num) / obj;
}

/*
    BigInt % string
    ----------------
*/

bigInt bigInt::operator%(const std::string &num)
{
    return *this % bigInt(num);
}

/*
    String % BigInt
    ----------------
*/

bigInt operator%(const std::string &num, const bigInt &obj)
{
    return bigInt(num) % obj;
}

// addition two number
//------------------

std::string bigInt::addition(std::string num1, std::string num2)
{
    /* complexity  

      1. time complexity = O(n);
      2. space complexity = O(1).

      algorith of addition function.

        1. input two number.
        2. first loop . small number and sum two number basic mathmatic sum.
        2. second loop. remainder and last big number sum .
        3.if last remainder add .
        4. return addition number.

    */
    std::string result;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int i, sum, remainder = 0;

    // starting two number sum basic mathmatical .
    for (i = 0; num2[i] != '\0'; i++)
    {
        sum = ((num1[i] - 48) + (num2[i] - 48)) + remainder;
        result = (char)(sum % 10 + 48) + result;
        remainder = sum / 10;
    }

    // adding remainder big number.
    for (; num1[i] != '\0'; i++)
    {
        sum = (num1[i] - 48) + remainder;
        result = (char)(sum % 10 + 48) + result;
        remainder = sum / 10;
    }

    if (remainder)
    {
        result = '1' + result;
    }

    return result;
}

// subtraction two numnber
//-----------------------

std::string bigInt::subtraction(std::string num1, std::string num2)
{
    /* complexity  

      1. time complexity = O(n);
      2. space complexity = O(1).

      algorith of addition function.

        1. input two number.
        2. reverse two number.
        3. first loop . small number and sum two number basic mathmatic sum.
        4. second loop. remainder and last big number sum .
        5.if last remainder add .
        6. return addition number.

    */

    std::string result;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int i, sub, remainder = 0;

    for (i = 0; num2[i] != '\0'; i++)
    {
        num2[i] += remainder;
        remainder = 0;

        if (num1[i] < num2[i])
        {
            sub = (((num1[i] - 48) + 10) - ((num2[i] - 48)));
            result.push_back(sub + 48);
            remainder = 1;
        }
        else
        {
            sub = ((num1[i] - 48) - (num2[i] - 48));
            result.push_back(sub + 48);
        }
    }

    for (; num1[i] != '\0'; i++)
    {
        if (num1[i] < (remainder + 48))
        {
            sub = ((num1[i] - 48) + 10) - remainder;
            result.push_back(sub + 48);
            remainder = 1;
        }
        else
        {
            sub = ((num1[i] - 48) - remainder);
            result.push_back(sub + 48);
        }
    }

    reverse(result.begin(), result.end());

    headZero(result); // first zero remove

    return result;
}

// Multiplication two number
// -------------------------

std::string bigInt::multiplication(std::string num1, std::string num2)
{
    /*Multiplication algorithm and complexity  

      1. time complexity = O(n2);
      2. space complexity = O(n).

      algorith of multiplication function.

        1. input two  string number.
        2. check small number.
        3. first loop . 1 by 1 number check. if zero then zeroadd++ then  other number.
        4. second loop. start and. multiplication first number .
        5.if last remainder add .
        6. zeroadd added . and first loop continue .
        7. return result.

    */
    std::string result;
    std::string temp;
    int num, sum, remainder = 0, zeroAdd = 0;

    if (num1 < num2)
    {
        swap(num1, num2);
    }

    int len1 = num1.size() - 1;
    int len2 = num2.size() - 1;

    for (int i = len1; i >= 0; i--)
    {
        num = num1[i] - '0';
        if (num == 0)
        {
            zeroAdd++;
            continue;
        }

        for (int i = len2; i >= 0; i--)
        {
            sum = (num * (num2[i] - '0')) + remainder;
            temp.push_back(sum % 10 + '0');
            remainder = sum / 10;
        }
        if (remainder)
        {
            temp.push_back(remainder + '0');
            remainder = 0;
        }

        reverse(temp.begin(), temp.end());

        if (1 <= zeroAdd)
        {
            for (int i = 1; i <= zeroAdd; i++)
            {
                temp.push_back('0');
            }
        }

        result = addition(temp, result);
        temp.clear();

        zeroAdd++;
    }

    if (result[0] == '0')
    {
        result = "0";
    }

    return result;
}

// division two number
// -------------------

std::string bigInt::division(std::string num1, std::string divisor)
{
    /*Division function algorithm and complexity  

      1. time complexity = O(n2);
      2. space complexity = O(1).

      algorith of division function.

        1. input two  string number.
        2. input error check . and division number check.
        3. loop 1 . 1 by 1 number add and dividion number.
        4. while loop. subtraction dividend number.
        5. return result.

    */
    if (divisor == "0")
    {
        std::cout << "Can't divide by 0\n";
        exit(1);
    }
    else if (num1 == "0")
    {
        return "0";
    }

    int val = string_compare(num1, divisor);

    if (val == -1) // num1 < num2
    {
        return "0";
    }
    else if (val == 0) // num1 == num2
    {
        return "1";
    }

    std::string result;
    std::string dividend;
    int result_count;
    int zero_add = 0;
    int value;

    for (int i = 0; num1[i] != '\0'; i++)
    {
        dividend += num1[i];

        headZero(dividend);
        result_count = 0;
        value = string_compare(dividend, divisor);
        // cout << "dividend = " << dividend << endl;
        // cout << "value = " << value << endl;
        // _getch();

        while (value >= 0)
        {
            dividend = subtraction(dividend, divisor);
            // cout << "dividend = " << dividend << endl;
            result_count++;
            zero_add = 1;
            value = string_compare(dividend, divisor);
            // cout << "value.... = " << value << endl;
            // _getch();
        }

        if (zero_add)
        {
            result += (result_count + '0');
        }
    }

    return result;
}

// mod two number
// --------------

std::string bigInt::mod(std::string num1, std::string num2)
{
    /*Modulus function algorithm and complexity  

      1. time complexity = O(n2);
      2. space complexity = O(1).

      algorith of modulus function.

        1. input two  string number.
        2. input error check . and division number check.
        3. loop 1 . 1 by 1 number add and dividion number.
        4. while loop. subtraction dividend number.
        5. return dividend number;

    */

    if (num2 == "0")
    {
        std::cout << "Error .Division by zero\n";
        exit(1);
    }
    else if (num1 == "0")
    {
        return "0";
    }

    int value = string_compare(num1, num2);

    if (value == -1) // num1 < num2
    {
        return num1;
    }
    else if (value == 0) // num1 == num2
    {
        return "0";
    }

    std::string dividend;

    for (int i = 0; num1[i] != '\0'; i++)
    {
        dividend += num1[i];

        headZero(dividend);
        value = string_compare(dividend, num2);

        while (value >= 0)
        {
            dividend = subtraction(dividend, num2);
            value = string_compare(dividend, num2);
        }
    }

    return dividend;
}

// ************** I/0 stream operators****************

// BigInt from input stream
//--------------------------

std::istream &operator>>(std::istream &input, bigInt &obj)
{
    std::string inputNum;
    input >> inputNum;
    obj = bigInt(inputNum);
    return input;
}

// BigInt to output stream
//--------------------------

std::ostream &operator<<(std::ostream &output, const bigInt &obj)
{
    if (obj.sign == '-')
    {
        output << obj.sign;
    }
    output << obj.number;
    return output;
}

bigInt::~bigInt()
{
}