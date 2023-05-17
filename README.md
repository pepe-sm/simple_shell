In this repository we will be handling simple shell, I have said we because it is a collaboration between two people, Edwin Kamau and Stephen Mburu

The shell should be compiled this way: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

The shell should work like this in interactive mode:

$ ./hsh ($) /bin/ls hsh main.c shell.c ($) ($) exit $

But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh hsh main.c shell.c test_ls_2 $ $ cat test_ls_2 /bin/ls /bin/ls $ $ cat test_ls_2 | ./hsh hsh main.c shell.c test_ls_2 hsh main.c shell.c test_ls_2 $

OUTPUT

program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

Example of error with sh:

$ echo "qwerty" | /bin/sh /bin/sh: 1: qwerty: not found $ echo "qwerty" | /bin/../bin/sh /bin/../bin/sh: 1: qwerty: not found $

Same error with my program hsh:

$ echo "qwerty" | ./hsh ./hsh: 1: qwerty: not found $ echo "qwerty" | ./././hsh ./././hsh: 1: qwerty: not found $

