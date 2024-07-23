# treng
An engine for computing tetration, written in C++. It comes with a built-in
"big-num" library for the numbers.

## What's Tetration?
Tetration is an operation based on repeated exponentations. We will use
[Knuth's up arrow notation](https://en.wikipedia.org/wiki/Knuth%27s_up_arrow_notation)
to describe it. Tetration itself is defined as

$$
a \uparrow\uparrow n := \begin{cases}
1 & \text{if } n = 0,\\
a^{a\uparrow\uparrow{(n-1)}} & \text{if } n > 0,
\end{cases}
$$

These numbers tend to grow very fast:
|       Tetration      | Number (approx) |
| -------------------- | --------------- |
| $2\uparrow\uparrow1$ | 1               |
| $2\uparrow\uparrow2$ | 4               |
| $2\uparrow\uparrow3$ | 16              |
| $2\uparrow\uparrow4$ | 65536           |
| $2\uparrow\uparrow5$ | $2\cdot10^{19728}$|


# Compilation
This requires G++ to compile for 64-bit. You are also probably going to want
to compile this on Linux, it generates a `.so` file.
```
make -C lib/
make
```

# Usage
To be written.
