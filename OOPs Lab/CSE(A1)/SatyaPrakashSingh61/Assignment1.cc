#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool searchPrices(vector<double>stockPrices,double price){
    for(double stockPrice:stockPrices){
        if(stockPrice==price){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter total number of companies:"<<endl;
    cin>>n;
    vector<double>stockPrices(n);
    vector<int>stockRose(n);
    //storing shareprice
    for(int i=0;i<n;i++){
        cout<<"Enter current stock price of company "<<(i+1)<<":"<<endl;
        cin>>stockPrices[i];
        cout<<"Did the company's stock price rise today compared to yesterday?(1 for true || 0 for false):"<<endl;
        cin>>stockRose[i];
    }
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    int choice;
    do{
        cout<<"*******************  MENU  ******************************************"<<endl;
        cout<<"Enter the operation that you want to perform:"<<endl;
        cout<<"1.Display the companies stock prices in ascending order"<<endl;
        cout<<"2.Display the companies stock prices in descending order"<<endl;
        cout<<"3.Display the total no of companies for which stock prices rose today"<<endl;
        cout<<"4.Display the total no of companies for which stock prices declined today"<<endl;
        cout<<"5.Search a specific stock price"<<endl;
        cout<<"6.Press 0 to exit"<<endl;
        cout<<"Choice:";
        cin>>choice;
        switch(choice){
            case 1:{
                // Displaying stock prices in ascending order
                vector<double> sortedPrices = stockPrices;
                sort(sortedPrices.begin(),sortedPrices.end());
                cout<<"Stock prices in ascending order are:"<<endl;
                for(double price : sortedPrices){
                    cout<<price<<" ";
                }
                cout<<endl;
                break;
            }
            case 2:{
                // Displaying stock prices in descending order
                vector<double> sortedPrices = stockPrices;
                sort(sortedPrices.begin(), sortedPrices.end(), greater<double>());
                cout<<"Stock prices in descending order are:"<<endl;
                for(double price : sortedPrices){
                    cout<<price<<" ";
                }
                cout<<endl;
                break;
            }
            case 3:{
                // Counting company which raise today as compare to yesterday   
                int count=0;
                for(auto check:stockRose){
                    if(check==true){
                        count++;
                    }
                }
                cout<<"Total no. of companies whose stock price rose today are: "<<count<<endl;
                break;
            }
            case 4:{
                // Counting companies with declining stock prices as compare to yesterday
                int count=0;
                for(auto check:stockRose){
                    if(check==false){
                        count++;
                    }
                }
                cout<<"Total no of companies whose stock price declined today:"<<count<<endl;
                break;
            }
            case 5:{
                // Searching of stock price
                double price;
                cout<<"Enter the stock price to search:";
                cin>>price;
                bool res=searchPrices(stockPrices,price);
                if(res){
                    cout<<"Stock of value "<<price<<" is present"<<endl;
                }else{
                    cout<<"Stock of value "<<price<<" is not present"<<endl;
                }
                break;
            }
            case 0:{
                cout<<"Exited successfully"<<endl;
                break;
            }
            default:
                cout<<"Invalid choice.Please try again."<<endl;
                break;
        }
    }while(choice!=0);
    return 0;
}