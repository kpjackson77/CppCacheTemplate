# Cache Exercise

## Create Cache

The current sequence of exercises are to define and then elaborate on the principle of a cache.  For each step in the exercises only complete the minimum, as later steps will refine the code.  The tests should then pass and you can then progress on to the next step. 

Define a cache which can be used as a constant cache.  This will illustrate the principle by ‘storing’ a large number of squares.  However, these values will be calculated when required (lazy evaluation).

To the ‘SquareCache’ class add a private data member for an array of 10000 integers.  Do not worry about the 'size' being hard coded in at this moment, as this will be addressed later.

Add a constructor to initialise the array values to -1.

Add a ‘const’ member function ‘get_square’ taking an integer index.  If the square of the index is not currently with the array (that is -1), calculate the square (store with the array) and return the square.  Within this function also add some output to indicate when the square is being calculated.

If it is attempted to index beyond the size of the array, throw an 'std::out_of_range' exception.

Within the main function make use of the ‘SquareCache’ to request a number of squares and output.


