
main: main.cpp
	${CXX} -o $@ $^

clean:
	-rm -f main