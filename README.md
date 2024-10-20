# The C version of brainfuck interpretator
<div style="text-align: center; margin: 0; padding: 0;">
    <img src= "./Brainfuck.png" alt="Brainfuck logo">
    <h3> Version 1.1.0 </h3>
</div>


## Practice

<b><i>brainfuck interpretator</i></b> is reading your code on Brainfuck and shows to you a reasult of this code. The code can be readed from a file, either from a CLI (Command Line Interface), which you are using.  

For now. The application can read per one file/code at the execution. But of course you can run more than one programm simultaneously.

## This project has some arguments to run.
|short arg | full arg    | Statement |  description |
|----------|-------------|--------------|--------------|
|   --A     |  -ASCII    |        | Will out all ints as character by according of ASCII table |
|   --c     |  -Code     | Brainfuck code ||
|   --Da    |            |        | Wirtes given args|
|   --f     |  -File     |    path   ||
|   --s     |  -Space    |        |Will out all symbols/ints with spaces between them|

The arguments can't be united like in UNIX command line. 
Example: 
```
application -c -s -f          
```
### You can compile it by using Cmake with your own C compiler

### Or use MAKEFILE, which is targeted to gcc
| make function  | Description  |  
|----------------|--------------|
|make_gcc | only builds the application without running it |  
|Unix_mrun_gcc | Build and run the program in an UNIX (Linux core based) environment system |
|Windows_mrun_gcc | Build and run the program in a Windows (NT core) environment |

<sub>As gcc complier says in binnary, this program couldn't run in DOS system. On the other side, if you're reading this text, then you're definitely using something modern. At least, I hope so</sub>  