# Turtle

Turtle is a **toy** "programming language" made for educational purposes. Turtle should not be used for anything more than just playing around. Any file extension works as long as the code inside is valid (though I've used `.TURT`).

## Implemented Instructions
* **OUT**: OUT _"\<string>"_ *or* OUT <number> *or* OUT <mathematical_expression>
  * example: OUT "HELLO" *or* OUT 5 *or* OUT (2+2)*3]
* **TO_BINARY**: TO_BINARY _"\<string>"_
  * info: This instruction converts the string in 8-bit binary sequences.
  * example: TO_BINARY "WORLD"
* **PARENTHESE_ENCODE**: PARENTHESE_ENCODE _"\<string>"_
  * info: This instruction encodes the string to the "Parenthese" joke cipher.
  * example: PARENTHESE_ENCODE "TEST"
* **PARENTHESE_DECODE**: PARENTHESE_DECODE _"\<string>"_
  * info: This instruction decodes the string from the "Parenthese" joke cipher.
  * example: PARENTHESE_DECODE "))))))))))))))))))))()))))()))))))))))))))))))())))))))))))))))))))("

### Note: 
Instructions are **not** case sensitive: `out` will work just as well as `OUT`.

## Usage
Run the `make` command then run the `build/output.exe` executable. Input the path of your `.TURT` (or any other extension) and press Enter. 

## Example Program
*(MAIN.TURT)*
```
OUT "HELLO WORLD"
OUT 5+5^5*(2+2)
```

## Limitations
* You cannot evaluate an expression like: `1 (1 + 1)`, you **have** to write it as `1 * (1 + 1)`.