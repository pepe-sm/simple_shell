# SIMPLE SHELL (collaboration Edwin and Stephen)

![Screenshot (30)](https://github.com/pepe-sm/simple_shell/assets/52682563/b8632583-9a67-4910-9cfb-41cc153fb38f)

# Details.

our simple shell tries to answer upto 100 of alx simple_shell project



it in the main 
on entry it uses getline function to allow input.

( it checks using the isatty to check if its from terminal or within project)


upon this clarification if its intaractive or non-interactive
it checks for EOF condition(ctrl + D) if this is met. it prints new line and exits

it also uses strcmp to check if command entered is exit. 
if it is exit then breaks from loop 

it checks for path and if path is a directory it tokenizes path and uses builtin path to verfy
if not path it frees directory.

it then tokenizes the string available
checks for path 
and executes using execve which acts as the core of our project.

#HOW IT WORKS
compiled using 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


it works in both interactive and non interactive mode

#non_interactive
echo "ls -la" | ./hsh

#Interactive
./hsh
ls -la

both will give you a sorted list, that entails even hidden files.

#VIDEO OF PROJECT


https://github.com/pepe-sm/simple_shell/assets/52682563/0d6cd18f-9315-4648-89d7-b3e68dad2a06



