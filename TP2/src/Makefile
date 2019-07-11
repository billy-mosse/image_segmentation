make: disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp main.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp main.cpp utils.cpp -o ./main
test: arreglo_rep.cpp arbol_rep.cpp arbol_comp.cpp inputHandler.cpp test.cpp image_to_graph_converter.cpp graph.cpp utils.cpp disjoint_set.cpp
	g++ arreglo_rep.cpp arbol_rep.cpp arbol_comp.cpp inputHandler.cpp test.cpp image_to_graph_converter.cpp graph.cpp utils.cpp disjoint_set.cpp -o ./test
	./test
experimain:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain.cpp utils.cpp -o ./experimain
	mkdir -p new_experiments/experiment1
	#./experimain 0 1 > 01.txt
	#./experimain 0 2 > 02.txt
	#./experimain 1 0 > 10.txt
	#./experimain 1 1 > 11.txt
	#./experimain 1 2 > 12.txt
	#python ../images/plot_experiment_matrices.py
	#mv *.png experiments/
