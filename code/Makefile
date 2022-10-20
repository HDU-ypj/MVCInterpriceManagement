obj = manager_view_impl.o manager_ctrl_impl.o manager_mode_impl.o manager.o service_ctrl_impl.o service_mode_impl.o department.o employee.o main.o emis.o tools.o service_view_impl.o
BIN = eims
CC = g++
FLAG = -std=gnu++0x -Wall -Werror

all:$(obj)
	$(CC) $(FLAG) -o $(BIN) $(obj) && mv $(obj) ../bin && ./$(BIN)

%.o:%.cpp
	$(CC) $(FLAG) -c $< -o $@

	
clean:
	rm -rf ../bin/*.o $(BIN) *.h.gch ./*.o
