## Operators

#### Assignment

`=` - assignment. Value on the right of the `=` is assigned to the variable on the left.

#### Arithmetic

Just like JS:

`+`, `-`, `*`, `/`, `%`

Shorthand is the same too:

```C
x *= 5;
```

Increment and decrement shorthand is the same as well:

```C
x++;
x--;
```

#### Boolean Expressions

Evaluation to either `true` or `false`. All non-zero values evaluate to `true`. Zero is `false`.

**Logical** vs **relational** boolean operators. Just like JS. Evaluate to true/false.

**Logical operators**

`AND` is true if and only if **all** operands are true.

```
(x && y)
```

`OR` is true if **any** operand is true.

```
(x || y)
```

`NOT` (aka "bang") inverts the value of the operand.

**Relational operators**

* Less than (x < y)
* Less than or equal to (x <= y)
* Greater than (x > y)
* Greater than or equal to (x >= y)
* Equality (x == y)
* Inequality (x != y)
