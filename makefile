# Target name
TARGET = opengl-learn

# Build folder path
BUILD_DIR = build

# debug build?
DEBUG = 0
# optimization
OPT = -Og

CFLAGS =

ifeq ($(DEBUG), 1)
CFLAGS += -g
endif

CFLAGS += $(OPT)

LDFLAGS = -lglfw

CXX_SOURCES = \
./src/main.cpp

C_SOURCES = \
./src/glad.c

INCLUDES = \
./include/


# list of objects
CXX_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(CXX_SOURCES:.cpp=.oxx)))
vpath %.cpp $(sort $(dir $(CXX_SOURCES)))

C_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

OBJECTS = $(CXX_OBJECTS) $(C_OBJECTS)

$(BUILD_DIR)/$(TARGET): $(OBJECTS) makefile
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.oxx: %.cpp makefile | $(BUILD_DIR)
	$(CXX) -c $(CFLAGS) -I$(INCLUDES) $< -o $@

$(BUILD_DIR)/%.o: %.c makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) -I$(INCLUDES) $< -o $@

$(BUILD_DIR):
	mkdir $@

clean:
	-rm -fr $(BUILD_DIR)

 # TODO: compile on h file change