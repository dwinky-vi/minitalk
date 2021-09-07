
SRCS_SERVER	= server.c utils.c utils_s.c

SRCS_CLIENT	= client.c utils.c utils_c.c

HEADER	= head_minitalk.h

SERVER	= server

CLIENT	= client

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

OBJS_DIR =	.obj

OBJS_SERVER	= 	$(addprefix $(OBJS_DIR)/, $(patsubst %.c, %.o, $(SRCS_SERVER)))

OBJS_CLIENT	= 	$(addprefix $(OBJS_DIR)/, $(patsubst %.c, %.o, $(SRCS_CLIENT)))


all:	clean_log $(SERVER) $(CLIENT)

run:	all
		./${NAME}

$(SERVER): 	$(OBJS_SERVER)
			@printf "$(GREEN)$(BOLD)Compiling $(NO_COLOR)$(UNDER_LINE)$(BOLD)$(SERVER)$(NO_COLOR)$(BOLD)  ––  "
			@$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER) 2>>log && printf "$(LIGHT_GREEN)$(BOLD)[Success]" && rm -rf log || \
			printf "$(RED)$(BOLD)[Failure]"
			@printf "$(NO_COLOR)\n"

$(CLIENT): 	$(OBJS_CLIENT)
			@printf "$(GREEN)$(BOLD)Compiling $(NO_COLOR)$(UNDER_LINE)$(BOLD)$(CLIENT)$(NO_COLOR)$(BOLD)  ––  "
			@$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT) 2>>log && printf "$(LIGHT_GREEN)$(BOLD)[Success]" && rm -rf log || \
			printf "$(RED)$(BOLD)[Failure]"
			@printf "$(NO_COLOR)\n"

$(OBJS_DIR)/%.o:	%.c ${HEADER}
					@test -d $(OBJS_DIR) || mkdir $(OBJS_DIR)
					@printf "$(GREEN)$(BOLD)Compiling $(UNDER_LINE)$(YELLOW)$<$(NO_COLOR)  $(BOLD)–– "
					@printf "$(RED)[KO]$(NO_COLOR)"
					@$(CC) $(CFLAGS) -c $< -o $@ 2>>log && printf "\b\b\b\b$(GREEN)[OK]$(NO_COLOR)\n" || printf "\n" 

clean_log:	
			@rm -rf log

clean:		clean_log
			@rm -rf $(OBJS_SERVER)
			@rm -rf $(OBJS_CLIENT)
			@/bin/rm -rf $(OBJS_DIR)

fclean: 	clean
			@rm -rf $(SERVER)
			@printf "$(UNDER_LINE)$(BOLD)$(SERVER)$(NO_COLOR) $(LIGHT_RED)deleted$(NO_COLOR)\n"
			@rm -rf $(CLIENT)
			@printf "$(UNDER_LINE)$(BOLD)$(CLIENT)$(NO_COLOR) $(LIGHT_RED)deleted$(NO_COLOR)\n"

re: 		fclean all

################
##   COLORS   ##
################

BOLD	 	= \033[1m
NO_COLOR 	= \033[0m
UNDER_LINE	= \033[4m

BLACK	 	= \033[0;30m
RED 	 	= \033[0;31m
GREEN 	 	= \033[0;32m
BROWN 	 	= \033[0;33m
BLUE 		= \033[0;34m
PURPLE 	 	= \033[0;35m
CYAN 	 	= \033[0;36m
LIGHT_GRAY	= \033[0;37m

DARK_GRAY	= \033[1;30m
LIGHT_RED	= \033[1;31m
LIGHT_GREEN	= \033[1;32m
YELLOW 		= \033[1;33m
LIGHT_BLUE	= \033[1;34m
LIGHT_PURPLE= \033[1;35m
LIGHT_CYAN	= \033[1;36m
WHITE 		= \033[1;37m

.PHONY:	all clean fclean re
.PHONY: SRCS NAME HEADER CC CFLAGS OBJS_DIR OBJS
.PHONY: UNDER_LINE BOLD NO_COLOR BLACK RED GREEN BROWN BLUE PURPLE CYAN LIGHT_GRAY DARK_GRAY LIGHT_RED LIGHT_GREEN YELLOW LIGTH_BLUE LIGHT_PURPLE LIGHT_CYAN WHITE
