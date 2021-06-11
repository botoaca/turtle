# Turtle

Turtle is a **toy** "programming language" made for educational purposes. Turtle should not be used for anything more than just playing around. Any file extension works as long as the code inside is valid (though i've used `.TURT`).

## Implemented Instructions

* **OUT**: _<arg_size>_ OUT _"\<string>"_
	* example: 5 OUT "HELLO" **(Will cause an error if the argument size is more/less than the string size)**

* **IN**: _<arg_size>_ IN
	* example: 5 IN **(It will take only the first 5 characters of your input)**

* **CALC**: 0 CALC _<first_operand>_ + _<second_operand>_
	* example: 0 CALC 5 + 5

* You can also use a **#** in the argument size spot to mark a comment.

## Usage
Run the `make` command then run the `build/output.exe` executable. Input the path of your `.TURT` (or any other extension) and press Enter. 

## Example Program
*(MAIN.TURT)*
```
0 CALC 5 + 5
5 OUT "HELLO"
5 OUT "WORLD"
```

## Limitations

* For the argument sizes, you can only use values from 0-9.
* For the functions such as the CALC function, the argument size does not matter, but shall still be present (can just be 0).
* Since the code is went through in a very simple way (without a lexer and parser), it's case-sensitive and position-sensitive.