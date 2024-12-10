// #include<iostream>
// #include<fstream>
// using namespace std;
// int main(){
//     //read file
//     ifstream out;
//     out.open("yash.txt");
//     if(!out){
//         cout<<"Errot in file Opening."<<endl;
//         return 0;
//     }
//     char ch;
//     int letter=0,word=0,line=0;
//   while(out) 
//      { 
//           if(ch!=' ' && ch!='\n') 
//             letter++; 
//           if(ch==' ') 
//                word++; 
//           if(ch=='\n') 
//           { 
//                line++; 
//                word++; 
//           } 
//           out.get(ch); 
//      } 
//     cout<<"Total Letters are:"<<letter<<endl;
//     cout<<"Total words are:"<<word<<endl;
//     cout<<"Total lines are:"<<line+1<<endl;
//     out.close();
//     return 0;
// }

#include <iostream> 
#include <fstream> 
#include <string> 
Using namespace std; 
 
int main() { 
     ifstream inputFile("input.txt"); 
 
    if (!inputFile.is_open()) { 
         cerr << "Error opening file!" <<  endl; 
        return 1; 
    } 
 
    int charCount = 0, wordCount = 0, lineCount = 0; 
     string line; 
 
    while ( getline(inputFile, line)) { 
        lineCount++;  // Increment line count 
// Increment character count (including spaces in the line) 
charCount += line.length(); 
// Increment word count by counting spaces and words in the line 
bool inWord = false; 
for (char ch : line) { 
if ( isspace(ch)) { 
if (inWord) { 
wordCount++; 
inWord = false; 
} 
} else { 
inWord = true; 
} 
} 
if (inWord) wordCount++;  // Count the last word if it exists 
} 
cout << "Number of characters: " << charCount <<  endl; 
cout << "Number of words: " << wordCount <<  endl; 
cout << "Number of lines: " << lineCount <<  endl; 
inputFile.close(); 
return 0; 
} 