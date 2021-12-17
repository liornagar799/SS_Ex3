#define TXT 1024
#define WORD 30
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/////////////////////1////////////////////////
char* cut(char str[], int len, int i , int j){
    char* str_cnt=(char*)malloc(TXT + 1);
    int g=0;
  for (int k = i; k <= j; k++)
  {
   str_cnt[g]=str[k];
   g++;
  }
 return str_cnt;
}

int isEqualSum(char s2[],char s1[], int t, int w) {
int sum_s1= 0;
    for (int i=0; i < w; i++) {
        if(s1[i] <= 90 && s1[i] >= 65){
	            sum_s1 += s1[i]-'A'+ 1;
	        }
         else if (s1[i] <= 122 && s1[i] >= 97){
	            sum_s1 += s1[i]-'a'+1;
	        }
    
    }
    int sum_s2=0;
    for (int i=0; i < t; i++) {
        if(s2[i] <= 90 && s2[i] >= 65){
	        sum_s2 += s2[i]-'A'+ 1;}
	  else   if (s2[i] <= 122 && s2[i] >= 97){
	        sum_s2 += s2[i]-'a'+1;}
	   
    }
  if (sum_s2!=sum_s1)
  {
    return 0;
  }
  
return 1;
}

int GematriaSequences(char *str, char *word, int lenTEXT, int lenWORD){
printf("Gematria Sequences: ");   
int x=0;
 for (int i = 0; i < lenTEXT; i++){
 for (int j = 0; j < lenTEXT; j++){
     int counter= isEqualSum(cut(str,lenTEXT, i ,j), word ,strlen(cut(str,lenTEXT, i ,j)), lenWORD);
        if (counter==1){ 
        char a[strlen(cut(str,lenTEXT, i ,j))];
        strcpy(a,cut(str,lenTEXT, i ,j));
        if(((a[0]<=90 && a[0]>=65) || (a[0]<=122&& a[0]>=97))&& ((a[strlen(a)-1]<=90 && a[strlen(a)-1]>=65) || (a[strlen(a)-1]<=122&& a[strlen(a)-1]>=97))){
        x++;
        if (x>1){
         printf("~");
         }
        for (int i = 0; i <strlen(a); i++)
        {  
           printf("%c",a[i]); 
        }}}}}
printf("\n");
 }

/////////////////////////2///////////////////////////////
int same(char *s2, char *s1, int t, int w){
    if(t!= w){
       return 0;
   }
    int idx_S2 = 0;
    int idx_S1 = 0;
    while(idx_S2<strlen(s2) && idx_S1<strlen(s1)){
        if(s2[idx_S2]==' '){
         idx_S2++;
        }else{
            if(s1[idx_S1] != s2[idx_S2]){
              return 0;
            }
            idx_S1++;
            idx_S2++;
      }}
      if (idx_S1<strlen(s1))
       return 0;

    return 1;
}

 void AtbashSequences(char *str, char *word, int lenTEXT, int lenWORD){
      printf("Atbash Sequences: ");
      for(int i=0; i<lenWORD; i++){
       if (word[i]>='a'&& word[i]<='z')
       {
           char c=word[i];
          word[i]= 'z'-c+'a';
       }

        if (word[i]>='A'&& word[i]<='Z')
       {
           char c=word[i];
           word[i]= 'Z'-c+'A';
       }  
     }
     char w[lenWORD];
     strcpy(w,word);
     char temp;
     int end_index=strlen(w)-1;
     for (int i=0 ; i <= end_index/2;++i)
     {
        temp= w[i];
        w[i]= w[end_index-i];
        w[end_index-i]=temp;
     }
     int x=0;
    for (int i = 0; i < lenTEXT; i++){
    for (int j = 0; j < lenTEXT; j++){
     int counter= same(cut(str,lenTEXT, i ,j), word ,strlen(cut(str,lenTEXT, i ,j)), lenWORD);
     int counter_r=same(cut(str,lenTEXT, i ,j), w ,strlen(cut(str,lenTEXT, i ,j)), lenWORD);
    if ((counter==1)||(counter_r==1)){
        char a[strlen(cut(str,lenTEXT, i ,j))];
        strcpy(a,cut(str,lenTEXT, i ,j));
        if((a[0]!=' ')&&(a[strlen(a)-1]!=' ')){
        x++;
        if (x>1){
        printf("~");
     }
        for (int i = 0; i <strlen(a); i++)
        {
           printf("%c",a[i]); 
      }}}}}
printf("\n");
 }

///////////////////////////3/////////////////////////////
int sameStr(char* s,char* wo, int t, int w) {
if(strlen(s)<strlen(wo)){
return 0;
}
    for (int i = 0; i < t-1; i++) {
      for (int j =0; j < t-i-1; j++) { 
         if (s[j] > s[j+1]) {
            char temp = s[j];
            s[j] = s[j+1];
            s[j+1] = temp;
         }}}
  
for (int i = 0; i < w-1; i++) {
for (int j = 0; j < w-i-1; j++) {
 if (wo[j] > wo[j+1]) {
            char cnt = wo[j];
            wo[j] = wo[j+1];
            wo[j+1] = cnt;
         }}}

    int idx_S2 = 0;
    int idx_S1 = 0;
    while(idx_S2<strlen(s) && idx_S1<strlen(wo)){
        if(s[idx_S2]==' '){
         idx_S2++;
        }else{
            if(wo[idx_S1] != s[idx_S2]){
              return 0;
            }
            idx_S1++;
            idx_S2++;
      }}
      if (idx_S2<strlen(s))
       return 0;
       if (idx_S1<strlen(wo))
       return 0;

return 1;
}

void AnagramSequences(char *str, char *word, int lenTEXT, int lenWORD){
printf("Anagram Sequences: ");   
int x=0;
 for (int i = 0; i < lenTEXT; i++){
 for (int j = 0; j < lenTEXT; j++){
     int counter= sameStr(cut(str,lenTEXT, i ,j), word ,strlen(cut(str,lenTEXT, i ,j)), lenWORD);
  if (counter==1)
    {  
        char a[strlen(cut(str,lenTEXT, i ,j))];
        strcpy(a,cut(str,lenTEXT, i ,j));
        if((a[0]!=' ')&&(a[strlen(a)-1]!=' ')){
        x++;
        if(x>1){
        printf("~");  
        }

        for (int i = 0; i <strlen(a); i++)
        {
        printf("%c", a[i]);
   }}}}}

 }

/////////////////////////////////////////////////////////
int main(){
    char str[TXT];
    char word[WORD];   
    char word_c[WORD];
    char str_c[TXT];
    scanf("%s", word_c);
    for(int i = 0; i < strlen(word_c) + 1; i++){
        if(word_c[i] == '\\'){
            if(word_c[i+1] == 't' || word_c[i+1] == 'n'){
                break;
            }else{ 
                word[i] = word_c[i];}
        }else{
            word[i] = word_c[i];}
    }

    scanf("%[^~]s", str_c);
    for(int i = 0; i < strlen(str_c) + 1; i++){
        if(str_c[i] == '~'){
            break;
        }else{
            str[i] = str_c[i];}
        str[i] = str_c[i];
    }
    char word1[WORD];
    char str1[TXT];
    strcpy(word1,word);
    strcpy(str1,str);
    GematriaSequences(str,word, strlen(str),strlen(word));
    AtbashSequences(str1, word1, strlen(str1),strlen(word1));
    AnagramSequences(str, word, strlen(str),strlen(word));
    return 0;
    }


