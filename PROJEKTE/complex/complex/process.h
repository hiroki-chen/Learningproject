#ifndef process_h
#define process_h
void maxfunc(int &x, int &y){
    if(y > x) {
        int temp = x;
        x = y;
        y = temp;
    }
}
void yuefen(int &x, int &y){
    int r;
    int tempx = x, tempy = y;
    maxfunc(tempx,tempy);
    while(tempy != 0){
        r = tempx % tempy;
        tempx = tempy;
        tempy = r;
    }
    x = x / tempx;
    y = y / tempx;
}

#endif /* process_h */
