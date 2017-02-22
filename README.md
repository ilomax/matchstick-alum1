Changelog :

1.0 -
 - Removed the my_printf() function which caused many Valgrind errors and eventually led to crashes on some systems. Now replaced by my_putstr(), my_putchar() and my_putstr().]
 - The error messages are now written on the error output (u no say ?), using my_putchar_err(), my_putsterr() and my_putnbr_err().
 - The AI has been fixed so it doesn't remove all the matches of the last line, making it a bit 'smarter'.

1.1 -
 - The 'cnt' variable is now reset after a line error, as it previously used the latest value instead of asking for a new input if needed.

______________________________________

FR (EN below) |

L'objectif de ce projet est de recoder un jeu de Nim, avec évidemment quelques règles supplémentaires. La map doit pouvoir être générée avec jusqu'à 100 lignes, chacune contenant 2 allumettes de plus que la précédente. Le 1er paramètre est le nombre de lignes d'allumettes à générer, le 2ème est le nombre maximum d'allumettes que le joueur est autorisé à enlever à chaque tour. Le joueur qui enlève la dernière allumette perd.

Le jeu doit être jouable seul, contre une IA. La mienne est basée sur des nombres aléatoires, mais optimisée de façon à ne pas perdre si elle peut gagner (en enlevant une seule allumette s'il en reste deux dans tous les cas) et générer les nombres sur une intervalle 1-[nombre d'allumettes restant sur la ligne] de façon a réduire le temps de calcul, même sur des maps de 100 lignes.

Le projet reproduit à l'identique le comportement montré en exemple sur le sujet, même sur les retours, mais il ne passe que quelques tests à la moulinette. Des modifications seront bientôt apportés pour règler ces problèmes.

A venir :

Amélioration de l'IA (modes de difficultés ?)
Une IA qui "triche" (Vous en saurez plus une fois terminé)
Un mode deux-joueurs en local
EN |

The goal of this project is to code a game of Nim with (obviously) a few specific rules. You have to be able to generate a map with up to 100 lines of matches, each line containing 2 more than the previous one. The first parameter given is the size of the map, the second one is the maximum amout of matches you are able to remove per turn. The one player to remove the last match loses.

The game should be playable alone, against an AI. Mine is based on randomly-generated numbers, but optimized so it doesn't lose if it can win (if there is only two matches, the AI will remove only one) and also generate numbers based on the remaining matches on the line.

All in all, it should greatly reduce the time, even with map of a hundred lines. This project reproduces the exact behaviour of what is shown as examples, but only passes a few tests. More fixes to come in order to pass all the tests possible.

Coming as well :

An improvement of the AI.
A "cheating" AI (I'll tell more once it's done).
A local 2-players mode.
