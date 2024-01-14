
CAST_LIB = CastLib
MATH_LIB = CastLib/MathLib

CLIENT_DRIVER = Client/src/main.cpp

CPP = g++
CPP_FLAGS = -std=c++17

INCLUDES = -I $(CAST_LIB) -I $(MATH_LIB)

BIN = bin
OUT = programOutput
OUT_IMG = programImage.ppm

main:
	$(CPP) $(CPP_FLAGS) $(INCLUDES) $(CLIENT_DRIVER) -o $(BIN)/$(OUT)
	./$(BIN)/$(OUT) > $(BIN)/$(OUT_IMG)