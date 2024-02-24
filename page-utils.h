int OPTPontos(unsigned int end, int posI, unsigned int *referenceString, int refStrT) {
    int pontos = 1;

    for (int i = posI; i < refStrT; i++) {
        if (referenceString[i] == end)
            break;
        pontos++;
    }

    return pontos;
}

int isPageInFrame(unsigned int page, unsigned int *frames, int framesT) { //Retorna a posição da página nos frames. Caso page fault, retorna -1
    for(int i = 0; i < framesT; i++) {
        if(page == frames[i]) {return i;}
    }
    return -1;
}

int greatestNumInFrame(unsigned int *frames, int framesT) { //Retorna a posição do maior número nos 
    int greatest = frames[0];
    int greatPos = 0;
    for(int i = 1; i < framesT; i++) {
        if(frames[i] > greatest) {
            greatest = frames[i];
            greatPos = i;
        }
    }
    return greatPos;
}