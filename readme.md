# Prototypage d'un POC

## <ins>Prérequis</ins>
- Avoir un groupe
- Avoir un compte [Github](https://github.com)
- Installer [Git / Git Bash](https://gitforwindows.org/)
- [VS Code](https://code.visualstudio.com/)
- Ajouter l'extension [Platformio](https://platformio.org/platformio-ide) à VS Code

---

## <ins>Préparation</ins>
1. `Forkez` le projet du TP sur votre compte github avec le nom **"PDP_ETUDIANTS_01_TD`<NUMERO_DE_TD>`\_GP`<NUMERO_DE_GROUPE>`"**. Par exemple, le groupe 7 du TD 2 devra créer le repo "PDP_ETUDIANTS_01_TD02_GP07"
2. Clonez **votre fork** sur votre machine avec `git clone <url>`
3. Ouvrir le projet avec PlatformIO (sinon les options de compilation et téléversement peuvent ne pas apparaître)
4. Compléter le code pour compléter chaque étape et `commit` **REGULIEREMENT**

Afin de vérifier votre compréhension du fonctionnement de l'environnement de développement, vous allez travailler avec Git, vous devrez donc `commit` vos modifications régulièrement. Chaque étape devra faire l'objet d'une `branch` distincte sur votre `repository`. Pour indiquer qu'un exercice est terminé, vous devrez tagguer le commit corrrespondant avec un formalisme indiqué dans les instructions. Comme vous devez travailler sur des branches par étape, le `master` devrait être inchangé à la fin.

## <ins>Evaluation</ins>
L'évaluation de votre travail sera réalisée sur les critères suivants :
- Etapes terminées
- Respect des consignes de nommage des `branch` et `tag` git
- Contenu et description des `commit`
- Qualité du code (structure, lisibilité, commentaires utiles si et seulement si nécessaire...)
- Temps nécessaire pour réaliser les étapes

## <ins>Quelques ressources</ins>
- [Documentation AZ-Delivery](https://cdn.shopify.com/s/files/1/1509/1638/files/ESP_-_32_NodeMCU_Developmentboard_Datenblatt_AZ-Delivery_Vertriebs_GmbH_10f68f6c-a9bb-49c6-a825-07979441739f.pdf?v=1598356497)
- [Reference framework Arduino](https://www.arduino.cc/reference/en/)
- [Datasheet DHT11](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf)

---

## <ins>Etape 1 - Blink pour vérifier que tout roule</ins>

## Réalisation
1. Créer une `branch` etape_1 à partir de master avec `git checkout -b etape_1 master`
2. Copier ce code dans `main.cpp` dans le dossier `src`. `NOTE : il est possible que VS Code indique une erreur sur la première ligne. Cette erreur peut être ignorée, il s'agit de l'extension C/C++ de VS Code qui cherche l'include au mauvais endroit mais PlatformIO peut la trouver.`

```C
#include <Arduino.h>

// Define the pins that we will use
#define CAPTEUR 33
#define LED 26

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}
```
3. Compiler et téléverser sur la carte ESP32 avec Platformio. Il faut garder le bouton "BOOT" enfoncé jusqu'à ce que Platformio ait trouvé la carte. En cas de souci, il peut être utile de couper le Bluetooth de son ordinateur (l'adaptateur Bluetooth utilise des ports COM que Platformio peut détecter par erreur).
4. Effectuer le montage sur la breadboard. Faire attention à ne pas plier les pins de l'ESP32. **Les breadboards sont étroites et seulement une rangée d'emplacements peut dépasser sous la carte, faire en sorte que la rangée entre les pins "V5" et "3V3" soit accessible pour des jumpers**.
5. Connecter V5 sur le rail positif de la breadboard (rouge) et GND sur le rail négatif.
6. Connecter une LED sur le bon pin en la protégeant avec une résistance de ~330Ω.
7. Vérifier le bon fonctionnement du montage, la LED doit clignoter.
9. Tagguer le dernier `commit` à corriger avec "e1" avec la commande `git tag e1 HEAD`. Cette commande utilise "HEAD" comme référence au commit le plus récent.
10. Publier vos `commits` avec `git push -u origin etape_1`
11. Publier vos `tags` avec `git push origin --tags`
---

## <ins>Etape 2 - Capteur et mesures</ins>

## Réalisation
1. Créer une `branch` etape_2 à partir de master avec `git checkout -b etape_2 master`
2. Votre objectif lors de ce TP est de créer et structurer l'application embarqué d'un objet avant de le rendre connecté. Lors de cette partie, on cherche a créer un montage sur breadboard avec les cartes AZ-Delivery ESP32 et le capteur d'hygrométrie et température DHT11. Le but pour l'instant est simplement de lire les valeurs du capteur à intervalle régulier, en mettant l'ESP32 en mode économie d'énergie entre les mesures.
3. Copier ce code dans `main.cpp` dans le dossier `src`

```C
#include <Arduino.h>

// Define the pins that we will use
#define CAPTEUR 33
#define LED 26

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // Effectuer une mesure toutes les 5s

  // Afficher l'humidité relative avec un peu de formatage

  // Afficher la température avec un peu de formatage
}
```
4. Utiliser le montage suggéré dans la [datasheet du DHT11](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf) pour installer le capteur d'humidité et température. **LE PIN 3 N'EST PAS UTILISE**. La LED n'est pas utilisée dans cette étape mais le sera plus tard. 
> [!CAUTION] Danger
> ATTENTION à l'orientation des pins, le capteur va **🔥 CRAMER 🔥** si branché avec la mauvaise polarité...
5. Utiliser Platformio pour installer les bibliothèques `Adafruit Unified Sensor` et `DHT sensor library`.
6. Utiliser l'exemple fourni sur la page de la bibliothèque `DHT sensor library` pour compléter le code fourni en prenant les mesures et en affichant les résultats régulièrement.
7. Vérifier le bon fonctionnement du montage
8. Tagguer le dernier `commit` à corriger avec "e2" avec la commande `git tag e2 HEAD`. Cette commande utilise "HEAD" comme référence au commit le plus récent.
9.  Publier vos `commits` avec `git push -u origin etape_2`
10. Publier vos `tags` avec `git push origin --tags`

---

## <ins>Etape 3 - Gestion de l'alimentation</ins>

## Réalisation
1. Créer une `branch` etape_3 _**à partir de l'étape précédente**_ avec `git checkout -b etape_3 etape_2`
2. Le produit que l'on cherche à créer devra fonctionner sur batterie pour être totalement indépendant, même si notre prototype sera alimenté par USB. Pour nous mettre dans des conditions plus proches du produit final, on cherche à utiliser les modes de veille qui seront utilisés dans le produit pour réduire la consommation et augmenter sa durée de vie sur batterie. Pour ça, on va utiliser le mode de veille "Deep sleep" de l'ESP32. L'ESP32 possède plusieurs modes d'alimentation récapitulés dans la table ci-dessous, et le Deep sleep est l'option qui consomme le moins, en éteigant tous les périphériques, les communications, etc. En deep sleep, l'ESP32 est inactive et complètement injoignable (sauf pour la programmer). Il est possible de programmer un timer pour l'éteindre pour une durée déterminée après une exécution, après quoi il redémarre.

<p align="center">
  <img src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/02/POWER-MODES.jpg?w=667&quality=100&strip=all&ssl=1" />
</p>

3. Modifier le code existant en remplaçant la boucle de lecture dans le loop par une mesure unique par exécution du code, suivie de 5s en mode deep sleep. Toute la logique du code est déplacée dans la fonction `setup`, la fonction `loop` doit alors être vide.
4. Vérifier que le code fonctionne toujours avec la gestion de l'alimentation.
6. Tagguer le dernier `commit` à corriger avec "e3" avec la commande `git tag e3 HEAD`. Cette commande utilise "HEAD" comme référence au commit le plus récent.
7. Publier vos `commits` avec `git push -u origin etape_3`
8. Publier vos `tags` avec `git push origin --tags`

---
