# include<iostream>
# include<string>
# include<iomanip>
# include<cmath>
# define S_BOX_IN_LEN 6
//S盒子输入长度
# define ENCODE_TURNS 16
//编码迭代次数
# define FULL_BITS_LENGTH 8
//存储单元长度
# define HALF_BITS_LENGTH 4
//存储单元长度一半
# define IP_LENGTH 64
//IP置换表长度
# define IP_HALF_LENGTH IP_LENGTH/2
# define P_LENGTH 32
//P置换表长度
# define PC_1_LENGTH 56
//PC1置换表长度
# define PC_2_LENGTH 48
//PC2置换表长度
# define PC_HALF_LENGTH PC_1_LENGTH/2
//PC1置换表长度的一半
using namespace std;
//初始置换
int IP[]={58,50,42,34,26,18,10,2,
            60,52,44,36,28,20,12,4,
            62,54,46,38,30,22,14,6,
            64,56,48,40,32,24,16,8,
            57,49,41,33,25,17, 9,1,
            59,51,43,35,27,19,11,3,
            61,53,45,37,29,21,13,5,
            63,55,47,39,31,23,15,7};
//初始置换逆置换
int IP_1[]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,
                38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
                36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,
                34,2,42,10,50,18,58 ,26,33,1,41, 9,49,17,57,25};
int* R=new int[IP_HALF_LENGTH];
int* L=new int[IP_HALF_LENGTH];

//置换选择表１
int PC_1[]={57,49,41,33,25,17,9,1,
                    58,50,42,34,26,18,10,2,
                    59,51,43,35,27,19,11,3,
                    60,52,44,36,63,55,47,39,
                    31,23,15,7,62,54,46,38,
                    30,22,14,6,61,53,45,37,
                    29,21,13,5,28,20,12,4 };
//置换选择表２
int PC_2[]={14,17,11,24,1,5,
                    3,28,15,6,21,10,
                    23,19,12,4,26,8,
                    16,7,27,20,13,2,
                    41,52,31,37,47,55,
                    30,40,51,45,33,48,
                    44,49,39,56,34,53,
                    46,42,50,36,29,32 };
int* C=new int[28];
int* D=new int[28];
//　Ｓ盒子
int S[][64]={{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
                0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
                4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
                15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 },
                {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
                    3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
                    0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
                    13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9},
                    {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
                    13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
                    13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
                    1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12},
                    {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
                    13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
                    10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
                    3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14},
                    {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
                    14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
                    4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
                    11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3},
                    {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
                    10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
                    9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
                    4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13},
                    {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
                    13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
                    1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
                    6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12},
                    {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
                    1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
                    7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
                    2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}};
//扩展置换
int E[]={32,1,2,3,4,5,
                4,5,6,7,8,9,
                8,9,10,11,12,13,
                12,13,14,15,16,17,
                16,17,18,19,20,21,
                20,21,22,23,24,25,
                24,25,26,27,28,29,
                28,29,30,31,32,1};
//P置换表
int P[]={16,7,20,21,
            29,12,28,17,
            1,15,23,26,
            5,18,31,10,
            2,8,24,14,
            32,27,3,9,
            19,13,30,6,
            22,11,4,25
};
//循环位移次数
int DISPLACEMENT_TURNS[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
//　字符串转字符数组
char* stringToCharArray(string str);
//　字符串转二进制数组
int* stringToBinaryArray(string str);
// S盒输出转二进制
int* convertToBinaryArray(int data);
//将字符转换成二进制数组
int* characterToBinaryArray(char ch);
//　二进制数组转字符串
string binaryArrayToString(int binary[],int len);
//　两个二进制数组异或操作
int* xor_op(int left[],int ll,int right[],int rl);
//　根据置换表生成新的数组
int* repace_op(int data[],int rep_tab[],int len);
//循环左移
int* leftCycle(int data[],int len,int total);
//子密钥产生
int* generateSubKey(int key[],int turns);
//ｆ函数
int* f_func(int R[],int key[],int len);
//S盒子函数
int* sbox(int data[],int len);

//DES加密
string DESEncode(string str,string key);
//打印整型数组
void print(int *binaryArray,int len);
//主函数
int main(){
    string str="1aA123456";
    int* p=stringToBinaryArray(str);
    int key[]={0,0,0,1,0,0,1,1, 0,0,1,1,0,1,0,0, 0,1,0,1,0,1,1,1, 0,1,1,1,1,0,0,1, 1,0,0,1,1,0,1,1, 1,0,1,1,1,1,0,0, 1,1,0,1,1,1,1,1, 1,1,1,1,0,0,0,1};
    int data_bin[]={0,0,0,0, 0,0,0,1, 0,0,1,0, 0,0,1,1, 0,1,0,0, 0,1,0,1, 0,1,1,0, 0,1,1,1, 1,0,0,0, 1,0,0,1, 1,0,1,0, 1,0,1,1, 1,1,0,0, 1,1,0,1, 1,1,1,0, 1,1,1,1};
    string data_str=binaryArrayToString(data_bin,64);
    string key_str=binaryArrayToString(key,64);
    cout<<data_str<<endl;
    p=stringToBinaryArray(key_str);
    p=xor_op(p,P_LENGTH,key,P_LENGTH);
    print(p,IP_LENGTH);
    string test=DESEncode(data_str,key_str);
    cout<<test<<endl;
    p=stringToBinaryArray(test);
    print(p,IP_LENGTH);
    test=DESEncode("HelloHelloHello!","00000000");
    cout<<test<<endl;
    return 0;
}
/**
* - 初始置换->16轮迭代加密->初始置换逆置换
*   - 初始置换, 即根据置换表将相应位置元素进行重新放置
*   - 迭代加密
*     Li=R(i-1)
*     Ri=L(i-1) xor f(R(i-1),Ki)
*   - f函数实质上是S盒子,该盒子用于加密
*   - Ki即第i轮子密钥,对初始密钥根据PC-1进行置换, 然后分为C,D两部分,二者均为28位
*     然后对C,D进行循环位移,每一轮循环位移的次数由轮次决定,循环位移结束后
*     将二者进行拼接,接着根据置换表PC-2进行置换就得到第i轮次密钥
*  - 左右循环位移函数(二进制数组,位移次数) 置换选择操作(原始数据, 置换表, 置换表大小) 异或操作 f函数(S盒子8组, 6bits->4bits)
*    二进制转字符串 字符串转二进制
**/
//打印整型数组
void print(int *binaryArray,int len){
    cout<<endl;
    for(int i=0;i<len;i++){
        cout<<setw(2)<<binaryArray[i];
    }
    cout<<endl;
}
//　字符串转字符数组
char* stringToCharArray(string str){
    int len=str.size();
    char* charArray=new char[len];
    for(int i=0;i<len;i++)
        charArray[i]=str[i];
    return charArray;
}

//将字符转换成二进制数组
int* characterToBinaryArray(char ch){
    int* binaryArray=new int[8];
    for(int i=0;i<FULL_BITS_LENGTH;i++){
        binaryArray[FULL_BITS_LENGTH-i-1]=(ch>>i)&1;
    }
    return binaryArray;
}

//　字符串转二进制数组
int* stringToBinaryArray(string str){
    int len=str.size();
    //原始数据长度
    int blank=len%FULL_BITS_LENGTH;
    blank=(0==blank)?0:FULL_BITS_LENGTH-blank;
    //原始数据长度对８取余
    for(int i=0;i<blank;i++){
        str.append(" ");
    }
    //８个字符长度对齐
    len+=blank;
    //更新字符长度
    char* bytes=stringToCharArray(str);
    //字符串转字符串数组
    int binary_len=FULL_BITS_LENGTH*len;
    //字符串对应二进制数组长度
    int* binaryArray=new int[binary_len];
    //二进制数组
    for(int i=0;i<len;i++){
        int* bin_tmp=characterToBinaryArray(bytes[i]);
        //将字符串中每一个字符转换成二进制
        int offset=FULL_BITS_LENGTH*i;
        for(int j=0;j<FULL_BITS_LENGTH;j++){
            binaryArray[j+offset]=bin_tmp[j];
        }
    }
    return binaryArray;
}

//　二进制数组转字符串
string binaryArrayToString(int binary[],int len){
    string str="";
    if(0!=len%FULL_BITS_LENGTH)
        return str;
    int d=len/FULL_BITS_LENGTH;
    for(int i=0;i<d;i++){
        char ch=0x00;
       // print(characterToBinaryArray(ch),8);
        int offset=i*FULL_BITS_LENGTH;
        for(int j=0;j<FULL_BITS_LENGTH;j++){
            //cout<<setw(2)<<binary[j+offset];
            ch=ch|binary[j+offset];
            if(FULL_BITS_LENGTH-1==j)
                continue;
             ch=ch<<1;
        }
        str.push_back(ch);
    }
    return str;
}

//　两个二进制数组异或操作
int* xor_op(int left[],int ll,int right[],int rl){
    int *p=NULL;
    if(rl!=ll) return p;
    p=new int[ll];
    for(int i=0;i<ll;i++){
        p[i]=left[i]^right[i];
    }
    return p;
}
// 根据置换表生成新的数组
int* repace_op(int data[],int rep_tab[],int len){
    int* res=new int[len];
    for(int i=0;i<len;i++){
        res[i]=data[rep_tab[i]-1];
    }
    return res;
}
//ｆ函数
int* f_func(int R[],int key[],int len){
    //对数据有半部分进行扩展
    int* er=repace_op(R,E,PC_2_LENGTH);
    //扩展结果与密钥进行异或运算
    int* xor_res=xor_op(er,len,key,len);
    //对异或运算结果进行Ｓ盒子置换
    int* s_box=sbox(xor_res,len);
    //对Ｓ盒子输出结果进行Ｐ置换
    int* res=repace_op(s_box,P,P_LENGTH);
    return res;
}
//S盒子函数
int* sbox(int data[],int len){
    int* res=new int[32];
    int d=len/S_BOX_IN_LEN;
    for(int i=0;i<d;i++){
        int offset=i*S_BOX_IN_LEN;
        //row
        int row=0x00;
        row=row|data[offset];
        row=row<<1;
        row=row|data[offset+S_BOX_IN_LEN-1];
        //column
        int column=0x00;
        column=column|data[offset+1];
        column=column<<1;
        column=column|data[offset+2];
        column=column<<1;
        column=column|data[offset+3];
        column=column<<1;
        column=column|data[offset+4];
        int index=row*16+column;
        int output=S[i][index];
        //S盒子元素选择
        offset=i*HALF_BITS_LENGTH;
        //Ｓ盒子选择结果只有４位
        int* tmp=convertToBinaryArray(output);
        for(int j=0;j<HALF_BITS_LENGTH;j++){
            res[offset+j]=tmp[j];
        }
        //保存选择结果至res数组
    }
    return res;
}
// S盒输出转二进制
int* convertToBinaryArray(int data){
    int* res=new int[HALF_BITS_LENGTH];
    int* tmp=characterToBinaryArray(data);
    for(int i=0;i<HALF_BITS_LENGTH;i++){
        res[i]=tmp[i+HALF_BITS_LENGTH];
    }
    return res;
}
//循环左移
int* leftCycle(int data[],int len,int total){
    int* res=new int[len];
    //cout<<"leftCycle():"<<len<<","<<total<<endl;
    for(int i=0;i<len;i++){
        int index=(i+total)%len;
        res[i]=data[index];
    }
   return res;
}
//子密钥产生
int* generateSubKey(int key[],int turns){
    int* subKey=new int[PC_1_LENGTH];
    if(1==turns){
        int* tmp=repace_op(key,PC_1,PC_1_LENGTH);
        for(int i=0;i<PC_HALF_LENGTH;i++){
            //cout<<i<<" "<<i+PC_HALF_LENGTH<<endl;
            C[i]=tmp[i];
            D[i]=tmp[i+PC_HALF_LENGTH];
            //cout<<tmp[i+PC_HALF_LENGTH]<<" "<<D[i+PC_HALF_LENGTH]<<endl;
        }
        C=leftCycle(C,PC_HALF_LENGTH,DISPLACEMENT_TURNS[turns-1]);
        D=leftCycle(D,PC_HALF_LENGTH,DISPLACEMENT_TURNS[turns-1]);
        for(int i=0;i<PC_HALF_LENGTH;i++){
            subKey[i]=C[i];
            subKey[i+PC_HALF_LENGTH]=D[i];
        }
       // print(subKey,PC_1_LENGTH);
        subKey=repace_op(subKey,PC_2,PC_2_LENGTH);
    }else{
        C=leftCycle(C,PC_HALF_LENGTH,DISPLACEMENT_TURNS[turns-1]);
        D=leftCycle(D,PC_HALF_LENGTH,DISPLACEMENT_TURNS[turns-1]);
        for(int i=0;i<PC_HALF_LENGTH;i++){
            subKey[i]=C[i];
            subKey[i+PC_HALF_LENGTH]=D[i];
        }
        subKey=repace_op(subKey,PC_2,PC_2_LENGTH);
    }
    return subKey;
}
//DES加密
string DESEncode(string str,string key){
    string encodeRes="";
    //数据长度计算
    int len=str.length();
    //64位对齐
     int blank=len%FULL_BITS_LENGTH;
    blank=(0==blank)?0:FULL_BITS_LENGTH-blank;
    len+=blank;
   // cout<<len<<endl;
    // 对原始数据进行分段加密
    int d=len/FULL_BITS_LENGTH;
    int key_len=key.length();
    if(8!=key_len) return encodeRes;
    for(int i=0;i<d;i++){
        //产生初始密钥
         int* subkey=stringToBinaryArray(key);
         //每８个字符为一段
        int pos=i*FULL_BITS_LENGTH;
        string tmp=str.substr(pos,FULL_BITS_LENGTH);
        //cout<<tmp<<endl;
        //将字符串转换为二进制数组
        int* p=stringToBinaryArray(tmp);
        //初始逆置换
        p=repace_op(p,IP,IP_LENGTH);
        //将置换结果分为左右两部分
        for(int j=0;j<IP_HALF_LENGTH;j++){
            L[j]=p[j];
            R[j]=p[j+IP_HALF_LENGTH];
        }
        for(int j=1;j<=ENCODE_TURNS;j++){
                //产生子密钥
                subkey=generateSubKey(subkey,j);
                //f函数调用
                int* fRes=f_func(R,subkey,PC_2_LENGTH);
                //与左半部分进行异或操作
                int* nextR=xor_op(L,P_LENGTH,fRes,P_LENGTH);
                //保存右半部分数据
                for(int k=0;k<P_LENGTH;k++)
                    L[k]=R[k];
                R=nextR;
        }
        int* data=new int[IP_LENGTH];
        for(int i=0;i<IP_HALF_LENGTH;i++){
            data[i]=R[i];
            data[i+IP_HALF_LENGTH]=L[i];
        }
        data=repace_op(data,IP_1,IP_LENGTH);
        string toString=binaryArrayToString(data,IP_LENGTH);
       // cout<<toString<<endl;
        encodeRes.append(toString);
    }
    return encodeRes;
}
