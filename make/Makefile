BIN_DIR = bin
SRC_DIR = src
INC_DIR = include
OBJ_DIR = $(BIN_DIR)\objs
APP_PATH = $(BIN_DIR)\app.exe

MKDIR = md
RMDIR = rd
CC = clang
CFLAGS = -std=c11 -I $(INC_DIR)

help:
	@echo Available commands:
	@echo - 'make build' to compile
	@echo - 'make clean' to clean
	@echo - 'make run' to execute app.exe

prepare : $(BIN_DIR) $(OBJ_DIR)

$(BIN_DIR) : 
	@echo Create bin directory
	@$(MKDIR) $@

$(OBJ_DIR) : 
	@echo Create obj directory
	@$(MKDIR) $@

build: prepare compile

compile:$(APP_PATH)

$(APP_PATH): $(OBJ_DIR)\main.o $(OBJ_DIR)\sum.o
	@echo Generating app.exe
	$(CC) -o $@ $^

$(OBJ_DIR)\main.o: $(SRC_DIR)\main.c
	@echo Generating main.o
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)\sum.o: $(SRC_DIR)\sum.c
	@echo Generating main.o
	$(CC) $(CFLAGS) -c -o $@ $<

clean : $(BIN_DIR)
	@echo Delete bin directory
	@$(RMDIR) /s /q $<

run: build
	cls
	@call $(APP_PATH)

.PHONY: prepare build clean compile help run