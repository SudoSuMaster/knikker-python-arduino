Vereisten:
1. Python 3.11
2. Laptop met Windows 10/11
3. Hardware voor de knikkerbaan
4. Visual Studio

Gebruiksaanwijzing:
1. Sluit eerst de knikkerbaan aan op de laptop via een USB-poort.
2. Controleer de COM-poort als volgt:
3. Ga naar "Configuratiescherm > Apparaatbeheer > Poorten" om de aangesloten seriële COM-poorten te bekijken.
4. Verander in de python code op line 6 standaard COM6 naar de poort waaraan je de Arduino hebt aangesloten.
5. Start Figma en zorg ervoor dat Figma reageert op handmatige gebruikersinvoer.
6. Start Python via Visual Studio Code of de command-line interface. In Visual Studio Code klik je op de groene driehoek "Run".
7. Zorg er tot slot voor dat je muis zich in het Figma-venster bevindt, zodat Python de toetsenbordopdrachten in het juiste venster kan uitvoeren.

sketch_jan3a.ino uitleg:
1. Wanneer op een van de vier knoppen (eens, oneens, herstart, start) wordt gedrukt, wordt voor elke knop een specifieke actie uitgevoerd:
De knikkerbaan heeft drie rijen servo motoren (rij 1 = 1 servo motor, rij 2 = 2 servo motoren, rij 3 = 4 servo motoren). 
Als de knoppen "eens" of "oneens" worden ingedrukt, draait een van de rijen sequentieel. Dit wordt bijgehouden door een teller die ervoor zorgt dat de rijen in de juiste volgorde draaien. 
Daarnaast wordt een protocol ("eens" of "oneens") via Serial.println naar Python gestuurd, zodat Python weet welke actie moet worden uitgevoerd.
2. Als op de knop "start" wordt gedrukt, wordt alleen een "start" protocol ('x') naar Python gestuurd, zodat Python Figma kan starten.
3. Als op de knop "reset" wordt gedrukt, wordt eerst de teller voor de rotatievolgorde van de knikkerbaan gereset om ervoor te zorgen dat de servo's weer in de juiste volgorde draaien. 
Bovendien wordt een protocol ("r") naar Python gestuurd, waardoor Python ook Figma kan resetten.

knikkerv2.py uitleg:
1. In dit Python-script luistert het programma naar de seriële poort om te bepalen welke toetsen op het toetsenbord moeten worden ingedrukt om Figma te besturen.
2. Als "eens" of "oneens" als protocol wordt ontvangen, drukt het script op de spatiebalk om naar de volgende stelling te gaan in het Figma-programma.
3. Als "r" als protocol wordt ontvangen, herkent Python dit als het reset-commando en activeert het de toets 'r' om Figma terug te zetten naar de beginstand. V
4. Als "x" als protocol wordt ontvangen, activeert Python de toets spatie om de startpagina te sluiten en de eerste stelling weer te geven.

Troubleshooting
Figma:
Als Figma niet reageert, controleer dan het volgende:
1. Is Python gestart?
2. Reageert Figma op gebruikersinvoer? (Controleer of Figma handmatig luistert naar de toetscommando's spatie/r)
3. Werkt de seriële communicatie tussen de Arduino en Python? Controleer de console van Python om te zien of de protocollen correct worden weergegeven.
4. Controleer of je de juiste COM-poort hebt geselecteerd. Als dat niet het geval is, wijzig dit in regel 6 van het Python-script (ser = serial.Serial('VERANDER HIER COM4 OF COM5,6,7 etc', 9600) # Vervang 'COM4' door de COM-poort van je Arduino).

Arduino:
Als de servo motoren problemen veroorzaken, controleer dan het volgende:
1. Zitten de inputpinnen op de microcontroller (Arduino) correct?
2. Zitten de kabels van de knoppen goed vast?
3. Zitten de weerstanden er goed in?
4. Zijn de ground- en plusverbindingen correct gemaakt tussen het breadboard, de microcontroller en de servo's?

EXTRA:
Er was een functie om gebruikersinvoer op het lcd-paneel en de console af te drukken, maar deze is niet opgenomen in deze versie.
De gebruikersinvoer zo in theorie ook opgeslagen kunnen worden in een sql database mocht dat een eis zijn.


