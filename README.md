# treng
Treng is an engine for performing hyperoperations, like tetration,
pentation, and so on and for forth. It comes with its own small
library for handling big numbers, see `lib/`

# What's Tetration?
Tetration is repeated exponentiation, for example $a\uparrow\uparrow{n}$
means $a^{\cdot^{\cdot^{a}}}$, where $n$ copies of $a$ are iterated
via exponentiation, for example:

| Tetration | Value |
| --------- | ----- |
| $2\uparrow\uparrow1$ | 1               |
| $2\uparrow\uparrow2$ | 4               |
| $2\uparrow\uparrow3$ | 16              |
| $2\uparrow\uparrow4$ | 65536           |
| $2\uparrow\uparrow5$ | $2\cdot10^{19728}$|


# Usage
Run `src/treng.js`, there are a few functions that you can use, see the
table below:

| Function syntax | What it does |
| --------------- | ------------ |
| `f(a,n)`        | $a\uparrow\uparrow{n}$ |
| `g(a,n)`        | $a\uparrow\uparrow\uparrow{n}$ |
| `h(a,n)`        | $a\uparrow\uparrow\uparrow\uparrow{n}$ |
