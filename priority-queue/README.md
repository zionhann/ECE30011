 
 # Notice
 * Make sure that you have installed the GCC C++ compiler and set the PATH system variable.
 * See https://code.visualstudio.com/docs/cpp/config-mingw

 # Run
 * Enter the command below in the console.

 ```shell
    $ make (or `mingw32-make`)
    $ ./main
 ```

* You can also use the command manually.

```shell
    $ g++ -std=c++11 -c *.cpp 
    $ g++ -o main *.o
    $ ./main
```

 # Clean
 ```shell
    $ make clean (or `mingw32-make clean`)
 ```

 or

```shell
    $ rm -f main *.o
 ```
