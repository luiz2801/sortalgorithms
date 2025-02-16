CXX = g++
TARGET = teste
SRC = main.cpp

CFLAGS = $(shell python3-config --cflags)
LDFLAGS = $(shell python3-config --ldflags) -lpython3.10  # Adicione o link para a biblioteca Python

$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC) $(CFLAGS) $(LDFLAGS)














#CXX = g++
#CXXFLAGS = -I/usr/include/python3.10 -Wall -std=c++11
#LDFLAGS = -L/usr/lib/python3.10/config-3.10-x86_64-linux-gnu -L/usr/lib/x86_64-linux-gnu -lpython3.10 -lcrypt -ldl -lm
#
## Diretórios
#SRC_DIR = .
#UTILS_DIR = utils
#
## Arquivos fonte
#SRCS = $(SRC_DIR)/main.cpp \
#       $(UTILS_DIR)/loadPythonModule.cpp
#
## Arquivos objeto
#OBJS = $(SRCS:.cpp=.o)
#
## Executável
#TARGET = sortalgorithms
#
## Regras
#all: $(TARGET)
#
#$(TARGET): $(OBJS)
#	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
#
#%.o: %.cpp
#	$(CXX) $(CXXFLAGS) -c $< -o $@
#
#clean:
#	rm -f $(OBJS) $(TARGET)
#