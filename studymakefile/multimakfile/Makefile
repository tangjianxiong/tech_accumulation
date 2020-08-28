NAME_APP1 = app1 
NAME_APP2 = app2 

TARGET = $(NAME_APP1) $(NAME_APP2)
SOURCE_COMMON = $(wildcard ./Common/*.c)
SOURCE_APP1 =$(SOURCE_COMMON) $(wildcard ./App1/*.c)
SOURCE_APP2 =$(SOURCE_COMMON) $(wildcard ./App2/*.c)

OBJ_APP1 = $(patsubst %.c, %.o, $(SOURCE_APP1))
OBJ_APP2 = $(patsubst %.c, %.o, $(SOURCE_APP2))

INCLUDE_COMMON = -I./Common/

CFLAGS = -Wall -c
CC = gcc

all: $(TARGET)
$(NAME_APP1):$(OBJ_APP1)
	@mkdir -p output/
	$(CC) $(OBJ_APP1) -o output/$(NAME_APP1)

$(NAME_APP2):$(OBJ_APP2)
	@mkdir -p output/
	$(CC) $(OBJ_APP2) -o output/$(NAME_APP2)

%.o: %.c 
	$(CC) $(INCLUDE_COMMON) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_APP1) $(OBJ_APP2) output/