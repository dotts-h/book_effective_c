# Getting Started with C

## Portability issues enumerated in Annex J of the C Standard documents

### Implementation-Defined Behavior

> Is program behavior that's not specified by the C Standard and that may offer different results among implementations, but has consistent, documented behavior within an implementation. (eg. number of bits in a byte)
> These behaviors are mostly harmless but can use defects when porting to different implementations.
>
> ***Whenever possible***, avoid writing code that depends on implementation-defined behaviors that vary among the C implementations you might use to compile your code.
>
> You can document your dependencies on these implementation-defined behaviors by using a *static_assert* declaration

### Unspecified Behavior

> Is program behavior for which the standard provides two or more options. The standard imposes no requirements on which options is chosen in any instance. Each execution of a given expression may have different results or produce a different value than a previous execution of the same expression. (eg. function parameter storage layout, which can vary among function invocations within the same program)
>
> Avoid writing code that depends on the unspecified behaviors

### Undefined Behavior

> Is behavior that isn't defined by the C Standard, or less circularly, `behavior, upon use of a nonportable or erroneous program construct or of erroneous data, for which the standard imposes no requirements`. (eg. signed integer overflow, dereferencing an invalid pointer value etc.)
> Undefined behaviors are identified in the standard as follows:
>
> - When a `shall` or `shall not` requirement is violated, and that requirement appears outside a constraint, the behavior is undefined
> - When behavior is explicitly specified by the words `undefined behavior`
> - By the omission of any explicit definition of behavior
>
> The first two kinds of undefined behavior are frequently referred to as `explicit undefined behaviors`, while the third kind is referred to as `implicit undefined behavior`.
> Developers frequently misunderstand undefined behaviors to be errors or omissions in the C Standard, but the decision to classify a behavior as undefined is `intentional` and `considered`. Behaviors are classified as undefined by the C Standards comittee to do the following:
>
> - Give the implementer license not to catch program errors that are difficult to diagnose
> - Avoid defining obscure corner cases that would favor one implementation strategy over another
> - Identify areas of possible conforming language extension in which the implementer may augment the language by providing a definition of the officially undefined behavior
>
> Compilers (implementations) have the latitude to do the following:
>
> - Ignore undefined behavior completely, giving unpredictable results
> - Behave in a documented manner characteristic of the environment (with or without issuing a diagnostic)
> Terminate a translation or execution (with issuing a diagnostic)
>
> It's best to avoid undefined behaviors except when the implementation specifies these behaviors are defined to allow you to invoke a language augmentation

### Locale-Specific Behavior and Common Extensions

> Depends on local conventions of nationality, culture, and language that each implementation documents. Common extensions are widely used in many systems but are not portable to all implementations
