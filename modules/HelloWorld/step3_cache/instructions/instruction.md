# Cache Exercise

## Template Cache

The SquareCache currently stores the squares as a int.  Whilst the value to be squared is used as the index into the array, there are alternative integral types.  Modify the SquareCache to be a template class which allows use of different integral types.  This will also require the MemoryPool to modified to be a template working with the same integral type.

Change the MemoryPool to be a template with type parameter for integral type and also a non-type parameter for the size of array of characters.  The non type parameter should be given a default value of 100000.

Change the SquareCache to be a template with type parameter for the integral type and also a non-type parameter for the size of the array.  Change the declaration of the MemoryPool to reflect the use of the template parameters (calculate the size required for the MemoryPool).

Change the type instantiated within the get_next member function to reflect the template type parameter.
