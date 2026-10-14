# 🖥️ Pseudocode to C Compiler

## 📚 College Project

### 📌 Project Overview

The **Pseudocode to C Compiler** is a compiler design project developed as part of our college curriculum. The project converts simple pseudocode into equivalent C source code, making it easier for beginners to understand programming concepts without worrying about complex syntax.

The compiler analyses the pseudocode, validates its syntax, and generates corresponding C code that can be compiled using a standard C compiler.

---

## 🎯 Objectives

- Convert pseudocode into valid C code.
- Simplify programming for beginners.
- Demonstrate the basic concepts of compiler design.
- Improve understanding of lexical analysis, parsing, and code generation.
- Generate clean and executable C programs.

---

## ✨ Features

- Variable declaration support
- Input and output statements
- Arithmetic operations
- Assignment statements
- Conditional statements (IF–ELSE)
- Loop statements (FOR, WHILE)
- Automatic C code generation
- User-friendly interface

---

## 🛠️ Technologies Used

- **Programming Language:** C
- **IDE:** Visual Studio Code
- **Compiler:** GCC (MinGW)
- **Version Control:** Git & GitHub

---

## 📂 Project Structure

```
Pseudocode-to-C-Compiler/
│
├── .vscode/
├── src/
├── input/
├── output/
├── README.md
└── Other project files
```

---

## ⚙️ Working

1. The user writes the algorithm in pseudocode.
2. The compiler reads the input.
3. The syntax is analysed and validated.
4. The compiler converts the pseudocode into equivalent C code.
5. The generated C code can be compiled and executed using GCC.

---

## 💻 Sample Input

```
START
READ x
READ y
sum = x + y
PRINT sum
END
```

### Generated C Code

```c
#include <stdio.h>

int main() {
    int x, y, sum;

    scanf("%d", &x);
    scanf("%d", &y);

    sum = x + y;

    printf("%d", sum);

    return 0;
}
```

---

## 📖 Applications

- Learning programming fundamentals
- Teaching algorithms
- Educational compiler demonstrations
- Beginner-friendly coding environment
- Academic and research purposes

---

## 🚀 Future Enhancements

- Support for arrays and strings
- Function support
- Better syntax error reporting
- GUI-based editor
- Support for additional programming constructs
- Optimization of generated C code

---

## 👥 Team Members

- Sannidhi Shetty
- Pratiksha
- Soundaryaa R
- Palguni 

---

## 🎓 Academic Information

**Project Title:** Pseudocode to C Compiler

**Course:** Compiler Design

**Department:** Information Science and Engineering

**Institution:** Sir M Visvesvaraya Institute of Technology 

**Academic Year:** 2026–27

---

## 📄 License

This project has been developed for academic and educational purposes as part of the college curriculum.
