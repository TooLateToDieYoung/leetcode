bool canConstruct(char * ransomNote, char * magazine){
    int counts[26] = {0};
    char * curr;
    
    curr = magazine;
    while(*curr){
        counts[(*curr)-'a']++;
        curr++;
    }
    
    curr = ransomNote;
    while(*curr){
        if(--counts[(*curr)-'a'] < 0) return false;
        curr++;
    }

    return true;
}
