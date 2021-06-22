# Turtle

Turtle is a **toy** "programming language" made for educational purposes. Turtle should not be used for anything more than just playing around. Any file extension works as long as the code inside is valid (though I've used `.TURT`).

## Implemented Instructions
* **CLEAR**: CLEAR
  * info: This instruction clears the screen.
  * example: CLEAR

* **OUT**: OUT _"\<string>"_ *or* OUT  _"\<number>"_ *or* OUT _<mathematical_expression>_
  * info: This instruction prints to the screen.
  * example: OUT "HELLO" *or* OUT 5 *or* OUT (2+2)*3

* **IN**: IN _"\<string>"_ _\<variable>_
  * info: This instruction prints a string to the screen then waits for input and stores it to a variable.
  * example: IN "What is your name?" @name

* **TO_BINARY**: TO_BINARY _"\<string>"_
  * info: This instruction converts the string in 8-bit binary sequences.
  * example: TO_BINARY "WORLD"

* **PARENTHESE_ENCODE**: PARENTHESE_ENCODE _"\<string>"_
  * info: This instruction encodes the string to the "Parenthese" joke cipher.
  * example: PARENTHESE_ENCODE "TEST"

* **PARENTHESE_DECODE**: PARENTHESE_DECODE _"\<string>"_
  * info: This instruction decodes the string from the "Parenthese" joke cipher.
  * example: PARENTHESE_DECODE "))))))))))))))))))))()))))()))))))))))))))))))())))))))))))))))))))("

## Variables
Declaration example: `@variable <string>` *or* `@variable <number>` *or* `@variable <mathematical_expression>`
You can also declare a variable's value as another variable:

*TEST.TURT*
```
@str = "hello world"
@str_copy = @str
out @str_copy
```

## If Statements
Syntax:

*IF.TURT*
```
if 1 is 1 then
  out "it was 1!"
endif
```

### Note: 
Instructions are **not** case sensitive: `out` will work just as well as `OUT`.

## Usage
Run the `make` command then run the `build/output.exe` executable. Input the path of your `.TURT` (or any other extension) and press Enter.

## Command Line Arguments
You can use a command such as `build/output.exe main.turt` to give a code file path. If no arguments are given, the program will ask you for a path.

## Example Program
*(MAIN.TURT)*
```
out "hello world"
out 5+5^5*(2+2)
```

## Limitations
* You cannot evaluate an expression like: `1 (1 + 1)`, you **have** to write it as `1 * (1 + 1)`.