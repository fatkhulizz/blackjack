TARGET		:=blackjack
SRC_DIR		:= ./lib
INC_DIR		:= ./include
OBJ_DIR		:= ./build

SRC 			:= $(wildcard $(SRC_DIR)/*.cpp)
OBJ 			:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP 			:= $(OBJ:.o=.d)

CXX 			:= -g++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm
DEPFLAGS := -MMD -MP
INCLUDE  	:= -I$(INC_DIR)/

all: build $(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< $(DEPFLAGS) -o $@

$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^ $(LDFLAGS)

-include @(DEP)

.PHONY: all build clean info

build: 
	@mkdir -p $(OBJ_DIR)

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(TARGET)

info:
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJ}     "
	@echo "[*] Dependencies:    ${DEP}"
