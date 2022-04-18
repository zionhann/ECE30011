# Priority Queue in C++ 

 ## Requirements
 * Make sure that you have installed the GCC C++ compiler and set the PATH system variable.
 * See https://code.visualstudio.com/docs/cpp/config-mingw

 ## Compilation
 * The code can be compiled with the provided makefile.
 * Just open a terminal and enter the command below.

 ```shell
    $ make (or `mingw32-make`)
 ```

 * If compiling the code manually, don't forget to include the flag `-std=c++11`.

```shell
    $ g++ -std=c++11 -c *.cpp 
    $ g++ -o main *.o
```

 ## Removing Object Files
 * If removing object files and an execution file, use
 
 ```shell
    $ make clean (or `mingw32-make clean`)
 ```

 or

```shell
    $ rm -f main *.o
 ```

 * Either way works.