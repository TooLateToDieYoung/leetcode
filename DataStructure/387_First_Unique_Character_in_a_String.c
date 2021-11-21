// Second Trying Runtime = 4ms

int firstUniqChar(char * s){
    int count[26] = {0};
    char * curr = s;
    while(*curr){
        count[(*curr)-'a']++;
        curr++;
    }
    
    int i;
    for(i=0; s[i]; ++i)
        if(count[s[i]-'a']==1) return i;

    return -1;
}

/* First Trying Runtime = 20ms

int firstUniqChar(char * s){
    char * check;
    bool found = true;
    int i = 0;
    for(i=0; s[i];){
        check = s;
        while(*check){
            if( *check==s[i] && check!=(&s[i]) ){
                found = false;
                i++;
                break;
            }
            check++;
        }
        if(found) return i;
        else found = true;
    }
    return -1;

*/
