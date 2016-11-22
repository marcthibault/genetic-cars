# CR - briefing des équipes - 18/10

## Team Car :

#### Définition des paramètres de la voiture
  - deux roues
    - diamètres
    - espacement
    - densités


  - "centre" omega
    - angle par rapport aux roues

  - points (nombre déterminé, fixe) (motié en haut, moitié en bas)
    - chacun un angle (/omega)
    - chacun une distance (/omega)


#### Liens avec autres teams
  - **team algo Gen** : définir clairement les paramètres ; finir la classe car.cpp
  - **team Physics Engine** : (plus tard) définir des accesseurs sur mesure pour pouvoir les générer


## Team Algo Gen :

#### Définition du modèle
  - combinaison linéaire de toutes les voitures
    - coefficients à définir
    - prends en compte tout le monde
    - prends en compte la réussite de chaque voiture


  - ajout d'un vecteur aléatoire
    - loi à déterminer

#### Liens avec autres teams
  - **team Car** : une fois le modèle et le cadre prêts, aller les aider pour la définition de la voiture (en fonction de leurs attentes)
  - **team Physics Engine** : définir le format de transmission des paramètres (résultats de la course)

## Team Physics Engine :

#### Problèmes avec `Box2D`

  - compilation pour tout le monde ?
  - le mettre dans notre git ?

#### Liens avec autres teams
  - **team Car** : le moment venu, voir avec eux pour définir les bons accesseurs (qui facilitent la tâche pour la modélisation)
  - **team UI** : le moment venu, définir le format dont ils auront besoin pour
    - le dessin et l'affichage des formes
    - l'interaction utilisateur (typiquement, `pause`)

  - **team Algo Gen** : définir le format de retour des paramètres

## Team UI :

#### Travail préliminaire

- découverte des interfaces Qt

#### Liens avec autres teams
- **team Physics Engine** : une fois le dessin appréhendé, voir avec eux la forme des paramètres à récupérer

## Architecture générale :

- clarification du process
