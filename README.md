###Serveris
 
#####Uzdevuma formulējums
 
Aiz trejdeviņiem kalniem un trejdeviņām jūrām bija valstiņa, kas līdz šim ļoti labi bija iztikusi bez datoriem. Taču vienā jaukā dienā viņi no kāda Bila saņēma sūtījumu ar datoriem, kuru skaits nepārsniedza 20000. Atsūtīja arī speciālistu vārdā Nets, kura uzdevums bija izveidot datortīklu starp visiem datoriem. Tā kā bija solīts katram datoram dot līdzi bezmaksas Vistu, valsts iedzīvotāji piekrita datortīkla izveidei. Kāpēc nepiekrist, ja sliktākajā gadījumā taču varēs apēst pa brīvu iedoto putnu, kaut arī baumo, ka Vista jau ir veca?
Nets uzreiz ķērās pie darba. Tomēr pēc brīža darbi apstājās, jo viņš konstatēja, ka tīkla vadu tā kā pamaz ir iedots. Izeja tika atrasta, savienojot datorus tā, lai no katra datora var pa tīklu sasniegt jebkuru citu, nepieciešamības gadījumā citus datorus izmantojot kā starpniekus. Diemžēl tīkla vadu trūkuma dēļ tīklu veidoja ļoti taupīgi - no katra datora uz jebkuru citu datoru eksistēja tikai viens ceļš.
Uz katra datora tika uzlikta programmatūra, kas 1 milisekundi pēc datu  saņemšanas no kāda datora nosūtīja šos datus visiem citiem pa tiešo pieslēgtajiem datoriem. Katrs dators-saņēmējs pats novērtēja, vai atsūtītie dati attiecas uz viņu.
Atlika tikai atrisināt problēmu - kuru datoru nokonfigurēt kā serveri, lai servera sūtītie dati visus datorus sasniegtu minimālā laikā. Nets pēc vadu (nevis gumijas) stiepšanas jutās tik noguris, ka vairs nespēja tikt galā ar šo uzdevumu. Palīdziet Netam noskaidrot, kuru datoru var izvēlēties kā serveri un cik milisekundēs visi datori būs saņēmuši servera ziņojumu.
Ja datoru skaits ir n [1..20000], tad katram datoram ir piešķirts unikāls numurs no 1 līdz n. Ieejas dati vienmēr ir korekti saskaņā ar specifikāciju.
 
#####Failu vārdi
 
serveris.c vai serveris.cpp, vai serveris.pas - programmas tekstam
serveris.in - ieejas dati
serveris.out - izpildes rezultāts
 
#####Ieeja:
Pirmā rindiņa satur atsūtīto datoru skaitu.
Nākošajās rindās ir doti visi tiešie savienojumi starp datoriem. Katrā rindā ir tieši divi skaitļi, kas nosaka tieši savienotos datorus.
Pēdējā rinda, kas signalizē par ieejas datu beigām, satur divus skaitļus 0.
 
#####Izeja:
Pirmā rinda satur minimālo garantēto laiku, kurā servera ziņojumu var saņemt visi tīkla datori.
Otrā rinda satur visus datoru numurus, kuri var kalpot par serveri. Datoru numurus uzrādīt pieaugošā secībā.
 
#####Piemērs:
Ieejas faila serveris.in saturs:
``` 
5
5 4
1 2
4 3
1 4
0 0
 ```
Izejas faila serveris.out saturs:
 ```
2
1 4
```
