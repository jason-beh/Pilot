# Variables
CC = g++
CFLAGS = -std=c++11
BUILD_DIR = build
SRC_DIR = src
DATABASE_DIR = ${SRC_DIR}/database
TEST_DIR = ${SRC_DIR}/tests
TESTUNIT_DIR = ${TEST_DIR}/unit
TESTINTEGRATION_DIR = ${TEST_DIR}/integration
TESTDATA_DIR = ${TEST_DIR}/data
TESTDATAINPUT_DIR = ${TESTDATA_DIR}/inputs
TESTDATAOUTPUT_DIR = ${TESTDATA_DIR}/outputs

# Wildcard that targets ALL source files and object files
CPP_SRC = $(wildcard $(SRC_DIR)/**/*.cpp) \
		$(wildcard $(SRC_DIR)/**/**/*.cpp) \
		$(wildcard $(SRC_DIR)/**/**/**/*.cpp)
OBJ = $(CPP_SRC:.cpp=.o)

# Wildcard that target source files and object files, excluding main.cpp and all tests scripts
CPP_SRC_FILTERED := $(filter-out $(SRC_DIR)/main.cpp $(wildcard $(TESTUNIT_DIR)/*.cpp) $(wildcard $(TESTINTEGRATION_DIR)/*.cpp), $(CPP_SRC))
OBJ_FILTERED = $(CPP_SRC_FILTERED:.cpp=.o)

# Compile all individual .cpp file to .o file
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@  

# Compile main into one executablea and runs it
main: $(OBJ_FILTERED)
	$(CC) $(SRC_DIR)/main.cpp -o ${BUILD_DIR}/$@ $^
	./${BUILD_DIR}/$@

# Regression tests to run all tests and ensure all previosly implemented test cases are passed
regressionTest: unitTest integrationTest

# Unit tests to test all individual functions
unitTest: unitTestUtils unitTestPaymentMethods unitTestDriver unitTestRider unitTestAuth unitTestRide unitTestUserBalance

# Integration tests to ensure various unit tests can be integrated well together
integrationTest: testSignUpAndExit testSignUpAndTopUp testSignUpAndDrive testSignUpAndBookRide testLoginAndExit testLoginAndTopUp testLoginAndDrive testLoginAndBookRide

# Breakdown of unit tests based on category
unitTestUtils: testCreateEntryInDatabase testGenerateUserOptions testGetEntryInDatabase testGetUserLongNumberInput testGetUserNumberInput testGetUserStringInput testSplitString testUpdateEntryInDatabase   
unitTestPaymentMethods: testAccountBalancePay testCashPay testCreditCardPay testOnlineBankingPay
unitTestDriver: testDriverDrive
unitTestRider: testRiderBookRide testRiderTopUp
unitTestAuth: testLogin testSignUp
unitTestRide: testLuxuryRideUseAmenities testRideUseAmenities
unitTestUserBalance: testSetCurrentBalance testGetCurrentBalance

# Compile unit tests scripts and compare them based on expected output
testCreateEntryInDatabase testGenerateUserOptions testGetEntryInDatabase testGetUserLongNumberInput testGetUserNumberInput testGetUserStringInput testSplitString testUpdateEntryInDatabase testAccountBalancePay testCashPay testCreditCardPay testOnlineBankingPay testDriverDrive testRiderBookRide testRiderTopUp testLogin testSignUp testLuxuryRideUseAmenities testRideUseAmenities testSetCurrentBalance testGetCurrentBalance: $(OBJ_FILTERED)
	$(CC) $(CFLAGS) $(TESTUNIT_DIR)/$@.cpp -o ${BUILD_DIR}/$@ $^
	./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt | diff - ${TESTDATAOUTPUT_DIR}/$@.txt

# Compile integrations tests scripts and compare them based on expected output
testSignUpAndExit testSignUpAndTopUp testSignUpAndDrive testSignUpAndBookRide testLoginAndExit testLoginAndTopUp testLoginAndDrive testLoginAndBookRide: $(OBJ_FILTERED)
	$(CC) $(CFLAGS) $(TESTINTEGRATION_DIR)/$@.cpp -o ${BUILD_DIR}/$@ $^
	./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt | diff - ${TESTDATAOUTPUT_DIR}/$@.txt

# Clean all .o files and build folder
clean:
	rm -f ${OBJ}
	rm -rf ${BUILD_DIR}
	mkdir ${BUILD_DIR}

# Note for automatic variables: 
# $@ - the name of the target being generated
# $^ - the entire list of dependencies
# $< - the first dependency
# Refer to https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean for simplified information
