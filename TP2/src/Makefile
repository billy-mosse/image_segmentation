make: disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp main.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp main.cpp utils.cpp -o ./main
test: arreglo_rep.cpp arbol_rep.cpp arbol_comp.cpp inputHandler.cpp test.cpp image_to_graph_converter.cpp graph.cpp utils.cpp disjoint_set.cpp
	g++ arreglo_rep.cpp arbol_rep.cpp arbol_comp.cpp inputHandler.cpp test.cpp image_to_graph_converter.cpp graph.cpp utils.cpp disjoint_set.cpp -o ./test
	./test
experimain:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain.cpp utils.cpp -o ./experimain
	./experimain 1 2 > experiments/experiment6_time/output.log 2> experiments/experiment7_cuali/table.csv
	#./experimain 0 1 > 01.txt
	#./experimain 0 2 > 02.txt
	#./experimain 1 0 > 10.txt
	#./experimain 1 1 > 11.txt
	#./experimain 1 2 > 12.txt
	#python ../images/plot_experiment_matrices.py
	#mv *.png experiments/
experimain_6_time:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_6_time.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_6_time.cpp utils.cpp -o ./experimain_6_time
	mkdir -p experiments/experiment_8_redone_experiment6
	./experimain_6_time 1 2 > experiments/experiment_8_redone_experiment6/output.log 2> experiments/experiment_8_redone_experiment6/table.csv
	#./experimain 0 1 > 01.txt
	#./experimain 0 2 > 02.txt
	#./experimain 1 0 > 10.txt
	#./experimain 1 1 > 11.txt
	#./experimain 1 2 > 12.txt
	#python ../images/plot_experiment_matrices.py
	#mv *.png experiments/
experimain_9_k:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_9_k.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_9_k.cpp utils.cpp -o ./experimain_9_k
	mkdir -p experiments/experiment_9_k
	./experimain_9_k 1 2 > experiments/experiment_9_k/output.log 2> experiments/experiment_9_k/table.csv
	#./experimain 0 1 > 01.txt
	#./experimain 0 2 > 02.txt
	#./experimain 1 0 > 10.txt
	#./experimain 1 1 > 11.txt
	#./experimain 1 2 > 12.txt
	#python ../images/plot_experiment_matrices.py
	#mv *.png experiments/
experimain_10_k:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_10_k.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_10_k.cpp utils.cpp -o ./experimain_10_k
	mkdir -p experiments/experiment_10_k
	./experimain_10_k 10 > experiments/experiment_10_k/output_10.log 2> experiments/experiment_10_k/table_10.csv
	./experimain_10_k 20 > experiments/experiment_10_k/output_20.log 2> experiments/experiment_10_k/table_20.csv
	./experimain_10_k 30 > experiments/experiment_10_k/output_30.log 2> experiments/experiment_10_k/table_30.csv
	./experimain_10_k 50 > experiments/experiment_10_k/output_50.log 2> experiments/experiment_10_k/table_50.csv
	./experimain_10_k 100 > experiments/experiment_10_k/output_100.log 2> experiments/experiment_10_k/table_100.csv
	./experimain_10_k 150 > experiments/experiment_10_k/output_150.log 2> experiments/experiment_10_k/table_150.csv
	./experimain_10_k 200 > experiments/experiment_10_k/output_200.log 2> experiments/experiment_10_k/table_200.csv
	./experimain_10_k 250 > experiments/experiment_10_k/output_250.log 2> experiments/experiment_10_k/table_250.csv
	./experimain_10_k 300 > experiments/experiment_10_k/output_300.log 2> experiments/experiment_10_k/table_300.csv
	./experimain_10_k 500 > experiments/experiment_10_k/output_500.log 2> experiments/experiment_10_k/table_500.csv
	./experimain_10_k 1000 > experiments/experiment_10_k/output_1000.log 2> experiments/experiment_10_k/table_1000.csv
	#./experimain 0 1 > 01.txt
	#./experimain 0 2 > 02.txt
	#./experimain 1 0 > 10.txt
	#./experimain 1 1 > 11.txt
	#./experimain 1 2 > 12.txt
	#python ../images/plot_experiment_matrices.py
	#mv *.png experiments/
experimain_11_k:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_10_k.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_10_k.cpp utils.cpp -o ./experimain_10_k
	mkdir -p experiments/experiment_11_k
	./experimain_10_k 10 > experiments/experiment_11_k/output_10.log 2> experiments/experiment_11_k/table_10.csv
	./experimain_10_k 20 > experiments/experiment_11_k/output_20.log 2> experiments/experiment_11_k/table_20.csv
	./experimain_10_k 30 > experiments/experiment_11_k/output_30.log 2> experiments/experiment_11_k/table_30.csv
	./experimain_10_k 50 > experiments/experiment_11_k/output_50.log 2> experiments/experiment_11_k/table_50.csv
	./experimain_10_k 100 > experiments/experiment_11_k/output_100.log 2> experiments/experiment_11_k/table_100.csv
	./experimain_10_k 150 > experiments/experiment_11_k/output_150.log 2> experiments/experiment_11_k/table_150.csv
	./experimain_10_k 200 > experiments/experiment_11_k/output_200.log 2> experiments/experiment_11_k/table_200.csv
	./experimain_10_k 250 > experiments/experiment_11_k/output_250.log 2> experiments/experiment_11_k/table_250.csv
	./experimain_10_k 300 > experiments/experiment_11_k/output_300.log 2> experiments/experiment_11_k/table_300.csv
	./experimain_10_k 500 > experiments/experiment_11_k/output_500.log 2> experiments/experiment_11_k/table_500.csv
	./experimain_10_k 1000 > experiments/experiment_11_k/output_1000.log 2> experiments/experiment_11_k/table_1000.csv
	#./experimain 0 1 > 01.txt
	#./experimain 0 2 > 02.txt
	#./experimain 1 0 > 10.txt
	#./experimain 1 1 > 11.txt
	#./experimain 1 2 > 12.txt
	#python ../images/plot_experiment_matrices.py
	#mv *.png experiments/
experiment_13_k:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_9_k.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_9_k.cpp utils.cpp -o ./experimain_9_k
	mkdir -p experiments/experiment_13_k
	./experimain_9_k 1 2 > experiments/experiment_13_k/output.log 2> experiments/experiment_13_k/table.csv
	#./experimain 0 1 > 01.txt
	#./experimain 0 2 > 02.txt
	#./experimain 1 0 > 10.txt
	#./experimain 1 1 > 11.txt
	#./experimain 1 2 > 12.txt
	#python ../images/plot_experiment_matrices.py
	#mv *.png experiments/
experiment_16_k:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_9_k.cpp utils.cpp
	echo "este es el que quedo"
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain_9_k.cpp utils.cpp -o ./experimain_9_k
	mkdir -p experiments/experiment_16_k
	./experimain_9_k 1 2 > experiments/experiment_16_k/output.log 2> experiments/experiment_16_k/table.csv
	#./experimain 0 1 > 01.txt
	#./experimain 0 2 > 02.txt
	#./experimain 1 0 > 10.txt
	#./experimain 1 1 > 11.txt
	#./experimain 1 2 > 12.txt
	#python ../images/plot_experiment_matrices.py
	#mv *.png experiments/
experimain_16:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain.cpp utils.cpp -o ./experimain
	mkdir -p experiments/experiment_15
	./experimain 1 2 > experiments/experiment_15/output.log 2> experiments/experiment_15/table.csv
experimain_17:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain.cpp utils.cpp -o ./experimain
	mkdir -p experiments/experiment_17
	./experimain 1 2 > experiments/experiment_17/output.log 2> experiments/experiment_17/table.csv
experimain_19:  disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain.cpp utils.cpp
	g++ disjoint_set.cpp arbol_comp.cpp arbol_rep.cpp arreglo_rep.cpp graph.cpp image_to_graph_converter.cpp inputHandler.cpp experimain.cpp utils.cpp -o ./experimain
	mkdir -p experiments/experiment_19
	./experimain "rocklets_blur_gray.txt" 0 > experiments/experiment_19/output_blur0.log 2> experiments/experiment_19/table_blur0.csv
	echo "Done"
	./experimain "rocklets_blur_gray.txt" 1 > experiments/experiment_19/output_blur1.log 2> experiments/experiment_19/table_blur1.csv
	./experimain "rocklets_noise_gray.txt" 0 > experiments/experiment_19/output_noise0.log 2> experiments/experiment_19/table_noise0.csv
	./experimain "rocklets_noise_gray.txt" 1 > experiments/experiment_19/output_noise1.log 2> experiments/experiment_19/table_noise1.csv
	./experimain "rocklets_gray.txt" 0 > experiments/experiment_19/output_0.log 2> experiments/experiment_19/table_0.csv
	./experimain "rocklets_gray.txt" 1 > experiments/experiment_19/output_1.log 2> experiments/experiment_19/table_1.csv
test_2: inputHandler.cpp test_2.cpp
	g++ inputHandler.cpp test_2.cpp -o ./test_2
graph_test: graph_test.cpp graph.cpp graph.h
	g++ graph_test.cpp graph.cpp -o ./graph_test
clean:
	rm ./main ./test ./graph_test *.o
