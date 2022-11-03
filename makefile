run:
	g++ -c *.cc *.cpp && g++ *.o -o stack.darss
com:
	./stack.darss
clean:
	rm *.darss
