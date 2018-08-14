# ft_printf

# Recoding of standard libC function printf

Regardless of the programming language considered, the printf function,(or its equivalents)
is always highly useful. The main reason is the ease of its formatting, and the
support of diverse types in variable numbers. Some variations even propose to be able to
write the resulting string of characters either in a file descriptor or in a particular stream.
Some also propose to recall this string without printing it. In short, undeniably, printf
is a vital function. 

You can find more information about printf family of functions reading it's man (type in console: man 3 printf).

## DESCRIPTION OF MY IMPLEMENTATION:

The aim of this project is to write a well-structured and easily expandable code.

Ft_printf manages 5 groups of data:
1) flags - "+", "0", "-", "+" and "space";
2) minimum field width - number that sets the output width, e.g. "10".
3) precision - always start with ".", e.g. ".5";
4) size flags - "h", "hh", "l", "ll", "j", "z".
5) conversion letter - s, S, p, D, d, i, o, O, u, U, x, X, c, C;

You can find more information in article "Secrets of “printf”" at the root of repository and also read **man**.

## HOW TO LAUNCH AND TEST:

First clone git repository (type in console):
```

git clone https://github.com/alikhtor/ft_printf.git ft_printf

```

Than go to the project folder and launch:
```

cd ft_printf

make

```

Than you can test it with your own code or use /test_files:
```

gcc test_files/main.c libftprintf.a && ./a.out

```
