# Projet-Bibliothèque

DESCRIPTION :
Projet CY-biblioTECH s’agit de réaliser un programme permettant de gérer automatiquement le stock de livres d’une bibliothèque universitaire. Le programme devra se baser sur une liste de livres et d’utilisateurs et gérer les emprunts et les restitutions de livres. L’application ne devra pas uniquement indiquer si un livre a été emprunté et par qui mais également gérer les règles de la bibliothèque comme les durées d’emprunts, le nombre de livres qu’il est possible d’emprunter etc. Il y aura deux types d’utilisateurs qui n’auront pas les mêmes droits en matière d’emprunts : les étudiants et les professeurs 

COMMENT IL FONCTIONNE :
Premièrement il vous est demandé de se connecter ou de s'inscrire. Vous devez suivre les instructions a l'écran. Ensuite, il y a une verification si vous avez respectez les règles. Par la suite, un menu s'affiche, avec votre nombre de livres emprunté et leurs titres puis  il vous sera demandez 4 actions : Eprunt, Rendre, Ajouter ou quitter. 

Connexion : inscriver votre id et votre mot de passe comme vous vous etes inscris.

Inscription : Entrer votre nouveau id, mdp, selectionné 1 pour prof ou 2 pour etudiant. Etat signifie si votre compte et actif ou non, et le nbr de livre emprunté est a 0 par defaut.

Emprunt: Le programme va verifier si vous pouvez encore emprunter un livre. La liste des livres s'affichera et vous inscrirez le titre du livre avec espace compris.

Rendre: Le prog vous demandera quel livre voulez vous rendre. Ensuite il va verifier si vous avez bien emprunté ce livre auparavant. Si oui pas de probleme, sinon vous ne pouvez pas rendre ce livre. Ensuite une verification est faite si vous avez respecté les delais d'emprunt. Il desactivera votre compte si vous n'avez pas respecté les règles.

Ajouter: Si vous etes prof vous pourrez ajouter un livre sinon impossible. Si vous l'etes, le prog va vous demander le titre (espace compris), auteur, numero d'identification et catégories (a selectionné avec 1,2,3 ou 4). Une verification des informations sera afficher, il suffira de mettre 1 pour oui et 2 pour non.
