/*
Consider the problem of searching for a pattern in a given string. Design a program to locate
the pattern using Horspool’s algorithm. Give the trace of this algorithm. Find its time
complexity.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 256

void shiftTable(char p[], int t[]) 
{
    int m=strlen(p);
    for(int i=0; i<MAX; i++) t[i]=m;
    for(int j=0; j<m-1; j++) t[p[j]]=m-1-j;
}

int horspool(char s[], char p[], int t[])
{
    int n=strlen(s);
    int m=strlen(p);
    int i=m-1;
    while(i<n) {
        int k=0;
        while(k<m && p[m-1-k]==s[i-k]) k++;
        if(k==m) return i-m+1;
        else i+=t[s[i]];
    }
    return -1;
}

int main()
{
    char source[MAX];
    char pattern[MAX];
    int table[MAX];
    printf("Enter the source string: ");
    gets(source);
    printf("Enter the pattern string: ");
    gets(pattern);
    shiftTable(pattern, table);
    int found=horspool(source, pattern, table);
    if(found==-1) {
        printf("Matching string not found\n");
    } else {
        printf("Matching string found at position %d\n", found+1);
    }
}