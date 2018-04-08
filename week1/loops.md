## Loops

Three major kinds of loops in C

#### Infinite Loops

Example:

```C
while(true)
{
  // execute forever
}
```

#### Normal `while` Loops

Repeat an unknown number of times. Example

```C
while (boolean-expression)
{
  // execute as long as boolean-expression evaluates to true
{
```

#### `do while` Loops

Executes everything inside curly braces and then checks the boolean expression. Guaranteed to run at least one time. Repeat an unknown number of times, but execute once.

```C
do
{
  // execute once, then check boolean-expression and repeat until false
}
while (boolean-expression);
```

#### `for` Loops

Repeat a discrete number of times. Looks just like JS

```C
for (int i = 0; i < 10; i++)
{
  // execute as long as i < 10
}
```
