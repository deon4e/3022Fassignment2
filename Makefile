CXX      := -c++
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/executables
TARGET   := extractor
INCLUDE  := -Iinclude/
SRC      :=                      \
   $(wildcard src/*.cpp)         \
   $(wildcard src/*.cpp)         \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES \
         := $(OBJECTS:.o=.d)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

info:
	@echo "[*] executable file directory: ${APP_DIR}     "
	@echo "[*] object directory:      ${OBJ_DIR}     "
	@echo "[*] source directory:         ${SRC}         "

run1:
	$(APP_DIR)/$(TARGET) myLargeImage.pgm -t 0 10 5000 5000 -s 640 480 -w invert invseq

run2:
	$(APP_DIR)/$(TARGET) myLargeImage.pgm -t 0 10 5000 5000 -s 640 480 -w invert invseq -w none sequence2