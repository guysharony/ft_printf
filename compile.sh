printf "\033[1;32m===== creating executable =====\n"
make
gcc main.c libftprintf.a
printf "\n\033[1;37m===== output =====\n"
./a.out | less
printf "\n\033[1;32m===== cleaning =====\n"
make fclean
printf "\033[0m"
