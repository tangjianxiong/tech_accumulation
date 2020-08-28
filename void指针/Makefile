SOURCE = void.c
OBJ = void.o	#将.c文件转为.o文件
INCLUDES = -I./hdr	#头文件路径


TARGET = void
CC = gcc

$(TARGET): $(OBJ)	
	$(CC) $(OBJ)  -o $(TARGET) 


.PHONY: clean
clean:
	rm -rf $(OBJ) 