#include "inputHandler.h"

vector<int> parseInputFile(char* inputPath){
    int n;
    double m;
    vector<int> numbers;
    ifstream inFile;
    inFile.open(inputPath);
    if (!inFile) {
        cerr << "Unable to open file " << inputPath;
        exit(1);
    }

    int count = 0;
    while (inFile >> m) {
        if(m==0)
            count = count+1;
    

        n = m;
        numbers.push_back(n);
    }
    inFile.close();
    return numbers;
}

//TODO int deberia ser unsigned int para los pixels
vector<vector<int> > separateValues(const vector<int> & numbers, int width, int height){
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

vector<int> numbersFromInput()
{
    int n;
    vector<int> numbers;
    int width;
    int height;
    cin >> width;
    cin >> height;
    numbers.push_back(width);
    numbers.push_back(height);
    for(int i = 0; i < width*height; i++){
        cin >> n;
        numbers.push_back(n);
    }
    return numbers;
}

vector<vector<int> > imageFromInput(vector<int> numbers){

    vector<vector<int> > image;
    int width = numbers[0];
    int height = numbers[1];

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