




    //Sunday�㷨

    int skipTable[256];//�ַ�����Χ,��Ӧֵ��ƥ�䴮�����ĳ���
    void fill_skip_table_sunday(char*T){
                //���ƥ�䴮��skiptable��ֵ

            int m = strlen(T);
            for(int i=0;i <256;i++)//Ĭ���ַ�δ��ƥ�䴮���ֹ�,��Ҫ����m+1����
                skipTable[i] = m+1;
            for(int i=0;i <m;i++)
                    skipTable[T[i]]=m-i;//��ǰ����m-i,ʹ��������ƥ�䴮����




    }
    int Index_Sunday(char *S,char *T,int pos){
        int n=strlen(S),m=strlen(T);
        int i=0;
        int n_m = n-m;
        fill_skip_table_sunday(T);
        while(i<n_m){

            if(memcmp(S+i,T,sizeof(char)*m)==0)return i;
            i+=skipTable[S[i+m]];//i+mΪ������ƥ�䴮�����,�����ұߵ��ַ�
        }


    }
