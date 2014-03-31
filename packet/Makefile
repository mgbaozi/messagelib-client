pb = login.pb.h chat.pb.h

all: $(pb)

$(pb): %.pb.h: %.proto
	protoc --cpp_out=. $<

.PHONY: clean
clean:
	rm -f *.pb.h
	rm -f *.pb.cc
