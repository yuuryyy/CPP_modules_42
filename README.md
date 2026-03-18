# 🚀 C++ Modules (42 Network)

A comprehensive journey through Object-Oriented Programming (OOP) using **C++98**. This repository contains all the C++ modules from the core curriculum at 1337 (42 Network). 

The goal of these modules is to transition from procedural C programming to Object-Oriented C++, understanding the core philosophies of objects, memory management, polymorphism, and the Standard Template Library (STL).

---

## 📖 The Curriculum Breakdown

The track is divided into 10 modules, each progressively introducing more complex C++ concepts. 

| Module | Core Concepts Explored |
| :---: | :--- |
| **CPP 00** | Namespaces, classes, member functions, `stdio` streams, initialization lists, `static`, `const`, and basic OOP syntax. |
| **CPP 01** | Memory allocation (`new`/`delete`), pointers to members, references, and the `switch` statement. |
| **CPP 02** | Ad-hoc polymorphism, **operator overloading**, and the introduction of the Orthodox Canonical class form. |
| **CPP 03** | **Inheritance** (public, private, protected) and the diamond problem. |
| **CPP 04** | Subtype polymorphism, **virtual functions**, abstract classes, and deep interfaces. |
| **CPP 05** | Repetition, **Exceptions** (`try`, `catch`, `throw`), and custom exception classes. |
| **CPP 06** | **C++ Casts**: `static_cast`, `dynamic_cast`, `reinterpret_cast`, and `const_cast`. |
| **CPP 07** | **Templates**: Function templates and class templates for generic programming. |
| **CPP 08** | Templated containers, **Iterators**, and standard algorithms (`std::vector`, `std::list`, `std::map`, etc.). |
| **CPP 09** | **Advanced STL**: Solving complex algorithmic problems (like Reverse Polish Notation and the Ford-Johnson merge-insert sort) using specific STL containers. |

---

## 🏛️ The Orthodox Canonical Form

From **Module 02** onwards, all classes strictly adhere to the **Orthodox Canonical Form**. This requires every class to explicitly declare:
1. A default constructor.
2. A copy constructor.
3. A copy assignment operator.
4. A destructor.

This rigorous standard ensures complete control over object initialization, duplication, and destruction, preventing shallow copy bugs and memory leaks.

---

## 🛠️ Compilation & Constraints

### The Rules
* All code is compiled strictly using the **C++98 standard**.
* No standard C library functions are used where C++ alternatives exist (e.g., `<iostream>` instead of `<stdio.h>`, `std::string` instead of `char *`).
* Memory is managed strictly with `new` and `delete` (no `malloc` or `free`).
* **Zero memory leaks** are permitted.

### How to Compile

Each module (and its sub-exercises) contains its own `Makefile`. To run a specific exercise:

1. Navigate into the desired module and exercise directory:
   ```bash
   cd CPP02/ex01
   ```

2. Compile the program:
   ```bash
   make
   ```
   *(This uses `c++ -Wall -Wextra -Werror -std=c++98`)*

3. Run the generated executable:
   ```bash
   ./<executable_name>
   ```

### Makefile Rules
* `make`: Compiles the source files into the executable.
* `make clean`: Removes `.o` object files.
* `make fclean`: Removes object files and the executable.
* `make re`: Runs `fclean` followed by `make`.

---

## 🎯 Skills Acquired

* **Object-Oriented Design:** Encapsulation, abstraction, inheritance, and polymorphism.
* **Memory Management:** RAII (Resource Acquisition Is Initialization) and manual heap management in C++.
* **Generic Programming:** Writing reusable, type-safe code using templates.
* **Data Structures & Algorithms:** Mastery of the STL to solve complex problems efficiently.

---
*Developed by Youssra Chagri at 1337 (UM6P).*
