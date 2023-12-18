Proje olusturmak özellikle C'de cok zor bir þey degil ama bunu yaparken projenizi modullerden meydana getirmeniz gerekir.

Bir projeniz birden fazla C dosyasý ve bunlarla alakalý birden fazla header dosyasýndan olusabilir.


Bunun yonetilmesi ile alakalý konusalým:
Burda bazý kavramlar var mesela "prepprocessor" dedigimiz ve bazý "macro definetionlarýný" ve bazý "sabitlerin" tanýmlandýgý bolum. 

Bu prepprocessor sayesinde biz C dosyalarýnda bazý iþlemleri macro olarak sýralayýp iþleri kýsaltabiliyoruz.

Compiler herhangi bir C kodunu ""assembly"" koduna donusturuyor.

Assembler olusturulmus assembly kodunu makine koduna donusturuyor.

Yani C kodunu derledigimiz zaman bazý kodlar makine koduna çevrilir bazý kodlar çevrilmez 
özellikle daha onceden derlenmis olan kodlar. 

Tekrar derlenmez burda assemblerlar derlenmis olan kodlarýn baglanmasýný saglarlar. 

Linker da bu derlenmis olan kodlarý getirip bizim programýmýza baglýyo ve sonunda "executable" dosya haline getiriliyor.

Demek burada biz bir kod yazsak printf scanf gibi onu derlesek bir yerde saklasak programý sýfýrdan olustururken derlerken 
tekrar onu derlemeye gerek yok eger bir degisiklik yapmadýysak boyle bir iyi bir tarafý da var 


Program niye split edilir parcalanýr :
Daha kolay yonetmek için tekrar kullanýlabilirliði arttýrmak için örnegýn bu onceden cok yapýlýyodu

kendi "data struct'ýrýnýzý" olusturabiliyorsunuz.

özellikle "header file'larý" biz fonksiyonlarýn prototiplerini saklamak için data struct'ýrýn definitionu için struct'ýrlarýn 
definitionu "typedef" ile oluyodu macro definitionlarýný saklamak için gloabal datalarý saklamak için kullanyoruz 
header file ile data.h uzantýlý stdio gibi standart input output dosyasý gibi 


bu programýmýzdakilerden bi tanesi de main fonksiyonunu bulunduran dosyamýz oluyor.
ve bu ilgili dosyalarý include ile ekliyorduk bu ilgili header dosyasý ve C dosyasýnýn birbiri ile ayný isimde olmasý gerekir.


Ýnclude komutunun 2 tane formu var: 

"make file" kendisine verilen parametrelerle bi defa derlenmisse ve degistirilmemisse o dosyayý tekrar derlemeye gerek duymuyor.
ornegin sizin projeniz su headerlardan ve C dosyalarýndan olussun 


Dependency'si nasýl calýsýr:
Siz programýnýzý test ederken içerisinde bir bug tespit ettiniz su io nun gittiniz naptýnýz 
bunu edit yaptýnýz edit yaptýktan sonra bu edit yaptýgýnýz kýsýmdan etkilenen nolucak bunlar etkilenecek 
bunlardan da projenin geneli etkilenencek ve projenin tamamýnýn guncellenmesine ihtiyac duyucaz bu buyuk bir problem 
ve boyle bir dependecy durumu ortaya çýkýyor.

Örnegýn data.c de yapýlan bir degisiklik data.h da yapýlan degisiklik bunlarý etkiliyor.
Ondan sonra mainde yapýlan kimleri etkiliyor.
Problemli bir þey iþte bundan kacýnmak için "make file" kullanýlýyor.

Þu mesela ornek bir make file'dir.
proje dedigimiz sey neleri olusturacak.
Burdaki bagýmlýlýk durumuna göre yazýyoruz proje dedigimiz sey data.obje dosyasý.
main.obje dosyasý io.obje dosayasýndan olusacak gcc derleyicisine dicez ki data.o yu main.o yu io.o yu al bunlarý bir araya getir.
proje1 executable file'ýný olustur dýyoruz.

bu data.o'nun da nasýl olusacagýný da surada tanýmlýyoruz.

data.o,data.c ve data.h'ýn gcc derleyicisinden data.c'nin derleyicisiyle elde edilecek bir dosyadýr.
main.o için ayný þey ve io.o için ayný sey  

Biz artýk kodu derlerken sürekli bunu yazmýcaz napýcaz sadece bu "make file'ýn" kendisini cagýrýcaz. 	

"make komutu" ile bu yazdýgýmýz "makeFile'ýn" adýný cagýrýcaz.

Bizim "dev.c" veya farklý ideler de ayný þeyi yapýyolar 

ve burda genellikle "Makefile" ismi kullanýlýr boyle bir gelenekselleþmiþ bir durum vardýr.

Çok uzun dosyalarda bu makefile bi kere yazýlýr ve derlemede kullanýlýr. 

Özellikle "eski iþletim sistemlerinde" ve "gömülü sistemlerde" bu hala kullanýlýyor.

Bu "makefile" içerisinde "macro" tanýmlanabiliyor.

Bu da makeFile'ýn programlanmasý ile alakalý.

Diyoruz ki þöyle bir obje diye bir degiskenimiz var.
Bu obje'yý macro gibi dusunucez.
Nerede obje görürsek bu objenin karsýsýna proje su alanlardan olusacak sonra bu alanlar birleþicek projenin dosyasýný olusturacak.

Bu nerede karsýnýza gelir gömülü sistemlerde karsýmýza gelir.

Her þeyiyle kendi yazdýgýn bir program olucaksa burda bu onemli.

C prepprocessleri program calýsmadan once kodlanmýs bolumler.

Biz burda genellikle "#define" ve "#include'u" kullandýk

Fakat bunun extra komutlarý var.

Bunlarýn bir kýsmýný gorduk bazýlarýný gormedik.

Macro dedigimiz sey fonksiyon benzeri bir yapýydý fonksiyondan farký: 
Fonksiyon cagrýsý geldiginde biz fonksiyonun bulundugu yere jump yapýyoduk.

Assemblydeki karsýlýgýnda boyle gidiyoduk.
Ýste burda bazý bilgiler nerde saklanýcak "stack bolgesinde" saklanýyordu.
Özellikle "program counter flag register" o anki bulundugumuz programýn degiskenlerinin degerleri bunlar stack' e atýlýyor.
Bunun belli avantajlarý oldugu gibi bu stack'e atma iþi birazcýk dezavantaj 
cunku surekli bir fonksiyon cagrýsý yapmak sürekli dallanma yapmak demektir.
O stack'e kopyalama sureci ve tekrar geri donme sureci birazcýk uzayabiliyor.

C de makro yazarken normal "noktalý virgul kullanmadan" birden fazla satýrda makro yazýlabiliyor.
Eger bir makronuz devam edicekse sonuna bir " \ " ekleyip buna devam ettirebiliyorsunuz.
Burda bir string üzerinde bir iþlem yapýlmýs atama iþlemi 
boyle birden fazla satýrý kapsayan bir sey olusturulmus ve sonuna noktalý výrgul koymuyoruz.

Bir atama yaparken eþittir de koymuyoruz ve bu bir "substitution'dur".
Bu genelde soyle ozetlenir nasýl bir fonksiyon cagrýldýgýnda fonksiyon cagrýldýgý yere gidiyorsak macro ifadesi yazýldýgýnda 
yani çaðýrým yapýldýgýnda "call" iþlemi yani biz ona gitmiyoruz o bizim istedigimiz yere geliyor.

yani nerde biz 
#define BUFF_LEN 512 
diye bir þey kullansak onun yerine bu kopyalanýyor.

Aslýnda bir genisletmedir.

Program derlendiginde programýmýzýn yazýlmýs hali ile derlenmis hali arasýnda cok ciddi fark bulunur. 

Nerede dosya açma ile alakalý bir iþlem yapsanýz bu yer degistirecek "substitution" yapýcaktýr.

O nedenle bazen dezavantajlar da oluyor.

Özellikle biz kendi programýmýzda bazý isimlendirmeler veya bazý kýsaltmalar da bunu cok yapýyoruz iþte BUFFER_SIZE 'ýmýz 256 olsun.
Bunu fonksiyon benzeri bir macro haline getirmek için de macro'nun adýný verdikten sonra da alýnacak argumanlarý parantez ile 
normal bir fonksiyon gibi alýyoruz. 

Karsýna da bir bosluk býrakýp macro'nun gövdesini yazýyoruz.
burada cok fazla yapýlan hata iþin sonunda noktalý výrgul koymak birinci hatamýz 
ikinci hatamýz macro definition da eþittir kullanmak.
iþte bu bi þekilde cozulebilir.

üçüncü hatamýz "side effect" dedigimiz hatamýz genel parametreleri guvenlý bir þekilde almak için  
su parantezi macronun govdesinde her bir degiskeni kendi içinde ayrý bir degiskene almak için kullanmamýz gerekiyor.nedeni açýklanacak 

#define MUL_BY_TWO(a) ((a)+(a))



ornegin sayýyý 2'ye katlayan bir þey yapýlmýs bunu cagýrýmý kod içinde boyle olucaktýr.
bu kod içinde boyle olucaktýr ne demek substitution biz buraya gitmicez 

j=MUL_BY_TWO(5);
f=MUL_BY_TWP(2.5);


iki sayýnýn hangisinin buyuk oldugunu bulan bir program macro definition hangisinin 
kucuk oldugunu burda dikkat edin gelen parametreler 

#define min(a,b) ((a)<(b)?(a):(b))

eger ben macro'yu su sekilde cagýrsam a'nýn degeri de 3 gibi bir þey olsun macro cagýrýlmasý demek oraya 3 -1 =2 gidicek demek degil.
soyle gidiyor 3-1   +  3-1 gidiyor eger ben burda toplama örnegini yaparsak bunun bi etkisini gormeyiz.burda hepsi eþit oncelikli 
operatorler oldugu için bir problem olmýcak ama arada bir carpi olsaydý
o zaman nolurdu 3-1 * 3-1 mesela burda sonuc -1 kalýcaktý iþte boyle bir side effect'i onlemek için gelen 
parametrelerin parantez içinde gönderilmesi gerekiyor.


j=MUL_BY_TWO(a-1);


side effect dedigimiz sey su 

#define min(a,b)  ((a)<(b)?(a):(b))

//ben yukarýdaki macroyu asagýdaki gibi cagýrdýgýmda nolucak iþte su x++'ýn once 
//tamamlanmasý bizim için oncelikli ise a ve b nýn parametrelerine parantez ekliyoruz 
z=min(x++,y);

z=((x++)<(y)?(x++):(y));


AVANTAJ: 

Macro genel olarak fonksiyondan daha hýzlýdýr.
Çunku fonksyion cagýrýmý ile alakalý sýkýntýdan bizi kurtarýyor.

herhangi bir tip kýsýtlamasý yoktur.
argumanlar uzerinde yani integer için float için karakter için veya struct için bunu kullanabiliyorsunuz 
normalde generic bir fonksiyon butun veri tipleri için yapmak pek mumkun olmuyor.
Fakat bunu macrolarla daha kolay yapabilme imkaný var iþte bir þey print ediceksiniz.
Kendisine gönderilen parametreyi void pointer mantýgýyla yapabilmeyi macrolarla yapabilmek biraz daha mumkun hale gelebiliyor.


Dezavantajlarýna baktýgýmýzda fonksiyon bi defa derlenir program calýsmadan once siz derlenmýs kodu cagýrýrsýnýz dolayýsýyla herhangi bir extension gerceklesmez ama macrolarda her macro govdesini cagýrmasý tekrar bir kopyala yapýstýr gibi bir durum oluyor kod içerisinde eger argumanlarýnýz bir side effect içerecek sekilde tasarlanýrsa bazý problemlere neden oluyor.macrolardaki expanded bazen problem olabilen bir durum normalde fonksiyonlarda bir expanded yok.
macrolar arguman tiplerini kontrol etmiyolar sadece argumanlarýn saysýný kontrol ediyolar sizin gonderdiginiz argumanlarýn dogrulugu sizin sorumlulugunuzda C'nin genelinde oldugu gibi.
bu macrolar üzerinde dogrudan debug yapmak ozellikle step-by-step calýstýrmak zor bir þey cunku dogrudan calýsýr herhangi bir þekilde alt adýmlarý analýz etmek mumkun degil.onun için bu da bir dezavantaj'dýr.


genel yapýlan hatalar 
//bu cok yapýlýyor.buna dikkat edelim bu calýsýr mý calýsýr nasýl calýsýr 
#define MAX = 100


for(j=MAX;j>0;j--)

for(j==100;j>0;j--)

bunu yaparsak calýsýr mesela



macro definition'u remove etmek de mumkun define ettiginiz bir þeyi eger uzerinde bir degisiklik yapýcaksanýz 
oncelikle "undefine" edip sonrasýnda "redefine" edebiliyorsunuz.

undefine etmek için yapýcagýnýz sey su:
#undef min
Bu yukardaki definition'u iptal eder.sonra kendiniz define edebilirsiniz.


built-in-macro

Hangi satýrdayýz hangi dosyadayýz saat kac tarih kac sonra standart ancý standartýný saglayýp saðlamadýgýný söyluyor.
Bunlar rutýn macrolardýr.

Derleme yaparken conditional compilation da mumkun belli sarta gore derle define edildiyse ona gore derle define edilmediyse once define et oyle derle gibi bazý opsiyonlar var.

#if #elif #else #endif

Yukarýdakilerde herhangi bir þekilde parantez kullanmaya gerek yok 

ornegin bir debug modunda debug yaparken eger debug tanýmlýysa surdaki islemleri yap gibi opsiyonla bunu yapabilirsiniz.bunun derlenmesiyle alakalý bilgi alýrken 



bitwise iþlemler hem gomulu sistemlerde hem de uygulamalarýmýzda karsýlastýgýmýz bir operatorlerden olusan genellikle bir iþlemler kumesi lojik de kullandýgýmýz bir cok operasyonu burda kullanabiliyoruz.mesela and or not xor bir de rotate iþlemleri ^ bu iþaret ust degildir.
sayýlar uzerinde genellikle napýyoruz iþte bitwise iþlemleri lojikteki iþlemlerin sonuclarýný görmeye calýsýyoruz burda 


1.00-1.22


