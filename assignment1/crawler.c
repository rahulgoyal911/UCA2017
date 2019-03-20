#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#define urlLength 1000
#define Base_Url "www.chitkara.edu.in"
static char name='a';

typedef struct LinkList  // structure for linked list
{
	 int Link_key;
   int Link_flag;
   char *Link_url;
   struct LinkList *Link_next;
   int Link_depth;
}LinkList;

struct Hashing  // structure for hashing
{
	struct LinkList *first;
	struct LinkList *last;
	int count;
};

struct Hashing hash[50];
LinkList *Head=NULL;
LinkList *last=NULL;

// void putInLinked(int key,char *links){
//  struct LinkList 
// }

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

int Check_Dir(char* argv[]) //function to check weather directory exists and we have permissions or not
{
    struct stat statbuf;
    if( stat(argv[3],&statbuf) == -1)
    {
        char str[100]="mkdir ";
        printf("%s",argv[3]);
        strcat(str,argv[3]);
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

void removeWhiteSpace(char* html) //removing white spaces from fetched page to extract links in it
{
  int i;
  char *buffer = (char *)malloc(strlen(html)+1), *p=(char *)malloc(sizeof(char)+1);
  memset(buffer,0,strlen(html)+1);
  for (i=0;html[i];i++)
  {
    if(html[i]>32)
    {
      sprintf(p,"%c",html[i]);
      strcat(buffer,p);
    }
  }
  strcpy(html,buffer);
  free(buffer); free(p);
}

int GetNextURL(char* html, char* urlofthispage, char* result, int pos) //to get next url present in fetched page will store it in result and return the index of last traversed point
{
  char c;
  int len, i, j;
  char* p1;  //!< pointer pointed to the start of a new-founded URL.
  char* p2;  //!< pointer pointed to the end of a new-founded URL.

  // NEW
  // Clean up \n chars
  if(pos == 0) {
    removeWhiteSpace(html);
  }
  // /NEW

  // Find the <a> <A> HTML tag.
  while (0 != (c = html[pos]))
  {
    if ((c=='<') &&
        ((html[pos+1] == 'a') || (html[pos+1] == 'A'))) {
      break;
    }
    pos++;
    //printf("%c\n", html[pos]);
  }
  //! Find the URL it the HTML tag. They usually look like <a href="www.abc.com">
  //! We try to find the quote mark in order to find the URL inside the quote mark.
  if (c)
  {
    // check for equals first... some HTML tags don't have quotes...or use single quotes instead
    //printf("%c\n", html[pos]);

    p1 = strchr(&(html[pos+1]), '=');

    if ((!p1) || (*(p1-1) == 'e') || ((p1 - html - pos) > 10))
    {
      // keep going...
      return GetNextURL(html,urlofthispage,result,pos+1);
    }
    if (*(p1+1) == '\"' || *(p1+1) == '\'')
      p1++;

    p1++;;

    p2 = strpbrk(p1, "\'\">");
    if (!p2)
    {
      // keep going...
      return GetNextURL(html,urlofthispage,result,pos+1);
    }
    if (*p1 == '#')
    { // Why bother returning anything here....recursively keep going...

      return GetNextURL(html,urlofthispage,result,pos+1);
    }
    if (!strncmp(p1, "mailto:",7))
      return GetNextURL(html, urlofthispage, result, pos+1);
    if (!strncmp(p1, "http", 4) || !strncmp(p1, "HTTP", 4))
    {
      //! Nice! The URL we found is in absolute path.
      strncpy(result, p1, (p2-p1));
      return  (int)(p2 - html + 1);
    } else {
      //! We find a URL. HTML is a terrible standard. So there are many ways to present a URL.
      if (p1[0] == '.') {
        //! Some URLs are like <a href="../../../a.txt"> I cannot handle this.
	// again...probably good to recursively keep going..
	// NEW

        return GetNextURL(html,urlofthispage,result,pos+1);
	// /NEW
      }
      if (p1[0] == '/') {
        //! this means the URL is the absolute path
        for (i = 7; i < strlen(urlofthispage); i++)
          if (urlofthispage[i] == '/')
            break;
        strcpy(result, urlofthispage);
        result[i] = 0;
        strncat(result, p1, (p2 - p1));
        return (int)(p2 - html + 1);
      } else {
        //! the URL is a absolute path.
        len = strlen(urlofthispage);
        for (i = (len - 1); i >= 0; i--)
          if (urlofthispage[i] == '/')
            break;
        for (j = (len - 1); j >= 0; j--)
          if (urlofthispage[j] == '.')
              break;
        if (i == (len -1)) {
          //! urlofthis page is like http://www.abc.com/
            strcpy(result, urlofthispage);
            result[i + 1] = 0;
            strncat(result, p1, p2 - p1);
            return (int)(p2 - html + 1);
        }
        if ((i <= 6)||(i > j)) {
          //! urlofthis page is like http://www.abc.com/~xyz
          //! or http://www.abc.com
          strcpy(result, urlofthispage);
          result[len] = '/';
          strncat(result, p1, p2 - p1);
          return (int)(p2 - html + 1);
        }
        strcpy(result, urlofthispage);
        result[i + 1] = 0;
        strncat(result, p1, p2 - p1);
        return (int)(p2 - html + 1);
      }
    }
  }
  return -1;
}
char* load_file(char const* path) //to get data from downloaded file
{
    char* buffer = 0;
    long length;
    FILE * f = fopen (path, "rb"); //was "rb"

    if (f)
    {
      fseek (f, 0, SEEK_END);
      length = ftell (f);
      fseek (f, 0, SEEK_SET);
      buffer = (char*)malloc ((length+1)*sizeof(char));
      if (buffer)
      {
        fread (buffer, sizeof(char), length, f);
      }
      fclose (f);
    }
    buffer[length] = '\0';

    return buffer;
}
void transferFile() //transfer file to moved directory after fetching urls from it
{
  system("mkdir asd/moved");
  char str[40] = "mv asd/temp.txt asd/moved/";
  str[strlen(str)] += name;
  str[strlen(str)+1] += '\n';
  // strcat(str,str(i));
  strcat(str,".txt");
  system(str);
  system("mv temp.txt asd/moved/");
  name++;
}
char** get_Page(char *url,char* argv[])  // function to fetch url from user and contact in urlBuffer and fetch page source code and add it to temp file
{
    char urlBuffer[urlLength + 300] = {0};
    strcat(urlBuffer, "wget -O ./");
    strcat(urlBuffer,argv[3]);
    strcat(urlBuffer, "/temp.txt ");
    strcat(urlBuffer, url);
    system(urlBuffer);
    strcat(argv[3],"/temp.txt");
    char *html=load_file(argv[3]);

    printf("Page fetched successfully");
    char *result;
   
    int ans=0;
    char **links;
    links=(char **)malloc(sizeof(char *)*101);
    for(int i=0;i<100;i++){
      links[i] = (char *)malloc(sizeof(char)*200);
    }
    int len=100;
    int flag=0;
     
    ans=GetNextURL(html, argv[1],result ,0);
    int l=0;
    
    strcpy(links[l++],result);

    while(l<100)
    {

      ans=GetNextURL(html, argv[1],result ,ans);
      
      for(int j=0;j<l;j++)
      {
        if(strcmp(result,links[j])==0)
        {
          flag=1;
          break;
        }
      }
      if(flag==0){
       strcpy(links[l++],result);
      }
      else{
       ans=GetNextURL(html, argv[1],result ,ans);
       flag=0;
      }
    }

  for(int i=0;i<l;i++){
    // printf("\n%s",links[i]);
  }
  //now there are 100 unique links in array named 'links'
  transferFile();
return links;
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

int Find_Key(char *link)
{
	int i=0,key=0;
	while(link[i]!='\0')
	{
	  key+=(int)link[i++];
	}
	while(key>100)
	{
	  key/=10;
	}
	return key;
}


int main(int argc,char* argv[])
{
  char **links;
    Check_Arguments(argc,argv);
    links = get_Page(argv[1],argv);
    for(int i=0;i<100;i++)
    {
        // printf("\n%d - %s",i,links[i]);
        int key = Find_Key(links[i]);
        printf("\n%d - %s - %d ",i,links[i] , key);
        putInLinked(key,links[i]);
  }
}
