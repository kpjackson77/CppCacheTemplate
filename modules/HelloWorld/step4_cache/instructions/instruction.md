# Cache Exercise

## Shared_ptr

Change the cache to use smart pointers rather than raw pointers (#include <memory>).

Modify the array to be an array of shared pointers to integral type (shared_ptr).

Within the ‘get_square’ method create a shared pointer for the address obtained for the square.  However, use the overload of shared_ptr to allow providing a ‘deleter’.  The deleter should do nothing.

