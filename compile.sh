printf "\033[1;32m===== creating executable =====\n"
make
gcc main2.c libftprintf.a
printf "\n\033[1;37m===== output =====\n"
./a.out > test.txt
printf "\n\033[1;32m===== cleaning =====\n"
make fclean
rm -rf a.out
printf "\033[0m"
