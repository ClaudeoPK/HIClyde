#include <Windows.h>
#include <iostream>
#include "Hiclyde.h"
int main()
{
    if (!HIC_Verify_Device_State_Routine()) {
        std::cout << "Now loading device..." << std::endl;
        int result = HIC_Load_Device_Routine();
        if (result) {
            std::cout << "The device has been loaded successfully." << std::endl;
        }
        else {
            std::cout << "Failed to load device." << std::endl;
        }
    }
    HIC_Verify_Device_State_Routine();
    HIClydeKeyStroke* pKStroke = new HIClydeKeyStroke[2];
    pKStroke[0].code = 69; //NumLock
    pKStroke[0].information = NULL;
    pKStroke[0].state = HICLYDE_KEY_DOWN;
    pKStroke[1].code = 69; //NumLock
    pKStroke[1].information = NULL;
    pKStroke[1].state = HICLYDE_KEY_UP;

    while (true) {

        if (GetAsyncKeyState(VK_F2)) {
            HIC_Send_Keyboard_Stroke_Routine(&pKStroke[0]);
            Sleep(200);
            HIC_Send_Keyboard_Stroke_Routine(&pKStroke[1]);
            Sleep(1000);

        }
    }
    system("pause");
}
