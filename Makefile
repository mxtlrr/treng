CXX				:= g++
CXXFLAGS	:= -Wall -Wextra -g -std=c++11 -Iinclude/

LINK := -Lbin/lib/ -lnums

override CXXFILES := $(shell find ./src -type f -name "*.cpp")
OFILES := $(patsubst %.cpp, %.o, $(CXXFILES))

app: ${OFILES}
	@mkdir -p bin/lib
	@echo -n Making binary...
	@$(CXX) $(LINK) $^ -o bin/treng
	@echo done!

%.o: %.cpp
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	@rm -v $(OFILES)