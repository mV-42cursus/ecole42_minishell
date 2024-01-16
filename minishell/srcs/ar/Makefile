NAME                    := libft.a
PROJECT	                := libft
CC                      := cc
# CFLAGS                  := -Wall -Wextra -Werror

SRC_DIR                 := ./srcs/
OBJ_DIR                 := ./objs/
HEADER_DIR              := header

BITMASK_DIR             := bit_mask/
LINKED_LIST_DIR         := data_structure/linked_list/
QUEUE_DIR               := data_structure/queue/
DISPLAY_DIR             := display/
ERROR_DIR               := error/
IMPLEMENTATION_DIR      := implementation/
GNL_DIR                 := $(IMPLEMENTATION_DIR)/get_next_line/
FT_PRINTF_DIR           := $(IMPLEMENTATION_DIR)/ft_printf/
IS_VERIFICATION_DIR     := is_verification/
MEMORY_DIR              := memory/
NUMERIC_DIR             := numeric/
STRING_DIR              := string/

# Colors for visual effects
BLACK                   := \033[0;30m
RED                     := \033[0;31m
GREEN                   := \033[0;32m
GREEN_BOLD              := \033[1;32m
YELLOW                  := \033[0;33m
BLUE                    := \033[0;34m
PURPLE                  := \033[0;35m
CYAN                    := \033[0;36m
WHITE                   := \033[0;37m
DEF_COLOR               := \033[0;39m
LF                      := \e[1K\r

DELAY_OBJS 	        := 0
DELAY_CLEAR 	    := 0
DELAY_CLEAR2 	    := 0

#################################################################

SRCS_BIT_MASK           :=  $(addprefix $(BITMASK_DIR), \
                            ft_is_bit_set_7.c \
                            ft_is_bit_set_8.c)

SRCS_LINKED_LIST        :=  $(addprefix $(LINKED_LIST_DIR), \
                            ft_lstadd_back.c \
                            ft_lstadd_front.c \
                            ft_lstclear.c \
                            ft_lstdelone.c \
                            ft_lstiter.c \
                            ft_lstlast.c \
                            ft_lstmap.c \
                            ft_lstnew.c \
                            ft_lstsize.c)

SRCS_QUEUE              :=  $(addprefix $(QUEUE_DIR), \
                            enqueue.c \
                            dequeue.c \
                            is_empty.c)

SRCS_DISPLAY            :=  $(addprefix $(DISPLAY_DIR), \
                            ft_putchar_fd.c \
                            ft_putendl_fd.c \
                            ft_putnbr_fd.c \
                            ft_putstr_fd.c \
						    ft_putstr.c)

SRCS_ERROR              :=  $(addprefix $(ERROR_DIR), \
                            ft_exit.c)

SRCS_GNL                :=  $(addprefix $(GNL_DIR), \
                            get_next_line.c \
                            get_next_line_utils.c)

SRCS_FT_PRINTF          :=  $(addprefix $(FT_PRINTF_DIR), \
                            ft_printf.c \
                            ft_printf_hex.c \
                            ft_printf_utils.c \
                            ft_printf_utils2.c \
                            ft_printf_utils3.c)

SRCS_IS_VERIFICATION    :=  $(addprefix $(IS_VERIFICATION_DIR), \
                            ft_isalnum.c \
                            ft_isalpha.c \
                            ft_isascii.c \
                            ft_isdigit.c \
                            ft_isprint.c)

SRCS_MEMORY             :=  $(addprefix $(MEMORY_DIR), \
                            ft_calloc.c \
                            ft_calloc_exit.c \
                            ft_memchr.c \
                            ft_memcmp.c \
                            ft_memcpy.c \
                            ft_memmove.c \
                            ft_memset.c \
                            ft_system_leaks.c)

SRCS_NUMERIC            :=  $(addprefix $(NUMERIC_DIR), \
                            ft_atoi.c \
                            ft_atoi_original.c \
                            ft_itoa.c)

SRCS_STRING             :=  $(addprefix $(STRING_DIR), \
                            ft_bzero.c \
                            ft_erase.c \
                            ft_insert.c \
                            ft_split.c \
                            ft_strchr.c \
                            ft_strcmp.c \
                            ft_strdup.c \
                            ft_striteri.c \
                            ft_strjoin_free.c \
                            ft_strjoin.c \
                            ft_strlcat.c \
                            ft_strlcpy.c \
                            ft_strlen_null.c \
                            ft_strlen.c \
                            ft_strmapi.c \
						    ft_strncmp.c \
                            ft_strnstr.c \
                            ft_strrchr.c \
                            ft_strtrim.c \
                            ft_substr.c \
                            ft_tolower.c \
                            ft_toupper.c)

SRCS                    :=  $(SRCS_BIT_MASK) \
                            $(SRCS_LINKED_LIST) \
                            $(SRCS_QUEUE) \
                            $(SRCS_DISPLAY) \
                            $(SRCS_ERROR) \
                            $(SRCS_GNL) \
                            $(SRCS_FT_PRINTF) \
                            $(SRCS_IS_VERIFICATION) \
                            $(SRCS_MEMORY) \
                            $(SRCS_NUMERIC) \
                            $(SRCS_STRING)

OBJS                    :=  $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

# Header file dependencies
HEADER_FILES            :=  $(HEADER_DIR)/libft.h \
                            $(HEADER_DIR)/get_next_line.h \
                            $(HEADER_DIR)/ft_printf.h \

TOTAL_FILES             :=  $(words $(SRCS))
CURRENT_FILE            :=  1

# [progress_bar]
progress_bar           = 		printf "$(LF)$(RED)[ ♔Compiling...♔ ]$(DEF_COLOR) $(CYAN)[$(CURRENT_FILE)/$(TOTAL_FILES)]$(DEF_COLOR) [$(Yellow)%0.1f%%$(DEF_COLOR)] $(DEF_COLOR)\b" $$(echo "scale=1; ($(CURRENT_FILE) * 100) / $(TOTAL_FILES)" | bc); \
          					    printf "$(YELLOW)[%-*s%s]$(DEF_COLOR)" 38 "$$(printf '%0.*s' $$(($$(($(CURRENT_FILE) * 38)) / $(TOTAL_FILES))) '=========================================================================')>" ""; \
   	        				    printf "\n\033[2K$(DEF_COLOR)  ✔︎ $(CYAN)Compiling... $< $(GREEN_BOLD)[OK]$(DEF_COLOR) \033[A\033[999C\e[?25l"; \

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@sleep 0.3
	@printf "\n\n\n$(GREEN)Compilation complete!$(DEFAULT_COLOR) $(GREEN_BOLD)[$(NAME)]$(GREEN) has been created.\e[?25h"
	@sleep $(DELAY_CLEAR)

#ifdef BONUS
#	@echo "$(GREEN)===============================================$(DEFAULT_COLOR)"
#	@echo "$(GREEN)|    🎉  $(PROJECT) bonus compile success.  🎉  |$(DEFAULT_COLOR)"
#	@echo "$(GREEN)===============================================$(DEFAULT_COLOR)"
#else
#	@echo
#	@echo "$(GREEN)===============================================$(DEFAULT_COLOR)"
#	@echo "$(GREEN)|      🥳  $(PROJECT) compile success. 🥳          |$(DEFAULT_COLOR)"
#	@echo "$(GREEN)===============================================$(DEFAULT_COLOR)"
#endif

$(OBJS): objs/%.o: srcs/%.c $(HEADER_FILES)
	@mkdir -p $(@D)
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@
	@$(eval CURRENT_FILE := $(shell expr $(CURRENT_FILE) + 1))
	@sleep $(DELAY_OBJS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@printf "$(LF)🚧 $(Yellow)Cleaning...🚨 $(White) $(OBJ_BO) $(OBJ) \n$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@printf "$(LF)$(YELLOW)Cleanup complete.$(DEFAULT_COLOR)\n\n"
	@sleep $(DELAY_CLEAR)

fclean:
	@make clean
	@printf "$(LF)🚧 $(Red)Cleaning...🚨 $(White)$(NAME)\n"
	@rm -f $(NAME)
	@echo "$(RED)Executable removed.$(DEFAULT_COLOR)\n"
	@echo "$(CYAN)Clearing terminal in [3 seconds]...$(DEFAULT_COLOR)"
	@sleep $(DELAY_CLEAR2)
	@clear

re:
	@sleep $(DELAY_CLEAR)
	@clear
	@make fclean
	@printf "$(PURPLE) ♻️  REBUILD  ♻️\n\n$(DEF_COLOR)"
	@$(MAKE) all

.PHONY: all clean fclean re
