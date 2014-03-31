pb = login.pb.h chat.pb.h

$(pb): %.pb.h: %.proto
	protoc --cpp_out=. $<

.PHONY: clean
clean:
	rm -f *.pb.h
	rm -f *.pb.cc
