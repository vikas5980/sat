#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

class Mystring
{
    // public:
    char* str;        //initialise the char array

    public:
        Mystring():str(nullptr)      // default or no argument constructor
        {
            str=new char[1];
            str[0]='\0';
        }

        Mystring(char* val)         //1 argument char array
        {
            if(val==NULL)
            {
                str=new char[1];
                str[0]='\0';
            }
            else
            {
                str=new char[strlen(val)+1];

                strcpy(str,val);
                str[strlen(val)]='\0';
                // cout << "1 arg The string passed is: "<< str << endl;
            }
        }

        Mystring(const Mystring& source)         //copy constructor
        {
            str=new char[strlen(source.str)+1];
            strcpy(str,source.str);
            str[strlen(source.str)]='\0';
            // cout << "copy The string passed is: "<< str << endl;
        }

		//overloading the assignment operator
        Mystring& operator=(const Mystring& rhs)
        {
            if(this==&rhs)//if we are coping ourself, then return direclty
                return *this;
            delete[] str;
            str=new char[strlen(rhs.str)+1];
            strcpy(str,rhs.str);
            return *this;
        }

        Mystring(Mystring&& source)//move constructor
        {
            str=source.str;
            source.str=NULL;
            // cout << "move The string passed is: "<< str << endl;
        }

        ~Mystring(){ delete []str;}//destructor



        //prototype for stream insertion, we can only use friend, because << is a class 
        //provided by c++, we cannot have access to it
        friend ostream& operator<<(ostream &os,  const Mystring& obj);


        //prototype for stream extraction
        friend istream& operator>>(istream &is,  Mystring& obj);

        //"+" operator overloading
        friend Mystring operator+(const Mystring& lhs,const Mystring& rhs);


        //"==" operator overloading
        friend bool operator==(const Mystring& lhs, const Mystring& rhs);

        //pop_back() function
        void pop_bk()
        {
            int length=strlen(str);
            char *buff=new char[length];

            //copy characters from str to buff[]
            for(int i=0;i<length-1;i++)
                buff[i]=str[i];
            buff[length-1]='\0';

            //assign new string with char a to string str;
            *this=Mystring(buff);
            delete[] buff;
        }


        //push_back() function
        void push_bk(char a)
        {
            //find the length of string
            int length=strlen(str);
            char *buff=new char[length+2];

            //copy characters from string to buff[]
            strcpy(buff,str);

            buff[length]=a;
            buff[length+1]='\0';

            //assign the new string with char a to string string
            *this=Mystring(buff);

            //delete the temp buff[]
            delete[] buff;
        }

        //to get the length of string
        int get_length()
        {
            return strlen(str);

        }


        //copy the string of length len from position pos
        void copy(char s[],int len,int pos)
        {
            for(int i=0;i<len;i++)
                s[i]=str[pos+i];
            s[len]='\0';
        }


        //swap strings function
        void swp(Mystring &rhs)
        {
            Mystring temp(rhs);
            rhs=*this;
            *this=temp;
        }
};

Mystring operator+(const Mystring& lhs,const Mystring& rhs)
{
    int length=strlen(lhs.str)+strlen(rhs.str);
    char *buff=new char[length+1];
    strcpy(buff,lhs.str);// copy lhs.str to buff
    strcat(buff,rhs.str);//concat buff and rhs.str
    buff[length]='\0';

    Mystring temp(buff);//create an object

	delete[] buff;
    //cout<<"ok"<<endl;
    return temp;
}

//overloading the stream extraction operator
//no const before second parameter, because we may change obj
istream& operator>>(istream& is,   Mystring& obj)
{
    char *buff= new char[1000];
    memset(buff,0,sizeof(buff));
    is>>buff;
    obj=Mystring(buff);
    delete[] buff;
    return is;
}

//overloading the stream insertion operator
//has const before obj, because we do not change obj
ostream& operator<<(ostream &os, const Mystring& obj)
{
    os<<obj.str;
    return os;
}

bool operator==(const Mystring& lhs, const Mystring& rhs)
{
    if(strcmp(lhs.str,rhs.str)==0)
        return true;
    return false;
}


int main()
{
    // Constructor with no arguments
    Mystring a;

    // Convert string literal to
    // char array
    char temp[] = "Hello";

    // Constructor with one argument
    Mystring b(temp);

    // Copy constructor
    Mystring c(a);

    char temp1[] = "World";

    // 1 arg constructor called,
    // then the move constructor
    Mystring d(Mystring(temp));

    //remove last characters from Mystring b
    b.pop_bk();

    //print string b;
    cout<<"Mystring b is: "<<b<<endl;


    //append last charater from mystring b;
    b.push_bk('o');
    cout<<b<<endl;
    Mystring n="djskhkf";
    Mystring m="hjkfdhjfhk";
    Mystring y="djskhkf";
    cout<<(n==m)<<endl;
    cout<<(n==y)<<endl;
    return 0;
}