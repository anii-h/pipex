# Pipex 🧵

**Pipex** is a C project from the **42 curriculum** that recreates the behavior of UNIX pipes.  
The program executes two commands with input/output redirection, simulating the shell pipeline:

```bash
< file1 cmd1 | cmd2 > file2
````

The project focuses on understanding **process creation**, **inter-process communication**, and **file descriptor management** at a low level ⚙️

---

## 🎯 Project Objectives

* Understand how UNIX pipes (`|`) work internally
* Manage multiple processes using `fork`
* Redirect standard input/output using `dup2`
* Execute commands with `execve`
* Handle errors and memory safely
* Respect the 42 Norm and project constraints

Only the **mandatory part** of the project is implemented.

---

## 🛠️ Technologies & Constraints

* **Language**: C
* **Allowed functions**:

  * `open`, `close`, `read`, `write`
  * `malloc`, `free`
  * `fork`, `pipe`, `dup`, `dup2`
  * `execve`, `wait`, `waitpid`
  * `access`, `perror`, `strerror`
* **Libft**: used
* **Memory leaks**: none
* **Norm**: compliant

---

## 📦 Installation & Cloning (SSH)

To clone the repository using **SSH**, run:

```bash
git clone git@github.com:anii-h/pipex.git
cd pipex
```

> ℹ️ Make sure your SSH key is added to your GitHub account before cloning.

---

## 🔨 Compilation

Compile the project with:

```bash
make
```

Available Makefile rules:

```bash
make        # compile the project
make clean  # remove object files
make fclean # remove object files and executable
make re     # recompile everything
```

Compiled with:

```
-Wall -Wextra -Werror
```

---

## ▶️ Usage

```bash
./pipex file1 cmd1 cmd2 file2
```

### Examples

```bash
./pipex infile "ls -l" "wc -l" outfile
```

Equivalent to:

```bash
< infile ls -l | wc -l > outfile
```

Another example:

```bash
./pipex infile "grep a1" "wc -w" outfile
```

---

## 🧠 Implementation Overview

* Two child processes are created:

  * The first reads from `file1` and writes to a pipe
  * The second reads from the pipe and writes to `file2`
* Proper handling and closing of file descriptors
* PATH resolution for command execution
* Error handling consistent with shell behavior
* Process synchronization using `waitpid`

---

## ⚠️ Known Limitations

* Commands requiring complex argument parsing (such as advanced quoting) are not fully supported due to simplified parsing logic.
* Standard command usage without advanced quoting works as expected.

This limitation does not affect the core pipe mechanism.

---

## ➕ Bonus Part

The bonus part was **not implemented**:

* Multiple pipes
* `here_doc` support

---

## 👩‍💻 Author

**Ani Hambardzumyan**
Computer Science student
American University of Armenia & 42 Yerevan
