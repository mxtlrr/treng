CXX				:= g++
CXXFLAGS	:= -fPIC -Wall -Wextra -g -std=c++11 -Iinclude/

override CXXFILES := $(shell find ./ -type f -name "*.cpp")
OFILES := $(patsubst %.cpp, %.o, $(CXXFILES))

library: ${OFILES}
	@mkdir -p ../bin/lib
	@echo -n Making shared object...
	@$(CXX) -shared $^ -o ../bin/lib/libnums.so
	@echo done!

%.o: %.cpp
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	@rm -v $(OFILES)
