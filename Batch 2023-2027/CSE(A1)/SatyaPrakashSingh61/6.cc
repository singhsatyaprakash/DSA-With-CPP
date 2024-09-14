/*The daily maximum temperatures recorded in 5 cities during the month of January (for all 31days) have been tabulated as follows:
Cities      Delhi       Mumbai      Kolkatta        Chennai     Dehradun
1
2
.
10
Write a program to read the table elements into a two-dimensional array temperature, and to find the city and day corresponding to (a) the highest temperature and (b) the lowest temperature.*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main(){
    int days=31;
    int cities=5;   
    // City names
    string cityNames[cities]={"Delhi","Mumbai","Kolkatta","Chennai","Dehradun"};
    //temperature data for 31 days for 5 cities
    int temperature[cities][days]={
        {15, 18, 12, 14, 19, 20, 21, 18, 17, 22, 23, 25, 24, 26, 28, 25, 27, 30, 31, 29, 32, 34, 33, 28, 26, 27, 25, 29, 30, 31, 32}, // Delhi
        {30, 32, 33, 35, 36, 34, 32, 31, 30, 33, 34, 36, 37, 39, 38, 37, 36, 35, 33, 34, 35, 36, 37, 38, 39, 37, 36, 35, 34, 33, 32}, // Mumbai
        {25, 26, 27, 28, 29, 28, 26, 27, 29, 30, 32, 33, 34, 35, 33, 34, 36, 37, 36, 35, 34, 32, 30, 29, 28, 29, 30, 32, 33, 35, 36}, // Kolkatta
        {28, 29, 30, 31, 32, 33, 34, 32, 30, 31, 33, 35, 37, 36, 38, 39, 37, 36, 35, 34, 33, 32, 30, 29, 28, 30, 31, 32, 33, 34, 36}, // Chennai
        {12, 14, 16, 17, 18, 16, 14, 13, 12, 15, 17, 18, 20, 19, 18, 16, 14, 15, 17, 18, 19, 20, 21, 23, 24, 22, 21, 20, 19, 18, 17}  // Dehradun
    };
    //Print table header
    cout<<setw(10)<<"Day";
    for(int i=0;i<cities;i++){
        cout<<setw(10)<<cityNames[i];
    }
    cout<<endl;
    // Print temperature data in tabular format
    for(int day=0;day<days;day++){
        cout<<setw(10)<<day+1;//Day number
        for(int city=0;city<cities;city++){
            cout<<setw(10)<<temperature[city][day];
        }
        cout<<endl;
    }
    int highestTemp=temperature[0][0];
    int lowestTemp=temperature[0][0];
    int highCityIndex=0,highDayIndex=0;
    int lowCityIndex=0,lowDayIndex=0;
    // Find the highest and lowest temperatures
    for(int i=0;i<cities;i++){
        for(int j=0;j<days;j++){
            if(temperature[i][j]>highestTemp){
                highestTemp=temperature[i][j];
                highCityIndex=i;
                highDayIndex=j;
            }
            if(temperature[i][j]<lowestTemp){
                lowestTemp=temperature[i][j];
                lowCityIndex=i;
                lowDayIndex=j;
            }
        }
    }
    // Output the results
    cout<<"\nThe highest temperature was recorded in "<<cityNames[highCityIndex]<<" on Day "<<highDayIndex+1<<" with "<<highestTemp<< " degrees.\n";     
    cout<<"The lowest temperature was recorded in "<<cityNames[lowCityIndex]<<" on Day "<<lowDayIndex+1<<" with "<<lowestTemp<<" degrees.\n";
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}
