//soru:bir þifreleme algoritmasý harflerin ascýý karsýlýklarýndan olusan MxM matristen meydana gelen bir image yaratýyor.
//(matrisin her bir hücresi 0-255 arasinda bir pixel degerine karþýlýk geliyor.bir pixelin degeri 0 ise bu pixelde harf olmadýgý anlamýna gelmektedir)bir kelimenin ilk harfi 0x0 hücresinde ikinci harf 0x1....þeklinde saklanýyor.
//bir metni þifreleyen ve þifreli metnin þifresini çözen birer algoritmayý c dilinde gercekleyelim
//not þifrenin uzunlugu önceden bilinmedigi varsayilacaktir.
//örnek input ve output
/*    89 73 76 68
      73 90 84 69
      75 78 73 75
      0  0  0  0 
      //matrix representetation of ýmage
      //the strýng "YILDIZTEKNÝK"
      
      */
      //bir hucresinde 0 varsa orda harf yok demek olucak
      //öncelikle hangý degiskenlere ýhtýyacýmýz var 
	  //ilk once mesela strýngýn uzunlugunu alýcaz bu yüzden 
	  //kelimemizin uzunlugunu tutan degiskene ýhtýyacýmýz var 
	  //bu uzunlugu aldýktan sonra napýcaz fotografýmýz MxM boyutunda bir matris olucagýna göre
	   //bu harflerin bu kelimerin sýgacagý sekilde M degerini hesaplamamýz gerekiyor 
	  //yani M ýn karesinden kucuk olucak sekilde olmalý bu kelimenin uzunlugu
	  
	  #include <stdio.h>
	  #include <stdlib.h>//dynamic memory allocation için
	  #include <math.h>
	  
	  
	  int main(int argc,char *argv[]){
	  	
		int textSize,m,i,j,k,pixel;
	  	
		//text dizisi 1D boyutundadýr.
		//kullanýcýdan alýnacak kelimenin tutuldugu array.
	  	char *text;//kullanýcýdan aldýgmýz text için bir dizi tutucaz
	  	
		  char junk;
	  	
	  	//ayný þekilde dizimizi tanýmlýyalým
	  	//bu bir matris 	
		  int **theImage;
	  	
	  	//kullanýcýdan bir tam sayi girmesini isticez
	  	printf("enter the length of text to encrypt\n");
	  	scanf("%d",&textSize);
	  	
	  	//dizimizi kullanýcýdan aldgýmýz tam sayý dogrultusunda olusturalým
	  	//textSize boyutunda text dizimizi tekrar güncellemiþ olduk
		  text=(char *)(malloc)(sizeof(char)*textSize);
	  	
	  	
	  	
	  	printf("enter the text \n");
	  	scanf("%c",&junk);
	   	scanf("%[^\n]",text);
	  	//alternatif scanf("%s",text);
	  	
	  	//burda sunu yapýyoruz mesela kelimemiz 12 harfli bunun karekoku 3 olur bunu yuvarlayýnca  4 eder 4x4=16 olur yaný textýmýz matrisimizin içine sýgmýs oluyor
	  	
	  	m =ceil(sqrt(textSize));
	  	
		//text dizisi için indextir
	  	k=0;
	  	theImage=(int**)(calloc)(m,sizeof(int*));
	  	for(i=0;i<m;i++){
	  		theImage[i]=(int*)(calloc)(m,sizeof(int));
		  }
	  	
	  	for(i=0;i<m;i++){
	  	//	theImage=(int**)realloc(theImage,(i+1)*sizeof(int*));
	  		for(j=0;j<m;j++){
	  	//		theImage[i]=(int*)realloc(theImage[i],(j+1)*sizeof(int));
	  			if (k<textSize){
	  				pixel=(int )text[k];
	  				theImage[i][j]=pixel;
	  				
				  }
				  else {
				  	theImage[i][j]=0;
				  }
				  k++;
	  		  	
			  }
		  }
	  	printf("the ýmage is:\n");
	  	for(i=0;i<m;i++){
	  		for(j=0;j<m;j++){
	  			printf("%3d",theImage[i][j]);
			  }
			  printf("\n");
		  }
		  free(theImage);
		  free(text);
	  	return  0;
	  }
	  //KOD CALISIYOR
	  //açýklamalarý yazýldý
