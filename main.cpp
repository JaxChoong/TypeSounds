#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>  // for kbhit and getch
#include <iostream>
#include <string>

#pragma comment(lib,"winmm.lib")

int main(){
    std::cout << "Press any key! \n";
    while (true){
        if (_kbhit()){
            int key = _getch();  // Get the pressed key (non-blocking)
            std::cout << key ;
            // Check if the Escape key is pressed to stop the sound
            if (key == 27) {  // 27 is ASCII code for Escape key
                PlaySound(NULL, 0, 0);  // Stop any playing sound
                std::cout << "Sound stopped. Exiting...\n";
                break;  // Exit the loop
            }
            PlaySound(TEXT("megalovania.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
    }
    Sleep(100);
    return 0;
}
