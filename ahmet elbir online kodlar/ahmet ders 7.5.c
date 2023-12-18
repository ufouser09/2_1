/*
N tane complex bir sayi saklamak istiyorum yani bir dizi olucak mesela ama bu N taneyi bellekte peþ peþe saklamak mümkün degil
cunku o kadar yerimiz yok
linked list ile array farký burda ortaya cýkýyor
mesela N elemanlý malloc ile bir array olusturduk 
bunlar bellekte bitiþik olarak sýralanýr
ama linked listte ayrý ayrý yerlerde olur 
bitiþik olmadýgý için bir yerden baslayýp teker teker elemanlarý gezmem lazým
mesela en bastaki eleman head olarak adlandýrýlýr 
ondan sonra 2.eleman 3.elemanlarý bir yerde saklamam lazým
iþte burda pointer mantýgý ile structlar birbiriyle saklanabiliyor

linked listler soyle oluyor mesela bi tanesi bir integer imajýner tutuyor bir tanesi integer reel tutuyor bi de node tutuyor
bu node bir sonraki node un adresini tutuyor
en sondaki elemanda son yerinde node degil artýk null tutuyor
bu sayede N elemanlý bir þey saklanabilir

linkli listin içinde birden fazla data saklayabiliriz ama mutlaka bir sonraki dugumun pointerýný saklýcaz
en sondaki eleman null u göstercek ama linked list içindeki baska bir elemaný da gösterebilir boylece circular linked list olusturursunuz
linked listin bir tek yonlusu vardýr bi de cýft yonlusu vardýr
çift yonlusune double lýnked list diyoruz

tek yonlude mesela *next tutuyorduk ya cýft yonlusunda *prev de tutyoruz ayný yerde böylece ileri geri yapmak daha kolay oluyor bizim için
burda bellekten kayýp veriyoruz ama

linked listte ilk eleman head dir
dizinin ilk elemanýný gösteren pointer head dir

array[i]
*(array+i)

(array)
array++;
burda yukardakinden farklý olarak ilk elemanýn adresini kaybediyoruz

en son dugum null u gösterir

dizinin sonuna daha kolay ulaþabilmek için *last pointer kullanýrýz diziye ekleme cýkarma yaptýgýmýzda bu last pointerý ayrýca guncellersiniz bu da head gibi ayrý bir pointerdýr

mesela bir dizide ekleme cýkarma yapmak istedigimizde noluyordu sureklý elemanlarý shift ediyorduk ama bu linked listte buna gerek yok
linked listte ekleme cýkarmalarda shift yapmýyoruz o yuzden dizilerde olan ekleme cýkarmadan daha kolay


//2.05.11 de kaldýk
