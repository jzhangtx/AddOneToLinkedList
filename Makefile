AddOneToList: AddOneToList.o
	g++ -g -o AddOneToList.exe AddOneToList.o -pthread    

AddOneToList.o: AddOneToList/AddOneToList.cpp
	g++ -g  -c -pthread AddOneToList/AddOneToList.cpp
