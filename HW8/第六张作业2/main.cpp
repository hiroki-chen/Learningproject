#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int number;
    cin>>number;
    int *sequence = new int [number];
    for (int i = 0; i < number; i++) {
        cin>>sequence[i];
    }
    void averagecalculation(int *array, int length);
    void maximumcalculation(int *array, int length);
    averagecalculation(sequence, number);
    maximumcalculation(sequence, number);
    delete [] sequence;
    return 0;
}
void averagecalculation(int *array, int length){
    double sum = 0;
    double average;
    for (int i = 0; i < length; i++) {
        sum += *(array + i);
    }
    average = sum/length;
    cout<<average<<endl;
}
void maximumcalculation(int *array, int length){
    int maximum;
    maximum = array[0];
    for(int i = 1;i <= length;i++){
        for(int j = 0;j < length;j++){
            if (array[j] >= maximum) {
                maximum = array[j];
        }
    }
}
    cout<<maximum<<endl;
}

