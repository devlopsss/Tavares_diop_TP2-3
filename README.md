Pour tester notre client nous avons installé tftp dans le terminal linux. Nous nous sommes ensuite connectés de la manière suivant:
"ensea@StudentLab:~$ tftp srvtpinfo1.ensea.fr"

Pour la première étape nous avons écris le  code nous permettant seulement d'afficher les arguments données dans les fonctions gettpft et puttpft, sans se soucier dans un premier temps du corps de la logique de la fontion.
Cela a été fait grace à la fonction write, entre autres.
  Pour l'appel de la fontion getaddrinfo nous avons eu recours à la structure addrinfo . 
Après test  de getaddrinfo nous lisons :
   ///mettre capture

3.
Le code C fait essentiellement trois choses :
 il prend le nom d'hôte du serveur TFTP en ligne de commande, résout cette adresse, puis crée et connecte un socket (une sorte de canal de communication) avec le serveur.
 La fonction reserveSocket gère ces étapes pour obtenir un socket prêt à être utilisé dans la communication avec le serveur TFTP.
 Ensuite, ce socket est utilisé dans le reste du programme, et à la fin, le programme se termine en fermant ce canal de communication.

