# Version
ver0.1 only simple quoting system is allowed.

# Features
* only simple commands is allowed.
```bash
$./pipex infile cmd1 cmd2 /dev/stdout
```
* no pipeline, list, compound commands, function definition according to bash syntax are allowed.
* following syntax is **not** supported [✗]
```bash
# pipeline as cmd
$./pipex infile cat "cat|cat" /dev/stdout
# list as cmd
$./pipex infile cat "cd ..; ls" /dev/stdout
# compound commands as cmd
$./pipex infile cat "{ cd ..; ls; }" /dev/stdout
```

# Requirement
* the c compiler `gcc`

# Installation
* `apt install gcc` or `brew install gcc`
 
# Usage
```bash
git clone https://github.com/alex216/ft_pipex
cd ft_pipex
make
./pipex infile cat | ls /dev/stdout
```
 
# License
* this code is under [MIT license](https://en.wikipedia.org/wiki/MIT_License).
