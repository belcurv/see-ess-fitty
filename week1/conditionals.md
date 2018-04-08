## Conditional Expressions

Different ways to do branching in C. Look basically identical to JS.

#### `if`

If the boolean expression evaluates to `true`, the block executes

```C
if (boolean-expression)
{

}
```

#### `else`

Just like JS

```C
if (boolean-expression)
{

}
else
{

}
```

#### `if ... else if ...`

Just like JS. The following chain describes mutually exclusive branching.

```C
if (boolean-expression)
{

}
else if (boolean-expression)
{

}
else if (boolean-expression)
{

}
else
{

}
```

Non-mutually exclusive branching? Just remove the `else`s from the `else if`s. Possible to satisfy more than one branch. In the following, only the last `if` above the `else` has mutual exclusivity with the `else`.

if (boolean-expression)
{

}
if (boolean-expression)
{

}
if (boolean-expression)
{

}
else
{

}

#### `switch`

Just like JS

```C
int x = GetInt();
switch (x)
{
  case 1:
    printf("One\n");
    break;
  case 2:
    printf("Two\n");
    break;
  case 3:
    printf("Three\n");
    break;
  default:
    printf("Sorry\n");
}
```

#### Ternary Expressions

Looks like JS. Do we have to wrap the expression in (parens)

```C
int x = (expr) ? 5 : 6;
```
