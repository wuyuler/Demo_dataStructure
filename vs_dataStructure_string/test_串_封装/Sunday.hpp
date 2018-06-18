




    //Sunday算法

    int skipTable[256];//字符集范围,对应值是匹配串滑动的长度
    void fill_skip_table_sunday(char*T){
                //针对匹配串给skiptable赋值

            int m = strlen(T);
            for(int i=0;i <256;i++)//默认字符未在匹配串出现过,需要滑动m+1长度
                skipTable[i] = m+1;
            for(int i=0;i <m;i++)
                    skipTable[T[i]]=m-i;//向前滑动m-i,使得主串与匹配串对齐




    }
    int Index_Sunday(char *S,char *T,int pos){
        int n=strlen(S),m=strlen(T);
        int i=0;
        int n_m = n-m;
        fill_skip_table_sunday(T);
        while(i<n_m){

            if(memcmp(S+i,T,sizeof(char)*m)==0)return i;
            i+=skipTable[S[i+m]];//i+m为主串与匹配串对齐后,主串右边的字符
        }


    }
