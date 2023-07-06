#include <iostream>
#include "PC3.h"
using namespace std;

int main() {
    COrden o1;
    o1.agregar_pizza(new CHawaiana(10));
    o1.agregar_pizza(new CPepperoni(20, true));
    o1.agregar_pizza(new CHawaiana(15));
    o1.agregar_pizza(new CPepperoni(20, false));
    cout << o1;
    return 0;
}
