#include "glib-object.h"
#include "glib.h"
#include "glibconfig.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-glib/json-glib.h>
#include <unistd.h>

// https://gnome.pages.gitlab.gnome.org/json-glib/ [json apis]
// https://gnome.pages.gitlab.gnome.org/json-glib/class.Parser.html parser class

int main(int argc, char *argv[]) {
    // get the JSON object
    if(argv[1] == NULL) {
        printf("No arguments to program, error\n");
        exit(-1);
    }
    char *jsonObject = calloc(strlen(argv[1]) + 1, sizeof(char));
    // ./a.out '{"a": 10, "b": 32}' program input
    strcpy(jsonObject, argv[1]);

    GError *error = NULL;
    gssize jsonLength = strlen(jsonObject);
    // https://gnome.pages.gitlab.gnome.org/json-glib/ctor.Parser.new.html
    JsonParser *parser = json_parser_new();

    // https://gnome.pages.gitlab.gnome.org/json-glib/method.Parser.load_from_data.html
    json_parser_load_from_data(parser /* JsonParser *parser */,
                               jsonObject /* const gchar *data */,
                               jsonLength /* gssize length */,
                               &error /* GError **error */);
    if(error) {
        printf("[ERR]: %s\n", error->message);
        exit(-1);
    }

    // https://gnome.pages.gitlab.gnome.org/json-glib/method.Parser.get_root.html
    JsonNode *rootObject = json_parser_get_root(parser);

    // https://gnome.pages.gitlab.gnome.org/json-glib/method.Node.get_object.html
    JsonObject *obj = json_node_get_object(rootObject);

    // get the values
    gint64 a = json_object_get_int_member(obj /* JsonObject *object */,
                                          "a" /* const gchar *member_name */);
    gint64 b = json_object_get_int_member(obj /* JsonObject *object */,
                                          "b" /* const gchar *member_name */);

    gint64 sum = a + b;
    // build json reply
    // https://gnome.pages.gitlab.gnome.org/json-glib/ctor.Builder.new.html
    JsonBuilder *jsonReply = json_builder_new();

    // https://gnome.pages.gitlab.gnome.org/json-glib/method.Builder.begin_object.html
    json_builder_begin_object(jsonReply);
    // https://gnome.pages.gitlab.gnome.org/json-glib/method.Builder.set_member_name.html
    char *replyString = calloc(20, sizeof(char));
    sprintf(replyString, "Addition of %ld + %ld", a, b);
    json_builder_set_member_name(jsonReply, replyString);
    // https://gnome.pages.gitlab.gnome.org/json-glib/method.Builder.add_int_value.html
    json_builder_add_int_value(jsonReply, sum);
    // https://gnome.pages.gitlab.gnome.org/json-glib/method.Builder.end_object.html
    json_builder_end_object(jsonReply);

    // https://gnome.pages.gitlab.gnome.org/json-glib/ctor.Generator.new.html
    JsonGenerator *gen = json_generator_new();
    // https://gnome.pages.gitlab.gnome.org/json-glib/method.Builder.get_root.html
    JsonNode *reply = json_builder_get_root(jsonReply);
    json_generator_set_root(gen, reply);
    // https://gnome.pages.gitlab.gnome.org/json-glib/method.Generator.set_pretty.html
    json_generator_set_pretty(gen, 1);
    // https://gnome.pages.gitlab.gnome.org/json-glib/method.Generator.to_data.html
    gchar *result = json_generator_to_data(gen, NULL);
    printf("%s\n", result);

    free(jsonObject);
    g_object_unref(parser);
    g_object_unref(jsonReply);
    g_object_unref(gen);
    json_node_free(reply);
    free(replyString);
    g_free(result);
    return 0;
}
