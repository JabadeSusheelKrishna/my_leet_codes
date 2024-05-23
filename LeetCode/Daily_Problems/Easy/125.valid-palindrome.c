bool isPalindrome(char* s) {
    int string_length = strlen(s);
    int offset = 'a' - 'A';
    
    // First i will remove all the spaces and make all the letters smalls.
    char* mod_string = (char*) malloc (sizeof(char) * string_length);
    
    int mod_index = 0;
    for(int i=0; i<string_length; i++)
    {
        if(s[i] <= 'Z' && s[i] >= 'A')
        {   // Capitals Case
            mod_string[mod_index++] = s[i] + (offset);
        }
        else if((s[i] <= 'z' && s[i] >= 'a') || s[i] <= '9' && s[i] >= '0')
        {   // Smalls Case
            mod_string[mod_index++] = s[i];
        }
    }
    
    // Now we need to check whether the New string is Palindrome or not
    for(int i=0; i<(mod_index/2); i++)
    {
        if(mod_string[i] != mod_string[mod_index-i-1])
        {
            return false;
        }
    }
    return true;
}
