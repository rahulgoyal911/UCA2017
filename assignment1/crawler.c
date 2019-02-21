
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<sys/types.h>
// #include<sys/stat.h>

// #define BASE_URL "www.chitkara.edu.in"
// #define urlLength 1000
// int checkArgueCount(int argc) {
//     if(argc == 4) 
//         return 1;
//     printf("Arguement are not passed as specified");
//     exit(0);
// }
// int checkDepth(char* argv[]) {

//     int depth;
//     sscanf(argv[2], "%d", &depth);
//     if(depth < 0) {
//         printf("Depth is not allowed in negative");
//         exit(0);
//     }  
//     return 1;
// }
// int checkUrl(char* argv[]) {

//     if(strcmp(BASE_URL, argv[1])) {
        
//        printf("Url is not correct");
//        exit(0); 
        
//     } 
//     return 1;
// }
// void check(int argc, char *argv[]) {
//     if(checkArgueCount(argc)) {
//         if(checkDepth(argv)) {
//             if(checkUrl(argv)) {
//                 printf("All things are correct");
//             }
//         }
//     }
// }
// void getPage(char *url) {
//     char urlBuffer[urlLength + 300] = {0};
//     strcat(urlBuffer, "wget -O ");
//     strcat(urlBuffer, "./htmlIntxt.txt ");
//     strcat(urlBuffer, url);
//     system(urlBuffer);
// }
// int main(int argc, char* argv[]) {

//     check(argc, argv);
//     getPage(argv[1]);

// }


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

#define urlLength 1000
#define Base_Url "www.chitkara.edu.in"

int Check_Argument(int check)  // function to check wheater user has entered total 3 arguments or not!!
{
    if(check==4)
        return 1;
        printf("ARGUMENTS ARE NOT PROPER");
        exit(0);
}

int Check_Depth(char* argv[])  // function to check wheater depth entered in postive or negative!!
{
    int depth;
    sscanf(argv[2], "%d" , &depth);
    if(depth<0)
    {
        printf("DEPTH CAN'T BE NEGATIVE");
        exit(0);
    }
    if(depth>30){
        printf("DEPTH IS TOO HIGH");
        exit(0);
    }
    return 1;
}
int Check_Url(char* argv[])  // function to check wheater url is correct or not!!
{
    char v[]="wget --spider ";
    char *b = (char*)malloc(sizeof(char)*300);
    strcat(b,"wget --spider ");
    strcat(b,argv[1]);
    if(!system(b))
    {
        if(strcmp(Base_Url,argv[1]))
        {
            printf("URL IS NOT CORRECT");
            exit(0);
        }
        else
            return 1;
    }
}

int Check_Dir(char* argv[])
{
    struct stat statbuf;
    if( stat(argv[3],&statbuf) == -1)
    {
        char str[100]="mkdir ";
        strcat(str,argv[3]);
        printf("%s",argv[3]);
        system(str);
        return 1;
    
    }
    if( !S_ISDIR(statbuf.st_mode))
    {
        printf("Invalid directory entry.Your input is't a directory\n");
        exit(0);
    }
    if( (statbuf.st_mode & S_IWUSR) !=S_IWUSR)
    {
        printf("Invalid directory entry. It isn't writable\n");
        exit(0);
    }
    return 1;
}

void get_Page(char *url)  // function to fetch url from user and contact in urlBuffer and fetch page source code and add it to temp file
{
    char urlBuffer[urlLength + 300] = {0};
    strcat(urlBuffer, "wget -O ");
    strcat(urlBuffer, "./temp.txt ");
    strcat(urlBuffer, url);
    system(urlBuffer);
    system("clear");
    printf("Page fetched successfully");
}

void Check_Arguments(int argc,char* argv[])  // function to check whether all arguments are correct or not!!
{
    	if(Check_Argument(argc))
        {
            if(Check_Depth(argv))
            {
                if(Check_Url(argv))
                {
                    system("clear");
                    printf("URL is corrent");
                    if(Check_Dir(argv))
                    {
                        printf("All Arguments are correct\n");
                    }
                }
            }
        }
}

int main(int argc,char* argv[])
{
    Check_Arguments(argc,argv);
    get_Page(argv[1]);
}