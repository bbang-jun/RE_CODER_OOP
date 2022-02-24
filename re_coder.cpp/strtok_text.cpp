#define _CRT_SECURE_NO_WARNINGS //scanf오류방지
#include <iostream>
#include <cstring>    //C++ : <cstring>

using namespace std;
int main(void)
{
    string cmd;     //commend
    string num;     //number
    string temp;    //commend + number
    char str[100];// = "Kim,Park,Lee,Choi,Seo";
    cin >> cmd;
    cin >> num;
    temp += cmd;
    temp += " ";
    temp += num;

    cout << "cmd: " << cmd << endl;
    cout << "num: " << num << endl;
    cout << "temp: " << temp << endl;

    strcpy(str, temp.c_str());

    char* ptr = strtok(str, " ");
    cout << "str: " << str << endl;

    cout << ptr << endl;

    ptr = strtok(NULL, " ");
    printf("%s\n", ptr);

    / ptr = strtok(NULL, " ");
    printf("%s\n", ptr);

    ptr = strtok(NULL, " ");
    printf("%s\n", ptr);

    ptr = strtok(NULL, " ");
    printf("%s\n", ptr);

    ptr = strtok(NULL, " ");
    printf("%s\n", ptr); /

        return 0;
}