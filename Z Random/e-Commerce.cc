#include<iostream>
#include<string>
using namespace std;
class Seller{
    protected:
        string name;
        double revenue;
    public:
    Seller(string name,double revenue):name(name),revenue(revenue){}
    void displaySellerInfo(){
        cout<<"Seller:"<<name<<endl;
    }
};
class IndividualSeller:public Seller{
    public:
    IndividualSeller(string name,double revenue):Seller(name,revenue){}
    void displayinfo(){
        cout<<"Individual Seller:"<<name<<endl;
        cout<<"Revenue:"<<revenue<<endl;
    }
    void showRevenue(){
        cout<<"Individual Revenue:"<<revenue<<endl;
    }

};
class BusinessSeller:public Seller{
    private:
    string businessName;
    public:
    BusinessSeller(string name,double revenue,string businessName):Seller(name,revenue),businessName(businessName){}
    void displayinfo(){
        cout<<"Business Seller:"<<businessName<<"(Owner:"<<name<<")"<<endl;
        cout<<"Revenue:"<<revenue<<endl;
    }
    void showBusinessDetails(){
        cout<<"Business Name:"<<businessName<<endl;
        cout<<"Business Owner:"<<name<<endl;
        cout<<"Business Revenue:"<<revenue<<endl;
    }

};
class Product{
private:
    string productName;
    double price;
    string category;
    IndividualSeller* indSeller;
    BusinessSeller* busSeller;
public:
    Product(string productName,double price):productName(productName),price(price){
        category="General";//default category
        indSeller=nullptr;
        busSeller=nullptr;
    }
    //with category..
    Product(string productName,double price,string category):productName(productName),price(price),category(category){
        indSeller=nullptr;
        busSeller=nullptr;
    }
    //indiviual seller..
    Product(string productName,double price,string category,IndividualSeller* seller):productName(productName),price(price),category(category),indSeller(seller){
        busSeller=nullptr;
    }
    //business seller..
    Product(string productName,double price,string category,IndividualSeller* seller):productName(productName),price(price),category(category),busSeller(seller){
        indSeller=nullptr;
    }

    //display..
    void displayProduct(){
        cout<<"\nProduct Name:"<<productName<<endl;
        cout<<"Price:$"<<price<<endl;
        cout<<"Category:"<<category<<endl;
        if(indSeller!=nullptr){
            indSeller->displayinfo();
        }
        else if(busSeller!=nullptr){
            business->displayinfo();
        }
    }
};
int main(){
    IndividualSeller indSeller("John Doe",5000.50);
    BusinessSeller busSeller("Jane Smith",15000.75,"TechBiz.Ltd");
    Product prod1("Laptop",999.99);//no seller
    Product prod2("SmartPhone",499.99,"Electronics");//Product with category..
    Product prod3("Tablet",299.99,"Electronics",&indSeller);
    Product prod4("SmartWatch",199.99,"Wearable",&busSeller);
    cout<<"\nProduct Listing....\n"<<endl;
    prod1.displayProduct();
    prod2.displayProduct();
    prod3.displayProduct();
    prod4.displayProduct();

}