/*Enter cost of 3 items from the user (using float data type) - a pencil, a pen and an eraser. You have to output the total cost of the items back to the user as their bill.
(Add on : You can also try adding 18% GST tax to the items in the bill as an advanced problem)*/
#include<iostream>
using namespace std;
int main(){
    float a,b,c;
    cout<<"Enter cost of pencil:";
    cin>>a;
    cout<<"Enter cost of pen:";
    cin>>b;
    cout<<"Enter cost of eraser:";
    cin>>c;
    cout<<"Total cost of item:"<<a+b+c<<endl;
    float gst=a+b+c+(18/100.0)*(a+b+c);//implict conversion...
    cout<<"Total cost of item (including GST tax):"<<gst<<endl;
    return 0;

}