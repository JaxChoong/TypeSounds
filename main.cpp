#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>  // for _kbhit and _getch
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#pragma comment(lib,"winmm.lib")


int main(){
    std::cout << "Press any key! \n";
    srand(static_cast<unsigned int>(time(0)));                                       // generate seed for randomizer
    while (true){
        if (_kbhit()){
            PlaySound(NULL, 0, 0); 
            int key = _getch();                                                      // Get the pressed key (non-blocking)
            // Check if the Escape key is pressed to stop the sound
            std::cout << char(key);
            if (key == 27) {                                                         // 27 is ASCII code for Escape key
                PlaySound(NULL, 0, 0);                                               // Stop any playing sound
                std::cout << "Sound stopped. Exiting...\n";
                break;                                                               // Exit the loop
            }
            int audioNum = rand() % 18;                                              // get number between 0 and 17
            audioNum++;                                                              // +1 to get between 1 and 18
            std::string audioFile = "sounds/" + std::to_string(audioNum) + ".wav";   // generate file name

            PlaySound(audioFile.c_str(), NULL, SND_FILENAME | SND_ASYNC |SND_NOSTOP);
        }
    }
    return 0;
}
