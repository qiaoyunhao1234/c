#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string,int> myMap;

int main(){
    myMap["Emma"] = 67;
    myMap["Bendict"] = 100;
    myMap.insert(pair<string,int>("Bob", 72));
    myMap.insert(pair<string,int>("Mary", 85));
    myMap.insert(pair<string,int>("Alice", 93));
    printf("Size of myMap: %d\n", myMap.size()); 
    printf("Score of Benedict: %d\n", myMap["Bendict"]);
    printf("Score of Mary: %d\n", myMap["Mary"]);
    myMap.erase("Bendict");
    map<string,int>::iterator it;
    for(it = myMap.begin(); it != myMap.end(); it++){
        cout<<"the score of "<<it->first;
        cout<<" is "<<it->second<<endl;
    }
    myMap.clear();
    if(myMap.empty()){
        printf("myMap is empty now.\n");
    }else{
        printf("myMap is not empty now.\n");
    }
    it=myMap.find("Bob");
    if(it != myMap.end()){
        printf("Found Bob in myMap.\n");
    }else{
        printf("Did not find Bob in myMap.\n");
    }
    printf("Size of myMap: %d\n", myMap.size());
    return 0;

    
}
