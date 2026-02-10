//**************************** PROJECT X ****************************** 
//  Copyright (c) 2021 Trenser 
//  All Rights Reserved 
//***************************************************************************** 
// 
// File     : main.c
// Summary  : Removes duplicate characters from a string 
// Note     : 
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
//******************************.FUNCTION_HEADER.****************************** 
// Purpose : Removes duplicate characters from an input string and writes the unique characters into the provided output buffer. 
// Inputs : pinputString - Pointer to the input string (null-terminated) 
//          pOutputString - Pointer to the caller-provided buffer where the // result will be stored 
// Outputs : pOutputString - Contains the string with duplicates removed 
// Return : uint8_t* - Pointer to the output buffer containing the // processed string 
// Notes :
//**********************************************************************************

uint8_t* ucRemoveDuplicates(uint8_t *pinputString, char *pOutputString) 
{
    uint16_t unIndex = 0;

    for (int32_t iDx1 = 0; pinputString[iDx1] != '\0'; iDx1++) 
    {
        uint8_t unChar = pinputString[iDx1];
        bool blPresent = false;

        // Check manually if c is already in uniqueString
        for (int32_t iDx2 = 0; iDx2 < unIndex; iDx2++) 
        {
            if (pOutputString[iDx2] == unChar) 
            {
                blPresent = true;
                break;
            }
        }

        if (!blPresent) 
        {
            pOutputString[unIndex++] = unChar;
        }
    }
    pOutputString[unIndex] = '\0'; // null terminate

    return pOutputString; // return pointer to caller's buffer
}
//*********************** Class Method Implementations ************************ 
 
int main() 
{
    uint8_t ucInputString[ARRAY_SIZE];
    uint8_t ucOutputString[ARRAY_SIZE]; // caller provides buffer

    printf("Enter a string: ");
    if (fgets(ucInputString, sizeof(ucInputString), stdin) != NULL) 
    {
        size_t len = strlen(ucInputString);
        if (len > 0 && ucInputString[len - 1] == '\n') 
        {
            ucInputString[len - 1] = '\0';
        }
    }

    uint8_t *ucResult = ucRemoveDuplicates(ucInputString, ucOutputString);
    
    printf("String without duplicates: %s\n", ucResult);

    return 0;
}
// EOF 

