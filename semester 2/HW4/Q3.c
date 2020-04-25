1 : the function of "realloc" is to resize memory block that was allocated before by malloc or calloc.
2 : realloc("pointer type variable", int size) 
3 : realloc returns a pointer to the newly allocated memory, or NULL if the request fails
4 : to prevent buffer over flow, limit the memory size of variable.
