Style
=====
- Use the clang format in project root to automatically format your code
- However, since the clang format isn't perfect, here's some general formatting stuff:
- For the C code, avoid the use of typedefs. For C++, you can't really avoid them
- For array initalizers, add a space between the curly brace and the values
- For struct initalizers, format it like this:
```c
    struct some_struct some_struct = {
        .a = 0, .b = 0, .c = 0,
        .d = 0, .e = 0, .f = 0
    };

    // OR

    struct some_struct some_struct = {
        .a = 0, 
        .b = 0, 
        .c = 0
    };

    // OR

    struct some_struct some_struct = { .a = 0, .b = 0, .c = 0 };
```
- Just pick whatever one is more readable depending on the situation