##
## EPITECH PROJECT, 2019
## my_makefile
## File description:
## makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
CLIC_T	=	"\e[5m"
RED_C	=	"\e[31m"
L_RED	=	"\e[91m"
BLUE_C	=	"\e[34m"
L_BLUE	=	"\e[94m"
GREEN_C	=	"\e[32m"
L_GREEN	=	"\e[92m"
PURPLE_C	=	"\e[35m"
YELLOW_C	=	"\e[33m"
TEAL	=	"\033[36m"

BLUE	=	"\e[34m"

C_T	=	$(BLUE_C)
T_T	=	$(RED_C)



CLIENT_DIR	=	./src/client


SERVER_DIR	=	./src/server

############################## Creation des binaires et le reste des regles #########################################


all:
	@make all --no-print-directory -C $(CLIENT_DIR)
	# @make all --no-print-directory -C $(SERVER_DIR)
	@cp $(CLIENT_DIR)/client .



clean:
	@make clean --no-print-directory -C $(CLIENT_DIR)
	# @make clean --no-print-directory -C $(SERVER_DIR)
	@$(ECHO) $(RED_C)$(BOLD_T)"[clean core]  "$(DEFAULT) \
		$(RED_C)"Deleted all object, valgrind and temporals files"$(DEFAULT)


fclean:
	@make fclean --no-print-directory -C $(CLIENT_DIR)
	# @make fclean --no-print-directory -C $(SERVER_DIR)
	@rm -rf client
	@$(ECHO) $(RED_C)$(BOLD_T)"[clean core]  "$(DEFAULT) \
		$(RED_C)"Deleted all object, valgrind and temporals files"$(DEFAULT)
	@$(ECHO) $(RED_C)$(BOLD_T)"[fclean core] "$(DEFAULT) \
		$(RED_C)"Deleted all binaries and a.out"$(DEFAULT)


re:	fclean all

.PHONY:	fclean	clean	re