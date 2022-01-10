int scanint(){
    char readstr[100000];
    int i,len;
    int number = 0, w;
    gets(readstr);
    len = strlen(readstr);
    for(i=0; i < len; i++){
        if(readstr[i] > 47 && readstr[i] < 58)
        {
            w = readstr[i]- 48;
        }
        else
        {
            return -1;
        }
        number = number*10 + w;
    }
    return number;
}



