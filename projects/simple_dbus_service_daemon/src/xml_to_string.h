#ifndef XML_TO_STRING_H
#define XML_TO_STRING_H

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlstring.h>

/* returns a pointer to a file */
xmlDocPtr openFile(const char *fileName);

/* Returns a dynamically allocated string */
char *xmlToString(xmlDocPtr doc);

#endif
