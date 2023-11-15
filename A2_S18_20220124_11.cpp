// File: A2_S18_20220124_11.cpp
// Purpose: compare two files
// Author:doaa ayman mohamed
// Section: s18
// ID: 20220124
// TA: rana abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <string> split (string str){  //function to split the line into words
    string word; 
    vector<string>vec;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i]!=' ')  
        {
            word+=str[i]; //pushing the character of the word into the variable 
            if (i==str.size()-1) // if it is the last word in the line push it
                vec.push_back(word);
        }
        else
     {
        if (str[i]==' '&&str[i-1]==' ')
                continue;    
            vec.push_back(word);
            word="";
        }
    }

    return vec;
}

int main(){
    int count=0;
    string file_name ,file2_name,line1,line2;
    cout<<"enter the first file name \n";
    cin>>file_name;
    cout<<"enter the second file name \n";
    cin>>file2_name;
    file_name = file_name+".txt";
    file2_name = file2_name+".txt";
    fstream file;
    fstream file2;
    file.open(file_name); // to open the file
    file2.open(file2_name);
    cout<<"please enter (1) to compare character by character and (2)to compare word by word\n";
    int choice;
    cin>>choice;
    if (choice==1) {
        while (file.good() && file2.good()) {
            count++;
            getline(file, line1); //to get every line in the file
            getline(file2, line2);
            for (int i = 0; i < line1.size(); ++i) {
                if (line1[i] != line2[i]) { //if there is character not equal the character at the another file
                    cout << "the line that has the different character is the line number " << count << "\n"; //printing number of the line
                    cout << "the line in the first file is : " << line1 << "\n"; 
                    cout << "the line in the second file is : " << line2 << "\n";
                    return 0;

                }
            }
        }
        cout << "the files are identical";
    }
    else { vector<string>myvec1;
           vector<string>myvec2;
        while (file.good()&&file2.good()){
            count++;
            getline(file, line1);
            getline(file2, line2);
            myvec1=split(line1); //call the function to split the line into words 
            myvec2=split(line2);
            for (int i = 0; i < myvec1.size(); ++i) {
               if (myvec1[i]!=myvec2[i]){ // if the two words are diffirent 
                    cout<<"the line that has the different word is the line number "<<count<<"\n";
                    cout<<"the different word in the first file is :"<<myvec1[i]<<"\n";
                    cout<<"the different word in the second file is :"<<myvec2[i]<<"\n";
                   return 0;
                }

            }
        }cout<<"the files are identical";
    }
}