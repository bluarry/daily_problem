filename= server client
all: $(filename)

% : %.o
	gcc -o $@ $<
%.o : %.c
	gcc -c $<

clean :
	rm -rf *.o server client
