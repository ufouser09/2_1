 binary text modundaki bir dosyay� hem text modda hem binary modda ac�p tek tek karakter karakter veri al�p karakter karakter veri yazabildik bu �rnegi g�rm�s olduk.
 s�md� getc() ve fgetc() fonksiyonlar�m�z var asl�nda getc() bir makro fgetc() ise bir fonksiyon,fonksiyon ile makro aras�ndaki avantaj ve dezavantajlara deginmi�tik.makrolar�n baz� beklenmedik yan etkileri olabiliyordu.fonksiyonlar bu y�zden daha avantajl� idi
 
 getc ve putc fgetc ve fputc den nerdeyse 2 kat daha h�zl�d�r.
 
 emin olmak i�in fgetc ve fputc kullan�n.
 
 �imdi de sat�r satir bilgi okuma ve satir satir bilgi yazma i�leminin nas�l yap�lacag�n� gorucez
 burda bir onceki ornege gore en onemli fark 
 �imdi binary modda degilde metin modunda acal�m dosyay�  
 
 fgets nin de 3 parametresi var 
 metinlerde null terminationa g�venemezsiniz
 
 mesela bir metin dosyas� act�k orda paragraf i�aretleri vard� ama bir dosya paragraf i�aretiyle bitmeyebilir.yani o metin dosyas� i�erisinde null karakteri yok bu nedenle biz sat�r satir okuycaz dedik ama bu satir otomatik bir return veya paragraf veya \n  veya \t bunlar degil belirli bir karakter kat�nda karakter okuma i�lemleri yapmam�z gerekiyor bu nedenle fazladan LINESIZE 100 diye bir ifade tan�mlad�k ve o ebatta okucam 
 fgets n�n parametrelerine bakarsam i�te birinci parametrem okudugum metinsel veriyi yaz�cag�m bir bellek alan� kac karakter okuycam LINESIZE dan bir eksik cunku en son karakteri null terminate yap�yor C bellekte ona ay�rmak istiyorum ��nk�
 fgets bana duzgun bir karakter katar� dondurmusse problem yok okumaya devam edicem yani bunun dondurdugu karakter katar� null olmad�g� surece okumaya devam edicem once okudugum sey� ikinci dosyaya yaz�cam ondan sonra tekrar okuma i�lemine gecicem eger bir �ey okuyabilmissem onu da tekrar yaz�cam 
 
 \n veya \t gorurse okuma s�ras�nda 100 karakteri doldurmay� beklemiyo 
