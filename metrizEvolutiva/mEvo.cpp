#include <bits/stdc++.h>

using namespace std;

vector<char> specialChars = {':',';','.','-','"','#',','};

void delSepecialChars(string& word){
    for(int i=0;i<specialChars.size();i++){
        if(word[0]==specialChars[i]){
            // 01234
            // ;hola
            // hola
            for(int j=0; j<word.size()-1;j++){
                word[j]=word[j+1];
            }
            word.pop_back();
        }
        if(word[word.size()-1]==specialChars[i]){
            // 01234
            // hola;
            // hola
            word.pop_back();
        }
    }
}

void printMat(vector<vector <int>>& mat,int n){
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout<< endl;
    }
}

int main(){

    // filestream variable file
    fstream file;
    string word, t, q;
    //vector<string> words; ex.txt.size = 26
    vector<string> words;
    
    
 
    // filename of the file
    string filename;
    cout<<"Nombre del Archivo: ";
    cin>>filename;
 
    // opening file
    file.open(filename.c_str());


 
    // extracting words from the file
    while (file >> word)
    {
        delSepecialChars(word);
        if(find(words.begin(), words.end(), word) == words.end()){ // no added
            
            words.push_back(word);
        }
    }

    cout<<"Palabras unicas: "<<endl;
    for (int i = 0; i < words.size(); i++){
        cout<<words[i]<<' ';
    }

    file.close();
    

    //cout<<"tamaño del vector: "<<words.size();    out: 26
    cout << endl << "tamaño del set: " << words.size();  //14

    // MATRICES
    vector<vector <int>> mat(words.size(), vector<int> (words.size(),0));
    vector<vector <int>> matAcum(words.size(), vector<int> (words.size(),0));


    //cout<<"MATRIZ ANTES: "<<endl;   printMat(mat, words.size());

    file.open(filename.c_str());
    string prevWord;
    int x, y;
 
    // extracting words from the file
    while (file >> word)
    {
        //cout<<"Hola : "<<word<<endl;
        delSepecialChars(word);
        auto it = find(words.begin(), words.end(), word);
        x = it - words.begin();
        if( x==0 ){
            prevWord = word;
        }else{
            // buscando la palabra previa 
            auto itPrev = find(words.begin(), words.end(), prevWord);
            y = itPrev - words.begin();  // pos en y
            //cout<<"y: "<< y<< endl;
            x = it - words.begin();
            //cout<<"x: "<< x<< endl;
            mat[y][x]++;
            prevWord = word;
        }
    }

    cout<<endl<<"MATRIZ EVO: "<<endl;   printMat(mat, words.size());
    
    // MATRIZ ACUMULATIVA
    int acum;
    vector<int> resAcum;
    for(int i = 0; i < words.size(); i++){
        acum=0;
        for(int j = 0; j < words.size(); j++){
            if(mat[i][j]!=0){
                acum+=mat[i][j];
                matAcum[i][j]=acum;
            }
        }
        resAcum.push_back(acum);
    }

    cout<<endl<<"MATRIZ ACUM: "<<endl;   printMat(matAcum, words.size());
    cout<<"Resultados Acumulativos: "<<endl;
    for(int i=0;i<resAcum.size();i++){
        cout<<resAcum[i]<<' ';
    }

    

    return 0;
}