export CLEAN = make clean
MAKEFLAGS = -w

.PHONY: all
all: packet
	g++ *.cc packet/*.cc --std=c++11 -o main -lprotobuf -levent -lpthread

packet: packet/login.pb.h packet/chat.pb.h
	$(MAKE) -C packet

run: all
	./main

.PHONY: clean
clean:
	$(CLEAN) -C packet
	rm -f main
