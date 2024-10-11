#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>  // for _kbhit and _getch
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

#pragma comment(lib,"winmm.lib")


std::vector<std::string> soundProfiles = {"AC/", "Another/"};
int soundProfileIndex = 0;

int main(){
    std::cout << "Press any key! \n";
    srand(static_cast<unsigned int>(time(0)));      
    std::string soundDirectory = "sounds/";                                 
    std::string soundProfilePath = "AC/";                                 // start with animal crossing sound profile
    while (true){
        if (_kbhit()){
            int key = _getch();                                                      // Get the pressed key (non-blocking)
            // Check if the Escape key is pressed to stop the sound
            std::cout << "key" << key<< std::endl;
            if (key == 27) {                                                         // 27 is ASCII code for Escape key
                PlaySound(NULL, 0, 0);                                               // Stop any playing sound
                std::cout << "Sound stopped. Exiting...\n";
                break;                                                               // Exit the loop
            }
            if (key == 9){  // tab key
                try{                                                                // try to swap to the next sound profile
                    soundProfileIndex++;
                    soundProfilePath = soundProfiles.at(soundProfileIndex);
                }
                catch(std::out_of_range){                                           // if out of range, go back to the first sound profile
                    soundProfileIndex = 0;
                    soundProfilePath = soundProfiles.at(soundProfileIndex);
                }
            }
            PlaySound(NULL, 0, 0); 
            int audioNum = rand() % 18;                                              // get number between 0 and 17
            audioNum++;                                                              // +1 to get between 1 and 18
            std::cout << std::endl << soundDirectory + soundProfilePath;
            std::string audioFile = soundDirectory + soundProfilePath + std::to_string(audioNum) + ".wav";   // generate file name

            PlaySound(audioFile.c_str(), NULL, SND_FILENAME | SND_ASYNC);
        }
    }
    return 0;
}
