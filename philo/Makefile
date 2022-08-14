CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=philo
SRCS=abort_philo.c\
	actions.c\
	add_end_list.c\
	check_death.c\
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
	routine.c\
	start.c\
	verification.c\
	will_die.c
OBJS=$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lpthread
all: $(NAME)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.o : .c
	$(CC) -o $@ -c $< $(CFLAGS)
