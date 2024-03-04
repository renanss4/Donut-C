# Donut-C
The famous C donut.

## Description

I have always liked the C and C++ programming languages a lot, and I have always been aware of the existence of this well-known donut in C. Following the explanation in this [video](https://youtu.be/DEqXNfs_HhY?list=PLbH3xSBlUp7VmzQHr5eOhZ4Pk4aRhOklw), I did it too.

More information in the [documentation](https://www.a1k0n.net/2011/07/20/donut-math.html).

## How to Run

> For Linux Users

1. **Install GCC (GNU Compiler Collection)**

    The `gcc` command is part of the GCC (GNU Compiler Collection), which is a set of compilers for various programming languages. GCC is commonly used for compiling C and C++ programs.

    To install GCC on Linux, you can use your distribution's package manager. For example, on Debian-based systems like Ubuntu, you can use the `apt` package manager:

    ```bash
    sudo apt install gcc
    ```

    This command will install GCC along with any necessary dependencies.

2. **Run the Code**

    After installing GCC, you can compile and execute the code using the following command:

    ```bash
    gcc -o donut donut.c -lm && ./donut
    ```

    Here's a breakdown of the command:

    - `gcc`: This invokes the GNU Compiler Collection, which is used to compile C code.

    - `-o donut`: This option specifies the output file name (`donut`) for the compiled executable. Without this option, the default output file name is `a.out`.

    - `donut.c`: This is the source code file that you want to compile.

    - `-lm`: This option links the math library (`-l`) to your program. The math library (`libm`) provides mathematical functions like `sin` and `cos` which are used in the code.

    - `&&`: This operator allows you to execute multiple commands sequentially. In this case, it ensures that the compilation (`gcc ...`) is successful before attempting to execute (`./donut`) the compiled program.

    - `./donut`: This command runs the compiled executable file named `donut`.

    Make sure you replace `donut.c` with the path to your actual source code file if it's located in a different directory.

## Note

I use it in the following way:

```bash
clear && mkdir -p compiled && gcc -o compiled/donut "/home/renan/workspace/Donut-C/donut.c" -lm && ./compiled/donut
```

This explains the .gitignore file =)

## License

This project is licensed under the [MIT License](LICENSE).
