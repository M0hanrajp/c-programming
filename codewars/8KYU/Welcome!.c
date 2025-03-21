/* Your start-up's BA has told marketing that your website has a large audience in Scandinavia and surrounding countries. Marketing thinks it would be great to welcome visitors to the site in their own language. Luckily you already use an API that detects the user's location, so this is an easy win.
The Task
Think of a way to store the languages as a database. The languages are listed below so you can copy and paste!
Write a 'welcome' function that takes a parameter 'language', with a type String, and returns a greeting - if you have it in your database. It should default to English if the language is not in the database, or in the event of an invalid input.
The Database
Please modify this as appropriate for your language.

[ ("english", "Welcome")
, ("czech", "Vitejte")
, ("danish", "Velkomst")
, ("dutch", "Welkom")
, ("estonian", "Tere tulemast")
, ("finnish", "Tervetuloa")
, ("flemish", "Welgekomen")
, ("french", "Bienvenue")
, ("german", "Willkommen")
, ("irish", "Failte")
, ("italian", "Benvenuto")
, ("latvian", "Gaidits")
, ("lithuanian", "Laukiamas")
, ("polish", "Witamy")
, ("spanish", "Bienvenido")
, ("swedish", "Valkommen")
, ("welsh", "Croeso")
]
Possible invalid inputs include:

IP_ADDRESS_INVALID - not a valid ipv4 or ipv6 ip address
IP_ADDRESS_NOT_FOUND - ip address not in the database
IP_ADDRESS_REQUIRED - no ip address was supplied */
//  don't allocate memory for return
//  instead, return a string literal
#include <string.h>
const char *greet (const char *language) {
  if(!strcmp(language, "english")){ return "Welcome";}
  if(!strcmp(language, "finnish")){ return "Tervetuloa";}
  if(!strcmp(language,  "polish")){ return "Witamy";}
  if(!strcmp(language, "latvian")){ return "Gaidits";}
  if(!strcmp(language,   "irish")){ return "Failte";}
  if(!strcmp(language,  "french")){ return "Bienvenue";}
  if(!strcmp(language,   "czech")){ return "Vitejte";}
  if(!strcmp(language,   "dutch")){ return "Welkom";}
  if(!strcmp(language,   "welsh")){ return "Croeso";}
  if(!strcmp(language,"estonian")){ return "Tere tulemast";}
  if(!strcmp(language,  "danish")){ return "Velkomst";}
  if(!strcmp(language, "flemish")){ return "Welgekomen";}
  if(!strcmp(language,  "german")){ return "Willkommen";}
  return "Welcome";
}
