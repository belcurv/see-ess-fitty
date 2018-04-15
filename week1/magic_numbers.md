# Magic Numbers

Some of the programs we've written have oddly specific numbers thrown in them. The height of Mario's pyramid, for example, was capped at 23. What do those numbers mean? If someone looks at your program, is the meaning of 23 immediately obvious? Directly writing constants into our code is sometimes referred to as using **magic numbers**. This is usually seen as bad practice.

We might have multiple functions in multiple separate files that each have to deal with some _thing_. In cases like this, hardcoding a magic number is a bad idea. For example, `52` in this pseudocode:

```
card deal_cards(deck name)
{
  for (int i = 0; i < 52; i++)
  {
    // deal the card
  }
}
```

What does 52 mean? We can give it symbolic meaning thusly:

```
card deal_cards(deck name)
{
  int deck_size = 52;
  for (int i = 0; i < deck_size; i++)
  {
    // deal the card
  }
}
```

That fixes one problem but introduces another. Even if globally declared, what if some other function in our suite manipulates `deck_size`?

## Macros

We've already seen/used one **preprocessor directive** (also called a **macro**): `#include`. C provides another preprocessor directive for creating symbolic constants: `#define`

```C
#define NAME REPLACEMENT
```

During compile, `#define` goes through you code and replaces `NAME` with `REPLACEMENT`. Think of it like find/replace. Importantly, **you can't manipulate a constant**.

Note: don't put semicolon after `#define`s!

Ex.

```C
#define PI 3.14159265
#define COURSE "CS50"
```

At compile time, compiler will go through and replace `PI` with `3.14159265`.

Why all caps? By convention. Makes it really clear that this particular element of our code is a defined constant.

**Solution**

```
#define DECKSIZE 52

card deal_cards(deck name)
{
  for (int i = 0; i < DECKSIZE; i++)
  {
    // deal the card
  }
}
```
