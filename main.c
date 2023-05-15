#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	printf("Hazirlayan: Eda Nur Ergin-1220505032\n\n");
	
	
	int dizi[]={4,8,3,84,47,76,9,24,68}; //dizimizi tanimlayip elemanlarini atadik.
	int boyut= sizeof(dizi)/sizeof(dizi[0]); //dizinin boyutunu bulduk
	
	//binary search algoritmasi siralanmis dizilerde arama yapar Bu yuzden once dizimizin elemanlarini siralacagiz
	// daha sonra arama algoritmasina gececegiz
	
	//insertion sort algoritmasi
	// verilerin sirasini degistirmek icin siralama_Key ve d degiskenlerini kullanacagiz.
	int e ; //for dongusu  parametresinde kullanacagiz
	int siralama_Key ; /*elemanlari tek tek siralarken once bu degiskene kaydedecegiz 
	yani bu degisken siralanacak olan elemanlari tutar.*/
	int d ; // while dongusu parametresinde kullanacagiz .Bu degisken siralanmis bölgedeki elemanlarin indeksini temsil eder
	
	for(e=1;e<boyut;e++) //burada e=0 diye baslamadik bunun sebebi insertionsort ile siralarken baslangicta kosede bir eleman ayirmamizin gerekmesidir.
	{
		siralama_Key = dizi[e]; //siralanacak olan elemani siralama_Key degiskenine kaydediyoruz.
		d =e-1; // bu atama  sayesinde while dongusunde dizide gezerken 0'inci indisten baslayacagiz.
		
		while( d>=0 && dizi[d]>siralama_Key) /*bu dongu siralanmis bölgedeki elemanlari , siralama_Key ile karsilastirir
	     ve siralama_Key 'den daha buyuk olanlari saga dogru kaydirir. Dongu sona erdiginde  siralama_Key dogru pozisyona yerlestirilecek.*/
		{
			dizi[d+1]= dizi[d]; //bu atama sayesinde , kucuk indisten buyuk indise dogru kucukten buyuge degerler yerlesecek
			d=d-1;// bu tanimlama sayesinde bir alt indise geceriz
		}
		
		dizi[d+1]=siralama_Key ; //siralama_Key degiskenini dogru pozisyona yerlestiriyoruz
	}
	
	//satir 21 -33 arasinda dizimizi siraladik Simdi siralanmis diziyi yazdiracagiz.
	
	int a ; // siralanmis dizimizi yazdirirken for parametresinde kullanacagimiz degiskeni tanimladik
	for(a=0;a<boyut;a++)
	{
		printf("%d. indis = %d \n",a,dizi[a]);
    }
	
	printf("\n\n\n\n");
	
	int aranan_eleman = 76 ;
	printf("ARANAN ELEMAN = 76 \n\n");
	int sag= boyut - 1 ; //dizinin sag siniri indexi
	int sol= 0 ; //dizinin sol siniri indexi
	int orta ; //dizinin ortasi indexi
	
	int sonuc ; // ikili arama algoritmasindan cikacak degeri tanimladik.
	
	sonuc = -5 ; // aranan deger bulunamazsa sonuc -5 olarak kalacaktir.
	
	//ikili arama algoritmasi yapisini olusturduk
	while( sol<=sag )
	{
		orta = sol +(sag-sol)/2 ; //ortadaki elemanin indexinin hesabini tanimladik.
		
		
		if(dizi[orta]== aranan_eleman) //aranan deger ortadaysa
		{
		   sonuc= orta; //sonuc, dizinin ortasindaki elemanin indexine atanir
		   break;// eger elemani bulduysan halen ikiye bolmeye devam etmemek icin donguyu durdurman gerek.
     	}
		
		if(dizi[orta]> aranan_eleman) // aranan deger ortadaki elemandan daha kucukse sol tarafi kontrol et
		{
		
		   sag = orta-1 ; // dizinin orta kisminin sol tarafinda bulunan elemanlar icin yeni sag degerin indexini atadik.
	    }
		  
		if(dizi[orta]< aranan_eleman) // aranan deger ortadaki elemandan daha buyukse sag tarafi kontrol et
		{
		   sol= orta+1; // dizinin orta kisminin sag tarafinda bulunan elemanlar icin yeni sol degerin indexini atadik.
	    }
		
	}
	

	 
	 if(sonuc == -5)
	 {
	     printf("aranan eleman bulunamadi \n");
	 }

	 else
	 {
	 	printf("aranan elemanin indexi : %d \n",sonuc);
	 }

	 
	 
	
	
	
	return 0;
}
