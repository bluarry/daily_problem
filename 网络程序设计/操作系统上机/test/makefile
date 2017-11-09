CC=gcc
filename=a b
all:$(filename)

%:%.o
	gcc -c %@ %<
%.o:%.c
	gcc -a %<
clean:
	rm -rf $(filename)
