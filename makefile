SRC_DIR = ./src
INC_DIR = ./inc
OUT_DIR = ./build
OBJ_DIR = $(OUT_DIR)/obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

.DEFAULT_GOAL := all
-include $(patsubst %.o,%.d,$(OBJ_FILES))

all: $(OUT_DIR)/app.elf doc

$(OUT_DIR)/app.elf: $(OBJ_FILES)
	@mkdir -p $(OUT_DIR)
	@gcc $(OBJ_FILES) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $< -I $(INC_DIR) -MMD -o $@

doc:
	@doxygen Doxyfile

clean:
	@rm -rf $(OUT_DIR)
