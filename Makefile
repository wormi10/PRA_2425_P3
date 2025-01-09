bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp
bin/testHashtable: testHashTable.cpp HashTable.h 
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp
bin/testBSTree: testBSTree.cpp BSTree.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp
bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h 
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp


remove:
	rm -rf *.o *.gch bin
