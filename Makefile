.PHONY: all clean

APP:=test-ics-nodes
NODES_DIR:=.
LIBUT_DIR:=../libut
NODES_SRCS:=ics-node.c
TEST_SRCS:=test-ics-node.c

CFLAGS:=-I$(NODES_DIR)/include -I$(LIBUT_DIR)/include
LIBS:=

all: $(APP)

$(APP): $(TEST_SRCS:.c=.o) $(NODES_SRCS:.c=.o)
	gcc -o$@ $^ $(LIBS)
$(TEST_SRCS:.c=.o): %.o: $(NODES_DIR)/test/%.c
	gcc -o$@ -c $< $(CFLAGS)
$(NODES_SRCS:.c=.o): %.o: $(NODES_DIR)/src/%.c
	gcc -o$@ -c $< $(CFLAGS)
clean:
	rm -fr *.o $(APP)
