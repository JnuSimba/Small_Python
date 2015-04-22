main: py_int_object.o  py_str_object.o py_dict_object.o py_type_object.o py_execute.o main.o
	g++ -g $^ -o $@
clean:
	-rm main *.o
.PHONY: clean
