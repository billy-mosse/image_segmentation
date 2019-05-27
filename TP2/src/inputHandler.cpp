#include "inputHandler.h"

vector<int> parseInputFile(char* inputPath){
    double n;
    int m;
    vector<int> numbers;
    ifstream inFile;
    inFile.open(inputPath);
    if (!inFile) {
        cerr << "Unable to open file " << inputPath;
        exit(1);
    }

    while (inFile >> n) {
        m = n;
        numbers.push_back(m);
    }
    inFile.close();
    return numbers;
}

//TODO int deberia ser unsigned int para los pixels
vector<vector<int> > separateValues(vector<int> numbers, int width, int height){
    vector<vector< int> > rows;


    for(int i = 0; i < height; i++)
    {
        //TODO mejorar
        int imagePosStart = 2 + i*width;

        vector<int> row;
        for(int j = 0; j < width; j++)
        {
            int p = numbers[imagePosStart + j];
            //cout<<"HOLA3"<< endl;

            row.push_back(p);
        }
        rows.push_back(row);
    }
    return rows;
}

vector<vector<int> > imageFromFile(char* inputPath){
    vector<int> numbers = parseInputFile(inputPath);
    int width = numbers[0];
    int height = numbers[1];

    vector<vector<int> > image = separateValues(numbers, width, height);
    return image;
}


vector<vector<int> > imageFromInput(int width, int height){


    int n;
    vector<int> numbers;
    while (cin >> n) {
        numbers.push_back(n);
    }

    vector<vector<int> > image;

    for(int i = 0; i < height; i++)
    {
        int imagePosStart = 2 + i*width;
        vector<int> row;
        for(int j = 0; j < width; j++)
        {
            int p = numbers[imagePosStart + j];
            row.push_back(p);
        }
        image.push_back(row);
    }
    return image;
}