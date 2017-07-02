/*
 * File name: testSingletonMain.cpp
 * Created on: Jul 3, 2017
 *
 */

#include <iostream>

#include "singletonDerivedStatic.h"
#include "singletonDerivedNew.h"

using namespace std;


class testClass{

public:
    testClass(){
        cout << "sigTest()" << endl;
    }

    virtual ~testClass(){
        cout << "~sigTest()" << endl;
    }

    void method(){
        cout << "method()" << endl;
    }

    virtual void virtualMethod(){
        cout << "virtual method()" << endl;
    }
};

int main() {

//    typedef singletonDerivedStatic<testClass> sigletonTestClass;
    typedef singletonDerivedNew<testClass> sigletonTestClass;

    cout << "/* ---------------------------------------------------------------------------------------------- */" << endl;

//    sigletonTestClass v; //ctor - private or deleted

    sigletonTestClass::getInstance().method(); //call method from testClass
    sigletonTestClass::getInstance().virtualMethod(); //call virtualMethod from testClass

    sigletonTestClass &rv = sigletonTestClass::getInstance();
//    sigletonTestClass v(rv); //c-ctor deleted

    cout << "/* ---------------------------------------------------------------------------------------------- */" << endl;

    rv.method();
    rv.virtualMethod();

    cout << "/* ---------------------------------------------------------------------------------------------- */" << endl;

    sigletonTestClass *pv = &sigletonTestClass::getInstance();

    pv->method();
    pv->virtualMethod();

    cout << "/* ---------------------------------------------------------------------------------------------- */" << endl;
}


