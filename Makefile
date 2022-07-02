CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=philo
SRCS=check_death.c\
	message.c\
	philosopher.c\
	routine.c
OBJS=$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
all: $(NAME)

clean:
	rm $(OBJS)

fclean:
	rm $(NAME)

.o : .c
	$(CC) -o $@ -c $< $(CFLAGS) 
