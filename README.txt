Gavriliu Andrei,313 CB

Initializam matricea cu punct pentru toate pozitiile
Citim numarul tasku-ului sub forma de caracter,pe car il vom transforma in intreg folosind functia atoi
Folosind functia switch apelam task-ul dorit

Task 0-Tiparim matricea deja initializata

Task 1-Citim datele de intrare;prelucrarea lor se face folosind functia atoi care transforma un caracter intr-un intreg si functia strtok care "sparge" un sir in mai multe siruri
      -Citim numarul de linii(N)
      -Citim datele de intrare linie cu linie;din fiecare linie vom extrage datele cerute adica numarul liniei(y),numarul coloanei(x),directia(d) si cuvantul(word)
      -In funcite de valoarea lui d(0 sau 1) vom aseza cuvantul in matrice,fie pe verticala(d=1),fie pe oirzontala(d=0)
      -Tiparim matricea

Task 2-Citim si prelucram datele de intrare
      -Initializam vectorul punctaj in care avem punctajul corespunzator pentru fiecare litera (contine 26 de pozitii)
      -Pentru liniile pare calculam scorul primului jucator;incepem sa parcurgem primul cuvant al jucatorului;calculam pozitia in vectorul punctaj a fiecarei litere din cuvant(indice);calculam scorul pentru cuvant(scor1)
      -Analog pentru jucatorul 2
      -Calculam scorurile pentru cei doi jucatori(s1 si s2) prin insumarea scorurilor pentru fiecare cuvant

Task 3-Citim si prelucram datele de intrare,doar ca de data aceasta vom introduce doua noi subsiruri XX si YY - utilizate pentru calculul bonusurilor pe cuvant
      -Calculam punctajul pentru fiecare cuvant si il stocam in variabila valword
      -Verificam daca subsirurile XX si YY apar in cuvant;daca gasim cel putin unul, vom incepe sa calculam punctajul bonus (se merge in matricea de bonusuri si se verifica daca, incepand cu coordonatele Xi si Yi, pe lungimea cuvantului (strlen) 
si pe directia corespunzatoare ( orizontala sau verticala) intalnim casute cu valori 1 sau 2; daca gasim 1 vom inmulti valoarea(punctajul) cuvantului cu 2;daca gasim un 2 si subsirul yy se afla la sfarsitul cuvantului vom inmulti valoarea cuvantului cu 3
      -Calculam punctajul pentru fiecare jucator - inmultim valword(punctaj) cu bonusul calculat pentru a vedea de cate ori se multiplica scorul (bonus initial=1)
      -Afisam cele 2 scoruri cu bonus

Task 4-Citim si prelucram datele de intrare(format identic cu Task 3)
      -Introducem cuvintele citite in matrice
      -Copiem cuvintele citite intr-un sir nou w pentru a-l folosi la verificarea cuvintelor noi din matricea words
      -Parcurgem fiecare cuvant din words si il comparam cu cele din w(cuvinte citite);cautam primul cuvant care nu e in lista w; cand il gasim, extragem prima litera din el si incercam sa il asezam pe tabla de joc; cautam litera in matricea game_board (cu cuvintele citite) pozitie cu pozitie;
pentru fiecare pozitie gasita, verificam daca exista spatiu liber la dreapta sau in jos, pe dimensiunea cuvantului si daca conditia este indeplinita, il asezam in matrice, gasit=1 si nu mai cautam alte cuvinte
      -Daca nu putem aseza cuvantul pe tabla de joc (au fost verificate toate pozitiile posibile din game_board), trecem la cuvantul urmator din words si tot asa pana parcurgem cele 100 de variante.
      -Tiparim matricea cu cuvantul gasit

Task 5-Citim si prelucram datele de intrare(format identic cu Task 3)
      -Copiem cuvintele citite intr-un sir nou w (similar ca in task 4)
      -Calculam punctajul cu bonus pentru fiecare jucator
      -Punem cuvintele citite in matrice
      -Initializam max(valoarea maxima) cu scorul jucatorului 2(s2)
      -Parcurgem fiecare cuvant din words si ii verificam validitatea(sa nu fie deja jucat,sa incapa pe tabla);daca il putem juca ii calculam punctajul bonus(s2_nou);daca (s2+s2_nou)>max vom face o interschimbare,pastram cuvantul gasit(cuv_final) coordonatele sale(i_nou,j_nou) si directia(dir)
      -Vom cauta cel mai avantajos cuvant astfel,cel care ii da jucatorului 2 cel mai mare scor
      -Daca cel max va fi egal cu (s2+s2_nou) vom alege cuvantul cu cea mai mica linie,apoi cea mai mica coloana(in caz de linii egale)
      -Stiind directia(dir) si coordonatele vom aseza cuvantul cautat in matrice
      -Daca gasim cuvantul vom afisa matricea, daca niciun cuvant nu ne da un scor mai mare decat jucatorul 1 vom afisa mesajul "Fail!"
