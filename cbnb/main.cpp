#include "user_options.h"

int main() {
    UserOptionsController *menu = new UserOptionsController();

    menu->ShowLogin();

    delete menu;


    return 0;
}
