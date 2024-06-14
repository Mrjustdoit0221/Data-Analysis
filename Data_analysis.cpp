#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
void even(int array[], int l)
{
    cout << "Even numbers in data are : " << endl;
    for (int i = 0; i < l; i++)
    {
        if (array[i] % 2 == 0)
            cout << array[i] << "\t";
    }
    cout << endl;
}
void odd(int array[], int l)
{
    cout << "Odd numbers in data are : " << endl;
    for (int i = 0; i < l; i++)
    {
        if (array[i] % 2 != 0)
            cout << array[i] << "\t";
    }
    cout << endl;
}
void prime(int array[], int l)
{
    int f = 0;
    cout << "Prime numbers in data are : " << endl;
    for (int i = 0; i < l; i++)
    {
        if (array[i] == 0 || array[i] == 1)
            continue;
        for (int j = 2; j <= array[i] / 2; j++)
        {
            if (array[i] % j == 0)
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            cout << array[i] << "\t";
        }
        f = 0;
        cout << endl;
    }
}
double average(int array[], int l)
{
    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum = array[i] + sum;
    }
    cout << "The average of the data is " << sum / l << ".";
    cout << endl;
    return sum/l;
}
void largest(int array[], int l)
{
    int large = array[0];
    for (int i = 0; i < l; i++)
    {
        if (array[i] >= large)
            large = array[i];
    }
    cout << "The Greatest number in data is  " << large << ".";
    cout << endl;
}
void smallest(int array[], int l)
{
    int small = array[0];
    for (int i = 0; i < l; i++)
    {
        if (array[i] <= small)
            small = array[i];
    }
    cout << "The Smallest number in data is  " << small << ".";
    cout << endl;
}
void meadian(int array[], int l)
{
    sort(array, array + l);
    if (l % 2 == 1)
    {
        cout << "Median of data is " << array[l / 2]<<"."<<endl;
    }
    else
    {
        int mid1 = l / 2 - 1;
        int mid2 = l / 2;
        cout << "Median of data is " << (array[mid1] + array[mid2]) / 2.0<<"."<<endl;
    }
}
void mode(int array[], int l)
{
    sort(array, array + l);
    int mode = array[0];
    int maxCount = 1;
    int currentCount = 1;
    for (int i = 1 ; i < l; ++i)
    {
        if(array[i]==array[i-1]){
            ++currentCount;
        }
        else{
        
        if(currentCount>maxCount){
            maxCount=currentCount;
            mode=array[i-1];
        }
           currentCount=1;
        }
    }
       if (currentCount > maxCount) {
        maxCount = currentCount;
        mode = array[l - 1];
    }
    cout<<"The mode of the data is "<<mode<<"."<<endl;
}
double Varience(int array[],int l,double a){
    double dev=0,x,var;
    for (int i = 0; i < l ; ++i)
    {
        x=((array[i]-a)*(array[i]-a));
        dev=dev+x;
    }
    var=dev/(l-1);
    cout<<"The Varience of the data is "<<var<<"."<<endl;
    return var;
}
double SD(int array[],int l,double var){
    double SD=sqrt(var);
    cout<<"The Standerd Deviation  of the data is "<<SD<<"."<<endl;
}
int main()
{
    int l = 0;
    cout << "Enter the amount of numbers: ";
    cin >> l;
    int data[l];
    cout << "Enter " << l << " numbers (only positive):    " << endl;
    for (int i = 0; i < l; i++)
    {
        cin >> data[i];
        if (data[i] < 0)
        {
            cout << "You entered a negative number";
            return 1;
        }
    }
    even(data, l);
    odd(data, l);
    prime(data, l);
    double avg=average(data, l);
    largest(data, l);
    smallest(data, l);
    meadian(data, l);
    mode(data, l);
    double var=Varience(data,l,avg);
    SD(data,l,var);
    return 0;
}