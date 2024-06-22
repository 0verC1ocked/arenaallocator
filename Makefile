.PHONY: clean debug release

BUILD_DIR := ./build
OBJ_DIR := $(BUILD_DIR)/obj
SRC_DIR := ./src
INC_DIR := ./inc
LIBS := -lprotobuf

TARGET := libarenaallocator.a

HEADERS := $(shell find $(INC_DIR) -name '*.h' -or -name '*.hpp')
SRCS := $(shell find $(SRC_DIR) -name '*.cpp' -or -name '*.c' -or -name "*.cc" -or -name '*.s')
OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CPPFLAGS := -fPIC
CXXFLAGS += -std=c++17 -w # Add -g flag for debug information

debug: CFLAGS += -g -DDEBUG
debug: $(BUILD_DIR)/$(TARGET)

release: CFLAGS += -O3 -fsantize=address
release: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(PCH) $(OBJS)
	@echo "Archiving"
	ar rcs $(BUILD_DIR)/$(TARGET) $(OBJS)

$(OBJ_DIR)/%.cpp.o: %.cpp
	@echo "Compiling sources..."
	mkdir -p $(dir $@) 
	clang++ $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -I $(SRC_DIR) -c $< -o $@

$(OBJ_DIR)/%.cc.o: %.cc
	@echo "Compiling sources..."
	mkdir -p $(dir $@) 
	clang++ $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -I $(SRC_DIR) -c $< -o $@

clean:
	rm -r $(BUILD_DIR)
