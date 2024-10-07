#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>

#pragma comment(lib,"winmm.lib")

int main(){
    std::cout << "Playing Music \n";
    PlaySound(TEXT("megalovania.wav"),NULL,SND_FILENAME |SND_ASYNC | SND_LOOP);
    Sleep(5000);
    return 0;
}
