make: disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp main.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp main.cpp -o ./main
test: arreglo_rep.cpp arbol_rep.cpp arbol_comp.cpp inputHandler.cpp test.cpp image_to_graph_converter.cpp graph.cpp
	g++ arreglo_rep.cpp arbol_rep.cpp arbol_comp.cpp inputHandler.cpp test.cpp image_to_graph_converter.cpp graph.cpp -o ./test
	./test
test_2: inputHandler.cpp test_2.cpp
	g++ inputHandler.cpp test_2.cpp -o ./test_2
graph_test: graph_test.cpp graph.cpp graph.h
	g++ graph_test.cpp graph.cpp -o ./graph_test
clean:
	rm ./main ./test ./graph_test *.o
