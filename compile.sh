printf "\033[1;32m===== creating executable =====\n"
make
gcc -Wall -Werror -Wextra main.c libftprintf.a
printf "\n\033[1;37m===== output =====\n"
./a.out
printf "\n\033[1;32m===== cleaning =====\n"
make fclean
rm -rf a.out
printf "\033[0m"
