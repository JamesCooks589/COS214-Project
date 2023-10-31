all: pizza

pizza: *.o 
	g++ $^ -o $@
	
%.o: %.cpp
	g++ -g -W -Wall -Werror -Wextra -pedantic -c $^
	
run: 
	make clean
	make
	./pizza

clean: 
	rm *.o pizza
	
	#
