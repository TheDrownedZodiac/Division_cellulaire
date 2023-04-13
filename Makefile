# E89 Pedagogical & Technical Lab
# project:     Makefile
# created on:  2022-11-28 - 11:34 +0100
# 1st author:  victor.vandeputte - victor.vandeputte
# description: Makefile

NAME		=	name

ARCH_NAME	=	lib$(NAME).a

SRCS		=	$(shell find src/ -name "*.c")

OBJS		=	$(SRCS:.c=.o)

NAME_TEST	=	test.out

SRCS_TEST	=	test/pipe_commands.c

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

IFLAGS		=	-Iinclude/ -Ilib/stu/include/

CFLAGS		+=	-W -Wall -Wextra $(IFLAGS)

LDFLAGS		+=

CC		:=	gcc

ARRC		:=	ar rc

ARCHFLAG	+= 	lib/stu/libstu.a $(ARCH_NAME)

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

RM		=	rm -vf

%.o: %.c
	@printf	"[\033[0;36mCompilation\033[0m]% 35s\r" $<  | tr " " "."
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mCompilé\033[0m]% 40s\n" $< | tr " " "."


all:	$(NAME)

debug:	CFLAGS	+= -g
debug:	$(NAME)

test:	$(NAME_TEST)

archive: $(ARCH_NAME)

$(NAME): $(OBJS)
	@printf "\033[5;36mObjets Compilés avec Succès!\033[0m\n"
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS) $(ARCHFLAG) -o $(NAME)
	@printf "\033[6;32mCompilation Terminée\033[0m\n"

$(ARCH_NAME):$(OBJS)
	@printf "\033[5;36mObjets Compilés avec Succès!\033[0m\n"
	$(ARRC) $(ARCH_NAME) $(OBJS)
	@printf "\033[6;36mArchive crée avec Succès!\033[0m\n"

$(NAME_TEST):$(OBJS) $(OBJS_TEST)
	@printf "\033[5;36mObjets Compilés avec Succès!\033[0m\n"
	$(CC) -o $(NAME_TEST) $(OBJS_TEST) $(OBJS) -lcriterion
	@printf "\033[6;32mTests Compilés avec Succès!\033[0m\n"

clean:
	@printf "[\033[31mSuppression\033[m][Objets]% 28d\n" `$(RM) $(OBJS) $(OBJS_TEST)| wc -l` | tr " " "."

fclean: clean
	@printf "[\033[31mSuppression\033[m][Exe]% 31s\n" '$(NAME)' | tr " " "."
	@printf "[\033[31mSuppression\033[m][Tests]% 29s\n" '$(NAME_TEST)' | tr " " "."
	@printf "[\033[31mSuppression\033[m][Archive]% 27s\n" '$(ARCH_NAME)' | tr " " "."

fc: fclean

re: fclean all


save:
	git status
	git add Makefile $(SRCS) $(SRCS_TEST) $(shell find include/ -name "*.h")
	git commit -m "$(NAME) sauvegarde du `date '+%d/%m/%Y'` à `date '+%R'`"
	git push

born:
	$(CC) test/stuborn.c $(OBJS) $(CFLAGS) -o stuborn

exe:
	make -j4 $(NAME_TEST)
	make -j4 born
	./$(NAME_TEST)
	make fclean

mclean:
	@printf "[\033[31mSuppression\033[m][Objets]% 28d\n" `$(RM) $(OBJS) $(OBJS_TEST)| wc -l` | tr " " "."
	@printf "[\033[31mSuppression\033[m][Exe]% 31s\n" '$(NAME)' | tr " " "."
	@printf "[\033[31mSuppression\033[m][Tests]% 29s\n" '$(NAME_TEST)' | tr " " "."
	@printf "[\033[31mSuppression\033[m][Archive]% 27s\n" '$(ARCH_NAME)' | tr " " "."
	@$(RM) $(OBJS) $(NAME) $(OBJS_TEST) $(shell find include/ -name "*.h~") Makefile~ $(shell find src/ -name "*.c~") $(shell find test/ -name "*.c~") $(shell find lib/stu/ -name "*.o")

.PHONY: all clean fclean re
