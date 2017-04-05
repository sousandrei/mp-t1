ifeq ($(OS),Windows_NT)
RMDIR = rd /s /q
RM = del 

DIRECTIVES = -std=c++11 -Wall -Wextra -c -I $(HEADER_PATH) -I $(SDL_PATH)\include
LIBS = -L -lmingw32 -lm

EXEC = t1.exe

else
RMDIR = rm -rf
RM = rm

DIRECTIVES = -std=c++11 -Wall -Wextra -c -I $(HEADER_PATH)
LIBS = -lm

EXEC = t1
endif

CC = clang++-3.8
# CC = g++

DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_PATH)/$*.d

HEADER_PATH = include
SRC_PATH = src/cpp
BIN_PATH = tmp/bin
DEP_PATH = tmp/dep

CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
# CPP_FILES += main.cpp

OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))

DEP_FILES = $(wildcard $(DEP_PATH)/*.d)


# $(info $$CPP_FILES is [${CPP_FILES}])
# $(info $$OBJ_FILES is [${OBJ_FILES}])
# $(info $$DEP_FILES is [${DEP_FILES}])

all: $(EXEC)
$(EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)

# $(BIN_PATH)/main.o: main.cpp 
$(BIN_PATH)/%.o: $(SRC_PATH)/%.cpp 
ifeq ($(OS),Windows_NT)
	@if not exist $(DEP_PATH) @mkdir $(DEP_PATH)
	@if not exist $(BIN_PATH) @mkdir $(BIN_PATH)
else
	@mkdir -p $(DEP_PATH) $(BIN_PATH)
endif
	$(CC) $(DEP_FLAGS) -c -o $@ $< $(DIRECTIVES)

debug: DIRECTIVES += -ggdb
debug: all

release: DIRECTIVES += -Ofast -mtune=native
release: all

print-% : ; @echo $* = $($*)

.PHONY: clean
clean:
	$(RMDIR) $(BIN_PATH) $(DEP_PATH)
	$(RM) $(EXEC)

$(DEP_PATH)/%.d: ;
.PRECIOUS: $(DEP_PATH)/%.d

-include $(DEP_FILES)

