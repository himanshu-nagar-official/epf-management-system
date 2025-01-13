# EPF Management System

## Description
This project is based on the idea of an **Employee Provident Fund (EPF) Management System**. The primary goal is to offer a simple, user-friendly **Salary Sheet Generator** for small organizations such as schools, colleges, and small businesses.

### Features
- **Manage Employee Data**: Add, search, modify, and delete employee information.
- **Salary Calculation**: Generate salary sheets for employees with EPF calculations (24% contribution from the employee's basic salary).
- **Single User System**: Designed for small, single-user environments.

### Target Audience
This system is intended for organizations that need a straightforward and efficient way to manage employee data, salaries, and EPF contributions. 

---

## Prerequisites

Ensure the following tools are installed on your machine:
- **C Compiler**: GCC (or TDM-GCC) for compiling the C code.
- **Windows Environment**: The project uses **Windows-specific headers** such as `<conio.h>` and `<windows.h>`. These are not compatible with non-Windows systems, but you can use alternatives for cross-platform functionality.

---

## Files Overview

### **Header Files Used**
1. **`<stdio.h>`**: Used for input and output operations (e.g., `printf()`, `scanf()`, `fopen()`).
2. **`<conio.h>`**: Provides console input/output functions (e.g., `clrscr()`, `gotoxy()`, `getch()`) which are specific to DOS/Windows systems.
3. **`<string.h>`**: Used for string operations (e.g., `strcpy()`, `strcmp()`).
4. **`<windows.h>`**: Windows-specific API functions (e.g., changing text color with `SetConsoleTextAttribute()`, controlling the console cursor with `SetConsoleCursorPosition()`).

---

## Installation & Compilation

### Step 1: Clone the repository
Clone the project repository to your local machine:
```bash
git clone https://github.com/himanshu-nagar-official/epf-management-system.git
```

### Step 2: Compile the code
Make sure the GCC compiler is installed on your system. Then, navigate to the project directory and compile the project:
```bash
gcc -o epf_management_system src/epf_management_system.c
```

### Step 3: Run the Program
After compiling, run the program:
```bash
./epf_management_system.exe
```

---

## File Structure

```
epf-management-system/
├── src/
│   └── epf_management_system.c       # Main source code
├── .gitignore                        # Git ignore rules
└── README.md                         # Project documentation
```

---

## Limitations
- The project is designed as a **single-user system**, which may not be suitable for multi-user environments.
- **Windows-specific functions** like `gotoxy()`, and `SetConsoleTextAttribute()` rely on `conio.h` and `windows.h`. These functions will not work on non-Windows platforms.
