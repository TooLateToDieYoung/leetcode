/* Second Trying Runtime = 20ms */
/*
static int CompareFunc(const char * left, const char * right)
{ return (*left - *right); }

bool isAnagram(char * s, char * t){
    
    if(strlen(s)!=strlen(t)) return false;
    
    qsort((void*)s,strlen(s),sizeof(char),CompareFunc);
    qsort((void*)t,strlen(t),sizeof(char),CompareFunc);
    
    return !strcmp(s,t);
}
*/

/* First Trying Runtime = 0ms */

bool isAnagram(char * s, char * t){
    
    if(strlen(s)!=strlen(t)) return false;
    
    int i, count[26] = {0};
    for(i=0; s[i] && t[i]; ++i){
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }
    
    for(i=0; i<26; ++i)
        if(count[i]) return false;
    
    return true;
}
