SOURCE = thread_mutex.c
OBJ = thread_mutex.o	#将.c文件转为.o文件
INCLUDES = -I./hdr	#头文件路径


TARGET = mutex
CC = gcc

$(TARGET): $(OBJ)	
	$(CC) $(OBJ)  -o out/$(TARGET) -lpthread


.PHONY: clean
clean:
	rm -rf $(OBJ) 