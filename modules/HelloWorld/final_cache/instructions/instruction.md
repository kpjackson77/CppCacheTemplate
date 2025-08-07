# Cache Exercise

## Policy Based Design

In this exercise it is intended to allow the creation of Caches for different powers, by using the approach of policy based design.  Define 'policy' classes to allow computation of square or cube (all that is required for this exercise).  Whilst the plugged in policy could be used in one of another of ways, in this case use static member functions.

Define template classes 'SquarePolicy' and 'CubePolicy', with static member function 'get_power'.  The type parameter should be used for the integral type of the index to be raised to the power.

Revise the name of the cache to 'PowerCache' and introduce a new type parameter to this template class for the policy.  Use a template template parameter to implement this introduction of the policy.  Revise the name of the member function 'get_square' to 'get_power'.

In the implementation of 'get_power' function call the get_power function on the policy.