main.exe: main.o Student.o Date.o
	g++ -o main.exe Student.o main.o Date.o
main.o: main.cpp Student.h
	g++ -c main.cpp
Student.o: Student.cpp Student.h
	g++ -c Student.cpp
Date.o: Date.cpp Date.h
	g++ -c Date.cpp
clean:
	del -f *.o
clobber: clean
	del -f *.exe