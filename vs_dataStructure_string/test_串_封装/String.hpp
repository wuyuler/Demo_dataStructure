#include"SepList.hpp"
#include <string.h>
struct String:SepList<char>{


    String(int c = 100):SepList(c){};//��ָ�����ȹ��촮

    String(const char*chars){
    //��"\0"��β�Ĵ����촮,���㽫c�����ַ���ת��Ϊ��ǰ��String
    while(*chars){

        append(*chars);
        chars++;}

    }

    String *subString(int pos,int len){
        //ȡ�ִ�,posΪ��ʼ���ȡlen���ȵ��ִ�
        String *result = new String(len);
        memcpy(result->elem,elem+pos,sizeof(char)*len);
        result->length = len;
        return result;

    }

    //�����ַ���
    String& concat(String& T){
        for(int i = 0;i < T.length;i ++)
            this->append(T[i]);

        return *this;   //��������,������������

    }
    //�Ƚ��ַ���,��������,��,���� ����,С��,����
    int compare(String &T){
        int n = length,m = T.length;
        int i = 0,j = 0;
        while(i < n&&j < m){
            if((*this)[i] != T[j])
                return (*this)[i] - T[j];

        }
        return n-m;
    }

    bool operator==(String &T){//�Ƚ�
    return compare(T) == 0;
    }

    void operator=(const String& T){  //const����ֻ�ܵ���const����
        //�������д�ᵼ���ַ��������鸳ֵ����ǳ����
        length = T.length;
        resize(length);
        memcpy(elem,T.elem,sizeof(char)*T.length);
//        for(int i = 0;i < T.length;i ++)
//            (*this)[i] = T[i];
    }

    int split(SepList<String>&subs,char Splitter){
        //����Splitter�ַ�,���ַ������ݷָ�,���δ洢��subs��

            int pos = 0,len = 0;
            int item = 0;
            for(int i = 0;i <length;i++){
                len++;
                if((*this)[i] == Splitter){//����Splitter�ַ�,ͨ��ȡ�ִ�����ȡ����pos��ʼlen-1���ִ���ӵ�subs��
                    if((*subString(pos,len-1)).length!=0){
                        subs[item] = *subString(pos,len-1);
                         item++;
                    }

                    pos = i+1;//����spliter�ַ�
                    len = 0;

                }
            }
        //���һ��
        if(len!=0)
            subs[item] = *subString(pos,len);
            return item+1;//�����и���ִ���

    }

    //ɾ����pos��ʼ��len���ַ�
    void remove(int pos,int len){
        for(int i = 0;i < len;i ++){
            cout<<"ɾ����"<<(*this)[pos]<<endl;
            (*this).SepListDelete(pos);




        }

    }
    //��A���뵽posλ����
    void insert(int pos,String &A){
        int len = A.length;
        for(int i = 0;i < len;i++){
            this->SepListInsert(pos,A[i]);

        }

    }
    //����T���ֵĵ�һ��λ��
    int index(String &T){
        int i=0,j = 0;

        while(i<length&&j<T.length){
            if((*this)[i] == T[j]) {i++;j++;}
            else{i = i-j +1;j = 0;}

        }
        if(j == T.length)   {

//        cout<<"�ҵ���";
//        T.outPut();
//        cout<<"��"<<i-T.length<<endl;
        return i - T.length;}
        else return -1;

    }
    //���ҵ�ǰ�ַ������е�A�ĳ�B
    void replace(String &A,String &B){
        while(this->index(A)!=-1){
            int indexOfA = this->index(A);
            this->remove(indexOfA,A.length);
            this->insert(indexOfA,B);

        }

    }
   int Index(String &T,int pos){//��ƥ��
       //��posλ��ʼ,����T������ֵ�λ��
       int n =length;
       int m=T.length;
       int i=pos,j=0;
       while(i<n&&j<m){
        if((*this)[i]==T[j]){i++;j++;}
        else{
            i=i-j+1;//����ƥ��λ����һλ
            j=0;
        }


       }

        if(j==m)return i-m;
            return -1;


   }



   int index_KMP(String &T){ //KMP�㷨
        int next[T.length];
        int i = 0,j = -1;
        next[i] = j;//�̶���һλnextֵΪ-1,�ڶ�λΪ0
        while(i < T.length){
            if(j == -1||T[i] == T[j]){//ǰ׺ƥ���׺,
                //����adaca,��ѭ������ad�̶�,iָ��aʱj=0;iָ��cʱ,j=1ע��,�´�ֱ����T[1]��T[i]�Ƚ�,����ɹ���,next[4]��Ϊ2,���ǽ�����һ�ν��֪��ǰ׺ad,��ǰ׺ac
                //��һλ��ͬ,��ƥ��ʧ��,next[1]=0,��ʱ��ƥ�����ǰ׺�ͺ�׺T[0],T[3],ƥ���ٴ�ʧ��,next[0]=-1,��ʱ�Ѿ�˵��adacû����ͬǰ��׺��,�ж�����Ҳ����j=-1,
                //i++,j++���next[i]=0
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
            //KMP�㷨
            //��Ҫ���Ϊʲô���԰��������ͬ��ǰ׺��׺����
            //����ababdƥ��ababc,���ʧ��,����KMP�㷨����ֱ������next[4] =2λ,Ϊʲô���ÿ���һλ,��Ϊ�������һλ���ϴ�ʧ��λ������λ��ͬ�Ļ�
            //��next[2]�͵���3��,��next������3,Ҳ����˵һ����ͬ

            if(j==-1||(*this)[i]==T[j]){i++;j++;}  //j=-1,����һ���ַ���ʧ��,��������һ��,�ִ�ָ��-1+1Ϊ0,�ӿ�ʼƥ��
            else j = next[j];//jʧ��ʱ,����next���һ���ƥ�䴮

        }
        if(j == T.length) return i - T.length;
        else{
            cout<<"δ�ҵ�ƥ���ִ�";
            return -1;

        }
    }











};
