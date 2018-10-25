#include<stdlib.h>
#include<stdio.h>

#define M

float a(int g){
	int s;


	for(; i < 23; ++i){
		while(i > a){
			i -= a;
			a(2);
		}
		if(a-2 <= 3) break;
	}

}

float x,y,z;

int main(){
    
    int i = 2;

    int a, b, d;

    return 0;
}

int main2(){
    
    int x;
    scanf("%d",&x);
    if(!((x>=1000&&x<=9999)||(x<=-1000&&x>=-9999))){
	printf("-1");
	exit(EXIT_FAILURE);
    }
    int y=x;
    if(y<0)
      y=-y;
    
    int a=y/1000;
    int b=(y/100)%10;
    int c=(y/10)%10;
    int d=y%10;
    
    if(a%2==1)
      a=a-1;
    if(b%2==1)
      b=b-1;
    if(c%2==1)
      c=c-1;
    if(d%2==1)
      d=d-1;
    
    y=a*1000+b*100+c*10+d;
    
    if(x<0)
      y=-y;
    
    printf("\n%d",y);
    
    return 0;
}