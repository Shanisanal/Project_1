//**************************** PROJECT 1 ****************************** 
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved 
//***************************************************************************** 
// 
// File     : main.c
// Summary  : Removes duplicate characters from a string 
// Note     : None
// Author   : Shani Sanal
// Date     : 10 Feb 2026
// 
//***************************************************************************** 
 
//******************************* Include Files ******************************* 

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

//******************************* Local Types ********************************* 
 
//***************************** Local Constants ******************************* 

#define ARRAY_SIZE  100

//***************************** Local Variables ******************************* 
 
//****************************** Local Functions ****************************** 

//******************************.RemoveDuplicates.****************************** 
// Purpose  :   Removes duplicate characters from an input string and writes the unique characters into the provided output buffer. 
// Inputs   :   pinputString - Pointer to the input string (null-terminated) 
//              pOutputString - Pointer to the caller-provided buffer where the result will be stored 
// Outputs  :   pOutputString - Contains the string with duplicates removed 
// Return   :   uint8_t* - Pointer to the output buffer containing the processed string 
// Notes    :   None
//**********************************************************************************

uint8_t* RemoveDuplicates(uint8_t *pinputString, uint8_t *pOutputString) 
{
    uint16_t unIndex = 0;

    for (int32_t iDx1 = 0; pinputString[iDx1] != '\0'; iDx1++) 
    {
        uint8_t ucChar = pinputString[iDx1];
        bool blPresent = false;

        for (int32_t iDx2 = 0; iDx2 < unIndex; iDx2++) 
        {
            if (pOutputString[iDx2] == ucChar) 
            {
                blPresent = true;
                break;
            }
        }

        if (!blPresent) 
        {
            pOutputString[unIndex++] = ucChar;
        }
    }
    pOutputString[unIndex] = '\0'; 

    return pOutputString; 
}
//************************************.main.*************************************
// Purpose  :   Entry point of the program. Reads an input string from the user,
//              removes duplicate characters using RemoveDuplicates, and 
//              displays the processed result. 
// Inputs   :   None 
// Outputs  :   Prints the output string after removing duplicates from the user input string.
// Return   :   0
// Notes    :   Nil
//********************************************************************************

int main() 
{
    uint8_t ucInputString[ARRAY_SIZE]  = {0};
    uint8_t ucOutputString[ARRAY_SIZE] = {0}; 

    printf("Enter a string: ");
    if (fgets(ucInputString, sizeof(ucInputString), stdin) != NULL) 
    {
        size_t len = strlen(ucInputString);
        if (len > 0 && ucInputString[len - 1] == '\n') 
        {
            ucInputString[len - 1] = '\0';
        }
    }

    uint8_t *ucResult = RemoveDuplicates(ucInputString, ucOutputString);
    
    printf("String without duplicates: %s\n", ucResult);

    return 0;
}
// EOF 

