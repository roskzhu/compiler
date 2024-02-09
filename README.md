# compiler

full-phase compiler that transforms WLP4, a simplified C-style language, into MIPS machine code; due to course policy, only header files are displayed for functionality overview, with complete code available upon request.

Components
Assembler
Functionality: Converts MIPS assembly code into binary machine code.
Usage: Processes assembly code written in MIPS syntax and outputs corresponding binary code.
Scanner
Functionality: Scans WLP4 code and outputs tokens with their types.
Usage: Reads WLP4 source code and breaks it down into a series of tokens, each labeled with an appropriate type for further processing.
Parser
Functionality: Parses WLP4 code to output a parse tree.
Usage: Analyzes the tokens produced by the Scanner to construct a parse tree, which represents the syntactic structure of the code.
Context-Sensitive Checker
Functionality: Checks for context-specific errors in the WLP4 code.
Usage: Performs semantic analysis on the parse tree to ensure that the code adheres to the language's rules and conventions.
Code Generator
Functionality: Converts WLP4 code into MIPS machine code.
Usage: Transforms the validated WLP4 code into MIPS assembly instructions, which are then assembled into machine code by the Assembler.
