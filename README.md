# Priority Queue in C++ 

 ## Discription
 * Priority queue using min-heap structure.
   - Maximum number of elements in the queue is 30.
   - The priority value for each element is always less than or equal to its child element(min-heap property).

 ## Build Process
 * The code can be compiled with the provided makefile.

   ```shell
      $ make main
   ```

 * If compiling the code manually, enter the command below.

   ```shell
      $ g++ -o main main.cpp minheap.cpp helper.cpp
   ```

 ## Features
 * There are 5 options in the program: `I`, `D`, `C`, `P`, `Q`.
 * Each option is case-insensitive.

   ```
   *********** MENU ****************
   I : Insert new element into queue.
   D : Delete element with smallest key from queue.
   C : Decrease key of element in queue.
   P : Print out all elements in queue.
   Q : Quit

   Choose menu:
   ```
 
 * Numbers are not allowed as an option.
   
   ```
   Choose menu: 2
   Error: Invalid command '2'.
   ```

 ### Insertion
 * A key value must be numeric and it ranges from 0 to 100.

   ```
   Enter name of element: foo
   Enter key value of element: 11.8
   New element [foo, 11.8] is inserted.
   ```

 * Exception occurs when the priority value is out of range

   ```
   Error: The key value must be greater than or equal to 0.0 and less than or equal to 100.0
   ```

   or when exceeding maximum capacity of the queue(30). 

   ```
   Error: The queue is already full.
   ```

 ### Deletion
 * Delete an element which has the smallest priority value from the queue(root).

   ```
   [foo, 11.8] is deleted.
   ```
 
 * Exception occurs when there are no more elements to delete.

   ```
   Error: Elements are no longer in the queue.
   ```

 ### Changing The Value of Element
 * The queue is **not** zero-indexed. It starts with index 1 instead. 
 * Since the queue in this program is based on min-heap structure, a new key value must be less than or equal to the current key value.

   ```
   Enter index of element: 1
   Enter new key value: 10

   [foo, 10] 
   ```

 * If not, execption occurs.
 
   ```
   Enter index of element: 1 
   Enter new key value: 12
   Error: The new key value must be less than the current key value.
   ```

 ### Printing Out

   ```
   [bar, 7] [foo, 10] 
   ```