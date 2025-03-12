#include <iostream>
using namespace std;
int main() {
    int Variable = 10;
    int* Pointer = &Variable;
    cout << "Initial value of Variable= " << Variable << endl;
    cout << "Value of Pointer (address )= " << Pointer << endl;
    cout << "Value pointed to by myPointer= " << *Pointer << endl;
    *Pointer = 20;
    // Display the modified values
 cout << "Modified value of Variable=" << Variable << endl;
 cout << "Value of Pointer (address )= " << Pointer << endl;
 cout << "Value pointed to by Pointer= " << *Pointer << endl;

}
