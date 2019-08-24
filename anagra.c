/*Q.Given two strings, check if they’re anagrams or not. Two strings are
anagrams if they are written using the same exact letters, ignoring
space, punctuation and capitalization. Each letter should have the same
count in both strings.*/


#include <stdio.h>

int find_anagram(char string1[], char string2[])
{
    int num1[26] = {0}, num2[26] = {0}, i = 0;
 
    while (string1[i] != '\0')
    {
        num1[string1[i] - 'a']++;
        i++;
    }
    i = 0;
    while (string2[i] != '\0')
    {
        num2[string2[i] -'a']++;
        i++;
    }
    for (i = 0; i < 26; i++)
    {
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;
} 

void lower_string(char s[]) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'A' && s[c] <= 'Z') {
         s[c] = s[c] + 32;
      }
      c++;
   }
}

void remove_pun(char string[])
{
    int i,j;
    for(i = 0; string[i] != '\0'; ++i)
    {
        while (!( (string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') || string[i] == '\0') )
        {
            for(j = i; string[j] != '\0'; ++j)
            {
                string[j] = string[j+1];
            }
            string[j] = '\0';
        }
    }
}


int main()
{
    char string1[100], string2[100];
    int count,i,j;


    printf("Enter the string\n");
    fgets(string1,100,stdin);
    
    printf("Enter another string\n");
    fgets(string2,100,stdin);


remove_pun(string1);
remove_pun(string2);
lower_string(string1);
lower_string(string2);

    count = find_anagram(string1,string2);
    if (count == 1)
        printf("Are anagrams.\n");
    else
        printf("Are Not anagrams.\n");

    return 0;
}
 

 /*OUTPUT 
 vaishnavi@pucsd:~/plc$ gcc anagra.c
vaishnavi@pucsd:~/plc$ ./a.out 
Enter the string
eleven plus two
Enter another string
twelve plus one
Are anagrams.
vaishnavi@pucsd:~/plc$
*/




