# Cache Exercise

## Memory Pool

Currently the square values are stored directly in an array of int.  Change this array to be an array of int*.  Do not directly dynamically allocate ints for individual square values, instead placement new will be used.

Create a new class called MemoryPool.  To the MemoryPool class add data members for a pointer to character (_data) and a pointer to integer (_next).  Within the no parameter constructor allocate memory (100000 characters) and assign to the pointer to character.  Initialise the _next pointer to _data.

Add a member function ‘get_next’ returning the address of the next available integer (_next) from the array of characters.

Create a MemoryPool member for the SquareCache.  Use this MemoryPool to provide the memory for an integer for each square (using placement new).