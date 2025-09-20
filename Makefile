# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: britela- <britela-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 12:33:07 by britela-          #+#    #+#              #
#    Updated: 2025/09/20 15:36:51 by britela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf

# Program names
SERVER = server
CLIENT = client

# Sources
SRC_SERVER = server.c
SRC_CLIENT = client.c

# Libs
LIBFT_DIR   = Libft
LIBFT       = $(LIBFT_DIR)/libft.a

PRINTF_DIR  = ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

# Build rules
all: $(SERVER) $(CLIENT)

$(SERVER): $(SRC_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(SRC_SERVER) $(LIBFT) $(PRINTF)

$(CLIENT): $(SRC_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(SRC_CLIENT) $(LIBFT) $(PRINTF)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
