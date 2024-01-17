#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite
void pf(const ULListStr& list){
    for(size_t i = 0; i < list.size(); i ++){
        cout << list.get(i) << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    ULListStr obj;
    obj.push_front("0");
    obj.push_front("1");
    obj.push_front("2");
    obj.push_front("3");
    obj.pop_front();
    obj.pop_front();
    obj.pop_front();
    obj.pop_front();
    obj.pop_front();
    obj.push_front("4");
    obj.push_front("5");
    obj.push_front("6");
    obj.push_front("7");
    obj.push_front("8");
    obj.push_front("9");
    obj.push_front("10");
    obj.push_front("11");
    obj.push_front("12");
    

    cout << obj.size() << endl;
    pf(obj);
    cout << obj.front() << endl << obj.back() << endl;
}
