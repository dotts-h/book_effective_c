# Objects, Functions, and Types

## General notes on chapter

> C distinguishes between *parameters*, which are objects declared as part of the function declaration that acquire a value on entry to the function, and *arguments*, which are comma-separated expressions you include in the function call expression

> C is a *call-by-value* (also called a *pass-by-value*) language, which means that when you provide an argument to a function, the value of that argument is copied into a distinct variable for use within the function

> C has four types of scope:
>
> - file
> - block
> - function prototype
> - function

> Four storage durations are available:
>
> - automatic
> - static
> - thread
> - allocated

---

*Scope and lifetime are entirely different concepts*. Scope *applies to identifiers, whereas* lifetime *applies to objects*. *The scope of an identifier is the code region where the object denoted by the identifier can be accessed by its name*. *The lifetime of an object is the time period for which the object exsits*

---

## Alignment

> An *alignment* represents the number of bytes between successive addresses at which a given object can be allocated
> C11 introduced alignments represented as values of the type *size_t*. Every valid alignment value is a nonnegative integral power of two. An object type imposes a default alignment requirement on every object of that type: a stricter alignment (a larger power of two) can be requested using the alignment specifier (*_Alignas*)

(eg.)

```c
struct S {
    int i; double d; char c;
};

int main(void){
    unsigned char bad_buff[sizeof(struct S)];
    _Alignas(struct S) unsigned char good_buf[sizeof(struct S)];

    struct S *bad_s_ptr = (struct S *) bad_buff;    // wrong pointer alignment
    struct S *good_s_ptr = (struct S *) good_buff;  // correct pointer alignment 
}
```

> Alignments are ordered from weaker to stronger (also called stricter) alignments. Stricter alignments have larger alignment values. An address that satisfies an alignment requirement also satisfies any valid, weaker alignment requirement

---

## Object Types

> Objects declares as `_Bool` can store only the values 0 and 1
> `c<stdbool.h>` > allows asignment of values `true = 1` or `false = 0`

(eg.)

```c
#include <stdbool.h>
_Bool flag1 = 0;
bool flag2 = false;
```

> Both spellings will work, but it is **better** to use `bool`, as this is the long termi direction for the language

> The C language defines three _character types_: `char`, `signed char`, and `unsigned char`. Each compiler implementation will define `char` to have the same alignment, size, range, representation, and behavior as either `signed char` or `unsinged char`. Regardless of the choice made, `char` is a separate type from the other two and is incompatible with both.

> You can represent the characters of a large character set as _wide characters_ by using the `wchar_t` type, which generally takes more space than a basic character. Typically, implementations choose 16 or 32 bits to represent a wide character.

> The actual size of the various integer types can be inferred from the minimum and maximum representable values specified in the `<limits.h>` header file
> We can specify actual width integers by using type definitions from the `<stdint.h>` or `<inttypes.h>` header like `uint32_t`

> An _enumeration_, or `enum`, allows you to define a type that assigns names (_enumerators_) to integer values in cases with an enumerable set of constant values

> The keyword `void` (by itself) means "cannot hold any value". On the other hand, the _derived type_ `void *` means that the pointer can reference _any_ object

---

## Function types

---

> **Never** declare functions with an empty parameter list in C.

---

## Derived Types

> _Derived types_ are types that are constructed from other types. These include:
>
> - pointers
> - arrays
> - type definitions
> - structures
> - unions

> A _pointer type_ is derived from the function or object type that it points to, called the _referenced_ type

---

### Type definitions

> We use a `typedef` to declare an alias for an existing type; it never creates a new type. For example, each of the following declarations creates a new type alias:
>
> ```c
> typedef unsigned int uint_type;
> typedef signed char schar_type, *schar_p, (*fp)(void);
> ```
>
> On the first line, we declare `uint_type` as an alias for the type `unsigned int`. On the second line, we declar `schar_type` as an alias for `signed char`, `schar_p` as an alias for `signed char *`, and `fp` as an alias for `signed char(*)(void)`. Identifiers that end in `_t` in the standard headers are type definitions (aliases for existing types). Generally speaking, we should not follow this convention in our own code because the C Standard reserrve identifiers that match the pattern int[0-9a-z_]\*\_t and uint[0-9a-z_]\*_t, and the Portable Operating System Interface (POSIX) reserves all identifiers that end in `_t`.

---

> A _structure type_ (also known as `struct`) contains sequentially allocated member objects
>
> ```c
> struct sigrecord {
>   int signum;
>   char signame[20];
>   char sigdesc[100]; 
> } sigline, *sigline_p;
> ```
>
> This example declares an object identified by `sigline` that has a tpye of `struct sigrecord` and a pointer to the `sigline` object identified by `sigline_p`

## Type Qualifiers

> Types can be _qualified_ by using one or more of the following qualifiers:
>
> - `const`
> - `volatile`
> - `restrict`

---

> *The `_Atomic` type qualifier, available since C11, supports concurrent programs*

---

> Objects of `volatile`-qualified types server a special purpose. Static `volatile`-qualified objects are used to model memory-mapped input/output ports, and static constant `volatile`-qualified objects model memory-mapped input ports such as a real-time clock
> The values stored in these objects may change without the knowledge of the compiler. For example, every time the value from a real-time clock is read, it may change, even if the value has not been written to by the C program. Using a `volatile`-qualified type lets the compiler know that the value may change, and ensures that every access to the real-time clock occurs (otherwise, an access to the real-time clock may be optimized away or replaced by a previously read and cached value). In the following code, for example, the compiler must generate instructions to read the value from `port` and then write this value back to `port`:
>
> ```c
> volatile int port;
> port = port;
> ```
>
> Without the `volatile` qualification, the compiler would see this as a _no-op_ (a programming statement that does nothing) and potentially eliminate both the read and the write.
> Also, `volatile`-qualified types are used for communications with `signal` handlers and with `setjmp`/`longjmp` (refer to the C Standard for information on `signal` handlers and `setjmp`/`longjmp`).
> Unlike in Java or other programming languages, `volatile`-qualified types in C should not be used for syncronizations between threads.

> A `restrict`-qualified pointer is used to promote optimization. Objects indirectly accessed through a pointer frequently cannot be fully optimized because of potential _aliasing_, which occurs when more than one pointer refers to the same object. Aliasing can inhibit optimizations, because the compiler can`t tell if portions of an object can change values when another apparently unrelated object is modified.

## To dos

- [ ] read more on Alignments in C
- [ ] read more on Volatile qualifier
- [ ] read more on pointer to functions in C