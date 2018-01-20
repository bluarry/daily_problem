filename= server
all: $(filename)

% : %.o
	gcc -o $@ $< -lsqlite3
%.o : %.c
	gcc -c $< -lsqlite3

clean :
	rm -rf *.o server client
