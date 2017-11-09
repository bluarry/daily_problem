filename= method1 method2 method3
all:$(filename)

%:%.o
	gcc -o $@ $<
%.o:%.c
	gcc -c $<

clean:
	rm -rf $(filename);
