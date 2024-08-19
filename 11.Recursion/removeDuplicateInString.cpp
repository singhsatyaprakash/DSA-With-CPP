#include<iostream>
#include<string>
using namespace std;
void removeDuplicates(string str,string ans,int i,bool map[26]){
    char ch=str[i];
    //base case...
    if(i==str.size()){
        cout<<"Output:"<<ans<<endl;
        return;
    }
    //finding index and its value in map array..
    int mapidx=(int)(ch-'a');
    if(map[mapidx]==true){//means charchater is gonna to repeat so we move next without adding to final ans string...
    removeDuplicates(str,ans,i+1,map);
    }
    else{//first time occur..
        map[mapidx]=true;
        removeDuplicates(str,ans+ch,i+1,map);
    }

}
int main(){
    string input,ans;
    cout<<"Input:";
    getline(cin,input);
    bool map[26]={false};//to check repeativitive of charchater...
    removeDuplicates(input,ans,0,map);
    return 0;
}
