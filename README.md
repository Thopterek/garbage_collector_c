Here is an bare bone garbage collector for C projects
-

<img width="534" alt="Garabe Collector works" src="https://github.com/user-attachments/assets/190edd7b-d587-4142-a289-febd31193b37" />

The version needs to be reworked depending on the need of the project:
- scoped cleanup with flags to track the specific allocations
- debugging logging for allocations being made and/or failure
- mutexes to make it thread safe

if you find something more to be reworked or there is some edge case: Write me!
