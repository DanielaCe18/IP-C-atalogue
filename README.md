# IP-Catalogue

Un utilitaire permettant de cataloguer les adresses IP (IPv4).

## Prérequis

Avant de lancer le programme, assurez-vous d'avoir téléchargé les dépendances nécessaires :
- [msys2](https://www.msys2.org/)
- [ucrt64](https://github.com/msys2/msys2/wiki/MSYS2-introduction#installation)
  
Pour lancer le programme, exécutez la commande suivante dans votre terminal :
```
gcc menu.c && ./a.exe
```

## Instructions d'utilisation

L'utilisateur est dirigé vers l'interface de l'IP Catalogue une fois le programme lancé. Il a la possibilité de choisir parmi quatre options :

1. **Ajouter une IP** : L'utilisateur doit saisir une adresse IP et un masque. Si le format de l'adresse IP est incorrect, le programme l'avertit et explique l'erreur. L'utilisateur peut ensuite confirmer, modifier, revenir en arrière ou annuler l'action en cours.
   - Confirmation de l'ajout : L'utilisateur peut en ajouter une nouvelle ou quitter.

2. **Lister les IP** : Affiche les adresses IP dans la base de données.

3. **Rechercher les IP dans le même sous-réseau** : L'utilisateur doit entrer une adresse IP et un masque, puis le programme affiche les adresses IP dans le même sous-réseau.

4. **Convertir les adresses IP** : L'utilisateur entre une adresse IP, puis celle-ci est convertie en hexadécimal, binaire et décimale.

5. **Quitter** : Permet à l'utilisateur de quitter le programme.

L'utilisateur peut choisir de continuer l'action en cours, revenir en arrière ou quitter le programme à tout moment.
