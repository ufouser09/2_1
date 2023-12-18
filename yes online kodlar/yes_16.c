random access:
biz herhangi bir dosyada calýsan kayýtlarýný yaptýgýmýz dosyada herhangi bir calýsanýn kayýdýný bulmak istiyorsak dosyanin basýndan baslayýp o kayýdý bulana kadar okumammýz gerekiyor normalde mesela dizilerde de oyle bir elemaný bulmak için en bastan baslayýp elemaný bulana kadar okuma yapmamýz gerekiyor.ama daha hýzlý bir arama istiyorsak da binary search gibi sýralý dizi üzerinde calýsan algoritmalarý kullanýyorduk.dosyalar için de benzer durum gecerli eger siralarsak daha kolay bulabiliriz.burda sýralama daha tercih edilebilir çünkü dosyaya erisim bellek erisiminden daha yavas fakat dosyalarý sýralamak da uzun sürecektir.
amacýmýz bellekteki herhangi bir dizi elemanýna git dizinin 3.elemanýna eris diye dogrudan bir index verebiliyorsak benzer þekilde dosyalarda iþlem yapabilir miyiz.yapabiliriz.buna da random access rastgele erisim deniyor.bunu yapabilmek için 2 tane temel fonksiyonumuz var:fseek() ve ftell()

fseek bize dosya konum isaretcisini belirli bir byte pozisyonuna goturmeyi saglýyor.
ftell ise dosya konum isaretcisinin suanda dosyanýn kacýncý byte'ýnda oldugunu soyluyor.
bu iki fonksiyonu kullanaraktan istedigimiz bir yere dosya konum iþaretcisini götürebiliriz ve ordan itibaren okumaya baslýyabiliriz.

fseek'in fonksiyon imzasý:
int fseek(FILE *stream,long int offset,int whence);

ilk eleman bir file pointer'ý ikinci parametre offset bir baslangýc noktasý bu sýfýr olabilir negatif olabilir,üçüncüsü ise offset üstüne ne kadar byte ekleyip dosya konum iþaretcisini oraya götürmemizi saðlýycak olan iþaretci.
offset'i genelde 0 tutmak mantýklýdýr.ama eger sizin algoritmanýzý kolaylastýracaksa negatif de olabilir.

eger stream dosya iþaretcisi binary modda ise byte cinsinden deger olmus oluyor offsete verecegimiz rakam.
eger metin dosyasýnda bunu actýysak ya sýfýrdýr veyahutta ftell()'in bize soyledigi degerdir.

nereye gitmek istedigimizle ilgili 3 tane ön tanýmlý sabit var
SEEK_SET:dosyanýn basý 
SEEK_CUR:su anki pozisyon 
SEEK_END:dosyanýn sonuna git anlamýna geliyor.
 
 ayrýca fseek()fonksiyonu bana ayrýca int olarak bir sonuc donduruyor.
 
 soyle bir fonksiyon cagýrdýgým zaman 
 stat=fseek(fp,10,SEEk_SET);
 soyle oluyor dosyanýn basýndan 10.karaktere git
 
 fseek fonksiyonunun ilk parametresi dosya iþaretcisi file pointer,ikinci parametre kac byte ilerlemek istedigimiz.bu negatif de olabilir tabi ki de geri de gitmek isteyebiliriz bulundugumuz konumdan ama nereden itibaren ofset kadar gidicez.mesela en bastan itibaren gitmek isteyebiliriz bulundugumuz konumdan itibaren gitmek isteyebiliriz veya dosyanýn sonundan itibaren gitmek isteyebiliriz.ama dosyanýn sonundayken offseti pozitif bir sayi girersek hata alýrýz çünkü dosyanýn sonundan daha ileri gidemeyiz ancak geri gitmemiz söz konusu olabilir o yüzden offset negatif olabiliyor.
 
 orneðýn soyle bir þey verirsek 
 
 stat=fseek(fp,10,SEEK_SET);
 burda sunu dýyor:dosya konum iþaretcisinin bulundugu konumdan 10 byte ileri git anlamýna geliyor.bundan sonra okuyacagým ya da yazýcagým eleman orda olmus oluyor.eger islem basarýlý ise 0 dönduruyor bize stat'ýn degeri 0 olmus oluyor.iþlem basarýsýz ise 0 olmayan bir deger donmus oluyor.
 
 her file point stream olarak iþleniyordu 0 dan baslanýyor.yani ben yukarýdaki gibi eger 10 dersem 11.karakter olmus oluyor.yani 0 dan saymaya basladýgýmýz için o 11.karakter olmus oluyor.
 
 fseek 'in 0 dýsýnda bir sorun döndürmesi neden olabilir.örneðin 
 
 madem rastgele erisim yapýyoruz,dosyanýn herhangi bir konumuna gitmek önemli ama dosyanýn neresinde oldugunu bilebilmek de onemli bunun için ftell fonksiyonumuz var aldýgý tek parametre dosya iþaretcisi bizde dondurdugu ise dosyanin konumunu baslangýcýndan itibaren kacýncý byte'ta oldugumuzu bize geri donduruyor.
 yalnýz binary degil metin dosyasýnda isek o zaman ftell'in dondurdugu farkli sekillerde yorumlanabiliyor.þimdi fseek'in 2 parametresi vardý 
 
 yani temel olarak 2 tane fonksiyonumuz var fseek ve ftell 
 
 fseek ile ilgili olarak bizi herhangi bir noktaya gidebilmemize yarýyor.
 ftell de nerdeyse onu öðrenmemize yarýyor.
 
 þimdi bunlarý bir araya getirecek bir ornek yapalým 
 bir çalýsan listesine bir hýz ve erisim yapmak istiyoruz bunun için dosyaya sýralamaktan kacýnmak istiyoruz.cunku dosyaya sýralamak da masraflý.ben sadece çalýsan numarasýna göre sýralama yapmak istemeyebilirim.calýsanýn adýna göre siralama yapmak isteyebilirim.calýsanýn maasýna göre sýralama yapmak isteyebilirim.yani farklý kriterlere göre sýralama yapmak isteyebilirim.farklý kriterlere göre arama yapmak isteyebilirim.o yuzden her bir fikir degistirdigimde de dosyayý tekrar tekrar sýralamakta mantýklý degil.ama birden fazla index olusturmak mantýklý býrakýn dosya oldugu gibi sýrasýz kalsýn fakat biz o dosya için bir veya daha fazla index tutalým dizin tutalým yani ve hangi sýrada gezmek istiyorsak o dosyayý ilgili index dosyasý üzerinden 
 index'imiz bir struct yapýsýndan olup 2 tane alaný olur.
 
 birinci alaný index'i tutmak istedigimiz bilgi 
 ikinci alaný bizim bu kayýdýmýz dosyada kacýncý konumda yer alýyor.
 
 sonra biz o structlardan olan diziyi sýraladýgýmýzda iþte size sýralý index
 ve biz kac farklý alanda index tutmak istiyorsak o kadar farklý structýmýz o kadar farklý dizimiz olur ondan sonra bu index'i bile ayrý bir dosyaya yazabiliriz.kalýcý olmasýný istiyorsak bu mantýklý çünkü programýmýz her acýldýgýnda index'i 0 dan olusturmaya çalýsmak yerine olusturdugunuz index'i dosyaya da yazabiliriz.
 sonra programýmýz bi da calýstýgýnda eger index dosyasý varsa o zaman bunu tekrar olusturmaya kalkmaz sadece o diskten hýzlýca okur tekrar sýralama iþlemi yapmaz bu da bizim için bir avantaj olur 
 ama tabiki de index'in guncel tutulmasý da onemlidir.bu ilgili calýsanlar dosyasýna herhangi bir duzenleme yapýldýgýnda index'inde tekrar tazelenmesi gerektigini programcý olarak unutmamamýz gerekiyor.
 
 
 eger veri dosyasýnda düzenleme yapýlmýs ise 
