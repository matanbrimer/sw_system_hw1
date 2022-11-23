FLAGS = -Wall -g
CC = gcc


all: recursived recursives loopd loops mains maindloop maindrec

loops:libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so



basicClassification.o: basicClassification.c NumClass.h
	$(CC) -fPIC $(FLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) -fPIC $(FLAGS) -c advancedClassificationLoop.c -lm



advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) -fPIC $(FLAGS) -c advancedClassificationRecursion.c -lm


mains: main.o libclassrec.a 
	$(CC) $(FLAGS) -o mains main.o ./libclassrec.a -lm

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so -lm


maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(CC) $(FLAGS) -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so


libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CC) $(FLAGS) -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rc libclassrec.a basicClassification.o advancedClassificationRecursion.o

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rc libclassloops.a basicClassification.o advancedClassificationLoop.o


.PHONEY: clean
clean:
	rm -f *.o *.a *.so mains maindloop maindrec