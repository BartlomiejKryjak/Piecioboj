# Piecioboj

Projekt symuluje pięciobój nowoczesny składający się z szermierki, pływania, jazdy konnej i biegu przełajowego połączonego ze strzelaniem. Zwycięża zawodnik, który zdobędzie największą liczbę punktów.

Na początku tworzonych jest 32 zawodników. Każdemu zawodnikowi są losowane statystyki (szermierka, pływanie, jazda konna, bieganie, strzelanie), losowana jest także jego najlepsza statystyka - zwiększana o losową liczbę punktów. Dodatkowo zawodnikowi przydzielana jest szansa na kontuzję - początkowo 1%. 

Zawodnicy przechodzą do treningów. Każdy zawodnik ma losowaną liczbę treningów (0-9), każdy trening zwiększa losową statystykę o 2 punkty i zmniejsza szansę na kontuzję o 0.1 punktu procentowego. Podczas treningu jest możliwa kontuzja, jednak szansa na nią jest dziesięciokrotnie mniejsza niż podczas zawodów.

Po treningach zawodnicy zaczynają ze sobą rywalizować. Pierwszą konkurencją jest szermierka - zawodnicy walczą w systemie "każdy z każdym" przez minutę lub do pierwszego trafienia. Jeżeli w wyznaczonym czasie żaden z zawodników nie trafi swojego przeciwnika, walka kończy się remisem. Zawodnik ma 70% szans na atak, którego powodzenie zależy od umiejętności atakującego. Każdy atak wiąże się z ryzykiem kontuzji. Jeżeli któryś z zawodników zostanie kontuzjowany - pojedynek jest przerywany, a zwycięzcą jest zdrowy gracz. Na koniec przyznawane są punkty za konkurencję - 1000 punktów dla gracza, który wygrał 75% pojedynków, odpowiednio mniej (więcej) punktów za mniej (więcej) zwycięstw. 

Drugą konkurencją jest pływanie - ponieważ liczy się tylko czas osiągany przez zawodnika, jego umiejętności są bezpośrednio przeliczane na zdobyte punkty. Możliwe jest, że zawodnik nie ukończy konkurencji z powodu kontuzji.

Następną dyscypliną jest jazda konna. Zawodnik musi pokonać 12 pojedynczych przeszkód, w tym jedną podwójną i jedną potrójną. Przy pokonywaniu każdej z nich możliwe jest niepowodzenie (zależne od umiejętności zawodnika) - upadek z konia (który może zakończyć się kontuzją zawodnika), odmowa skoku przez konia lub zwyczajna zrzutka. Każda zrzutka to 20 karnych punktów, odmowa skoku - 40, a upadek - 60 punktów. Dodatkowo punkty są odejmowane za przekroczenie dopuszczalnego czasu.

Ostatnią konkurencją jest bieg przełajowy połączony z trzykrotnym strzelaniem. Zadownik może opuścić strzelnicę dopiero po 5 trafieniach w cel (celność strzałów zależy od umiejętności), przy czym jeżeli nie uda mu się tego zrobić w ciągu 70 sekund - biegnie dalej. Czas biegu zawodnika także zależy od jego umiejętności. Jeżeli całkowity czas biegu i strzelania przekroczył ustalony limit, zawodnikowi odejmowane są punkty. Za osiągnięcie rezultatu poniżej wyznaczonej granicy, przyznawane są dodatkowe punkty.

W ostatniej fazie symulacji zapisywane są do pliku wyniki zawodów oraz statystyki poszczególnych zawodników (według malejącej liczby punktów). 
