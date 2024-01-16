# [TARGET]
NAME           					:=  minishell

# [DEBUG OPTION]
DEBUG          					:=  -fsanitize=address -g3 # basic leak test

# [COMPILATION FLAGS]
# DONG-KIM'S CLUSTER-MAC
CFLAGS        				:= -Wall -Wextra -Werror -I/Users/dong-kim/.brew/opt/readline/include #$(DEBUG)
LDFLAGS						:= -lreadline -L/Users/dong-kim/.brew/opt/readline/lib

# # DONG-KIM'S SAMSUNG-LAPTOP
# CFLAGS        					:= -Wall -Werror -Wextra $(DEBUG)
# LDFLAGS							:= -L/home/linuxbrew/.linuxbrew/Cellar/readline/8.2.1 -lreadline

# # JONGOLEE'S MACBOOK-PRO
# CFLAGS        				:= -I/usr/local/opt/readline/include #$(DEBUG)
# LDFLAGS						:= -lreadline -L/usr/local/opt/readline/lib

# # JONGOLEE'S CLUSTER-MAC
# CFLAGS        				:=  -Wall -Wextra -Werror -I/Users/jongolee/.brew/opt/readline/include #$(DEBUG)
# LDFLAGS						:= -lreadline -lncurses -L/Users/jongolee/.brew/opt/readline/lib

# CC
CC								:=  cc

# [MAINSTREAM DIR]
SRC_DIR        					:=  ./srcs/
OBJS_DIR       					:=  ./objs/
HEADER_DIR     					:=  header

# [HEADER DIR FOR ARCHIVE]
AR_HEADER_DIR   				:=  srcs/ar/header/
AR_HEADER_FILES 				:=  $(AR_HEADER_DIR)/libft.h \
									$(AR_HEADER_DIR)/ft_printf.h \
									$(AR_HEADER_DIR)/get_next_line.h

# [COLOR SETTINGS]
BLACK          					:=  \033[0;30m
RED            					:=  \033[0;31m
GREEN          					:=  \033[0;32m
GREEN_BOLD     					:=  \033[1;32m
YELLOW         					:=  \033[0;33m
BLUE           					:=  \033[0;34m
PURPLE         					:=  \033[0;35m
CYAN           					:=  \033[0;36m
WHITE          					:=  \033[0;37m
DEF_COLOR      					:=  \033[0;39m
LF             					:=  \e[1K\r

# [DELAY_TIME]
DELAY_OBJS 					:= 0
DELAY_CLEAR 				:= 0
DELAY_CLEAR2 				:= 0

# # ================================== MANDATORY PART ======================================= #

###############################################################################################
############################### [MANDATORY directory] #########################################
###############################################################################################

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #
# [HEADER FILES]
HEADER_MANDATORY_DIR			:=  $(HEADER_DIR)
# HEADER_FILES_MANDATORY			:=  $(HEADER_MANDATORY_DIR)/minishell.h
HEADER_FILES_MANDATORY			:=  $(HEADER_MANDATORY_DIR)/const_macro.h \
									$(HEADER_MANDATORY_DIR)/prototypes_execution.h \
									$(HEADER_MANDATORY_DIR)/prototypes_parse.h \
									$(HEADER_MANDATORY_DIR)/structure.h \

# [MANDATORY DEFAULT DIRECTORIES]
MANDATORY						:= $(SRC_DIR)mandatory/

# [MANDATORY DIRECTORIES]
PARSING_DIR						:= $(SRC_DIR)parse
EXEC_DIR						:= $(SRC_DIR)execution
DISPLAY_DIR						:= $(SRC_DIR)display/

#[MANDATORY SRCS FILE CLASS]
SRCS_PARSE_AST					:=	$(addprefix $(PARSING_DIR)/ast, \
									/queue/queue_1.c \
									/queue/queue_2.c \
									/ast_left.c \
									/ast_right.c \
									/ast.c \
									/main.c)

SRCS_PARSE_ERROR				:=	$(addprefix $(PARSING_DIR)/err, \
									/syntax_1.c \
									/syntax_2.c \
									/syntax_3.c \
									/syntax_4.c)

SRCS_PARSE_EXPANSION			:=	$(addprefix $(PARSING_DIR)/expansion, \
									/expansion_cmd_1.c \
									/expansion_cmd_2.c \
									/expansion_redirection.c)

SRCS_PARSE_HEAP					:=	$(addprefix $(PARSING_DIR)/heap, \
									/heap_1.c \
									/heap_2.c \
									/heap_3.c)

SRCS_PARSE_LEXER				:=	$(addprefix $(PARSING_DIR)/lexer, \
									/lexer_1.c \
									/lexer_2.c)
	
SRCS_PARSE_TOKENIZER			:=	$(addprefix $(PARSING_DIR)/tokenizer, \
									/token_array_1.c \
									/token_array_2.c)

SRCS_PARSE_UTILS				:=	$(addprefix $(PARSING_DIR)/utils, \
									/ast_utils.c \
									/here_doc_utils.c \
									/lst_dollar_1.c \
									/lst_dollar_2.c \
									/lst_env_1.c \
									/lst_env_2.c \
									/lst_export_1.c \
									/lst_export_2.c \
									/lst_redirection_1.c \
									/lst_redirection_2.c)

# [EXECUTION]
SRCS_EXEC_COMMAND 				:= 	$(addprefix $(EXEC_DIR)/command, \
									/cmd1.c \
									/cmd2.c \
									/cmd3.c \
									/cmd4.c \
									/cmd5.c \
									/cmd6.c)

SRCS_EXEC_ERROR					:= $(addprefix $(EXEC_DIR)/err, \
									/error.c )

SRCS_EXEC_FD					:= $(addprefix $(EXEC_DIR)/fd, \
									/here_doc.c \
									/here_doc2.c \
									/here_doc3.c \
									/redirection.c)

SRCS_EXEC_SIGNAL				:= $(addprefix $(EXEC_DIR)/signal, \
									/signal.c)

SRCS_EXEC_TRAVERSE				:= $(addprefix $(EXEC_DIR)/traversal, \
									/traverse_execution.c \
									/traverse_execution2.c)

SRCS_EXEC_UTILS					:= 	$(addprefix $(EXEC_DIR)/utils, \
									/utils.c \
									/utils2.c)

# [AGGREGATION OF SUB CLASSES]
SRCS_PARSE						:= 	$(SRCS_PARSE_AST) \
									$(SRCS_PARSE_ERROR) \
									$(SRCS_PARSE_EXPANSION) \
									$(SRCS_PARSE_HEAP) \
									$(SRCS_PARSE_LEXER) \
									$(SRCS_PARSE_TOKENIZER) \
									$(SRCS_PARSE_UTILS) \

SRCS_EXECUTION					:= 	$(SRCS_EXEC_COMMAND) \
									$(SRCS_EXEC_ERROR) \
									$(SRCS_EXEC_FD) \
									$(SRCS_EXEC_SIGNAL) \
									$(SRCS_EXEC_TRAVERSE) \
									$(SRCS_EXEC_UTILS)

# [AGGREGATION OF ALL MANDATORY CLASSES]
SRCS							:=	$(SRCS_PARSE) \
									$(SRCS_EXECUTION) \
									$(SRCS_DISPLAY)
									
				
# ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #

# [MANDATORY OBJS DIRECTORY]
OBJS 				    		:= $(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

##############################################################################################
##############################################################################################
##############################################################################################

# [LIBFT ARCHIVE DIRECTORY]
LIB_DIR 			   			:= ./srcs/ar/
LIB 				   			:= $(LIB_DIR)libft.a

# [PROGRESS BAR SETTING]
# [FILE DATA]
TOTAL_FILES 	        		:= $(words $(SRCS))
CURRENT_FILE 		    		:= 1

# [BAR DATA]
progress_bar                    =	printf "$(LF)$(RED)[ ♔Compiling...♔ ]$(DEF_COLOR) $(CYAN)[$(CURRENT_FILE)/$(TOTAL_FILES)]$(DEF_COLOR) [$(Yellow)%0.1f%%$(DEF_COLOR)] $(DEF_COLOR)\b" $$(echo "scale=1; ($(CURRENT_FILE) * 100) / $(TOTAL_FILES)" | bc); \
          					    	printf "$(YELLOW)[%-*s%s]$(DEF_COLOR)" 38 "$$(printf '%0.*s' $$(($$(($(CURRENT_FILE) * 38)) / $(TOTAL_FILES))) '=========================================================================')>" ""; \
   	        				    	printf "\n\033[2K$(DEF_COLOR)  ✔︎ $(CYAN)Compiling... $< $(GREEN_BOLD)[OK]$(DEF_COLOR) \033[A\033[999C\e[?25l"; \


# [MAKE ALL : MANDATORY RULE]
all: $(OBJS_DIR) $(NAME)

# [CREATING TARGET FILE + LIBFT ARCHIVE(libft.a)]
$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "\n"
	@sleep $(DELAY_CLEAR)
	@printf "$(GREEN)===============================================\n$(DEF_COLOR)"
	@printf "$(GREEN)|     🥳  [$(NAME)] compile success. 🥳    |\n$(DEF_COLOR)"
	@printf "$(GREEN)===============================================\n\n$(DEF_COLOR)"
	@printf "\e[?25h"

# [CREATING OBJECT FILES]
$(OBJS): objs/%.o: srcs/%.c $(HEADER_FILES_MANDATORY) $(AR_HEADER_FILES)
	@mkdir -p $(@D)
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -I$(HEADER_MANDATORY_DIR) -I$(AR_HEADER_DIR) -c $< -o $@
	@$(eval CURRENT_FILE := $(shell expr $(CURRENT_FILE) + 1))
	@sleep $(DELAY_OBJS)
# [CREATING OBJECT DIRECTORY]
$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

# =========================================================================================== #

# [LIBFT ARCHIVE FILE]
$(LIB): $(AR_HEADER_FILES)	
	@sleep $(DELAY_CLEAR)
	@clear
	@sleep $(DELAY_CLEAR)
	@echo "\n\t$(GREEN)MINISHELL$(DEF_COLOR) compliation has been successfully finished.\n"
	@sleep $(DELAY_CLEAR2)
	@clear
	@sleep $(DELAY_CLEAR)
	@echo "\n\t$(GREEN)LIBFT ARCHIEVE$(DEF_COLOR) compliation process begins...$(DEFAULT_COLOR)\n"
	@sleep $(DELAY_CLEAR2)
	@clear
	@sleep $(DELAY_CLEAR)
	@printf "\n$(GREEN_BOLD)LIBFT ARCHIEVE compliation in progress...$(DEFAULT_COLOR)\n\n"
	@$(MAKE) -C $(LIB_DIR) 

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJ_DIR_BONUS)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@printf "$(LF)🚧 $(Yellow)Cleaning...🚨 $(White) $(OBJ_BO) $(OBJ) \n$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@printf "$(LF)$(YELLOW)Cleanup complete.$(DEFAULT_COLOR)\n\n"
	@sleep $(DELAY_CLEAR)

# ============================================================================================= #

fclean: clean
	@printf "$(LF)🚧 $(Red)Cleaning...🚨 $(White)$(NAME)\n"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@echo "$(RED)Executable removed.$(DEFAULT_COLOR)\n"
	@echo "$(CYAN)Clearing terminal in [3 seconds]...$(DEFAULT_COLOR)"	
	@sleep $(DELAY_CLEAR2)
	@clear
	@printf "$(DEF_COLOR)"

re: fclean
	@sleep $(DELAY_CLEAR2)
	@clear
	@printf "$(PURPLE) ♻️  REBUILD  ♻️\n\n$(DEF_COLOR)"
	@$(MAKE) all

.PHONY: all clean fclean re bonus
