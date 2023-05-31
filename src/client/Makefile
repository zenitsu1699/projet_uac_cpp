##
## PROJECT, 2023
## BY Gérard TOUDOGUIN
## File description:
## Makefile
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


C_T	=	$(BLUE_C)
T_T	=	$(RED_C)

GREEN           =       "\033[0;32m"
TEAL            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[1;33m"

CC              =       g++


CXXFLAGS	+=	-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lGL -lGLU -lc -lm

NCNAME          =       client
NCSRC           =       $(shell find ./  -name '*.cpp')
NCOBJ           =       $(NCSRC:.cpp=.o)

all             :	title $(NCNAME)

title		:
			@$(ECHO) $(YELLOW_C)CLIENT $(DEFAULT)


$(NCNAME)         :	$(NCOBJ)
			@$(CC) -o $(NCNAME) $(NCOBJ) $(CXXFLAGS) && \
				$(ECHO) $(BOLD_T)$(GREEN_C)"[✔] "$(BLUE_C)"COMPILED:" $(DEFAULT)$(CLIC_T)$(L_GREEN) "$(NCNAME)"$(DEFAULT) || \
				$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(BLUE_C)"BUILD FAILED:" $(L_RED) "$(NCNAME)"$(DEFAULT)


.cpp.o		:
			@$(CC) $(CXXFLAGS) -c $< -g3 -o $@  && \
			 $(ECHO) $(GREEN_C)"    [OK]" $(BOLD_T)$(TEAL) $< "--->" $@ $(DEFAULT) || \
			 $(ECHO) $(RED_C)"    [KO]" $(TEAL) $^ $(DEFAULT)


clean           :
			@rm -f $(NCOBJ)

fclean          :       clean
			@rm -f $(NCNAME)
			@rm -f a.out

re              :       fclean all

.PHONY:	fclean	clean	re
