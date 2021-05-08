main:
	g++ src/main.cpp src/controllers/AuthController.cpp src/utils/createEntryInDatabase.cpp src/utils/searchEntryInDatabase.cpp -o build/main
	./build/main

test:
	g++ src/tests/EntryDatabaseTest.cpp src/utils/createEntryInDatabase.cpp src/utils/searchEntryInDatabase.cpp -o build/test
	./build/test

cleanBuild:
	rm -rf build
	mkdir build

cleanDatabase:
	rm -rf src/database
	mkdir src/database