# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 01:29:57 by caeduard          #+#    #+#              #
#    Updated: 2023/10/27 02:04:49 by caeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = .
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(wildcard $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

EXECUTABLE = rpn

.PHONY: all clean fclean re

all: $(BUILD_DIR) $(EXECUTABLE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all
