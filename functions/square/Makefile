# BIN = main
SRCS = main.cpp plugincontainer.cpp
PLUGIN_SRCS = square.cpp

CFLAGS = -O2 -Wall -Werror -std=c++11 -I/Users/kevin/Projects/gecode/gecode/flatzinc/blackbox
LDFLAGS = -ldl
LDFLAGS_PLUGIN = -fPIC -shared

OBJS = $(SRCS:%.cpp=%.o)
PLUGIN_SOBJS = $(PLUGIN_SRCS:%.cpp=%.so)

.PHONY: all clean

all: $(PLUGIN_SOBJS)

# $@ substitutes the name of the target file
# $< substitutes the name of the source file
# %.so is the target, % in the %.cpp stands for the same stem
%.so: %.cpp
	g++ $(CFLAGS) -o $@ $< $(LDFLAGS_PLUGIN)

%.o: %.cpp
	g++ $(CFLAGS) -c -o $@ $<

$(BIN): $(OBJS)
	g++ $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(BIN) $(OBJS) $(PLUGIN_SOBJS)
