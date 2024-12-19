#include "types.h"
#include <stdio.h>
#include <string.h>
int str_hex(char *hexstr)
{
    int result = 0;
    for(int i=0;i<4;i++)
    {
        result <<= 8;
        result |= hexstr[i];
    }
    return result;
}
int view_tager (FILE *r)
{
    printf("\n------------------------------------Selected View Details-----------------------------------\n\n");
    printf("--------------------------------------------------------------------------------------------\n\t\t\t\tMP3 Tag Reader And Editor For ID3v2\n");
    printf("------------------------------------Selected View Details-----------------------------------\n");
    char str[128]="0",buffer[4]="0";
    int i=0;
    fread(str,1,4,r);
    if(strcmp(str,"TIT2") == 0)
    {
        char srt1[4]="0";

        fread(srt1,1,4,r);
        int size=str_hex(srt1);
        fseek(r,2,SEEK_CUR);
        fread(str,size,1,r);
        printf("Title\t\t:\t");
        for(i = 0;i < size;i++)
            printf("%c",str[i]);
        printf("\n");
        fread(str,4,1,r);
        str[4] = '\0';
        if(strcmp(str,"TPE1") == 0)
        {
            fread(srt1,1,4,r);
            size=str_hex(srt1);
            fseek(r,2,SEEK_CUR);
            fread(str,size,1,r);
            str[size] = '\0';
            printf("Artist\t\t:\t");
            for(i = 0;i < size;i++)
                printf("%c",str[i]);
            printf("\n");
        }
        fread(str,4,1,r);
        str[4] = '\0';
        if(strcmp(str,"TALB") == 0)
        {
            fread(srt1,1,4,r);
            size=str_hex(srt1);
            fseek(r,2,SEEK_CUR);
            fread(str,size,1,r);
            str[size] = '\0';
            printf("Album\t\t:\t");
            for(i = 0;i < size;i++)
                printf("%c",str[i]);
            printf("\n");
        }
        fread(str,4,1,r);
        str[4] = '\0';
        if(strcmp(str,"TYER") == 0)
        {
            fread(srt1,1,4,r);
            size=str_hex(srt1);
            fseek(r,2,SEEK_CUR);
            fread(str,size,1,r);
            str[size] = '\0';
            printf("Year\t\t:\t");
            for(i = 0;i < size;i++)
                printf("%c",str[i]);
            printf("\n");
        }
        fread(str,4,1,r);
        str[4] = '\0';
        if(strcmp(str,"TCON") == 0)
        {
            fread(srt1,1,4,r);
            size=str_hex(srt1);
            fseek(r,2,SEEK_CUR);
            fread(str,size,1,r);
            str[size] = '\0';
            printf("Content\t\t:\t");
            for(i = 0;i < size;i++)
                printf("%c",str[i]);
            printf("\n");
        }
        fread(str,4,1,r);
        str[4] = '\0';
        if(strcmp(str,"COMM") == 0)
        {
            fread(srt1,1,4,r);
            size=str_hex(srt1);
            fseek(r,2,SEEK_CUR);
            fread(str,size,1,r);
            str[size] = '\0';
            printf("Comment\t\t:\t");
            for(i = 0;i < size;i++)
                printf("%c",str[i]);
            printf("\n");
        }
        printf("offset is %ld\n",ftell(r));
        printf("--------------------------------------------------------------------------------------------\n\n");
        printf("------------------------------Details Displayed Successfully--------------------------------\n\n");
        return e_success;
    }
    else
    {
        printf("they are not same\n");
        return e_failure;
    }
}

