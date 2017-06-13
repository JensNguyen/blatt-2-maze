# blatt-2-maze

[![Build Status](https://travis-ci.org/algdat/blatt-2-amf0.svg?branch=master)](https://travis-ci.org/algdat/blatt-2-maze.svg?branch=master)

[![Build Status](https://codecov.io/gh/algdat/blatt-2-maze/coverage.svg?branch=master)](https://travis-ci.org/algdat/blatt-2-maze.svg?branch=master) 
<a href="https://codecov.io/gh/algdat/blatt-2-maze/branch/master">details</a>



### Ziel des Projektes

Es sollen verschiedene Labyrinthlösungs Algorithmen implementiert und auf ihre Effizienz und Schnelligkeit verglichen werden.
Darüber hinaus sollen die Lösungenwege der Algorithmen visuell dargestellt werden.

### Rahmenbedingungen
Compiler: c++11  
JUnit-Tests: gTest 

### Aufgabenverteilung
~~Wall follower~~/ReadMe.md (Jens)  
Tremaux's algorithm (Emir)  
Recursive(Wall Follower) (Flo)  
Shortest path algorithm (breadth-first search) (Rudi)  

### Erläuterung der Algorithmen
Wall follower:
Man legt einfach seine link/rechte Hand an die Wand des Labyrinths und läuft and dieser entlang ohne den Kontakt zu verlieren. 
Falls alle Mauern zusammenhängen oder mit der Außenseite verbunden sind dieser Algorithmus, dass man entweder einen anderen Ausgang erreicht, oder wieder zum Eingang zurückkehrt.

Tremaux's algorithm:
Ein Weg ist entweder unbesucht, einfach oder zweifach markiert. Am Anfang wird eine beliebige Richtung gewählt (wenn es mehr als eine gibt). Dann wird jeder beschrittene Gang von Kreuzung zu Kreuzung zum Beispiel mit einem Strich am Boden markiert. Erreicht man eine Kreuzung, an die man noch nie gekommen ist (erkenntlich daran, dass es keine Markierungen am Boden gibt), wählt man einen beliebigen Gang, um weiterzugehen (und markiert ihn wie beschrieben). Erreicht man dagegen eine markierte Kreuzung und ist der Gang, aus dem man gerade kommt, nur einmal markiert, dreht man um und geht zurück (und markiert den Gang ein zweites Mal). Ansonsten wählt man einen Gang mit möglichst wenigen Markierungen (und markiert ihn wie immer). Erreicht man schließlich sein Ziel, so ist der direkte Weg zurück zum Start mit genau einem Strich markiert.
Sollte es keinen Ausgang geben, erreicht man schließlich wieder den Ausgangspunkt, und alle Gänge des Irrgartens sind mit genau zwei Strichen markiert.

Shortest path algorithm (breadth-first search):
 Dieser Algorithmus wandelt den Weg durch das Labyrinth als Pfad zum Blatt eines Baumes um. Jede Fläche im Labyrinth ist ein Knoten im Baum und jede neue Fläche zu dem man von dort gelangen kann ist ein Kind dieses Knotens.
 Dieser Algorithmus geht nun immer erst die gesamte Breite einer Tiefe durch, bevor es eine Ebene weiter runter geht.

**Wall follower:**
Man legt einfach seine link/rechte Hand an die Wand des Labyrinths und läuft and dieser entlang ohne den Kontakt zu verlieren. 
Falls alle Mauern zusammenhängen oder mit der Außenseite verbunden sind dieser Algorithmus, dass man entweder einen anderen Ausgang erreicht, oder wieder zum Eingang zurückkehrt.

**Tremaux's algorithm:**
Ein Weg ist entweder unbesucht, einfach oder zweifach markiert. Am Anfang wird eine beliebige Richtung gewählt (wenn es mehr als eine gibt). Dann wird jeder beschrittene Gang von Kreuzung zu Kreuzung zum Beispiel mit einem Strich am Boden markiert. Erreicht man eine Kreuzung, an die man noch nie gekommen ist (erkenntlich daran, dass es keine Markierungen am Boden gibt), wählt man einen beliebigen Gang, um weiterzugehen (und markiert ihn wie beschrieben). Erreicht man dagegen eine markierte Kreuzung und ist der Gang, aus dem man gerade kommt, nur einmal markiert, dreht man um und geht zurück (und markiert den Gang ein zweites Mal). Ansonsten wählt man einen Gang mit möglichst wenigen Markierungen (und markiert ihn wie immer). Erreicht man schließlich sein Ziel, so ist der direkte Weg zurück zum Start mit genau einem Strich markiert.
Sollte es keinen Ausgang geben, erreicht man schließlich wieder den Ausgangspunkt, und alle Gänge des Irrgartens sind mit genau zwei Strichen markiert.

**Shortest path algorithm (breadth-first search):**
 Dieser Algorithmus wandelt den Weg durch das Labyrinth als Pfad zum Blatt eines Baumes um. Jede Fläche im Labyrinth ist ein Knoten im Baum und jede neue Fläche zu dem man von dort gelangen kann ist ein Kind dieses Knotens.
 Dieser Algorithmus geht nun immer erst die gesamte Breite einer Tiefe durch, bevor es eine Ebene weiter runter geht.

 
### Umsetzung
Alle Algorithmen wurden in C++ implementiert.
Wir messen die Zeit und benötigten Schritte, die ein Algorithmus braucht um bestimmte Labyrinte zu lösen.
Diese Messwerte vergleichen wir mit den anderen, um den effizientesten unter den ausgewählten Algorithmen zu finden.
Zur visuellen Darstellung der Algorithmen wurde  <a href="https://www.qt.io/">QT</a> verwendet




### <a href="https://algdat.github.io/blatt-2-maze/doxygen_doc/html/">Doxygen Dokumentation</a>



### Bezeichnungen für Startfeld
. = open (Weg)  
\# = blocked (Wand)  
S = start  
G = goal  
\+ = path (Lösungsweg)  

### Rahmenbedingungen
Compiler: c++11  
JUnit-Tests: gTest  

### <a href="https://algdat.github.io/blatt-2-maze/doxygen_doc/html/">Dokumentation</a>

### ToDo
- Website
  
