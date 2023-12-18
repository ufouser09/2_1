
-klavye----------> input, ekran----------> output
-input sadece klavye olmayabilir.
-ekran sadece output olmayabilir .

-Eger programýnýzda kullandýgýnýz verileri kalýcý olarak saklamak istiyorsanýz program kapandýktan sonra da saklansýn diyorsanýz 
"hard-disk üzzerinde"(kalýcý hafýza üzerinde) "belli alanlar olusturup" bu alanlarda verilerinizi saklamanýz gerekiyor.

-buna biz "ýnput/output" diyoruz ve burda kullanýlan þey daha cok "file islemleri" olucak 
 Biz burda bir þekilde "iþletim sistemi" ile beraber bir þekilde haberleþme halinde olucaz.

**veri okurken hard-diske eriþmek gerekiyor**.

-hard-disk'in özellikle calýsma mantýgý sudur:
hard-disk uzerindeki veri ram'e kopyalanýyor içeriði neyse bu kopyalama esnasýnda bir veri akýsý meydana geliyor 
ve bu dosyalar ya dogrudan "clear bir þekilde" saklanýr veya "binary þekilde" kodlanarak saklanýr.
Ýþletim sistemi bu kodlarý cozecek dosya okuma formatlarýyla alakalý bilgiye sahip olmasý gerekir.

-Buffer olmasýnýn anlamý sürekli git gel yapmýyo hard-diske belirli aralýklarla yapýyor.

-I/O ve stream sudur:
Bir program c programý olmak zorunda degil bir dosyayý okumak istediginde veya bir yazýcýya veri gondermek istediginde 
veriler bu sekilde bir dizi halinde kopyalanýyor akýs gerceklesiyor.

-stream dedigimiz sey iþletim sistemi tarafýndan ayrý bir yapý.

-Bizim I/O operasyonlarýný programýmýz içinde gerçekleþtirebilmemiz için stream'i bir þekilde elde etmemiz gerekir,
onunla bir þekilde haberleþmemiz gerekir.
Assosiciate bir iliþki kurmamýz gerekiyor.
Bunu bir C dilinde yapmanýn yolu "FILE" turunde bir pointer tanýmlamaktan gecer ve bu aslýnda bir "struct'týr".
FILE struct'ýrýndan bir pointer tanýmlamak gerekiyor.

-Bir streamýn oldugunu ,iþletim sistemiyle bir þekilde haberleþmeye geçmemiz gerektiðini bilmemiz gerekiyor.

-Temelde 3 tane standart stream vardýr ve bu iþletim sistemiyle alakalýdýr:
Bir ýnput yapýlacaksa streamde "stdin" stream türü kullanýlýyor.
Output kullanýlacaksa "stdout" kullanýlýyor.
Herhangi bir hata durumunda da "stderr" kullanýlýyor.
bu iþletim sistemiyle alakalý bunun uygulamasýný C de de görücez.	
 
-Bizim printf scanf fonksiyonlarýnýn arkada yaptýgý sey su
printf--->stdout kullanýyor.
scanf----->stdin kullanýlýyor.

-Bu fonksiyonlarý kullanarak dosyalar üzerinde herhangi bir dosyayý iþaret ederek.
yapýcagýmýz sey o dosya uzerinden I/O yapmak.

printf nasýl program üzerinde ve bir comment line üzerinde çalýþýyor ise 
bizde ayný þekilde bir dosya üzerinde ayný bir comment line gibi çalýþýcaz.

-Aslýnda printf'in yaptýgý da arkada bir dosya okumaktýr.

-O dosya comment line'ýn özel dosyasý arka planda calýsan dosyasý.

Dosya nedir?
Bi kere dedik ki bunlar "hard-disk üzerinde" kalýcý olarak saklanacak.
Dosya dedigimiz sey ---->0 ve 1'ler dizisi.

Ama biz bunu genelde su sekilde gösteriyoruz

**


-Kullandýgýmýz hemen hemen her dosya bu þekilde "0 ve 1'ler dizisi" þeklinde saklanýyor.
O zaman ben bu 0 ve 1'lerin yerleþimine bir anlam katarsam özel amaçlý bir dosya olusturmus olurum.

Örneðin kýsýlerin adýný soyadýný ID sýný bir excelde saklýycam.
Excel'in daha basit hali csv dir ve virgüllerle ve noktalý virgüllerle ayrýlan bir dosya formatýdýr.
Bunu clear text olarak sakladýgýnýzý düsünün.

Eger ben 0 ve 1'lerle saklýyorsam buna binary ,ad=efe soyad=girgin diye saklýyosam da buna text formatý demiþ olurum.

Þimdi her bir dosya için bazý önemli meta veriler lazým.

þimdi bizim bir 0 ve 1 ler dizisi olan bir binary formatta dosyam var.
biz bu dosyayý 3'e böldügümüzü düþünün:
ilk kýsmý "header" olur
2.si "data" olur.
3.sü "fonter" olur.----------->fonter her zaman olmak zorunda degil.

-dosyaya ait bazi ön bilgileri "header" dosyasýnda saklamak gerekebilir.

Örneðin bir resim dosyasý acmak istiyorsunuz veya bizim C dosyasýný açmak isterken surda detaylarý var:
bunun adý ney ,uzantýsý ney ,tipi ne ,iþte bulundugu lokasyon ne
Bu bilgilerin bi yerde saklanmasý lazým ki sen bu dosyayý acmak istediginde ilgili programlar iliþkilendirilsin.

Ýlgili program örneðin bir görüntü açýcaksýnýz.
Ne kadar boyutta oldugunu biliyor muyuz týklarken bilmiyoruz.
Týklayýnca bir malloc gibi bir þey arka tarafta çalýþmasý lazým ki git bak bellekte þu kadar yer aç bi görüntü geliyor demesi lazým.

Ýþte o bilgiler arka tarafta o "header" tarafýndan alýnmasý gerekiyor.

Sadece boyut tür degil örnegin bu dosyanýn nasýl bir yapýda olucagý orda soylenmesi gerekiyor.

-Binary saklanmasýnýn sebebi "daha az yer kaplamasý" ve "dosya içeriðinin gizlenmesi" ile alakalýdýr.

Bizim dosyalarýmýzda bu üç alan olur ama "footer" bazen olmayabilir,"header" genellikle vardýr.

Biz bunu C de yapmak için "stream'e eriþmek için" bir "FILE pointer" kullanmak gerekiyor.

Bu FILE pointer "stdio.h" içindedir.

**Bu FILE pointer'ýndan bir degisken olustururken hard-diskt'te "bir dosyanýn adresini" point etmesini isticez.**

Ve bu pointer vasýtasýyla stream üzerinde iþlemler yapabilicez--------->ister text dosya olsun ister binary dosya olsun. 

Bu stream,identifier'ý tutuyor aslýnda 

**Öncelikle dosyanýn file pointer'ýnýn olusturcaz olusturduktan sonra dicez ki dosyayý acmaya calis.

Bir program ayný anda birden fazla stream iþlemi yapabilir mi?  ----------->yapabilir.
Yani bi yandan okurken bi yandan yazma yapabilirsiniz.
Bunlar "concurrent stream" dedigimiz þeyler.


"File pointer" ile "file position indicator'ý" karýstýrmamak gerekir.

File pointer sudur iste "FILE turunden" olusturcaz beným bir hard-disktte dosyam vardý ben bunu bir þekilde bellege getirdim.
Ýþte O bellekteki dosyanýn adresi FILE pointerdýr. 

file position dosyanýn içindeki þu "curser'ýn pozisyonunu" gösteriyor.
file pointer dosyanýn adresini ifade ediyor.
file position belli bir byte pozisyonunu ifade ediyor.
oburu dosyanýn device uzerindekki adresini soyluyor.


Þimdi biz "<stdio.h>" içindeki "header file'a" baktýgýmýzda
Ornegin I/O fonksiyonlarý için bazý prototip declarationlar vardýr:
Ne demek bu declarationlar örnegin "EOF" veya bazý macro sabitleri burda kullanýlan sey veya typedef'ler file struct'ýrýn definition'u vardýr.
Yine bunun içerisinde file struct'ýrýn içerisindeki elemanlar iþte stdin stdout stderr gibi standart streamler vardýr.

Biz fscanf dýsýnda bu "stdin" ve "stdout'u" kullanarak klavyeden veri okuyusu ornegi yapýcaz.
fscanf kullanmadan baska bir sekilde 

"EOF" lar vardýr bunlar dosyanýn sonuna ulasýp ulasmadýgýný gösterir.
File position EOF'nýn ulasýp ulasmadýgýný kontrol eder.
 
 
Ýþte null dedigimiz null pointer ile ilgili iþlemler iþte dosya açýldý mý açýlmadý mý gibi 
 
bu stddef ile stdio ile kullanýrsak dosya içerisindeki null iþlemlerini gorebilicez
 
Ve bundan sonra dosya üzerindeki iþlemleri yapmak kalýyor.

Genel olarak konsept bu sekilde 
 
Dedik ki dosyalar "binary" veya "text" olarak bir þekilde sýralanýyor.
 
 eriþimlerine gore dosyalarý sýralamak þimdi 2 turlu erisim var:--------------------------------------
 bir "random access dosyada"
 bir de "sequantial access"
 
sequantial access de olan olay sudur bu bir bit dizisi ister satýr seklinde dusunun ister sadece 0 ve birler þeklinde dusunun
bu dosya acýldýgýnda bunun pozisyon controller'ý burdadýr.
 
 Sen ister bir bit okursun ister bir byte okursun ister bir satýr okursun istersen bir blok okursun.
 Bakýn "bit" okuyabiliyorum ,"byte" okuyabiliyorum, "formatted data" okuyabiliyorum .
 Yani git bi tane string bi tane integer bi tane float oku bi seferde bunu okuyabiliyoruz "line" okuyabiliyorum 
 Yani bi satýrýn tamamýný okuyabiliyorum veya bir blok okuyabiliyorum.ve bu okuma iþleminden sonra bit okuduysam 
 Bu curser bir bit kayýyor su formatta okuduysak onun size'ý kadar kayýyor.bi sonrakini okuyabilmek için 
 bu tamamen text dosyalarýnýn içerisinde de olabilir.
 binarylerde de olabilir.genellikle biz text dosyalarýnda "formatted data" dedigimizi çok kullanýrýz.
 binarylerde bit okumamýz gerekir.byte okumamýz gerekir.
 
 
 Random access de olan olay sudur.
 File position elemanýný dersin ki sen suan burdasýn git suraya kopyala 
 aradaki elemanlarý okumadan buraya konumlandýr.veya end-of-file'a git.veya rewrite diye bir fonksiyon vardýr.
 o fonksiyonu görünce tekrar basa don iþte satýrýn basýna gel.
 
 tape lerde verilerin sýralý girisine izin veren veri kaydetme birimleri vardýr.eski kasetler buna bir ornektir.
 
 
random accessde de bulundugun yerden git ordan bir bit oku diyebilirsin.veya bir byte oku diyebilirsin.veya bir formatlý data oku diyebilirsin.---------------------------------
 
 
 "FÝLE OP":
 Þimdi genel olarak dosya iþlemleri neler:
 Dosyayý "create" edebilirim,"delete" edebilirim,"rename" edebilirim.
 
 Bunlar bildigimiz klasorde mouse'un uzerine sað týklayýp yaptýgýmýz veya comment line uzerinden yaptýgýmýz seyler.
 Bu operasyonlar tamam ama asýl yapýlacak islem bir "read iþlemi" vardýr,birde "write iþlemi" vardýr.
 
 Write iþlemi,içerisindeki "bir veriyi update etmek olabilir",veya içerisinde "sýfýrdan bir veri yazmak olabilir","append etmek olabilir"
 append etmek sonuna eklemek demektir.
 
 Write iþlem,hiçbir þey yapmadan sýfýrdan yazmak anlamýna da gelir.
 
 Genellikle write modu ,"içerigini önce bosaltýr","ondan sonra sýfýrdan yazmaya baslar".
 
 Update içerisindeki bir veriyi degistirmek demektir.
 
 Append de kaldýgý yerden yani su file position elemanýnýn kaldýgý yerden oraya veri ekle demektir,içerigini bozma. 
 
 Read de sadece read yapýyor.----------------------------------------------------------------------------------
 Ýstedigin yerden ister bastan ister sondan okuma demektir.
 
peki dosya nasýl okunur? siz dosyayý nasýl okuyorsunuz? C de ya da herhangi bir programlama dilinde dosyayý nasýl okutursunuz?

 Dosyanýn bir adý vardýr ,bir de uzantýsý vardýr.
 Ben bi tane C de dosyayý açtým ben bunun içerigini nasýl okucam?

Dosyada birinci onemli þey yazýldýgý gibi okunur. 
dosya dedigimiz sey 0 ve 1 ler yani burda EOF dedigimiz sey en son -sonda- dosya ,ister text olsun ister binary olsun
sonucta bu 0 ve 1 ler degil mi her halde her bilgisayarda beným programlama dilim gidicek onu 0 ve 1'lere cevirecek.

Dosya nasýl yazýldýysa ona göre okunacak nasýl yazýldýktan kastýmýz su okuyacagýn ilk 4 eleman iþte dosyanýn adý olucak
sonra dosyanýn uzantýsý gelicek yani dosyayý yazan kýsý burda hangi mantýkla yazdýysa nasýl yazýldýysa dedigimden kastým bu.

Ona göre o 0 ve 1 leri alýyosun tek tek napýyosun anlamlandýrýyosun.

burda ben su ornegi veriyorum protein sentezi denilen bir olay var demi sýmdý proteýn sentezini baslatan bir 3 lu bir kodon vardýr,
bi de bitiren bir þey vardýr.Arada da kodlar vardýr.
O baslatýcý kodonu gorunce sentezin baslýcagýný yani iþlem baslýyo diyo sonra ondan sonra gelen her ücünden bir amýnoasýt karsýlý uretip 
napýyo sistem protein sentezi yapýyor.
ayný burda da oldugu gibi bu text dosyasý da olsa binary de olsa bunun genel hali burda baslayýp dosyanýn sonuna kadar giden
su 0 ve birler diyoki bu su kadar kýsýmda bunu al bu dosyanýn adý olsun artýk bunu yazan kýsý nasýl yazdýysa.
ondan sonraki	elemaný al o da dosyanýn size'ý olsun gibi 
 
 head'ýrda ilk okuyacagýmýz 2 byte dosyanýn type'ýna giriyomus.sonraki size'ýna giriyomus.soonra dosya kac tane renktten olusuyor 
 kac tane genislikte pixel var kac tane yukseklýkte pixel var yani boyutlarýný bunlar burdaki mantýkla kodlanmýs.
 artýk siz dosyayý nasýl tasarladýysanýz o tasarlanan mantýga göre okumak zorundasýnýz
  kuralý kim koyduysa o kurala uygun okumak zorundasýnýz mesela acýn bir pdf dosyasýnýn header'ini inceleyin 
  internetten o pfd okuyucularýn hepsi napmak zorunda o pdf ýn versiyonuna göre bikac tane versiyonu var ------------------------------------------
  o versiyona göre dosya okumak zorundadýr.yoksa program açmaz.mesela word programý baska hangi uygulamalarda çalýsýyo mesela free ofis programlarýnda calýsýyor neden calýsýyor word'un headerini ve yazým seklini o uygulamalar desteklýyor word'un uzantýsý ne doc ve docx.bunlar acaba nasýl bir dosyada kodlanmýs onu okuyan kýsý ona sahiptir ona gore dosya acýlýr.ayný þekilde dosyada bir veri degisikliði update veya yaz yatýgýnda da kaydederken o yazma formatýný kullanmak zorunda.dosya nasýl okunur:nasýl yazýldýysa oyle okunur.
 
 DOSYA NASIL YAZILIR:
 dosya nasýl istiyosanýz oyle yazýlýr.
 peki nasýl istememiz lazým:
 Kolay okunacak sekilde,kolay yazýlacak sekilde,anlamlý olucak rahat olucak bizi yormýcak sekilde yoksa bunun belli bir þeyi olsa 
 butun dosyalar belli formatta yazýlýr.
 
 Derler ki yaný sunu diyebilirlerdi resim dosyalarý ýcýn mesela bu iste png dosyasý png ler ne olsun bundan sonra 0 ve 1 olarak kodlansýn 
 veya 20 tane resim dosyasý var biz bunu en fazla 4 bitle kodlarýz mesela ilk 4 bit onun hangi turden oldugunu soylesin.
 ondan sonra sonraki 4bit size'ýný soylesýn sonraki bilmem kac bit kac pixelden olustugunu soylesin ondan sonra datasý gelsin iste 
 red green red green falan en sona durdurucu bir bit dizisi ekliyelim..
 yani hýc bir þekilde boyle bir standart yok.optýmum verimliligi saglýcak dosya formatý nedir yani öyle bir tasarlýyalým ki okumamýz 
 yazmamýz guncellememiz yapýcagýmýz her iþ kolay olsun herkesin kullanabilicegi bir þey olsun anlaþýlabilir olsun sade olsun.
 
 Dosya nasýl okunur?---------------> yazýldýgý gibi okunur.
 Dosya nasýl yazýlýr?---------------> istendigi gibi. 
 Nasýl isticez ?-------------------->optýmum sekilde yani performans kriterini goz onunde bulundurarak.
 
 Tabi performanstan kastým sadece erisim de olmamamlý bazý durumlarda dosyanýn az yer kaplamasý gerekir.
 Az yer kaplamasý için iþin içine burda "data compression" konusu giriyor.
 
 --file organization diye bizde bir ders var.yani bu cok kapsamlý bir dersttir.--
 
 Dosyalarý "ram uzerinde" degil de sonuca bunu "harddisk üzerinde" saklýcaz.
 Hard-disk uzerinde iþte bi-treeler   2 3 4 tree dedigimiz tree yapýlarý var.
 Veri yapýlarý onlarý kullanarak saklýcak sekilde bir sistem olusturmasý lazým. 
   

	mesela size proje verdik C de pdf okuyucu yazýn diye napmamýz lazým once pdf okuyucu yazýcaksak
 	ben once pdf 'in bu dosya formatýný bir ogreniyim ayný surda yaptýgým gibi eger ben bu dmp yý okucaksam bunun dosya formatýný
  	ogreniyim o dosya formatýný olusturan format neyse o mantýgý bilip ona göre ben ahmet.pdfreader veya imaj.reader gibi
   	bir þey yazmam gerekir.    
   
   
   Ýlk yapýcagýmýz þey okuma yazmadan once dosyayý acmak dosyayý acarken 2 tane arguman gönderiyooruz:------------------------
   Birincisi dosyanýn adý. 
   dosyanýn adýndan kastýmýz C'nin içindeki deneme.c mesela 
   sonra hangi access modu ile eriscez 
   sýmdý bu access modlarý okumak için mý acýyosun yazmak için mý acýýyosun eklemek için mý acýyosun 
   onun yanýna þoyle scanf'de kullandýgýmýz gibi "r" yazarýz.
   Þoyle olur yani:("C://Deneme.c","r").
   fopen fonksiyonu bunu yapýyor bize ve burdan geriye bir pointer donuyor.--------------->bu da file pointer'dýr.
   File pointer neydi FILE dan üretilen FILE structýn dan uretilen bir þey :------------->FILE * fp=("C://Deneme.c","r") boyle 
   
   Text streamler için ve Binary streamler için farklý access modlarý var.
   
   Text streamler için access modlarý slayttaki gibi 
   
   Binary moddakiler de bunlarýn aynýsý fakat bunlara ek olarak bunun sonuna bir "b" ekleniyor.
   
   Örnegin bu "r" var olan bir dosyayý okumak için aç demektir.
   
   Okuma nerden baslýyor dosyanýn basýndan baslýyor.
   
   Dosyanýn var olmadýgý durumda hata alýrsýnýz file pointer "null" doner.
   
   	"w"ile actýgýmýzda yazmak için yeni bir dosya aç 
   	eger dosya zaten varsa bu içi bosaltýlacak yani tamamen silinecek.
   	onun için cok tehlikelidir.
   	
	write modda acarken dosyanýzý yedekleyin ve bu yazmak için acýlacagý için sýfýrdan olusturulacagý için 
   	file position dosyanýn basýna geliyor.
   
   	"a" ile acarsak "a" append demektir.
   	Var olan bir dosyayý append moddda yani ekleme yapýlacak modda aç.
   	
   	Dosyanýn file position'u nerdeyse en sondaysa en sondadýr sonra ne kadar yazdýysam oraya kadar gelmiþimdir.
	sen dosya pozisyonunu farklý bi yere tasýsan bile dosyanýn sonuna ekliyor.Bu append mod birazcýk boyle bir kýsýtý var 
	
	
	"r+" dosyayý okumak ve yazmak için ac dosya pointer'ý yani file pointer ýndýcator'u
	baslangýcta dosyanýn basýna gelir dolayýsýyla ben bu dosyanýn basýna ne yapabilirim 
	bu file'ý yazabiliyorum bakýn a ile yazdýgýmda sona götürüyor beni
	"r+" ile actýgýmda dosyanýn basýna bir þey ekliceksem yapabilir.
	  
	"w+" yeni bir dosya olustur okumak ve yazmak için yukarýdaki sadece yazmak içindi
	eger zaten dosya var ise bu bosaltýlacaktýr.
	"+" ekleyince buna bir okuma opsiyonu da ekleniyor.
	"a+"bir dosya ac veya yeni bir tane olustur.bu su demek dosya var ise o dosyayý acar yoksa o dosyayý olusturur datayý herhangi bir yerden okuaybilirsiniz.fakat yazýcagýnýz sey ne olucak dosyanýn sonuna olucak diyo.
	  
	Bunlar C programlama dilinin dosya okuma yazma ile alakalý kullandýgý modlar.
	Tabi neler için text streamler için eger ben bunlarý binary streamler için kullanýcaksam 
	yazýcagým sey mesela r yerine rb ,w yerine wb ,ab,r+b,w+b,a+b gibi olur.
	 
	***************************************  
	|  dosya onceden olmasý gerekir:r,r+  |
	|  eski dosya sýlýnýyor:w,w+          |
	|  dosya okunabiliyor:r,r+,w+,a+      |
	|  dosya yazabiliyoruz:w,a,r+,w+,a+   |
	|  stream sadece sona yollucaksam:a,a+|
	***************************************  
	  
	 fopen bir file pointer'ý dondurcek bunun tipi "FILE" olucak bunu program içerisinde kullanýcaz. 
	 Bizim structtan ya da int pointer'dan farký var mý pek yok sadece "fp." diyince bazý þeyler gorucez o kadar 
	 ama her yerde parametre aktarýmý falan filan hepsý ayný.
	 Bu pointerýnýn pointerýný kullanmaya pek gerek yok. 
	 Hata alýrsa null dönduruyor hatadan farklý ise null dan farklý bir þey donduruyor.
	 
	 fprintf() printf'ýn hememn hemen aynýsýdýr sadece printf ile ekrana yazdýgýmýz seyi fprintf ile stream uzerinden istenilen locasyona yazdýrýyoruz.
	 
	 þimdi dosyayý actýk operasyonlarýmýza bakalým þimdi pointerýmýz da var.
	 bir karakter okumak için kullanýcagýmýz fonksiyonlar getc ve putc okumak veya yazmak için. 
	 bir satýr okumak istiyosak gets diye bir fonksiyonumuz vardý bu ne demekti stream oku demektý bunu nerden okuyodu kullanýcýdan yani comment line uzerinden klavye ile veya okumak yazmak içindi 
	 ben buna fgets,fputs dersem o zaman dosyadan okuma yapmayý saðlýcam 
	 block için fread veya fwrite bunlarýn kendilerine gore avantaj ve dezavantajlarý var eger ben bit okumam gerekiyorsa gidip burdan block okumak olmaz veya satýr okumama gerek yok karakter okumama gerek yok napýcam yaný bi karakter okuyup 7 biti silecek degilim veya bir block okucaksam iþi garantiye alýyým tek tek karakter karakter bit bit okuyam o da olmaz ve bu da performansý kotulestýrýr.bunlar dikkat etmemiz gereken seyler.
	 
	 bir diger þey butun I/O seviyelerinde bir kural streamden bir veri okuyamazsýnýz o zaman su fseek() rewind() ve fflush() fonksiyonlarýný rahatsýz etmeden kullanýcagýnýz bir yazma fonksiyonu var bunlara bakacaz 
	 fseek dedigimiz belli bir noktaya git 
	 
	 Write moddan read moda gecis program calýsýrken mumkun degil hangi modda actýysak acalým.
	 
	 bu üç fonksiyon sadece I/O fonksiyonudur,buffer'ý temizlemek için kullanýlan diger fonksiyonlar demiþ. 
	 
	 Eger memory shortage'ýnýz yoksa stream'den bir veri okursunuz onu construct edersiniz ve outputu yazmak için output stream'e gönderebilirsiniz.eger herhangi bir memory probleminiz yoksa.
	 
	 input ve output streamleri bir dosyayý gösterebilir.fakat 	dosya ile iþiniz bitti bunu kapatmak gerekiyor.tekrar yazma oncesinde.dosyayý da kapatýcaz yani en son iþimiz bitince.
	 
	 closing functionda verdiginiz dosya pointer'ýna erisimi kapatýyor.ne demek bu streami sonlandýr diye iþletim sistemine bir sinyal gönderiyor.ve buffer'ýn temizlenmesi soyleniyor.
	 
	 iþletim sistemlerininde processlere tahsis edicegi streamler sýnýrlý sayýdadýr.
	 bir de streamler karýsýrsa mevcut olan dosyanýzýn içerigi bozulabilir.onun için dosyayý kapatmak onemlidir.
	 eger programýnýz abort ederse kapanýrsa iþletim sistemlerinin çogu artýk o dosyalarýn cogunu kendisi otomatik kapatýyor.fakat bu her zaman da garanti bir þey degil.yani windows garanti kapatýyor diyoruz ama kapatmadýgý durumlarda olabiliyor.
	 
	 
	//burda bir karakter okucaz 
	//Þimdi FAIL ve SUCCESS diye 2 tane þeyimiz var.
	//Bir dosyadan alýcaz oburune kopyalýcaz iki tane file pointer'ýmýz var.
	 
	#include <stdio.h>
	#define FAIL 0 
	#define SUCCESS 1
	
	int copyfile(char * infile, char * outfile){
	FILE *fp1, *fp2;
	
	//burda diyorum ki dosyayý aç.
	//infile yerine bir isim gelicek "rb"'su modda aç yani binary modda eger null ise dosya acýlamadý hatasý. 
	if ((fp1 = fopen(infile, "rb" )) == NULL) {
	printf("Could not open the input file\n"); return FAIL; 
	}
	
	//ikinci dosyayý ac bunu da "wb" modunda aç birini okumak için birini yazmak için aç eger açamadýysam.
	//eger bu da olmadýysa dosyayý actýk.
	if ((fp2=fopen (outfile, "wb" )) == NULL) {
	printf("Could not open the output file\n"); fclose( fp1 ); return FAIL;
	}
	
	
	//yukardakilerde olmadýysa dosyayý actýk feof özel bir fonksiyondur dosyanýn sonuna geldin mi demektir.
	//hangi dosyanýn fp1 ile gösterilen dosyanýn sonuna geldin mi veya gelene kadar bu while dongusunu dondur.
	//while ve altýndaki putc olan satýr dongusu bunu dondur demek.putc ile nereye yaz fp2'ye yaz neyi yaz getc ile fp1 den aldýgmýzý.dondu dondu bir karakter aldý bunu yazdý.bu sayede napýyosunuz dosyanýn içerigini diger yere yazýyosunuz.fclose iþimiz bitti.return success dedik suralarda herhangi bir hata olmadýysa success de donduyse program tamamlanýyor.bu kodu alýp bilgisayarýnýzdaki herhangi bir dosya için deneyin mp3 dosyasý için falan 
	
	while (!feof( fp1 ))
	putc( getc(fp1), fp2 );
	fclose(fp1); fclose(fp2); return SUCCESS;
	} //to be continued with the main method

  	


getc() return value'sunu kullanamýyoruz yaný dosyanýn sonuna gelip gelmedigini kontrol etmek için binary modda eger soyle yazarsak 


int c;
while ((c = getc( fp1 )) != EOF)
putc( getc(fp1), fp2 );

  EOF ile arada baska EOF karakteri varsa o zaman exit edicektir.onun için bunu kullanmak cok makul degil.
  
  getc nýn return value'sunu kullanmak yerine yukardaký sekildekiný kullanýp bunun dosyanýn sonuna gelip gelmedigini kontrol etmek daha iyi.cunku burda binary dosyalarda EOF ile karýsacak durumlar olabilir.
  
  bu iþi kesinlikle saðlýcak seu feof() fonksiyonudur.
  
  ornegin geri kalanýna baktýgýmýzda 
  
  int main(){
char infl[100], outfl[100]; 
int result;
//birinci dosyanýn adýný girin demis 
printf("enter name of the input file\n"); scanf("%s", infl);
//ikinci dosyanýn adýný girin demis 
printf("enter name of the output file\n"); scanf("%s", outfl);

//dosyayý kopyala 
result=copyfile(infl, outfl);
if(result == SUCCESS)
printf("input file is copied to the output file \n");
if(result == FAIL)
printf("input file could not be copied to the output file \n");
return 0; 
}
//burda ne okuduk þimdi bir kopya operasyonunda karakter okuduk 

bu iþi streamle yapan getc veya putc diye makro olarak kullanan iki tane de özel þey var
bir de fgetc functýon'dýr.
fputc digerfunctýon'dýr.bunlarýn farký bu ayný iþlemleri yapýyor.

putc ve getc zaten makrolar implement edildigi için bunlarýn daha hýzlý calýstýgý soyleniyor.söyle demis fgetc ve fputc 'nin 2 katý hýzlýdýr.fakat bunlar makro oldugu için bazý side effect'lere yatkýndýr.örneðin ben putc içerisine bi macro cagýrdýgýmda gönderilen argumana parametreler karýsabiliyor.

o yuzden putc ve getc kullanýrken dikkat edin 

eger bu argumanýnýz yanlýs argumanlar içerirse bunun yerine fonksiyon kullanmak daha garantidir.

þimdi macro tanýmladýk mesela soyle 
#define SQR(x) x*x
ben bunu asagýda cagýrýrken soye cagýrýrsam 
SQR(x) dogru sonucu alýrým 
fakat soyle cagýrýsam 
SQR(4+3) 
mesela burda 7 nin karesini almýyor.
soyle yapýyor bu iþlemi
4+3*4+3 soyle yapýyo sonuc da 19 cýkýyor.sonuc boyle sýkýntýlý geliyor.bu da kullanýcý tarafýndan delinebiliyor.onun için dikkat etmek gerekiyor.


//diger copy operation'u 


#include <stdio.h>
//#include <stddef.h> 
#define FAIL 0 
#define SUCCESS 1
#define LINESIZE 100
int copyfile(char * infile, char * outfile){
FILE *fp1, *fp2; char line[LINESIZE];
if ((fp1 = fopen(infile, "r" )) == NULL) {
printf("Could not open the input file\n"); return FAIL; 
}
if ((fp2=fopen (outfile, "w" )) == NULL) {
printf("Could not open the output file\n"); fclose( fp1 ); return FAIL;
}
//bir gets alýyo burdaki bir line kadar line Size'ýmýz su kadarmýs,file pointer'ýný alýcak bu get strýngý line 'ýn içerisine kopyalýcak line da bir eleman,bir karakter dizisi,bu kadarlýk bir eleman oku ve okudugun sey null dan farklý ise devam et okudugun seyý de al diger dosyaya kopyala geri kalaný main methodu ile ayný biraz önce ne okumustuk tek bir byte okumustum bakýn burda aslýnda biz string okuyoruz tam bir blok degil kucuk bir blok ama bloktan kastýmýz structý dusunun struct'ýn sýze'ý kadar veri okumaktan bahsediyoruz. 
//line dan kastýmýz burda bir string karakter dizisi olarak ne oluyor bir karakter dizisi bilgisi okunuyor.fgets okumak için yazmak için ise fputs
//line ýn yanýndaki ne kadarlýk bir dosyadan okucagýmýz ve hangi dosyadan okucagýmýz 



while (fgets ( line, LINESIZE-1, fp1 ) != NULL)
fputs( line, fp2 ); 
fclose(fp1); fclose(fp2); return SUCCESS;
} //the main method will be the same as the previous example




line I/O:
char *fgets( char *s, int n, FILE stream );

s pointer okuyacagýmýz seyi bellekte nereye yazýcaz onun baslangýc elemaný ,N kac tane karakter okunacagý streamden ve bu da hangi dosyayý okuyacagýmýzý soyleyen þey.þimdi bunu okuyunca neden kod içinde LINE-1 dediniz soyledýr burda mesela normalde 100 tane bunu okuyunca bunun sonuna otomatýk olarak \0 ekleniyor onun için 100 tane okuyacaksan 99'unu oku 100.su o olsun bunun oyle bir ozelligi var.
null karakter dedigimiz sey \0 yani 

dolayýsýyla burdaki n parametresi s'nin size'ýndan 1 eksik oluyor.

eger dosyanýn sonuna ulastýysak NULL dondurecek yoksa dondurecegi seyý fgets'ýn dondurecegi seyi okudugumuz string'in first argumanýný yani string okuyosak s'yi dondurecek bize 

fputs'de
fputs(char *s, FILE stream) 
bunun tam simetrigi diyebiliriz.napýyo bu karakter dizisini bu file stringini okuyo burda boyut verilmiyo dikkat edin 

gets nedir gets de gets stdin ile karakter okur bir fonksiyondur.ama bunu nerden okuyor dosyadan degil otomatik olarak bizim comment line dan okuyor.okudugu zaman sonuna \0 ekliyor.iki fonksiyonda sonuna null karakter ekliyor.bu fgets sonlandýran newline karakterini include eder yani kendi içinde ayrýca vardýr diyor.

bu fgets'in içinde bir specification yapmamýz mumkun fakat gets'in içerisinde napýyo gets dogrudan newline veya EOF'yi gorene kadar kendisi okuyor.

iþte isim girince mesela ahmet girdik ali girdik su aradaki boslugu gorup onun çözüm yontemlerinden bir tanesi bunu kullanmak 

block I/O da 
bir data turunu ozellikle structlarda cok kullanýlýyor.block seklinde okumaktýr.veya block seklinde yazmaktýr.bunun için kullandýgýmýz fread() ve fwrite() burda bir pointer void pointer neden bir void pointer bu ,void pointer'ý ne için kullanýyoduk generic bir durum var burda okuyacagýmýz blok karakter de olabilir integer dizisi de olabilri ondan sonra bir struct'ýr dizisi de olabilir veya bir struct'ýr elemaný da olabilir bunun için oyle pointer .diyoruz ki su kadarlik size da bir veri oku bir defa oku 2 defa oku nerden oku file struct'ýrýndan oku FÝLE pointer'ýndan oku 
size_t dedigimiz sey integer olucak genellikle biz buralarda sizeof'u cok kullanýrýýz.mesela sizeof benim struct'ýrým kadar oku meslea sizeof employee kadar oku veya sizeof integer kadar oku 
ptr dedigimiz onu okuduktan sonra onu nereye yazýcagýmýz 
su dedigimiz sey de kac defa okunacak bu elemanlar onu soyluyoruz 
fread kac defa eleman okundugunu donduruyor.bu aslýnda 3.argumanla ayný eger herhangi bir hata olmazsa EOF' e gelmek ile alakallý kac defa okundugunu dondurur.fwrite da onun tam mirror dedigimiz simetrigidir.hemen hemen ayný argumanlarý alýyor.
bu pointerdan su kadar size kadar veriyi al bir defaya mahsus olmak üzere suraya yaz 2 defa yazarsam pes pese 2 veriyi almýs olucam 
block size larý fread ve fwrite için I/O operasyonlarýnýn sayýsýný etkilemiyo ornek olarka buffer size'ýmýz 1024 byte ise ve block size 'ýmýz bir read operasyonunda 512 byte ise operatýn system bize 1024 byte getirecek ve bunu bellekte store edicek fakat ilk 512 byte fread tarafýndan okunacaktýr.
býr sonraki fread'de bu guzel bir þey normalde buffer 1024 getirdi duruyo sen fread yaptýn farklý bir veri görüyosun o þu demek fread'ýn okudugu veri tamamlanmamýs yani buffer da belli bir kýsým duruyor.2 seferde gelicek bu birazcýk sýkýntýlý bu kontrol edilmesi gereken bir þey 


• size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream); 
• void fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);

bir binary modda blok okuma ornegý 
block size'ýmýzý 512 vermiþiz 
onun asagýsýnda bir karakter data þeyi var 

#include <stdio.h>
#include <stddef.h> 
#define FAIL 0 
#define SUCCESS 1
#define BLOCKSIZE 512
typedef char DATA;
//continued in the next slide


//yine ayný örnek dosyayý açýyoruz veya açamýyoruz 


int copyfile(char * infile, char * outfile){
FILE *fp1, *fp2; int num_read; char block[BLOCKSIZE];
if ((fp1 = fopen( infile, "rb" )) == NULL){
printf( "Error opening file %s for input.\n", infile ); return FAIL;
}
if ((fp2 = fopen( outfile, "wb" )) == NULL){
printf( "Error opening file %s for output.\n", outfile );
fclose(fp1); return FAIL;
}

//bloack oku sizeof(DATA) kadar sizeof(DATA) dedigimiz bir karakter kadar ve bu block size'ý 512 demis sizeof(DATA) 1 byte degil mi 512 defa 1 byte oku demektir.file pointer'da ve bu okudugumuz seyý blogu.bu blogu al sizeof(DATA) kadarki þeyi yine num_read kadar file pointer'a yaz sonra en son okunan kýsmý tekrar yazmak için soyle bir seye ihtiyac duyuyoruz ondan sonra dosyalar kapanýyor.
//sonra herhangi bir hata olduysa FAIL yoksa SUCCESS diye dondur.bunlar daha cok sýralý erisim ile alakalýydý 
while ((num_read = fread( block, sizeof(DATA), BLOCKSIZE, fp1 )) == BLOCKSIZE)
fwrite( block, sizeof(DATA), num_read, fp2 );
fwrite( block, sizeof(DATA), num_read, fp2 ); //notice this line!
fclose(fp1); fclose(fp2);
if (ferror(fp1)) { printf( "Error reading file %s\n", infile ); return FAIL; }
return SUCCESS;
} //the main method will be the same as the previous example





	RANDOM ACCESS:
	burda da genelde 3 tane fonksiyon var:
	-fseek 
	-ftell    

	fseek bizi istedigimiiz yere göturuyor.
	
	ftell ise bulundugumuz yerin pozisyon bilgisini veriyor.
	
	Bu sayede random access'i saglamýs oluyoruz.
	
	fseek in içerisinde dedik ki pointer tasýnacak burdaki gibi FILE stream'ýn pointer'ýný veriyoruz
	offset bilgisini veriyoruz ve whence dedigimiz seyi veriyoruz.

	bunlar ne bulundugumuz yerden ornegin diyoruz ki itibaren bir onceki noktaya git veya bir sonraki noktaya git. 

	int fseek( FILE *stream, long int offset, int whence);

	Bulundugun yeri de long int offset gösterir.
	file stream içerisinden bulundugun yerden offsete +1 dersek bir sonrakine gider -1 dersem bir oncekine gider bir karakter açýsýndan 

	whence dedigimiz sey de startýng position dosyanýn pozisyon elemanýný dosyanýn basýna gönder dosyanýn basýna gönderince  dosyanýn basýndan itibaren basýndakinden bir sonrakine gec 

	current position dersek nerdeysem onun bir oncesine bir sonrasina git end-of-file'a da gittiginde dosyanýn sonundan itibaren bir gezinti yap


	stat = fseek(fp, 10, SEEK_SET);

	mesela  yukarýdaki dosyanýn basýndan itibaren 10 tane sonraya gönderiyor.
	bu ne olabilir okunacak veya yazýlacak bir karakter olabilir.
	bulundugun yerdesin bundan 10 tane ileriye git oraya ulas. 

	streamler 0.pozisyon ile baslýyor.bu 10.karakter gercekte 11.karakterin yerine geliyor.

	fseek den donen deger 0 ise bizim istegimiz yerine getirilmis.
	0'dan farklý bir þey ise bir hata olusmus demektir.
	Bu çeþitli sebeplerden oluyomus örnegýn ben set'teyken buraya bir eksi bir þey yazarsam nolur.bunun eksisi yok ki bu bir sýkýntýdýr veya and'deyken 1 yazarsam bi sonrakisi yoktur.

	bu seek_end genellikle read-only file'larda kullanýlýr.
	offset degeri de iþte 0 dan kucuk veya 0'a esit olmalý.
	seek_set'de ayný sekilde 0 dan buyuk veya esit olmalý.
	bu file pozisyonunu dikkat edin indicator'u dosyanýn sonuna eklememeye dikkat etmek gerekiyor.

	ftell de bir parametresiz fonksiyon bize dosyada kaldýgýmýz yeri soyluyor.genellikle biz bunu surdaki sey yerine de kullanabiliyoruz.current pozisyon dedik ya current yerine ftell dersek bulundugun yeri getir demektir.

	binary streamlerde bastan itibaren kacýncý karakterde oldugumuzun bilgisini return eder.text streamlerde ise bu implementasyona baglý olarak nerede kaldýgýný nerede oldugunu soyleyen bir fonksiyon cagýrýsýdýr.

	personalstat struct'ýrýmýz varmýs 
	veriler random bir þekilde duzenlenmýs bunu diyoruz ki isimlerine göre sýralýyalým yaný struct'ýrýn içerisinde isimlerine göre sýrala ve bunlarda dosyada saklanýyor.

	dynamýc memory allocation + file operation + pointer +function bunlarýn hepsinin bir arada oldugu ornekler geliyor.

	bunu sýralamak istiyoruz bunu sýralamak için dosya içerisinde sýralamak cok zor bir þey
	onu önce bellege alýcaksýn bellekte sýralayýp dosyaya geri yazýcaksýn.



	oncelikle demis ki data'mýz su sekilde olucak bizim datanýn formatýnýn boyle oldugunu soylemýs bunlara bir index verdigimizi dusunelim.struct içerisinde okuduk structta indexlerimiz var sýraladýktan sonra bunlarý isme göre sýraladýktan sonra su sekilde dosya da görülmesini isticez tabi diger bilgilerde saklanýcak sekilde diger bilgiler nasýl saklanýcak þimdi biz structlarda sýralama yaptýk sýraladýgýmýz structý buraya oldugu gibi blok seklinde yazarsak nolur dosyanýn içerisinde sýralanmýs görürüz.

	bunun için ilk once struct'ý tanýmlamamýz gerekiyor.bu aslýnda butun yazýlým projelerinde yapýlan sey oncelikle data base iliskisel semasý sýralanýr.biz burda basýt bir database'i file larla olusturucaz.ve bu database ne tarafta HDD tarafýndan bize ne lazým ram uzerýnde calýsacak 


2.56.40










