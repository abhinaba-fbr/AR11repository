#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int bsize=15;
int m1,n1,max,equalizedmax;
char filetype[3];
typedef struct P3
{
	int a,b,c;
}P3;
void read_name(char *s)
{
    int i;
   	fgets(s,BUFSIZ,stdin);
    for (i=0; s[i]!='\n'; i++);
    s[i]='\0';
    return;
}
void writeanimageP2(int **,char *);
int** arrayofimageP1(char *name)
{
//	char name[100];
//	scanf("%s",name);
    int **array;
    FILE *image = fopen(name,"r");
   // FILE *out = fopen("ouput.txt","w");
    char ch;
    if(image==NULL)
    {
    	printf("Error!\n");
    	exit(1);
	}
    ch = getc(image);
    int flag = 0;
    int flag1 = 0;
    int n,m;
    int count = 0;
  //  char filetype[3];
    while(ch!=EOF)
    {
    	if(count<2)
    	{
    		filetype[count++]=ch;
    		ch = getc(image);
    		continue;
		}
    	ch = getc(image);
    	if(ch=='#')
    	{
    		while(1)
    		{
    			ch = getc(image);
    			if(ch=='\n'){
    				break;
				}
    			
			}
		}
    	if(ch>='0' && ch<='9')
    	{
    		flag = 1;
		}
		if(flag==1)
		{
			ungetc(ch,image);
			fscanf(image,"%d %d",&n,&m);
			m1= n;
			n1 = m;
			array = (int **)malloc(n1* sizeof(int *));
			for (int i=0; i<n1; i++)
         		array[i] = (int *)malloc(m1 * sizeof(int));
		//	int array[m][n];
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				fscanf(image,"%d",&array[i][j]);
			}
		}
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				printf("%d ",array[i][j]);
			}
			printf("\n");
		}
		//	input(n,m,image);
			break;
		}
	}
//	printf("%s",filetype);
//	printf("%d %d\n",n,m);
	/*ungetc(ch,image);
	int m,n;
	fscanf(image,"%d %d",&m,&n);
	printf("%d %d\n",m,n); */
	fclose(image);
//	fclose(out);
	return array;
}
int** arrayofimageP2(char *name)
{
//	char name[100];
//	scanf("%s",name);
    int **array;
    FILE *image = fopen(name,"r");
   // FILE *out = fopen("ouput.txt","w");
    char ch;
    if(image==NULL)
    {
    	printf("Error!\n");
    	exit(1);
	}
    ch = getc(image);
    
    int flag = 0;
    int flag1 = 0;
    int n,m;
    int count = 0;
  //  char filetype[3];
    while(ch!=EOF)
    {
    	if(count<2)
    	{
    		filetype[count++]=ch;
    		ch = getc(image);
    		continue;
		}
		if(ch=='#')
    	{
    		while(1)
    		{
    			ch = getc(image);
    			if(ch=='\n')
				{
    				break;
				}
    			
			}
		}
    	ch = getc(image);
    	
    	if(ch>='0' && ch<='9')
    	{
    		flag = 1;
		}
		if(flag==1)
		{
			ungetc(ch,image);
			fscanf(image,"%d %d",&n,&m);
			fscanf(image,"%d",&max);
			m1= n;
			n1 = m;
			array = (int **)malloc(n1* sizeof(int *));
			for (int i=0; i<n1; i++)
         		array[i] = (int *)malloc(m1 * sizeof(int));
		//	int array[m][n];
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				fscanf(image,"%d",&array[i][j]);
			}
		}
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
			//	printf("%d ",array[i][j]);
			}
		//	printf("\n");
		}
		//	input(n,m,image);
			break;
		}
	}
//	printf("%s",filetype);
//	printf("%d %d\n",n,m);
	/*ungetc(ch,image);
	int m,n;
	fscanf(image,"%d %d",&m,&n);
	printf("%d %d\n",m,n); */
	fclose(image);
//	fclose(out);
	return array;
}

//read an binary P2 image
int** readImageP2(char *name)
{
    FILE *img=fopen(name,"rb");
    int x=0;
    int y=0;
    int i=0,j=0;
    int n=0;
    char c=fgetc(img);
    c=fgetc(img);
    c=fgetc(img);
    while(c!=10)
    {
        x=x*10+(c-48);
        n1=x;
        c=fgetc(img);
    }
    c=fgetc(img);
    while(c!=10)
    {
        y=y*10+(c-48);
        m1=y;
        c=fgetc(img);
    }
    c=fgetc(img);
    c=fgetc(img);
    c=fgetc(img);
    c=fgetc(img);
    int **array;
	array=(int**)malloc(n1*sizeof(int*));
	for(i=0;i<n1;i++)
	    *(array+i)=(int*)malloc(m1*sizeof(int));
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            c=fgetc(img);
            n=c;
            if(n<0)
            {
                n=256+n;
            }
            array[i][j]=n;
			printf("%d ",array[i][j]);
        }
        printf("");
    }
    return array;
}

P3** arrayofimageP3(char *name)
{
//	char name[100];
//	scanf("%s",name);
    P3 **array;
    FILE *image = fopen(name,"r");
   // FILE *out = fopen("ouput.txt","w");
    char ch;
    if(image==NULL)
    {
    	printf("Error!\n");
    	exit(1);
	}
    ch = getc(image);
    int flag = 0;
    int flag1 = 0;
    int n,m;
    int count = 0;
  //  char filetype[3];
    while(ch!=EOF)
    {
    	if(count<2)
    	{
    		filetype[count++]=ch;
    		ch = getc(image);
    		continue;
		}
    	ch = getc(image);
    	if(ch=='#')
    	{
    		while(1)
    		{
    			ch = getc(image);
    			if(ch=='\n')
    			{
    				break;
				}
    			
			}
		}
    	if(ch>='0' && ch<='9')
    	{
    		flag = 1;
		}
		if(flag==1)
		{
			ungetc(ch,image);
			fscanf(image,"%d %d",&n,&m);
			fscanf(image,"%d",&max);
			m1= n;
			n1 = m;
			array = (P3 **)malloc(n1* sizeof(P3 *));
			for (int i=0; i<n1; i++)
         		array[i] = (P3 *)malloc(m1 * sizeof(P3));
		//	int array[m][n];
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				fscanf(image,"%d %d %d",&array[i][j].a,&array[i][j].b,&array[i][j].c);
			}
		}
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
			//	printf("%d ",array[i][j]);
			}
		//	printf("\n");
		}
		//	input(n,m,image);
			break;
		}
	}
//	printf("%s",filetype);
//	printf("%d %d\n",n,m);
	/*ungetc(ch,image);
	int m,n;
	fscanf(image,"%d %d",&m,&n);
	printf("%d %d\n",m,n); */
	fclose(image);
//	fclose(out);
	return array;
}

void writeanimageP1(int **array)
{
	FILE *image = fopen("output.PBM","w");
	fprintf(image,"%s\n",filetype);
//	fprintf(image,"# image of FEEP\n");
	fprintf(image,"%d %d\n",m1,n1);
	for(int i = 0;i<n1;i++)
	{
		for(int j = 0;j<m1;j++)
		{
			fprintf(image,"%d ",array[i][j]);
		}
		fprintf(image,"\n");
	}
	//fclose(image);
	return;
}

void writeanimageP2(int **array,char *str)
{
	FILE *image = fopen(str,"w");
	fprintf(image,"%s\n",filetype);
//	fprintf(image,"# image of FEEP\n");
	fprintf(image,"%d %d\n",m1,n1);
	fprintf(image,"%d\n",max);
	for(int i = 0;i<n1;i++)
	{
		for(int j = 0;j<m1;j++)
		{
			fprintf(image,"%d ",array[i][j]);
		}
		fprintf(image,"\n");
	}
	//fclose(image);
	return;
}

void writeanimageP3(P3 **array)
{
	FILE *image = fopen("output.PPM","w");
	fprintf(image,"%s\n",filetype);
//	fprintf(image,"# image of FEEP\n");
	fprintf(image,"%d %d\n",m1,n1);
	fprintf(image,"%d\n",max);
	for(int i = 0;i<n1;i++)
	{
		for(int j = 0;j<m1;j++)
		{
			fprintf(image,"%d %d %d  ",array[i][j].a,array[i][j].b,array[i][j].c);
		}
		fprintf(image,"\n");
	}
	fclose(image);
	return;
}

void niblacks(char *name){
    int i,j,k,l;
    int mean=0.0,SD=0.0;
    float T;
    int **array;
    FILE *fp = fopen(name,"r");
	if(fp==NULL)
	{
		printf("Error!\n");
	}
	char ch = getc(fp);
	ch = getc(fp);
	fclose(fp);
	int **new_array;
    if(ch=='2'){
        //read image
		array = arrayofimageP2(name);
		for(i = 0;i<n1;i++)
		{
			for(j = 0;j<m1;j++)
			{
				printf("%d ",array[i][j]);
			}
			printf("\n");
		}
        //start of niblacks algo
		new_array=(int**)malloc(n1*sizeof(int*));
	        for(i=0;i<n1;i++)
	    *(new_array+i)=(int*)malloc(m1*sizeof(int));
        printf("\n\n\n\nAfter NIBLACKS BINARIZATION\n\n");
        for(i=0;i<n1;i++){
            for(j=0;j<m1;j++){
                mean=0;
                SD=0;
                for(k=i-(bsize/2);k<=i+(bsize/2);k++){
                    for(l=j-(bsize/2);l<=j+(bsize/2);l++){
                        if(l<0||k<0||k>=n1||l>=m1)
                        {
                        	continue;
						}
                        else mean=mean+array[k][l];
                    }
                }
                mean=mean/(bsize*bsize);
                for(k=i-(bsize/2);k<=i+(bsize/2);k++){
                    for(l=j-(bsize/2);l<=j+(bsize/2);l++){
                        if(l<0||k<0||k>=n1||l>=m1)
                            continue;
                        SD=SD+(array[k][l]-mean)*(array[k][l]-mean);
                    }
                } 
                SD=SD/(bsize*bsize);
                SD=(int)sqrt(SD);
                //printf("%d %d ",mean,SD);
                T=mean-0.5*SD;
                //printf("%d %f ",array[i][j],T);
                if(array[i][j]<T)
                    array[i][j]=0;
                else if(array[i][j]>T)
                    array[i][j]=255;
                printf("%d ",array[i][j]);
            }
            printf("\n");
        }//End of niblacks algo
        writeanimageP2(array,"niblacksoutput.pgm");     //making the new image 
    }
    else{
        printf("Enter an pgm image!!!\n\n");
    }
}

void savola(char *name){
	int i,j,k,l;
    int mean=0.0,SD=0.0;
    float T;
    int **array;
    FILE *fp = fopen(name,"r");
	if(fp==NULL)
	{
		printf("Error!\n");
	}
	char ch = getc(fp);
	ch = getc(fp);
	fclose(fp);
	int **new_array;
    if(ch=='2'){
        //read image
		array = arrayofimageP2(name);
		for(i = 0;i<n1;i++)
		{
			for(j = 0;j<m1;j++)
			{
				printf("%d ",array[i][j]);
			}
			printf("\n");
		}
        //start of savola algo
		new_array=(int**)malloc(n1*sizeof(int*));
	        for(i=0;i<n1;i++)
	    *(new_array+i)=(int*)malloc(m1*sizeof(int));
        printf("\n\n\n\nAfter SAVOLA BINARIZATION\n\n");
        for(i=0;i<n1;i++){
            for(j=0;j<m1;j++){
                mean=0;
                SD=0;
                for(k=i-(bsize/2);k<=i+(bsize/2);k++){
                    for(l=j-(bsize/2);l<=j+(bsize/2);l++){
                        if(l<0||k<0||k>=n1||l>=m1)
                        {
                        	continue;
						}
                        else mean=mean+array[k][l];
                    }
                }
                mean=mean/(bsize*bsize);
                for(k=i-(bsize/2);k<=i+(bsize/2);k++){
                    for(l=j-(bsize/2);l<=j+(bsize/2);l++){
                        if(l<0||k<0||k>=n1||l>=m1)
                            continue;
                        SD=SD+(array[k][l]-mean)*(array[k][l]-mean);
                    }
                } 
                SD=SD/(bsize*bsize);
                SD=(int)sqrt(SD);
                //printf("%d %d ",mean,SD);
                T=mean*(1+0.5*((SD/128)-1));
                //printf("%d %f ",array[i][j],T);
                if(array[i][j]<T)
                    array[i][j]=0;
                else if(array[i][j]>T)
                    array[i][j]=255;
                printf("%d ",array[i][j]);
            }
            printf("\n");
        }//End of niblacks algo
        writeanimageP2(array,"savolaoutput.pgm");     //making the new image 
    }
    else{
        printf("Enter an pgm image!!!\n\n");
    }
}

void bernsen(char *name){
    int i,j,k,l;
    int min,max;
    float T;
    int **array;
    FILE *fp = fopen(name,"r");
	if(fp==NULL)
	{
		printf("Error!\n");
	}
	char ch = getc(fp);
	ch = getc(fp);
	fclose(fp);
	int **new_array;
    if(ch=='2'){
        //read image
		array = arrayofimageP2(name);
		for(i = 0;i<n1;i++)
		{
			for(j = 0;j<m1;j++)
			{
				printf("%d ",array[i][j]);
			}
			printf("\n");
		}
        //start of bernsen's algo
		new_array=(int**)malloc(n1*sizeof(int*));
	        for(i=0;i<n1;i++)
	    *(new_array+i)=(int*)malloc(m1*sizeof(int));
        printf("\n\n\n\nAfter NIBLACKS BINARIZATION\n\n");
        for(i=0;i<n1;i++){
            for(j=0;j<m1;j++){
                min=256;
                max=-1;
                for(k=i-(bsize/2);k<=i+(bsize/2);k++){
                    for(l=j-(bsize/2);l<=j+(bsize/2);l++){
                        if(l<0||k<0||k>=n1||l>=m1)
                        {
                        	continue;
						}
                        if(array[k][l]<min)
							min=array[k][l];
						if(array[k][l]>max)
							max=array[k][l]; 
                    }
                }
                T=(min+max)/2;
                if(array[i][j]<T)
                    array[i][j]=0;
                else if(array[i][j]>T)
                    array[i][j]=255;
                printf("%d ",array[i][j]);
            }
            printf("\n");
        }//End of bernsens algo
        writeanimageP2(array,"bernsensoutput.pgm");     //making the new image 
    }
    else{
        printf("Enter an pgm image!!!\n\n");
    }
}

void combinedBinarization(char *ni,char *sa,char *be){
	printf("\n");
	//read niblacks
	int **arrayNi;
    FILE *fp1 = fopen(ni,"r");
	if(fp1==NULL)
	{
		printf("Error!\n");
	}
	char ch1 = getc(fp1);
	ch1 = getc(fp1);
	fclose(fp1);
    if(ch1=='2')
		arrayNi = arrayofimageP2(ni);
	else{
		printf("Enter a pgm image!! Task terminated\n");
		return;
	}
	//read savola
	int **arraySa;
	FILE *fp2 = fopen(sa,"r");
	if(fp2==NULL)
	{
		printf("Error!\n");
	} 
	char ch2 = getc(fp2);
	ch2 = getc(fp2);
	fclose(fp2);
	if(ch2=='2')
		arraySa = arrayofimageP2(sa);
	else{
		printf("Enter a pgm image!! Task terminated\n");
		return;
	}
	//read bernsen
	int **arrayBe;
	FILE *fp3 = fopen(be,"r");
	if(fp3==NULL)
	{
		printf("Error!\n");
	} 
	char ch3 = getc(fp3);
	ch3 = getc(fp3);
	fclose(fp3);
	if(ch3=='2')
		arrayBe = arrayofimageP2(be);
	else{
		printf("Enter a pgm image!! Task terminated\n");
		return;
	}
	//combining
	int **new_array;
	int i,j;
	new_array=(int**)malloc(n1*sizeof(int*));
	for(i=0;i<n1;i++)
		*(new_array+i)=(int*)malloc(m1*sizeof(int));
	for(i=0;i<n1;i++){
		for(j=0;j<m1;j++){
			if(arrayNi[i][j]==0&&arraySa[i][j]==0&&arrayBe[i][j]==0)
				new_array[i][j]=0;
			else
				new_array[i][j]=255;
			printf("%d ",new_array[i][j]);
		}
	}
	printf("\n");
	writeanimageP2(new_array,"combinedoutput.pgm");
}




int main(){
    /*char name[100];
    printf("Enter the name of the image file(.pgm) : ");
    read_name(name);*/
	char ni[100],sa[100],be[100];
	printf("Enter the name of the image(niblacks) file(.pgm) : ");
    read_name(ni);
	printf("Enter the name of the image(savolas) file(.pgm) : ");
	read_name(sa);
	printf("Enter the name of the image(bernsens) file(.pgm) : ");
	read_name(be);
    combinedBinarization(ni,sa,be);
    return 0;
}
