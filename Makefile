main:
	g++ src/main.cpp src/controllers/AuthController.cpp src/utils/countdownTimer.cpp src/utils/generateUserOptions.cpp src/utils/getUserNumberInput.cpp src/controllers/RiderController.cpp src/utils/createEntryInDatabase.cpp src/utils/searchEntryInDatabase.cpp  src/classes/User.cpp src/classes/Driver.cpp src/classes/Rider.cpp src/classes/PaymentMethod.cpp src/classes/CreditCard.cpp src/classes/OnlineBanking.cpp src/classes/Cash.cpp src/classes/Auth.cpp -o build/main
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