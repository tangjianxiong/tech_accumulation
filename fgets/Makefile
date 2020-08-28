SOURCE = stringio.c
obj= stringio.o

TARGET = stringio
CC= gcc

$(TARGET): $(obj)
	@mkdir	-p output/
	$(CC) $(obj) -o output/$(TARGET)

.PHONY:clean
clean:
	rm -rf $(obj) 