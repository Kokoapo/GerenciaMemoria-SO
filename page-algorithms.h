#include "page-utils.h"
#include <iostream>
using namespace std;

unsigned int OPT(unsigned int *frames, int framesT, unsigned int *referenceString, int refStrT) {
    unsigned int pageFaults = 0;
    int *framesPontos = new int[framesT];
    for (int i = 0; i < framesT; i++)
        framesPontos[i] = 0; 

    int maiorPontos = 0x80000000;
    int frame = -1;
    for (int e = 0; e < refStrT; e++) {
        bool miss = true;
        for (int f = 0; f < framesT; f++) {
            if (frames[f] == 0xFFFFFFFF) {
                frame = f;
                break;
            } else if (frames[f] == referenceString[e]) {
		framesPontos[f] = OPTPontos(referenceString[e], e+1, referenceString, refStrT);
		miss = false;
                break;
            }

            if (maiorPontos < framesPontos[f]) {
                maiorPontos = framesPontos[f];
                frame = f;
            }
        }

        if (miss) {
            frames[frame] = referenceString[e];
            framesPontos[frame] = OPTPontos(referenceString[e], e+1, referenceString, refStrT);
            pageFaults++;
        }
    }

    return pageFaults;
}

unsigned int LRU(unsigned int *frames, int framesT, unsigned int *referenceString, int refStrT) {
    cout << "LRU!\n";
    unsigned int pageFaults = 0;

    int *framesLRU = new int[framesT];
    int frame;
    for(int i = 0; i < framesT; i++)
        framesLRU[i] = 0; 
    
    for(int i = 0; i < refStrT; i++) {
        bool miss = true;
        for(int j = 0; j < framesT; j++) {
            if(frames[j] == 0xFFFFFFFF) {
                frame = j;
                break;
            }
            int pagePos = isPageInFrame(referenceString[i], frames, framesT);
            if(pagePos != -1) {
                frame = pagePos;
                miss = false;
            } else {
                frame = greatestNumInFrame(frames, framesT);
            }
        }

        if(miss) {
            frames[frame] = referenceString[i];
            pageFaults++;
        }

        for(int j = 0; j < framesT; j++) {
            framesLRU[j]++;
        }
        framesLRU[frame] = 0;

        /*printf("[ ");
        for(int j = 0; j < framesT; j++) {
            printf("%u ", frames[j]);
        }
        printf("]\n");*/
    }
    
    return pageFaults;
}