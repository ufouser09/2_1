 binary text modundaki bir dosyayý hem text modda hem binary modda acýp tek tek karakter karakter veri alýp karakter karakter veri yazabildik bu örnegi görmüs olduk.
 sýmdý getc() ve fgetc() fonksiyonlarýmýz var aslýnda getc() bir makro fgetc() ise bir fonksiyon,fonksiyon ile makro arasýndaki avantaj ve dezavantajlara deginmiþtik.makrolarýn bazý beklenmedik yan etkileri olabiliyordu.fonksiyonlar bu yüzden daha avantajlý idi
 
 getc ve putc fgetc ve fputc den nerdeyse 2 kat daha hýzlýdýr.
 
 emin olmak için fgetc ve fputc kullanýn.
 
 þimdi de satýr satir bilgi okuma ve satir satir bilgi yazma iþleminin nasýl yapýlacagýný gorucez
 burda bir onceki ornege gore en onemli fark 
 þimdi binary modda degilde metin modunda acalým dosyayý  
 
 fgets nin de 3 parametresi var 
 metinlerde null terminationa güvenemezsiniz
 
 mesela bir metin dosyasý actýk orda paragraf iþaretleri vardý ama bir dosya paragraf iþaretiyle bitmeyebilir.yani o metin dosyasý içerisinde null karakteri yok bu nedenle biz satýr satir okuycaz dedik ama bu satir otomatik bir return veya paragraf veya \n  veya \t bunlar degil belirli bir karakter katýnda karakter okuma iþlemleri yapmamýz gerekiyor bu nedenle fazladan LINESIZE 100 diye bir ifade tanýmladýk ve o ebatta okucam 
 fgets nýn parametrelerine bakarsam iþte birinci parametrem okudugum metinsel veriyi yazýcagým bir bellek alaný kac karakter okuycam LINESIZE dan bir eksik cunku en son karakteri null terminate yapýyor C bellekte ona ayýrmak istiyorum çünkü
 fgets bana duzgun bir karakter katarý dondurmusse problem yok okumaya devam edicem yani bunun dondurdugu karakter katarý null olmadýgý surece okumaya devam edicem once okudugum seyý ikinci dosyaya yazýcam ondan sonra tekrar okuma iþlemine gecicem eger bir þey okuyabilmissem onu da tekrar yazýcam 
 
 \n veya \t gorurse okuma sýrasýnda 100 karakteri doldurmayý beklemiyo 
