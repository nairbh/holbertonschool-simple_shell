<p align="center">
  <img src="https://user-images.githubusercontent.com/124582867/229380110-7673c718-e712-4ac6-aa56-c816d5535188.png">
</p>
<h1> C - Simple Shell</h1></p>

<h2> Context of the project</h2></p>

This project is the second group project of our term. We had to create a simple shell.
Our team during this project, my partner and I (our heads during our 2 intense weeks):

![C2E74F96-5A97-487E-9487-DF08811B1B9D](https://user-images.githubusercontent.com/124582867/233963334-d393c9a9-bb2f-4c08-ba4f-8e26ed6c9762.JPG)

<h2> Tasks</h2></p>

<h3> 0. README, man, AUTHORS</h3>

- Write a README
- Write a man for your shell.
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

<h3> 1. Betty would be proud</h3>

- Write a beautiful code that passes the Betty checks

<h3> 2. Simple shell 0.1</h3>

Write a UNIX command line interpreter.
- Usage: simple_shell

Your Shell should:
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:
- use the PATH
- implement built-ins
- handle special characters : ", ', `, \, *, &, #
- be able to move the cursor
- handle commands with arguments
- execve will be the core part of your Shell, don’t forget to pass the environ to it…

```
julien@ubuntu:~/shell$ ./shell 
#cisfun$ ls
./shell: No such file or directory
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#cisfun$ exit
./shell: No such file or directory
#cisfun$ ^C
julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ julien@ubuntu:~/shell$
```

<h3> 3. Simple shell 0.2</h3>

Simple shell 0.1 +
- Handle command lines with arguments

<h3> 4. Simple shell 0.3</h3>

Simple shell 0.2 +
- Handle the PATH
- fork must not be called if the command doesn’t exist

```
julien@ubuntu:~/shell$ ./shell_0.3
:) /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls -l /tmp 
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
:) ^C
julien@ubuntu:~/shell$ 
```

<h3> 5. Simple shell 0.4</h3>

Simple shell 0.3 +
- Implement the exit built-in, that exits the shell
- Usage: exit
- You don’t have to handle any argument to the built-in exit

<h3> 6. Simple shell 1.0</h3>

Simple shell 0.4 +
- Implement the env built-in, that prints the current environment

```
julien@ubuntu:~/shell$ ./simple_shell
$ env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$ exit
julien@ubuntu:~/shell$ 
```

<h2> Description </h2></p>

Shell is a program that receives computer commands given by a user from his keyboard to send them to the operating system which will execute them.

<h2> Compilation</h2></p>

Your shell will be compiled this way:

```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```

<h2> Testing</h2></p>

Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
<h2> Flowchart</h2></p>

![Flowchart](https://user-images.githubusercontent.com/124582867/234859580-4af92cc9-1063-42c5-8a45-e66bdd7fc66a.jpg)

<h3>Authors</h3>

Houcine Nair Benrokia - [@nairbh](https://github.com/nairbh)<br>

Nicolas De Sousa - [@Nico-dsa](https://github.com/Nico-dsa)<br> 

