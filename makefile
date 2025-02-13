CXX = g++
TARGET = teste
SRC = main.cpp

CFLAGS = $(shell python3-config --cflags)
LDFLAGS = $(shell python3-config --ldflags) -lpython3.10  # Adicione o link para a biblioteca Python

$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC) $(CFLAGS) $(LDFLAGS)
