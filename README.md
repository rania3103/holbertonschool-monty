
# Monty Bytecode Interpreter

Monty 0.98 is a scripting language that compiles into Monty bytecode files, similar to Python.
It operates using a unique stack and specific instructions for manipulating it.

The project's aim is to create an interpreter for Monty ByteCodes files. These files typically have a .m extension and consist of one instruction per line, allowing for spaces before or after the opcode and its argument:
```
Montiti@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
Montiti@ubuntu:~/monty$
```
Monty bytecode files can include blank lines, which can be entirely empty or consist only of spaces. Additionally, any text beyond the opcode or its required argument on a line is disregarded during interpretation:
```
Montiti@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
Montiti@ubuntu:~/monty$
```


## Flowchart 🚀
## Compilation 🔧
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Usage 😊
```
monty file
```
- 'file' is the path to the file containing Monty byte code
## Opcodes 📃
- ### Push
The opcode ``push`` pushes an element to the stack.

#### Usage: ``push <int>``
where <int> is an integer
- ### Pall
The opcode ``pall`` prints all the values on the stack, starting from the top of the stack.

#### Usage: ``pall``
- ### Pint
The opcode ``pint`` prints the value at the top of the stack, followed by a new line.

#### Usage: ``pint``
If the stack is empty, will print the following error message:
```
 L<line_number>: can't pint, stack empty
```
* ### Pop
The opcode ``pop`` removes the top element of the stack.

#### Usage: ``pop``
If the stack is empty, will print the following error message: 
```
L<line_number>: can't pop an empty stack
```
- ### Swap
The opcode ``swap`` swaps the top two elements of the stack.

#### Usage: ``swap``
If the stack contains less than two elements, will print the following error message:
```
L<line_number>: can't swap, stack too short
```
- ### Add
The opcode ``add`` adds the top two elements of the stack.

#### Usage: ``add``
If the stack contains less than two elements, will print the error message:
```
L<line_number>: can't add, stack too short
```
- ### Nop
The opcode ``nop`` doesn’t do anything.

#### Usage: ``nop``
## Usage example 👩‍💻
```
Montiti@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
Montiti@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
Montiti@ubuntu:~/monty$ 
```

## Authors

- [@Amal Elzowawi](https://www.github.com/amaalyy)
- [@Mariam Charrada](https://www.github.com/ariamCHARRADAM)
- [@Rania Abassi](https://www.github.com/rania3103)

