random access:
biz herhangi bir dosyada cal�san kay�tlar�n� yapt�g�m�z dosyada herhangi bir cal�san�n kay�d�n� bulmak istiyorsak dosyanin bas�ndan baslay�p o kay�d� bulana kadar okumamm�z gerekiyor normalde mesela dizilerde de oyle bir eleman� bulmak i�in en bastan baslay�p eleman� bulana kadar okuma yapmam�z gerekiyor.ama daha h�zl� bir arama istiyorsak da binary search gibi s�ral� dizi �zerinde cal�san algoritmalar� kullan�yorduk.dosyalar i�in de benzer durum gecerli eger siralarsak daha kolay bulabiliriz.burda s�ralama daha tercih edilebilir ��nk� dosyaya erisim bellek erisiminden daha yavas fakat dosyalar� s�ralamak da uzun s�recektir.
amac�m�z bellekteki herhangi bir dizi eleman�na git dizinin 3.eleman�na eris diye dogrudan bir index verebiliyorsak benzer �ekilde dosyalarda i�lem yapabilir miyiz.yapabiliriz.buna da random access rastgele erisim deniyor.bunu yapabilmek i�in 2 tane temel fonksiyonumuz var:fseek() ve ftell()

fseek bize dosya konum isaretcisini belirli bir byte pozisyonuna goturmeyi sagl�yor.
ftell ise dosya konum isaretcisinin suanda dosyan�n kac�nc� byte'�nda oldugunu soyluyor.
bu iki fonksiyonu kullanaraktan istedigimiz bir yere dosya konum i�aretcisini g�t�rebiliriz ve ordan itibaren okumaya basl�yabiliriz.

fseek'in fonksiyon imzas�:
int fseek(FILE *stream,long int offset,int whence);

ilk eleman bir file pointer'� ikinci parametre offset bir baslang�c noktas� bu s�f�r olabilir negatif olabilir,���nc�s� ise offset �st�ne ne kadar byte ekleyip dosya konum i�aretcisini oraya g�t�rmemizi sa�l�ycak olan i�aretci.
offset'i genelde 0 tutmak mant�kl�d�r.ama eger sizin algoritman�z� kolaylast�racaksa negatif de olabilir.

eger stream dosya i�aretcisi binary modda ise byte cinsinden deger olmus oluyor offsete verecegimiz rakam.
eger metin dosyas�nda bunu act�ysak ya s�f�rd�r veyahutta ftell()'in bize soyledigi degerdir.

nereye gitmek istedigimizle ilgili 3 tane �n tan�ml� sabit var
SEEK_SET:dosyan�n bas� 
SEEK_CUR:su anki pozisyon 
SEEK_END:dosyan�n sonuna git anlam�na geliyor.
 
 ayr�ca fseek()fonksiyonu bana ayr�ca int olarak bir sonuc donduruyor.
 
 soyle bir fonksiyon cag�rd�g�m zaman 
 stat=fseek(fp,10,SEEk_SET);
 soyle oluyor dosyan�n bas�ndan 10.karaktere git
 
 fseek fonksiyonunun ilk parametresi dosya i�aretcisi file pointer,ikinci parametre kac byte ilerlemek istedigimiz.bu negatif de olabilir tabi ki de geri de gitmek isteyebiliriz bulundugumuz konumdan ama nereden itibaren ofset kadar gidicez.mesela en bastan itibaren gitmek isteyebiliriz bulundugumuz konumdan itibaren gitmek isteyebiliriz veya dosyan�n sonundan itibaren gitmek isteyebiliriz.ama dosyan�n sonundayken offseti pozitif bir sayi girersek hata al�r�z ��nk� dosyan�n sonundan daha ileri gidemeyiz ancak geri gitmemiz s�z konusu olabilir o y�zden offset negatif olabiliyor.
 
 orne��n soyle bir �ey verirsek 
 
 stat=fseek(fp,10,SEEK_SET);
 burda sunu d�yor:dosya konum i�aretcisinin bulundugu konumdan 10 byte ileri git anlam�na geliyor.bundan sonra okuyacag�m ya da yaz�cag�m eleman orda olmus oluyor.eger islem basar�l� ise 0 d�nduruyor bize stat'�n degeri 0 olmus oluyor.i�lem basar�s�z ise 0 olmayan bir deger donmus oluyor.
 
 her file point stream olarak i�leniyordu 0 dan baslan�yor.yani ben yukar�daki gibi eger 10 dersem 11.karakter olmus oluyor.yani 0 dan saymaya baslad�g�m�z i�in o 11.karakter olmus oluyor.
 
 fseek 'in 0 d�s�nda bir sorun d�nd�rmesi neden olabilir.�rne�in 
 
 madem rastgele erisim yap�yoruz,dosyan�n herhangi bir konumuna gitmek �nemli ama dosyan�n neresinde oldugunu bilebilmek de onemli bunun i�in ftell fonksiyonumuz var ald�g� tek parametre dosya i�aretcisi bizde dondurdugu ise dosyanin konumunu baslang�c�ndan itibaren kac�nc� byte'ta oldugumuzu bize geri donduruyor.
 yaln�z binary degil metin dosyas�nda isek o zaman ftell'in dondurdugu farkli sekillerde yorumlanabiliyor.�imdi fseek'in 2 parametresi vard� 
 
 yani temel olarak 2 tane fonksiyonumuz var fseek ve ftell 
 
 fseek ile ilgili olarak bizi herhangi bir noktaya gidebilmemize yar�yor.
 ftell de nerdeyse onu ��renmemize yar�yor.
 
 �imdi bunlar� bir araya getirecek bir ornek yapal�m 
 bir �al�san listesine bir h�z ve erisim yapmak istiyoruz bunun i�in dosyaya s�ralamaktan kac�nmak istiyoruz.cunku dosyaya s�ralamak da masrafl�.ben sadece �al�san numaras�na g�re s�ralama yapmak istemeyebilirim.cal�san�n ad�na g�re siralama yapmak isteyebilirim.cal�san�n maas�na g�re s�ralama yapmak isteyebilirim.yani farkl� kriterlere g�re s�ralama yapmak isteyebilirim.farkl� kriterlere g�re arama yapmak isteyebilirim.o yuzden her bir fikir degistirdigimde de dosyay� tekrar tekrar s�ralamakta mant�kl� degil.ama birden fazla index olusturmak mant�kl� b�rak�n dosya oldugu gibi s�ras�z kals�n fakat biz o dosya i�in bir veya daha fazla index tutal�m dizin tutal�m yani ve hangi s�rada gezmek istiyorsak o dosyay� ilgili index dosyas� �zerinden 
 index'imiz bir struct yap�s�ndan olup 2 tane alan� olur.
 
 birinci alan� index'i tutmak istedigimiz bilgi 
 ikinci alan� bizim bu kay�d�m�z dosyada kac�nc� konumda yer al�yor.
 
 sonra biz o structlardan olan diziyi s�ralad�g�m�zda i�te size s�ral� index
 ve biz kac farkl� alanda index tutmak istiyorsak o kadar farkl� struct�m�z o kadar farkl� dizimiz olur ondan sonra bu index'i bile ayr� bir dosyaya yazabiliriz.kal�c� olmas�n� istiyorsak bu mant�kl� ��nk� program�m�z her ac�ld�g�nda index'i 0 dan olusturmaya �al�smak yerine olusturdugunuz index'i dosyaya da yazabiliriz.
 sonra program�m�z bi da cal�st�g�nda eger index dosyas� varsa o zaman bunu tekrar olusturmaya kalkmaz sadece o diskten h�zl�ca okur tekrar s�ralama i�lemi yapmaz bu da bizim i�in bir avantaj olur 
 ama tabiki de index'in guncel tutulmas� da onemlidir.bu ilgili cal�sanlar dosyas�na herhangi bir duzenleme yap�ld�g�nda index'inde tekrar tazelenmesi gerektigini programc� olarak unutmamam�z gerekiyor.
 
 
 eger veri dosyas�nda d�zenleme yap�lm�s ise 
