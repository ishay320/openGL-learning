# Target name
TARGET = main

# Build path
BUILD_DIR = build

# debug build?
DEBUG = 0
# optimization
OPT = -Og

CXXFLAGS =

ifeq ($(DEBUG), 1)
CFLAGS += -g
endif

CFLAGS += $(OPT)

LDFLAGS =

CXX_SOURCES = \
./src/main.cpp

C_INCLUDES =


# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(CXX_SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(CXX_SOURCES)))

$(BUILD_DIR)/$(TARGET): $(OBJECTS) makefile
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: %.cpp makefile | $(BUILD_DIR) 
	$(CXX) -c $(CXXFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@

$(BUILD_DIR):
	mkdir $@

clean:
	-rm -fr $(BUILD_DIR)

# TODO: compile c along cpp