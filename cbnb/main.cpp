#include <iostream>
#include "domain.h"

int main() {
    Date date;
    try {
    date.SetValue("1111a");
    cout << "Deu bom";
    }
    catch (exception& e) {
    cout << e.what() << '\n';
    }
    return 0;
}
