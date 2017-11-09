filename = reader writer
all:$(filename)
	
% : %.o
	gcc -o $@ $<
%.o:%.c
	gcc -c $<

clean:
	rm -rf $(filename)
