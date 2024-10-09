#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>  // for kbhit and getch
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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
            srand(time(0));  // generate seed for randomiser
            int audioNum = rand() % 18; // get number between 0 and 17
            audioNum++;  // +1 to get between 1 and 18
            std::cout << "this is audioNum" +  std::to_string(audioNum) + "heh\n";
            std::string audioFile = "sounds/" + std::to_string(audioNum) + ".wav";   // generate file name
            std::cout << audioFile;
            const char* audioFileCStr = audioFile.c_str(); // get acceptable string format for TEXT()
            PlaySound(audioFileCStr, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            if (GetLastError() != 0) {
                std::cout << "Error playing sound: " << GetLastError() << std::endl;
            }
        }
    }
    Sleep(100);
    return 0;
}
