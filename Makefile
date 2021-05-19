# Variables
CC = g++
CFLAGS = -std=c++11
BUILD_DIR = build
SRC_DIR = src
DATABASE_DIR = ${SRC_DIR}/database
TEST_DIR = ${SRC_DIR}/tests
TESTDATA_DIR = ${TEST_DIR}/data
TESTDATAINPUT_DIR = ${TESTDATA_DIR}/inputs
TESTDATAOUTPUT_DIR = ${TESTDATA_DIR}/outputs

# Wildcard source files to get all cpp files
CPP_SRC = $(wildcard $(SRC_DIR)/**/*.cpp) \
		$(wildcard $(SRC_DIR)/**/**/*.cpp) \
		$(wildcard $(SRC_DIR)/**/**/**/*.cpp)

CPP_SRC_FILTERED := $(filter-out $(SRC_DIR)/main.cpp $(wildcard $(TEST_DIR)/*.cpp), $(CPP_SRC))
OBJ_FILTERED = $(CPP_SRC_FILTERED:.cpp=.o)

OBJ = $(CPP_SRC:.cpp=.o)

# Compile all individual .cpp file to .o file
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@  

# Compile main into one executable
main: $(OBJ_FILTERED)
	$(CC) $(SRC_DIR)/main.cpp -o ${BUILD_DIR}/$@ $^
	./${BUILD_DIR}/$@

allTests: test testGetUserNumberInput testGetUserLongNumberInput testGenerateUserOptions

test: $(OBJ_FILTERED)
	$(CC) $(TEST_DIR)/$@.cpp -o ${BUILD_DIR}/$@ $^
	./${BUILD_DIR}/$@

testGetUserNumberInput: $(OBJ_FILTERED)
	$(CC) $(TEST_DIR)/$@.cpp -o ${BUILD_DIR}/$@ $^
	# ./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt > ${TESTDATAOUTPUT_DIR}/$@.txt
	./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt | diff - ${TESTDATAOUTPUT_DIR}/$@.txt

testGetUserLongNumberInput: $(OBJ_FILTERED)
	$(CC) $(TEST_DIR)/$@.cpp -o ${BUILD_DIR}/$@ $^
	# ./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt > ${TESTDATAOUTPUT_DIR}/$@.txt
	./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt | diff - ${TESTDATAOUTPUT_DIR}/$@.txt

testGenerateUserOptions: $(OBJ_FILTERED)
	$(CC) $(TEST_DIR)/$@.cpp -o ${BUILD_DIR}/$@ $^
	# ./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt > ${TESTDATAOUTPUT_DIR}/$@.txt
	./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt | diff - ${TESTDATAOUTPUT_DIR}/$@.txt

testLogin: $(OBJ_FILTERED)
	$(CC) $(TEST_DIR)/$@.cpp -o ${BUILD_DIR}/$@ $^
	./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt | diff - ${TESTDATAOUTPUT_DIR}/$@.txt

testSignUp: $(OBJ_FILTERED)
	$(CC) $(TEST_DIR)/$@.cpp -o ${BUILD_DIR}/$@ $^
	./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt | diff - ${TESTDATAOUTPUT_DIR}/$@.txt

testOnlineBankingPay: $(OBJ_FILTERED)
	$(CC) $(TEST_DIR)/$@.cpp -o ${BUILD_DIR}/$@ $^
	/${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt | diff - ${TESTDATAOUTPUT_DIR}/$@.txt

testCreditCardPay: $(OBJ_FILTERED)
	$(CC) $(TEST_DIR)/$@.cpp -o ${BUILD_DIR}/$@ $^
	./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt > ${TESTDATAOUTPUT_DIR}/$@.txt
	# ./${BUILD_DIR}/$@ < ${TESTDATAINPUT_DIR}/$@.txt | diff - ${TESTDATAOUTPUT_DIR}/$@.txt

# Clean all .o files and build folder
clean:
	rm -f ${OBJ}
	rm -rf ${BUILD_DIR}
	mkdir ${BUILD_DIR}

cleanDatabase:
	rm -rf ${DATABASE_DIR}
	mkdir ${DATABASE_DIR}