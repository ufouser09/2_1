
Structure alignment

þimdi structure alignment ettiðimizde aþaðýdaki gibi yazdigimzida burdaki sýraya göre bellekten yer kaplar.
ve bu bellekten yer kaplama esnasýnda arada bosluklar olabiliyor.
Bu bosluklar neye sebep oluyor:verimsiz alan kullanýmýna sebep oluyor.
Gömülü gibi alanlarda bellek çok önemlidir.
Bunlarýn verimli kullanýmý saðlýycak yaklasýmlardan bir tanesi bit field'lar

structure ALIGN_EXAMP{
char mem1;
short mem2;
char mem3;
}s1;

//BÝT FÝELDS

Normalde bir degiskenin kapladýgý alan bellidir mesela int için 4 byte dedik char için 1 byte dedik.
Bunu daha cok kýsýtlayabiliyoruz ve bellegi daha etkin kullanabiliyoruz.
Örneðin tc kimlik numarasý sayýsal olarak düþündüðünüzde a
Mesela gün dedigimiz sey en fazla 30 olabiliyor yani 5 bit olabiliyor.
O yüzden bu alaný azaltmak gerekiyor o yüzden bit fieldlardan kullanýyoruz.

Bit field bellegin bir hücresindeki ilgili bitlere eriþmekle alakalý oldugu için 2 tane sýkýntýsý var.
1-Bunun adresini alamýyorsunuz çünkü ben bir adrestte birden fazla veri saklamaya çalýsýyorum.
2-Bit field'larla bir dizi olusturamýyoruz.

Genellikle bit field'lar kullanýlýrken int veya unsigned int gibi þeyler kullanmak iyi olur niye gereksiz verilerin önüne geçersiniz.
Mesela gün ay yýl bunlarý unsigned oldugunu biliyoruz bu yüzden bunlarý integer yazmak yerine unsigned yazmak daha doðru olur.



yazýlýmý þöyle olur

struct{
int a:3;//burda a 3 bitlik bir integer oldugunu söyler.
int b:7;//burda b 7 bitlik bir integer oldugunu söyler.
int c:2;
}s;
Sadece implemantasyon aþamasýnda bir veri yazýcaksanýz ona dikkat etmeniz gerekiyor.

Eger bizim burda kullandýgýmýz alan bu þeye yetmezse bir sonraki bitfield bir sonraki hücreden baslýycaktýr.

Genellikle bunu nerde kullanýrýz:
Gün ay yil gibi belli alanlarda belli aralýklarda degerlerin girilecegi yerde kullanýlýr.
Bu sunu da saglar veri güvenliðini de saglar


UNION 

Bu da bir structer elemaný gibidir ama structer da tanýmlanan her bir elemanýn kendine ait bir lokasyonu bellek adresi varken
Burda ortak kullanýmý saðlamak adýna bir bellek hücresi birden fazla degiskene tahsis edilebiliyor.
Mesela tc vatandaþý ise tc kimlik numarasýný gir yabancý vatandaþ ise pasaport numarasýný gir gibi.
Bu tarz durumlarda bu tür þeyler kullanýlýr.


