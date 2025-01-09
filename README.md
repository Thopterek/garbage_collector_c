Here is a bare bone garbage collector for C projects
-

<img width="534" alt="Garabe Collector works" src="https://github.com/user-attachments/assets/190edd7b-d587-4142-a289-febd31193b37" />

As you can see it works and what it does is:
- keep track of all the allocations when using bin functions
- clean them all in one go and reset itself for further use


<img width="504" alt="header" src="https://github.com/user-attachments/assets/4ce9bef9-8720-4ae4-a081-d0a334b7fd9b" />

Everything is happening by using one function bin_malloc():
- its the only function needed to use the garbage collector in code
- in my bin_malloc code you can see how it allocates and cleans the memory
- the rest of the functions are just reworked libft functions that use it internally
- extra functions are not needed for functionality they are just handy to use in projects

<img width="560" alt="bin_malloc" src="https://github.com/user-attachments/assets/73e7575a-846e-4321-96cf-ab1fc0da31fc" />

This version needs to be reworked depending on the need of the project:
- scoped cleanup with flags to track the specific allocations
- debugging logging for allocations being made and/or failure
- mutexes to make it thread safe

if you find something more to be reworked or there is some basic case in which it fails: 
- option one: write me
- option two: get in contact by any means necessary
