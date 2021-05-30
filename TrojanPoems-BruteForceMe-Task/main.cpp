#include <Windows.h>
#include <iostream>
/*
Author:
TrojanPoem

Language:
C/C++

Upload:
8:13 PM 04/26/2021

Platform
Windows

Difficulty:
2.0

Quality:
4.0

Description

You are required to attack the target using brute force.Therefore,hook the function responsible for password checking then do brute force using it.

Useful info:
The password consists of 4 letters , all of which are of small letters and no special letters or numbers.

Rules:
1. No patching
2. No reversing the check password function

*/


//check pass func sub_291130
//pass in ecx
/*
lea ecx,dword ptr ds:[ecx+1]
add edx,eax
movsx eax,byte ptr ds:[ecx]
test eax,eax
jne bruteforceme.2911D0
mov ecx,bruteforceme.293315
cmp edx,19F
je bruteforceme.2911EE
*/


#include <stdio.h>
#include <stdlib.h>


void sumandprint(char* arr)
{
    int sum = 0, i = 0;
    while (arr[i] != 0)
        sum += arr[i++];
    if (sum == 0x19F)
        printf("%s\n", arr);
}

int main()
{
    printf("Generating all combinations...\n");
    char arr[5] = "aaaa";
    while (strcmp(arr, "zzzz") != 0)
    {
        sumandprint(arr);
        if (arr[3] != 'z')
        {
            arr[3]++;
            continue;
        }
        if (arr[2] != 'z')
        {
            arr[2]++;
            arr[3] = 'a';
            continue;
        }
        if (arr[1] != 'z')
        {
            arr[1]++;
            arr[2] = 'a';
            arr[3] = 'a';
            continue;
        }
        if (arr[0] != 'z')
        {
            arr[0]++;
            arr[1] = 'a';
            arr[2] = 'a';
            arr[3] = 'a';
            continue;
        }

    }
}
