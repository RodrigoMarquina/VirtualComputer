# Computer Inside a Computer

A ground-up simulation of a computer built entirely in C++, starting from a single logic primitive and ending with a playable game running on top of the architecture.

## The Constraint

One primitive. One function. Everything else must be derived from it:

```cpp
bool nand(bool a, bool b) {
    return !(a && b);
}
```

No `&&`, no `||`, no `!` anywhere else in the codebase. Every logic gate, every adder, every memory cell, every CPU instruction — all of it constructed exclusively from calls to `nand()`. This mirrors how real hardware actually works. NAND is a universal gate. This is not a simplification. This is the truth.

## The Path

```
1. Logic Gates         — NOT, AND, OR, XOR built from NAND only
2. Half Adder          — First binary addition
3. Full Adder          — Addition with carry
4. ALU                 — Arithmetic Logic Unit
5. Memory              — RAM simulation, addressing, read/write
6. CPU                 — Fetch, decode, execute cycle with a simple instruction set
7. Assembly Language   — A minimal assembly-like language running on the CPU
8. Minesweeper         — A working game running on top of the architecture
```

ADD     0000
SUB     0001
NOT     0010
AND     0011
OR      0100
NAND    0101
XOR     0110
LOAD    0111
STORE   1000    
JUMP    1001
JUMPZ   1010
JUMPS   1011

Each milestone is a shippable, testable unit. Nothing moves forward until the current stage works and is understood.

## Secondary Purpose — CI/CD

This project is also a hands-on CI/CD learning exercise. Every milestone is committed to GitHub with clean, professional versioning. Build scripts will be written and automated progressively. The goal is to treat this like a real production project — not a tutorial, not a sandbox.

- Clean commits with meaningful messages
- Versioned releases per milestone (v0.1, v0.2, etc.)
- Automated build scripts added incrementally
- Eventually: a CI pipeline that builds and tests on every push

## Why

Understanding what a computer actually is — at the level of gates, memory, and instruction cycles — permanently changes how you write code. Cache misses stop being abstract. Pointer arithmetic makes physical sense. This is the foundation.


LOAD 0
ADD 1
ADD 2
STORE 0