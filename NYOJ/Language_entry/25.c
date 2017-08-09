#include <stdio.h>
#include<string.h>
int main(void)
{
    char note[20][10] = 
    {
        "Ab minor","G# minor",
        "A# major","Bb major",
        "A# minor","Bb minor",
        "C# major","Db major",
        "Db minor","C# minor",
        "D# major","Eb major",
        "D# minor","Eb minor",
        "Gb major","F# major",
        "Gb minor","F# minor",
        "G# major","Ab major"
    };
    char str[10];
    int i,temp;
    int num = 0;
    while(gets(str) != NULL)
    {
        num++;
        int flag = 0;
        for(i = 0;i < 20;i++)
        { 
            if(!strcmp(note[i],str))
            {
                temp = i;
                flag = 1;
                break;
            }
            else
            continue;
        }
        if(flag == 0)
        {
            printf("Case %d: UNIQUE\n",num);
            continue;
        }
        if(temp%2 == 0)
        printf("Case %d: %s\n",num,note[i+1]);
        else
        printf("Case %d: %s\n",num,note[i-1]);

    }

    return 0;
}

/* 此题主要内容进行相同含义的字符串之间的转换
 * 
 * 坑点在于"=="与"="还是要细心区分,每次都误用
 *
 * 哎~~~,
 *
 * 然后,就是对于题意的理解,其实是双向的,
 *
 * 可以左译右,也可以右译左
 *
 * 注意配对上的字符串,不同方向的打印即可
 *
 * 另外最优解是C++,我现在真的是看不懂
 *
 */


 
#include<iostream>
#include<string>
using namespace std;
string trans(string a){
	string b="";
	if(a[1]=='#'){
		b+=char((a[0]-'A'+1)%7+'A');
		b+='b';
	}else{
		b+=char((a[0]-'A'+6)%7+'A');
		b+='#';
	}
	return b;
}
int main(){
	string a,b;
	for(int t=1; cin>>a>>b; t++){
		cout<<"Case "<<t<<": ";
		if(a.length()==1)
			cout<<"UNIQUE"<<endl;
		else
			cout<<trans(a)<<" "<<b<<endl;
	}
	return 0;
}
        
