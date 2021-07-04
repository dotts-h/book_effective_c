# Arithmetic Types

## Integers

### Signed Integers

> Historically, the C language has supported thress signed integer representation schemes:
>
> - **Sign and magnitude** The high-order bit indicates the sign, and the remaining bits represent the magnitude of the value in pure binary notation
> - **Ones' complement** The sign bit is given the weight -(2^(N-1)-1), and the other value bits have the same weights as for unsigned
> - **Two's complement** The sign bit is given the weight -(2(N-1)), and the other value bits have the same weights as for unsigned

## Floating-point

---
> As with integers, the sign bit represents whether the number is positive or negative: 0 denotes a positive number, and 1 denotes a negative number.
> The _exponent field_ needs to represent both positive and negative exponents. To avoid storing the exponent as a signed number, a bias is implicitly added to the actual exponent to get the stored exponent. For the `float` type, the bis is 127. Consequently, to express an exponent of 0, we would store 127 in the exponent field. A stored value of 200 indicates an exponent of 200-127, or 73. Exponents of -127 (where every exponent bit is 0) and +128 (where every exponent bit is 1) are reserved for special numbers. Similarly, the bias for double-precision numbers is 1023. This means that the value stored will range from 0 to 255 for a `float`, and 0 to 2047 for a `double`.
> The _significand bits_ represent the precision bits of the number. For example, if you were to represent the value 1.0100110 x 2^4 as a floating-point value, the significand refers to the precision bits 1.0100110, and the exponent refers to the power of 2, which is 4 in this examepl (Hollasch 2019)

## Integer Conversion Rank

> The C Standard states that every integer type has an integer conversion rank where the following applies:
>
> - No two signed integer types have the same rank, even if they have the same representation
> - The rank of a signed integer type is greater than the rank of any signed integer type with less precision
> - The rank of `long long int` is greater than the rank of `long int`, which is greater than the rank of `int`, which is greater than the rank of `short int`, which is greater than the rank of `signed char`
> - The rank of any unsigned integer type equals the rank of the corresponding signed integer type, if any
> - The rank of `char` equals the rank of `signed char` and `unsigned char`
> - The rank of `_Bool` is less than the rank of all other standard integer types
> - The rank of any enumerated type equals the rank of the compatible integer type. Each enumerated type is compatible with `char`, a signed integer type, or an unsigned integer type
> - The rank of any extended signed integer type relative to another extended signed integer type with the same precision is implementation-defined but still subject to the other rules for determining the integer conversion rank

## Usual Arithmetic Conversions

> The usual arithmetic conversions first check whether one of the operands in the balancing conversion is a floating-point type. If so, it applies the following rules:
>
> 1. If one type of either operand is `long double`, the other operand is converted to `long double`
> 2. Otherwise, if one type of either operand is `double`, the other operand is converted to `double`
> 3. Otherwise, if the type of either operand is `float`, the other operand is converted to `float`
> 4. Otherwise, the integer promotions are performed on both operands
>
> If neither operand is a floating-point type, the following usual arithmethic conversion rules are applied to the promoted integer operands:
>
> 1. If both operands have the same type, no further conversion is needed
> 2. Otherwise, if both operands have signed integer types or both have unsigned integer types, the operand with the type that has the lesser integer conversion rank is converted to the type of the operand with greater rank. If one operand has the type `int` and the other operand has the type `long`, for example, the operand of type `int` is converted to an object of type `long`
> 3. Otherwise, if the operand that has the unsigned integer type has a rank greater than or equal to the rank of the other operand's type, then the operand with the signed integer type is converted to the type of the operand with the unsigned integer type. For example, if one operand has the type `signed int`, and the other operand has the type `unsigned int`, the operand of type `signed int` is converted to an object of type `unsigned int`
> 4. Otherwise, if the type of the operand with the signed integer type can represent all of the values of the type of the operand with unsigned integer type, then the operand with unsigned integer type is converted to the type of the operand with signed integer type. For example, if one operand has the type `unsigned int` and the other operand has the type `signed long long`, and the `signed long long` type can represent all the values of the `unsigned int` type, then the operand of type `unsigned int` is converted to an object of type `signed long long`.
> 5. Otherwise, both operands are converted to the unsigned integer type coresponding to the type of the operand with signed integer type

## To Dos

- [ ] read up on floating point representation and arithmetic in C