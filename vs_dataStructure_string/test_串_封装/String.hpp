#include"SepList.hpp"
#include <string.h>
struct String:SepList<char>{


    String(int c = 100):SepList(c){};//按指定长度构造串

    String(const char*chars){
    //以"\0"结尾的串构造串,方便将c语言字符串转换为当前的String
    while(*chars){

        append(*chars);
        chars++;}

    }

    String *subString(int pos,int len){
        //取字串,pos为开始向后取len长度的字串
        String *result = new String(len);
        memcpy(result->elem,elem+pos,sizeof(char)*len);
        result->length = len;
        return result;

    }

    //连接字符串
    String& concat(String& T){
        for(int i = 0;i < T.length;i ++)
            this->append(T[i]);

        return *this;   //返回自身,方便连续调用

    }
    //比较字符串,返回正数,零,负数 大于,小于,等于
    int compare(String &T){
        int n = length,m = T.length;
        int i = 0,j = 0;
        while(i < n&&j < m){
            if((*this)[i] != T[j])
                return (*this)[i] - T[j];

        }
        return n-m;
    }

    bool operator==(String &T){//比较
    return compare(T) == 0;
    }

    void operator=(const String& T){  //const对象只能调用const函数
        //深拷贝不重写会导致字符串的数组赋值出现浅拷贝
        length = T.length;
        resize(length);
        memcpy(elem,T.elem,sizeof(char)*T.length);
//        for(int i = 0;i < T.length;i ++)
//            (*this)[i] = T[i];
    }

    int split(SepList<String>&subs,char Splitter){
        //根据Splitter字符,将字符串内容分割,依次存储到subs里

            int pos = 0,len = 0;
            int item = 0;
            for(int i = 0;i <length;i++){
                len++;
                if((*this)[i] == Splitter){//遇到Splitter字符,通过取字串函数取出从pos开始len-1个字串添加到subs里
                    if((*subString(pos,len-1)).length!=0){
                        subs[item] = *subString(pos,len-1);
                         item++;
                    }

                    pos = i+1;//跳过spliter字符
                    len = 0;

                }
            }
        //最后一段
        if(len!=0)
            subs[item] = *subString(pos,len);
            return item+1;//返回切割的字串数

    }

    //删除从pos开始的len个字符
    void remove(int pos,int len){
        for(int i = 0;i < len;i ++){
            cout<<"删除了"<<(*this)[pos]<<endl;
            (*this).SepListDelete(pos);




        }

    }
    //将A插入到pos位置上
    void insert(int pos,String &A){
        int len = A.length;
        for(int i = 0;i < len;i++){
            this->SepListInsert(pos,A[i]);

        }

    }
    //返回T出现的第一个位置
    int index(String &T){
        int i=0,j = 0;

        while(i<length&&j<T.length){
            if((*this)[i] == T[j]) {i++;j++;}
            else{i = i-j +1;j = 0;}

        }
        if(j == T.length)   {

//        cout<<"找到了";
//        T.outPut();
//        cout<<"在"<<i-T.length<<endl;
        return i - T.length;}
        else return -1;

    }
    //查找当前字符串所有的A改成B
    void replace(String &A,String &B){
        while(this->index(A)!=-1){
            int indexOfA = this->index(A);
            this->remove(indexOfA,A.length);
            this->insert(indexOfA,B);

        }

    }
   int Index(String &T,int pos){//简单匹配
       //从pos位开始,返回T最早出现的位置
       int n =length;
       int m=T.length;
       int i=pos,j=0;
       while(i<n&&j<m){
        if((*this)[i]==T[j]){i++;j++;}
        else{
            i=i-j+1;//初期匹配位右移一位
            j=0;
        }


       }

        if(j==m)return i-m;
            return -1;


   }



   int index_KMP(String &T){ //KMP算法
        int next[T.length];
        int i = 0,j = -1;
        next[i] = j;//固定第一位next值为-1,第二位为0
        while(i < T.length){
            if(j == -1||T[i] == T[j]){//前缀匹配后缀,
                //比如adaca,在循环中是ad固定,i指向a时j=0;i指向c时,j=1注意,下次直接用T[1]与T[i]比较,如果成功了,next[4]就为2,这是借助上一次结果知道前缀ad,和前缀ac
                //第一位相同,但匹配失败,next[1]=0,这时想匹配最短前缀和后缀T[0],T[3],匹配再次失败,next[0]=-1,这时已经说明adac没有相同前后缀了,判断条件也满足j=-1,
                //i++,j++最后next[i]=0
                i++;
                j++;
                next[i] = j;
            }
            else j = next[j];

        }
//        for(int k = 0;k < T.length;k++)
//            cout<<next[k]<<endl;

         i = 0,j = 0;


        while(i < length&&j<T.length){
            //KMP算法
            //主要理解为什么可以按着最大相同的前缀后缀来跳
            //举例ababd匹配ababc,最后失配,按照KMP算法可以直接右移next[4] =2位,为什么不用考虑一位,因为如果右移一位除上次失配位的其他位相同的话
            //那next[2]就等于3了,而next不等于3,也就是说一定不同

            if(j==-1||(*this)[i]==T[j]){i++;j++;}  //j=-1,连第一个字符都失配,主串滑动一个,字串指针-1+1为0,从开始匹配
            else j = next[j];//j失配时,调用next向右滑动匹配串

        }
        if(j == T.length) return i - T.length;
        else{
            cout<<"未找到匹配字串";
            return -1;

        }
    }











};
