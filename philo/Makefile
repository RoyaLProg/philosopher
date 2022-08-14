CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=philo
SRCS=abort_philo.c\
	actions.c\
	add_end_list.c\
	check_death.c\
	check_forks.c\
	end.c\
	finish.c\
	ft_atollu.c\
	ft_atolu.c\
	ft_error.c\
	ft_isdigit.c\
	ft_malloc.c\
	ft_strlen.c\
	get_time.c\
	initialisations.c\
	is_all_digit.c\
	is_end.c\
	message.c\
	philosopher.c\
	release_forks.c\
	routine.c\
	start.c\
	verification.c\
	will_die.c
OBJS=$(SRCS:.c=.o)
ifneq (,$(findstring xterm,${TERM}))
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	RESET := $(shell tput -Txterm sgr0)
else
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	PURPLE       := ""
	BLUE         := ""
	RESET        := ""
endif
TITLE="\n $(BLUE)██████  ██   ██ ██ ██       ██████  ███████  ██████  ██████  ██   ██ ███████ ██████  \n"\
	"$(BLUE)██   ██ ██   ██ ██ ██      ██    ██ ██      ██    ██ ██   ██ ██   ██ ██      ██   ██ \n"\
	"$(BLUE)██████  ███████ ██ ██      ██    ██ ███████ ██    ██ ██████  ███████ █████   ██████  \n"\
	"$(BLUE)██      ██   ██ ██ ██      ██    ██      ██ ██    ██ ██      ██   ██ ██      ██   ██\n"\
	"$(BLUE)██      ██   ██ ██ ███████  ██████  ███████  ██████  ██      ██   ██ ███████ ██   ██\n"\
	"\n\n $(PURPLE)ᐅ $(YELLOW)Making something like $(GREEN)philosopher $(YELLOW)or a shitty thing $(RED)(╯°□°)╯︵ ┻━┻ $(RESET)\n\n"

.SILENT:

$(NAME): title $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lpthread
all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.o : .c
	$(CC) -o $@ -c $< $(CFLAGS)

title:clear
	echo $(TITLE)

clear:
	clear
