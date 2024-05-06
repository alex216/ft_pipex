# [done]accept argc and argv
# echo "## test1"
# ans=`./pipex "hello" "world"`
# echo $ans

# test 0 done using execve
# echo "## test 0"
# ans=`echo "## test2"`
# ./pipex ls -l
# echo $ans

# # test 1 done using fork pipefd
# ./pipex "/bin/ls" "/usr/bin/wc"
#
# # # test 2 done
echo "## test 2"
./pipex infile "/bin/ls" "/usr/bin/wc" /dev/stdout

# # test 3 done use malloc split
echo "## test 3"
./pipex infile "/bin/ls -l" "/usr/bin/wc -l" /dev/stdout

# # errortest
 # test 6 no read permission according to cursus pdf output is as follows
echo ''
echo '## test 6 ##' && rm -rf infile outfile && touch infile outfile
echo 'a1\n a1\n aaa\n' > infile
chmod u-r infile
printf '[system]bash: infile: Permission denied\n[answer]'
./pipex infile "grep a1" "wc -l" outfile
echo ''

# # test 7 no infile done according to cursus pdf, output is as follows
echo '## test 7 ##' && rm -rf infile outfile && touch infile outfile
echo 'a1\n a1\n aaa\n' > infile
rm infile
printf "[system]bash: infile: No such file or directory\n[answer]"
./pipex infile "grep a1" "wc -l" outfile
echo ''

# # test 8 no outfile
echo '## test 8 no outfile##'
rm -rf infile outfile
touch infile outfile
echo 'a1\n a1\n aaa\n' > infile
rm outfile
printf "[system]"
< infile grep a1 | wc -l > outfile && cat outfile
rm outfile
printf "[answer]"
./pipex infile "grep a1" "wc -l" outfile && cat outfile
echo ''
#
echo "## test 9 outfile can't read ##"
rm -rf infile outfile
touch infile outfile
printf "[system]"
echo 'a1\n a1\n aaa\n' > infile
chmod u-r outfile
< infile grep a1 | wc -l > outfile && cat outfile
printf "[answer]"
./pipex infile "grep a1" "wc -l" outfile && cat outfile
echo ''
#

echo "## test 9-1 outfile can't write ## (exit status: 1)"
rm -rf infile outfile && touch infile outfile
echo 'a1\n a1\n aaa\n' > infile
chmod u-w outfile
printf "[system]bash: outfile: Permission denied\n[answer]"
./pipex infile "grep a1" "wc -l" outfile && cat outfile
echo $?
echo ''

echo "## test 10 outfile already exists"
rm -rf infile outfile
touch infile outfile
echo 'a1\n a1\n aaa\n' > infile
echo 'a1\n a1\n aaa\n' > outfile
printf "[system]"
< infile grep a1 | wc -l > outfile && cat outfile
echo 'a1\n a1\n aaa\n' > outfile
printf "[answer]"
./pipex infile "grep a1" "wc -l" outfile && cat outfile
echo ''

echo "## test 11 invalid cmd1 (exit status: 0)" && rm -rf infile outfile && touch infile outfile
printf "[system]bash: cmd42: command not found\n[answer]"
./pipex infile "cmd42" "ls" outfile
echo $?
echo ''
#
echo "## test 12 invalid cmd2 (exit status: 127)" && rm -rf infile outfile && touch infile outfile
printf "[system]bash: cmd42: command not found\n[answer]"
./pipex infile "ls" "cmd42" outfile
echo $?
echo ''
#
echo "## test 13 invalid both cmd1 cmd2 (exit status: 127)" && rm -rf infile outfile && touch infile outfile
printf "[system]\nbash: cmd42: command not found\nbash: cmd41: command not found\n[answer]\n"
./pipex infile "cmd41" "cmd42" outfile
echo $?
echo ''

echo "## test 14 (#18)invalid /bin/cmd41 with absolute path(exit status: 0)" && rm -rf infile outfile && touch infile outfile
printf "[system]bash: /bin/cmd41: No such file or directory\n[answer]"
./pipex infile "/bin/cmd41" "wc" outfile
echo $?
echo ''
#
echo "## test 15 (#18)invalid /bin/cmd42 with absolute path(exit status: 127)" && rm -rf infile outfile && touch infile outfile
printf "[system]\nbash: /bin/cmd42: No such file or directory\n[answer]\n"
./pipex infile "ls" "/bin/cmd42" outfile
echo $?
echo ''
#
echo "## test 16 (#18)invalid /bin/cmd41 /bin/cmd42 with absolute path(exit status: 127)" && rm -rf infile outfile && touch infile outfile
printf "[system]\nbash: /bin/cmd41: No such file or directory\nbash: /bin/cmd42: No such file or directory\n[answer]\n"
./pipex infile "/bin/cmd41" "/bin/cmd42" outfile
echo $?
echo ''

echo "## test 17 (#13) echo 'hello world'(exit status: 0)" && rm -rf infile outfile && touch infile outfile
touch 'file whitespace' && echo "hello-single-quote" > 'file whitespace'
printf "[system]hello-single-quote\n[answer]"
./pipex infile "ls" "cat 'file whitespace'" outfile && cat outfile
echo $?
echo ''

echo "## test 18 (#13) echo \"hello world\"(exit status: 0)" && rm -rf infile outfile && touch infile outfile
touch 'file whitespace' && echo "hello-double-quote" > 'file whitespace'
printf "[system]hello-double-quote\n[answer]"
./pipex infile "ls" "cat 'file whitespace'" outfile && cat outfile
echo $?
echo ''

echo "## test 19 (#13) awk with \" \'(exit status: 0)" && rm -rf infile outfile && touch infile outfile
touch 'file whitespace' && echo "hello-world" > 'file whitespace'
printf "[system]This is a double quote: \".\n[answer]"
./pipex infile ls "awk 'BEGIN {print \"This is a double quote: \\\".\"}'" outfile && cat outfile
echo $?
echo ''

echo "## test 20 shell script no execute permission"&& rm -rf infile outfile && touch infile outfile script.sh
echo "#!/bin/bash\nls" > script.sh
chmod u-x script.sh
printf "[system]bash: ./script.sh: Permission denied\n[answer]"
./pipex infile ls "./script.sh" outfile
echo $?
echo ''

echo "## test 21 (exit status: 0)" && rm -rf infile outfile && touch infile outfile
echo "./pipex \"ls -l\" \"wc -l\" /dev/stdout"
printf "[system]\n"
ls -l | wc -l
printf "[answer]\n"
./pipex infile "ls -l" "wc -l" /dev/stdout

echo "## test 22 (exit status: 0)" && rm -rf infile outfile && touch infile outfile
echo "./pipex \"whoami\" \"grep yliu\" \"wc -l\" /dev/stdout"
printf "[system]\n"
printf "       1"
printf "\n[answer]\n"
./pipex infile "whoami" "grep yliu" "wc -l" /dev/stdout

echo "## test 23 (#30) (exit status: 0)" && rm -rf infile outfile && touch infile outfile
echo "./pipex \"ifconfig -a\" \"grep ether\" \"wc -l\" \"bc\" /dev/stdout"
printf "[system]\n"
printf "11"
printf "\n[answer]\n"
./pipex infile "ifconfig -a" "grep ether" "wc -l" "bc" /dev/stdout

# echo "## test bonus ls x 200?"
# ./pipex infile  "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls" "ls"  outfile
# test
#all kinds of sys call error pattern
