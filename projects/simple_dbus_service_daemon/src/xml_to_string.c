#include "xml_to_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

xmlDocPtr openFile(const char *fileName) {
    xmlDocPtr file = xmlReadFile(fileName, /*const char *URL */
                                 NULL, /* const char *encoding */ 
                                 0 /* int options */ );
    if(file == NULL) {
        printf("[INFO]: XML read failed\n");
        exit(-1);
    } else {
        printf("[INFO]: XML read complete @ %s\n", __func__);
    }
    return file;
}

char *xmlToString(xmlDocPtr doc) {
    xmlChar *xmlBuff;
    int bufferSize;

    /* @doc:  Document to generate XML text from
     * @xmlbuff:  Memory pointer for allocated XML text
     * @buffersize:  Length of the generated XML text
     * @format:  should formatting spaces been added
     */
    xmlDocDumpFormatMemory(doc, &xmlBuff, &bufferSize, 1); // 1 for pretty printing

    // If you need a dynamically allocated string, you need to copy the data:
    char *result = (char *)malloc(bufferSize + 1);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    snprintf(result, bufferSize + 1, "%s", xmlBuff);

    xmlFree(xmlBuff); // Free the buffer allocated by libxml2
    return result;
}

/* To test
int main(void) {
    xmlDocPtr doc = openFile("introspect_add.xml");
    char *s = xmlToString(doc);

    if (s) {
        printf("XML as string:\n%s\n", s);
        free(s); // Free the memory allocated in xml_to_string
    }
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}
*/
