#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>  // for _kbhit and _getch
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <filesystem>

#pragma comment(lib,"winmm.lib")


std::vector<std::string> soundProfiles = {"AC/", "Another/"};
int soundProfileIndex = 0;
std::string soundDirectory = "sounds/";
std::string soundProfilePath = "AC/";                                 // start with animal crossing sound profile
std::string combinedPath = soundDirectory + soundProfilePath;

int countFilesInDirectory(const std::string& directoryPath){
    // count number of files in directory
    int count = 0;
    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)){
        count++;
    }
    return count;
}

int fileCount = countFilesInDirectory(combinedPath);

int main(){
    std::cout << "Press any key! \n";
    srand(static_cast<unsigned int>(time(0)));                                       
    
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
                combinedPath = soundDirectory + soundProfilePath;
                fileCount = countFilesInDirectory(combinedPath);
                std::cout << "Sound profile changed to " << soundProfilePath << std::endl;
                std::cout << "Number of files in directory: " << fileCount << std::endl;
            }
            PlaySound(NULL, 0, 0); 
            int audioNum = rand() % fileCount;                                              // get number between 0 and 17
            audioNum++;                                                              // +1 to get between 1 and 18
            std::cout << std::endl << combinedPath;
            std::string audioFile = combinedPath + std::to_string(audioNum) + ".wav";   // generate file name

            PlaySound(audioFile.c_str(), NULL, SND_FILENAME | SND_ASYNC);
        }
    }
    return 0;
}
