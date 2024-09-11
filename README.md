# WLP4 to MIPS Compiler

This project is a full-phase compiler that translates WLP4, a simplified C-style language, into MIPS machine code. Due to course policies, only header files are included to provide a functional overview. Full code is available upon request.

## Components

### 1. Assembler
- **Purpose**: Converts MIPS assembly code into binary machine code.
- **Functionality**: Reads MIPS assembly instructions and translates them into their binary representation.

### 2. Scanner
- **Purpose**: Tokenizes WLP4 source code.
- **Functionality**: Scans the input WLP4 code and outputs a sequence of tokens, each labeled with a type for further processing.

### 3. Parser
- **Purpose**: Constructs a parse tree from WLP4 code.
- **Functionality**: Analyzes tokens produced by the Scanner and builds a parse tree that represents the syntactic structure of the program.

### 4. Context-Sensitive Checker
- **Purpose**: Ensures the program's semantic correctness.
- **Functionality**: Checks the parse tree for context-specific errors, ensuring the code adheres to the language’s rules and conventions.

### 5. Code Generator
- **Purpose**: Converts validated WLP4 code into MIPS machine code.
- **Functionality**: Generates MIPS assembly instructions from the context-checked WLP4 code, which are then assembled into machine code by the Assembler.
